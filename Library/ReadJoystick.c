/* Joystick Reading                                 */
/*                                                  */
/* By tim lindner, 2007                             */
/*                                                  */
/* This file is in the public domain                */

#include "coco_hardware.h"
#include "ReadJoystick.h"

void initialize_joystick()
{
	/* Set CB2 of PIA 1 to output */
	*PIA1_CRB |= 0x30;
	
	/* Set CA2 to be output */
	*PIA0_CRA |= 0x30; 
	
	/* Set CB2 to be output */
	*PIA0_CRB |= 0x30;

	/* Setup sound register */
	*PIA1_CRA &= 0xfb;		/* Engage direction register */
	*PIA1_DdRA |= 0xfc;		/* Set sound pins to output */
	*PIA1_CRA |= 0x04;		/* Engage data register */
	
	/* Setup pin 7 of port A of PIA 0 to be comparator input */
	*PIA0_CRA &= 0xfb;		/* Engage direction register */
	*PIA0_DdRA &= 0x7f;		/* Set comparator pin to input */
	*PIA0_CRA |= 0x04;		/* Engage data register */
}

char sample_joystick( char axis )
{
	 char cra, crb, sound=0;
	 char previous_sound, i, j;
	
	if( axis > 3 )
		return 0;

	/* Mute CoCo */
	*PIA1_CRB &= 0xf7;
	
	/* Configure MUX switch */
	cra = *PIA0_CRA;
	cra &= 0xf7; /* Clear line */
	
	if( (axis & 0x01) == 0x01 )
		cra |= 0x08; /* Set line */
	
	*PIA0_CRA = cra;

	crb = *PIA0_CRB;
	crb &= 0xf7; /* Clear line */

	if( (axis & 0x02) == 0x02 )
		crb |= 0x08; /* Set line */

	*PIA0_CRB = crb;
	
	previous_sound = 0xff;
		
	/* Successive approximate josytick value */
	for( i=0; i<10; i++ )
	{
		sound = 0x80;	/* Half-way sound value */
		
		for( j=0x40; j!=1; j>>=1 )
		{
			sound |= 0x02;
			*PIA1_DdRA = sound;
			sound &= ~0x02;

			if( (*PIA0_DdRA & 0x80) == 0x80 )
				sound += j;
			else
				sound -= j;
		}
		
		if( sound == previous_sound )
		{
			break;
		}
		
		previous_sound = sound;
	}

	*PIA1_CRB |= 0x38;	/* Set CB2 of PIA 1 to output, and unmute CoCo */

	return sound >> 2; 
}
