/* Console Test                                     */
/*                                                  */
/* By tim lindner, 2007                             */
/*                                                  */
/* This file is in the public domain                */

#include "coco_hardware.h"
#include "Console.h"

int main()
{
	char i;
	
	initialize_text_display( VDG_32, 0x8000 );
	goto_x_y( 0, 1 );

	output_string( "START TYPING\r" );
	
	initialize_keyboard_hardware();
	
	while(1)
	{
		i=key_number();
		
		if( i != 0xff )
		{
			output_string( "KEY NUMBER: " );
			output_number_char_dec( i );
			output_string( "\r" );
			
		}
	};
	
	return 0;
}

