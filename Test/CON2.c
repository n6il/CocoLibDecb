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
	{
		output_number_char_dec( i );
		output_string( " " );
	}

	while(1) {};
	
	return 0;
}

