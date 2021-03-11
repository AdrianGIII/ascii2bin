CCFLAGS=-g -DMAIN
SOURCE=ascii2bin.c


all: ascii2bin

test: 
	cat 54356.txt      | ./ascii2bin 
	cat 138.txt        | ./ascii2bin 
	cat 2863311530.txt | ./ascii2bin 
	cat 4294967295.txt | ./ascii2bin 
	cat error.txt      | ./ascii2bin 


ascii2bin.o: ascii2bin.c 
	$(CC) -o ascii2bin.o -c $(CCFLAGS) ascii2bin.c

ascii2bin.i: ascii2bin.c 
	$(CC) -o ascii2bin.i -E ascii2bin.c

ascii2bin.s: ascii2bin.c 
	$(CC) -o ascii2bin.s -S ascii2bin.c


clean:
	rm -f ints2bytes *.bytes
	rm -f ascii2bin ascii2bin.o ascii2bin.i ascii2bin.s 
	rm -f *~ \#*
