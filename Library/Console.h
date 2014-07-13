/* Console I/O                                      */
/*                                                  */
/* By tim lindner, 2007                             */
/*                                                  */
/* This file is in the public domain                */

#define VDG_32 1
#define GIME_40 2
#define GIME_80 3

char initialize_text_display( char mode, unsigned int address );

void show_text_display();

void clear_screen();

void goto_x_y( char x_position, char y_position );

void output_char( char character );

void output_string( char *string );

void output_number_char_hex( char number );

void output_number_char_dec( char number );

void output_number_schar_dec( signed char number );

void output_number_ushort_dec( unsigned short number );

void output_number_short_dec( short number );

void output_number_uint_dec( unsigned int number );

void output_number_int_dec( int number );

void initialize_keyboard_hardware();

char key_number();

char get_key_now();
