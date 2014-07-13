#include <coco_hardware.h>
#include <ReadJoystick.h>

char *hex = "0123456789ABCDEF";

int main()
{
	initialize_joystick();
	
	while( 1 )
	{
		char a, b;
		
		a = sample_joystick(COCO_JOY_RIGHT_H);
		b = sample_joystick(COCO_JOY_RIGHT_V);

		BASIC_VDG_TEXT[0] = hex[a >> 4];
		BASIC_VDG_TEXT[1] = hex[a & 0x0f];
		BASIC_VDG_TEXT[2] = hex[b >> 4];
		BASIC_VDG_TEXT[3] = hex[b & 0x0f];
		
		if( (a==0) && (b==0) )
			break;
	}
	
	return 0;
}
