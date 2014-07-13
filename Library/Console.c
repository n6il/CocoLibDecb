/* Console I/O                                      */
/*                                                  */
/* By tim lindner, 2007                             */
/*                                                  */
/* This file is in the public domain                */

#include "coco_hardware.h"
#include "Console.h"

static void setup_text_display( char mode, unsigned int address );
static char current_mode;
static char *start_address;
static unsigned short screen_buffer_length;
static unsigned short cursor_position;

static char *keyboard_table="@HPX08\rAIQY19 BJRZ2: CKS^3; DLT 4, EMU 54- FNV 6. GOW 7/ ";

char initialize_text_display( char mode, unsigned int address )
{
	if( (mode < VDG_32) || (mode > GIME_80) )
		return 0xff;
	
	setup_text_display( mode, address );
	clear_screen();
	show_text_display();
	
	return 0;
	
}

static void setup_text_display( char mode, unsigned int address )
{
	current_mode = mode;

	switch( current_mode )
	{
		case VDG_32:
			start_address = (char *)((short)address & 0xfe00);
			screen_buffer_length = 512;
			break;

		case GIME_40:
			break;
		
		case GIME_80:
			break;
		
		default:
			break;
	}
}		
	
void show_text_display()
{
	switch( current_mode )
	{
		case VDG_32:
			*PIA1_CRB &= 0xfb; /* Enable DDRB */
			*PIA1_DdRB |= 0x7c; /* Set bits 3 thru 7 to output */
			*PIA1_CRB |= 0x04; /* Enable DRB */
			*PIA1_DdRB &= 0x03; /* Set AI text screen */
			
			/* Set video buffer mode */
			*SAM_V0_CLR = 0;
			*SAM_V1_CLR = 0;
			*SAM_V2_CLR = 0;
			
			
			/* Set starting address*/
			if( (unsigned short)start_address & 0x200 )
				*SAM_F0_SET = 0;
			else
				*SAM_F0_CLR = 0;
				
			if( (unsigned short)start_address & 0x400 )
				*SAM_F1_SET = 0;
			else
				*SAM_F1_CLR = 0;
				
			if( (unsigned short)start_address & 0x800 )
				*SAM_F2_SET = 0;
			else
				*SAM_F2_CLR = 0;
				
			if( (unsigned short)start_address & 0x1000 )
				*SAM_F3_SET = 0;
			else
				*SAM_F3_CLR = 0;
				
			if( (unsigned short)start_address & 0x2000 )
				*SAM_F4_SET = 0;
			else
				*SAM_F4_CLR = 0;
				
			if( (unsigned short)start_address & 0x4000 )
				*SAM_F5_SET = 0;
			else
				*SAM_F5_CLR = 0;
				
			if( (unsigned short)start_address & 0x8000 )
				*SAM_F6_SET = 0;
			else
				*SAM_F6_CLR = 0;
				
			break;
		
		case GIME_40:
			break;
		
		case GIME_80:
			break;
		
		default:
			break;
	}
}

void clear_screen(void )
{
	unsigned short i;
	
	switch( current_mode )
	{
		case VDG_32:
			for(i=0; i< screen_buffer_length; i++ )
				start_address[i]=0x60;
			break;

		case GIME_40:
			break;
		
		case GIME_80:
			break;
		
		default:
			break;
	}

	cursor_position = 0;
}

void goto_x_y( char x_position, char y_position )
{
	switch( current_mode )
	{
		case VDG_32:
			cursor_position = (y_position * 32) + x_position;
			break;

		case GIME_40:
			break;

		case GIME_80:
			break;
		
		default:
			break;
	}
}

void output_char( char character )
{
	unsigned short i;
	
	if( current_mode == 0 )
		return;
		
	if( character == 0x0d )
	{
		cursor_position += (32 - (cursor_position % 32) );
		return;
	}
	
	/* Control characters ignored */
	if( character < 0x20 )
		return;
	
	if( (character & 0x80) != 0x80 ) /* Graphic Characters pass thru */
	{
		if( character < 0x40 ) /* Special character? */
			character ^= 0x40; /* invert bit 6, swapping case */
		else if( character < 0x60 ) /* Upper/lower case? */
			{}
		else
		{
			character &= 0xdf; /* Clear bit 5, force upper case */
			character ^= 0x40; /* invert bit 6, swapping case */
		}
	}
	
	/* Check if scrolling necessary */
	if( cursor_position == screen_buffer_length )
	{
		for( i=32; i<screen_buffer_length; i++ )
			start_address[i-32] = start_address[i];
		
		for( i=screen_buffer_length-32; i<screen_buffer_length; i++ )
			start_address[i]=0x60;
		
		cursor_position = screen_buffer_length - 32;
	}
	
	start_address[cursor_position++] = character;
}

void output_string( char *string )
{
	if( current_mode == 0 )
		return;
		
	while( *string )
		output_char( *string++ );
}

static void output_number_char_hex_nibble( char number )
{
	if( number > 9 )
		number += 'A'-'9'-1;
	
	number += '0';
	
	output_char( number );
}

void output_number_char_hex( char number )
{
	output_number_char_hex_nibble( number>>4 );
	output_number_char_hex_nibble( number & 0x0f );
}

void output_number_char_dec( char number )
{
	char a, flag;
	
	flag = 0;
	a = number / 100;
	
	if( a != 0 )
	{
		output_number_char_hex_nibble( a );
		number -= a*100;
		flag = 1;
	}
	
	a = number / 10;
	
	if( flag || (a != 0) )
	{
		output_number_char_hex_nibble( a );
		number -= a*10;
	}

	output_number_char_hex_nibble( number );
}

void output_number_schar_dec( signed char number )
{
	if( number == 0 )
	{
		output_char('0');
		return;
	}
	
	if( number < 0 )
	{
		output_char('-');
		number *= -1;
	}
	
	output_number_char_dec( number );

}

void output_number_ushort_dec( unsigned short number )
{
	short a, b, flag;
	
	for(a=10000, flag=0; a>=1; a = a/10 )
	{
		b = number / a;
		
		if( flag || (b != 0) )
		{
			flag = 1;
			output_number_char_hex_nibble( b );
			number -= b*a;
		}
	}
}

void output_number_short_dec( short number )
{
	if( number == 0 )
	{
		output_char('0');
		return;
	}
	
	if( number < 0 )
	{
		output_char('-');
		number *= -1;
	}
	
	output_number_ushort_dec( number );
}

void output_number_uint_dec( unsigned int number )
{
	unsigned long a;
	unsigned short b, flag;
	
	for(a=1000000000, flag=0; a>=1; a = a/10 )
	{
		b = number / a;
		
		if( flag || (b != 0) )
		{
			flag = 1;
			output_number_char_hex_nibble( b );
			number -= b*a;
		}
	}
}

void output_number_int_dec( int number )
{
	if( number == 0 )
	{
		output_char('0');
		return;
	}
	
	if( number < 0 )
	{
		output_char('-');
		number *= -1;
	}
	
	output_number_uint_dec( number );
}

void initialize_keyboard_hardware()
{
	/* Setup keyboard column register */
	*PIA0_CRB &= 0xfb;		/* Engage direction register */
	*PIA0_DdRB |= 0xff;		/* Set column pins to output */
	*PIA0_CRB |= 0x04;		/* Engage data register */

	/* Setup keyboard row register */
	*PIA0_CRA &= 0xfb;		/* Engage direction register */
	*PIA0_DdRA &= 0x80;		/* Set row pins to input */
	*PIA0_CRA |= 0x04;		/* Engage data register */
}

char key_number()
{
	char b, a, result;
	
	result = 0xff;
	b = 0xfe;
	
	// asm( "emubrk" );
	
	while( b != 0xff )
	{
		*PIA0_DdRB = b;
		a = *PIA0_DdRA & 0x7f;
		
		if( a != 0x7f )
			break;
		
		result += 7;
		
		b <<= 1;
		b |= 0x01;
	}
	
	if( b == 0xff )
		return 0xff;
	
	a |= 0x80;

	while( a != 1 )
	{
		result += 1;

		if( (a & 0x01) == 0 )
			break;
		
		a >>= 1;
	}
	
	return result;
	
}

char get_key_now()
{
	int i;
	
	i = key_number();
	
	if( i==0xff )
		return 0xff;
		
	return keyboard_table[ i ];
}
