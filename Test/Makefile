VPATH = /usr/local/coco/include/:/usr/local/coco/lib/gcc/m6809-unknown/4.6.1

PATH=/usr/local/coco/bin:$PATH
CC=/usr/local/coco/bin/m6809-unknown-gcc
CFLAGS=-Wall -Wa,-l,-s -I /usr/local/coco/include -O0
LDFLAGS=-Wall -Wl,-M -Wa,-l,-s -L/usr/local/lib/gcc/m6809-coco-none/4.6.1 -L/usr/local/coco/lib -lRSDOS -O0

%.dsk: %.BIN
	rm -rf $@
	decb dskini $@
	#u="$(echo $^ | awk '{print toupper($0)}')"
	decb copy -2b $^ $@,
	decb dir $@,

%.BIN: %.o
	$(CC) $(LDFLAGS) -o $@ $<

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

%o: %s
	$(CC) $(CFLAGS) -c -o $@ $<

%o: %S
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.a
