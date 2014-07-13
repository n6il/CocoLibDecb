# Make test programs

CC = m6809-gcc
CFLAGS = -Wall -Werror
LDFLAGS = -lRSDOS

VPATH = /usr/local/m6809/include/:/usr/local/lib/gcc/m6809/3.4.6/

%.BIN: %.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)


all: joystick.dsk console.dsk

JOY.BIN: coco_hardware.h ReadJoystick.h crt0.o
JOY1.BIN: coco_hardware.h ReadJoystick.h crt0.o
CON.BIN: coco_hardware.h Console.h crt0.o
CON1.BIN: coco_hardware.h Console.h crt0.o
CON2.BIN: coco_hardware.h Console.h crt0.o
CON3.BIN: coco_hardware.h Console.h crt0.o
CON4.BIN: coco_hardware.h Console.h crt0.o

joystick.dsk: JOY.BIN JOY1.BIN
	decb dskini $@
	decb copy -2b $^ $@,
	decb dir $@,

console.dsk: CONA.BIN CON1.BIN CON2.BIN CON3.BIN CON4.BIN
	decb dskini $@
	decb copy -2b $^ $@,
	decb dir $@,

.PHONY: clean
clean:
	rm -f *.dsk *.BIN
	
	

