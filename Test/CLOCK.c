/* clock implemented in C.  Depends on having the VDG's FS irq enabled and HS disabled */


#include <Console.h>
#include <coco_hardware.h>
#include <Timer.h>

int main() {
	t_clock_bcd clock;

	/* base hardware initialization */
	initialize_text_display( VDG_32, 0x8000 );
	initialize_keyboard_hardware();

	/* Start the timer */
	init_timer();

	while (1) {
		timer_clock_bcd(&clock);
		goto_x_y(0,0);
		output_number_char_dec(clock.hours);
		output_char(':');
		output_number_char_dec(clock.minutes);
		output_char(':');
		output_number_char_dec(clock.seconds);
		output_char(':');
		output_number_char_dec(timer_ms());
		output_char(' ');

		// goto_x_y(0,1);
		// output_number_char_dec(timer_countdown());
	}

	return 0;
}
