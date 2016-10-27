CC:=gcc
CFLAGS:=-Wall -ansi -pedantic -O2

ep4: tabelaSimbolo.o tabelaSimbolo_VD.o tabelaSimbolo_VO.o 
	tabelaSimbolo_LD.o tabelaSimbolo_LO.o tabelaSimbolo_AB.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c %.h
	$(CC) $(CFLAGS)	-c -o $@ $<

clean:
	rm -rf *.o