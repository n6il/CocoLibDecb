# libRSDOS - a simple Color Computer Library of functions
#            by tim lindner, 2007

# libc - a simple Color Computer Library of functions that conforms to Standard C
#        by tim lindner, 2007

CC = m6809-gcc
CFLAGS = -Wall -L/usr/local/coco/lib -I/usr/local/coco/include

%.a:
	m6809-ar -rc $@ $^

.PHONY: all
all: libc.a libRSDOS.a

ReadJoystick.o: coco_hardware.h ReadJoystick.h
Console.o: coco_hardware.h Console.h
Timer.o: Timer.h

# Libraries
libc.a: libc_exit.o libc_abort.o libc_stdio.o libc_syscalls.o libc_string.o
#libc.a: libc_exit.o libc_abort.o
libRSDOS.a: ReadJoystick.o Console.o Timer.o

.PHONY: install
install:
	cp -f libc.a /usr/local/coco/lib/
	m6809-ar --cache /usr/local/coco/lib/libc.a

	cp -f libRSDOS.a /usr/local/coco/lib/
	m6809-ar --cache /usr/local/coco/lib/libRSDOS.a

	cp -f *.h /usr/local/coco/include/

.PHONY: clean
clean:
	rm -f *.o *.a
