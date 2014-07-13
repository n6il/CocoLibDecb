/* Joystick Reading                                 */
/*                                                  */
/* By tim lindner, 2007                             */
/*                                                  */
/* This file is in the public domain                */

/* This function reads the joystick value of a given axis

	Specify the axis as a value between 0 and 3
*/

#define COCO_JOY_RIGHT_H 0
#define COCO_JOY_RIGHT_V 1
#define COCO_JOY_LEFT_H 2
#define COCO_JOY_LEFT_V 3

/* Call this function to initialize the PIA hardware for use with
   a standard Color Computer joystick. */

void initialize_joystick();

/* Call this function to sample one axis of one joystick.
   The axis argument must be an integer between 0 and 3.
   Value returned is an integer between 0 and 63. */

char sample_joystick( char axis );
