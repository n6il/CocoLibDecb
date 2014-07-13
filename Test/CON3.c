/* Console Test                                     */
/*                                                  */
/* By tim lindner, 2007                             */
/*                                                  */
/* This file is in the public domain                */

#include "coco_hardware.h"
#include "Console.h"

int main()
{
	unsigned short a=0;
	short b=0;
	signed char sc;
	
	initialize_text_display( VDG_32, 0x8000 );
	goto_x_y( 0, 1 );

	output_string( "ushort a=0:" );
	a=0;
	output_number_ushort_dec( a );
	output_string( "\r" );

	output_string( "ushort a=120:" );
	a=120;
	output_number_ushort_dec( a );
	output_string( "\r" );

	output_string( "ushort a=32768:" );
	a=32768;
	output_number_ushort_dec( a );
	output_string( "\r" );

	output_string( "ushort a=42001:" );
	a=42001;
	output_number_ushort_dec( a );
	output_string( "\r" );

	output_string( "ushort a=5006:" );
	a=5006;
	output_number_ushort_dec( a );
	output_string( "\r" );

	output_string( "ushort a=65535:" );
	a=65535;
	output_number_ushort_dec( a );
	output_string( "\r" );

	output_string( "short b=-123:" );
	b=-123;
	output_number_short_dec( b );
	output_string( "\r" );

	output_string( "short b=0:" );
	b=0;
	output_number_short_dec( b );
	output_string( "\r" );

	output_string( "short b=4025:" );
	b=4025;
	output_number_short_dec( b );
	output_string( "\r" );

	output_string( "schar b=-123:" );
	sc=-123;
	output_number_schar_dec( sc );
	output_string( "\r" );

	output_string( "schar sc=56:" );
	sc=56;
	output_number_schar_dec( sc );
	output_string( "\r" );

	output_string( "schar sc=0:" );
	sc=0;
	output_number_schar_dec( sc );
	output_string( "\r" );

	while(1) {};
	
	return 0;
}

