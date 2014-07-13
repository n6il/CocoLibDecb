#include "unistd.h"

#ifndef STDIO_H
#define STDIO_H

#define putchar(c) fputc(c, STDOUT_FILENO)
#define putc(c, f) fputc(c, f)
#define getchar() fgetc(STDIN_FILENO)
#define getc(f) fgetc(f)
#define puts(s) fputs(s, STDOUT_FILENO)

// int fputc(int c, FILE *stream);
int fputc(int, int);
// int fputs(const char *s, FILE *stream);
int fputs(const char *, int);

// int fgetc(FILE *stream);
int fgetc(int);
// char *fgets(char *s, int size, FILE *stream);
char *fgets(char *, int, int);
// int ungetc(int c, FILE *stream);

#endif
