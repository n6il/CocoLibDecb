/* Console Test                                     */
/*                                                  */
/* By tim lindner, 2007                             */
/*                                                  */
/* This file is in the public domain                */

#include "coco_hardware.h"
#include "Console.h"

int main()
{
	initialize_text_display( VDG_32, 0x8000 );
	
	while( 1 )
	{
		output_char('H');
		output_char('E');
		output_char('L');
		output_char('L');
		output_char('O');
		output_char(' ');
		output_char('W');
		output_char('O');
		output_char('R');
		output_char('L');
		output_char('D');
		output_char(' ');
		
		output_string( "Hello World!" );
	}
	
	return 0;
}

