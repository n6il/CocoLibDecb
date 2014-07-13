/* _bcd_clock implemented in C.  Depends on having the VDG's FS irq enabled and HS disabled */

#include <coco_hardware.h>
#include "Timer.h"

/* Color Basic defines this as the IRQ Vector JMP(0x7E) *(0x010D)*/
#define IRQ_JUMP_ADDR ((unsigned int *)0x010D)

unsigned int _ticks;
unsigned int ms;
char _countdown;
char junk;
t_clock_bcd _bcd_clock;

/* time to update the clock */
void do_clock() {
	_bcd_clock.seconds++;
	if(_bcd_clock.seconds==60) {
		_bcd_clock.seconds=0;
		_bcd_clock.minutes++;
	}
	if(_bcd_clock.minutes==60) {
		_bcd_clock.minutes=0;
		_bcd_clock.hours++;
	}

}

/* called when FS goes low */
void __attribute__((interrupt())) irq_callback(void) {
	// asm("emubrk");

	/* clear interrupt */
	*PIA0_CRB|=0x04;
	junk=*PIA0_DdRB;

	if (junk&0x80) {
		_countdown--;
		_ticks++;
		/* (17*40)+(16*20)=1000 */
		if (_countdown >= 40) {
			ms+=16;
		} else {
			ms+=17;
		}
	}
	if (_countdown==0) {
		_countdown=60;
		do_clock();
	}
	// asm("rti");	
}

void init_timer() {
	/* Initialize the clock */
	_bcd_clock.hours=_bcd_clock.minutes=_bcd_clock.seconds=0;
	_ticks=0;
	ms=0;

	/* Set up the countdown timer: 60 ticks==1 second */
	_countdown=60;

	/* Register the irq callback */
	*IRQ_JUMP_ADDR=irq_callback;

	*PIA0_CRA&=0xFE; /* disable horizontal scan irq */
	*PIA0_CRB|=0x01; /* enable vertial scan irq */

	/* enable interrupts */
	//asm("emubrk");
	asm("orcc #0x40"); /* mask firq */
	asm("andcc #0xEF"); /* unmask irq */
}

unsigned int timer_ticks() {
	return _ticks;
}

unsigned int timer_ms() {
	return ms;
}

unsigned int timer_countdown() {
	return _countdown;
}

t_clock_bcd * timer_clock_bcd(t_clock_bcd *buf) {
	buf->hours=_bcd_clock.hours;
	buf->minutes=_bcd_clock.minutes;
	buf->seconds=_bcd_clock.seconds;

	return buf;
}
