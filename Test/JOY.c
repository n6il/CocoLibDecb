#include <coco_hardware.h>
#include <ReadJoystick.h>

int main()
{
	initialize_joystick();
	
	while( 1 )
	{
		char a,b;
		
		a = sample_joystick(COCO_JOY_RIGHT_H);
		b = sample_joystick(COCO_JOY_RIGHT_V);
		
		BASIC_VDG_TEXT[0] = a;
		BASIC_VDG_TEXT[1] = b;
	}
	
	return 0;
}
