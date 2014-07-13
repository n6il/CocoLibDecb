#ifndef TIMER_H
#define TIMER_H
#endif


typedef struct clock_bcd {
	char hours;
	char minutes;
	char seconds;
} t_clock_bcd;
	
/* Initialize Timer */
void init_timer();
/* Get Ticks */
unsigned int timer_ticks();
/* Get Timer In Ms */
unsigned int timer_ms();
/* Get BCD Clock  */
t_clock_bcd * timer_clock_bcd(t_clock_bcd *);

