#include "unistd.h"

void abort()
{
	_exit(255);
}
