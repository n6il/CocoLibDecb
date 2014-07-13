void _exit( int );

void abort()
{
	_exit(255);
}
