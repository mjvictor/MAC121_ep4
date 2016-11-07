CC:=gcc
CFLAGS:=-Wall -ansi -pedantic -O2

ep4: tabelaSimbolo.o tabelaSimbolo_VD.o tabelaSimbolo_VO.o buffer.o stable_op.o 
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c %.h
	$(CC) $(CFLAGS)	-c -o $@ $<

clean:
	rm -rf *.o