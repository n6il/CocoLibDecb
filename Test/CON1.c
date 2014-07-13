/* Console Test                                     */
/*                                                  */
/* By tim lindner, 2007                             */
/*                                                  */
/* This file is in the public domain                */

#include "coco_hardware.h"
#include "Console.h"

int main()
{
	char i=0;
	
	initialize_text_display( VDG_32, 0x8000 );
	goto_x_y( 0, 1 );

	for(i=0; i<0xff; i++ )
		output_char(i);
	
	output_string( "\r" );
	output_string( "0X01: " );
	output_number_char_hex( 0x01 );
	output_string( " 0X23: " );
	output_number_char_hex( 0x23 );
	output_string( " 0X45: " );
	output_number_char_hex( 0x45 );
	output_string( " 0X67: " );
	output_number_char_hex( 0x67 );
	output_string( " 0X89: " );
	output_number_char_hex( 0x89 );
	output_string( " 0XAB: " );
	output_number_char_hex( 0xab );
	output_string( " 0XCD: " );
	output_number_char_hex( 0xcd );
	output_string( " 0XEF: " );
	output_number_char_hex( 0xef );
	output_string( "\r" );
	
	output_string( "123: " );
	output_number_char_dec( 123 );
	output_string( "\r" );
	output_string( "255: " );
	output_number_char_dec( 255 );
	output_string( "\r" );
	output_string( "0: " );
	output_number_char_dec( 0 );
	output_string( "\r" );
	output_string( "19: " );
	output_number_char_dec( 19 );
	output_string( "\r" );

	while(1) {};
	
	return 0;
}

