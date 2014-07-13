#include "stddef.h"

#ifndef UNISTD_H
#define UNISTD_H

#define STDIN_FILENO 0
#define STDOUT_FILENO 0
#define STDERR_FILENO 0
#define CONSOLE_FILENO 0
#define TAPE_FILENO -1
#define PRINTER_FILENO -2

int read ( int, void *, int );
int write( int, void *, int );
void exit(int);
void _exit(int);


#endif
