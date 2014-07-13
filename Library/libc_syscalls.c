#include "stddef.h"
#include "unistd.h"
#include "Console.h"

int _console_output ( char *buf, int count ) {
	int i;

	for (i=0; i<count; i++) {
		output_char(buf[i]);
	}

	return i;	
}

int write( int file, void *buf, int count ) {

	if( file < PRINTER_FILENO ) {
		_exit(1);
	}

	if ( buf == NULL ) {
		_exit(1);
	}

	if ( count <= 0 ) {
		return 0;
	}

	switch(file) {
		case PRINTER_FILENO:
		case TAPE_FILENO:
			break;

		case CONSOLE_FILENO:
			return _console_output (buf,count);
			break;

		default:
			break;
	}

	return 0;
}

int _blocking_keyboard_input( char *buf, int count ) {
	int i;
	char c;
	i=0;
	while( i<count ) {
		c=get_key_now();
		if (c != 0xff) {
			buf[i++]=c;
		}
	}
	return i;	
}

int read( int file, void *buf, int count ) {

	if( file < PRINTER_FILENO ) {
		_exit(1);
	}

	if ( buf == NULL ) {
		_exit(1);
	}

	if ( count <= 0 ) {
		return 0;
	}

	switch(file) {
		case PRINTER_FILENO:
		case TAPE_FILENO:
			break;

		case CONSOLE_FILENO:
			return _blocking_keyboard_input(buf,count);
			break;

		default:
			break;
	}

	return 0;
}
