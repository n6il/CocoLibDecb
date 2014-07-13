#include "string.h"
#include "stdio.h"
#include "unistd.h"

int fgetc(int f) {
	int rv;
	char c;
	rv=read(f, &c, 1);

	if (rv != 1) {
		return -1;
	} else {
		return c;
	}
}

int fputc(int c, int f) {
	int rv;
	char c1;
	c1=c;

	rv=write(f, &c1, 1);
	return rv;
}

int fputs(const char *s, int f) {
	if (s==NULL) {
		return -1;
	}

	write( f, (void *)s, strlen(s) );

	return 0;
}

char *fgets(char *s, int n, int f) {
	int i;

	if (s==NULL) {
		return NULL;
	}

	for(i=0; i<n; i++) {
		read(f, (void *)&s[i], 1);
		if(s[i]==0x0d) break;
	}
	
	if (i==n) {
		s[n-1]=0;
	} else {
		s[i]=0;
	}
	
	return s;
}
