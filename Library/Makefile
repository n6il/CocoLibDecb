# libRSDOS - a simple Color Computer Library of functions
#            by tim lindner, 2007

# libc - a simple Color Computer Library of functions that conforms to Standard C
#        by tim lindner, 2007

CC = m6809-gcc
CFLAGS = -Wall -Werror

%.a:
	m6809-ar -rc $@ $^

.PHONY: all
all: libc.a libRSDOS.a

ReadJoystick.o: coco_hardware.h ReadJoystick.h
Console.o: coco_hardware.h Console.h

# Libraries
libc.a: libc_exit.o libc_abort.o
libRSDOS.a: ReadJoystick.o Console.o

.PHONY: install
install:
	cp -f libc.a /usr/local/m6809/lib/
	m6809-ar --cache /usr/local/m6809/lib/libc.a

	cp -f libRSDOS.a /usr/local/m6809/lib/
	m6809-ar --cache /usr/local/m6809/lib/libRSDOS.a

	cp -f *.h /usr/local/m6809/include/

.PHONY: clean
clean:
	rm -f *.o *.a
