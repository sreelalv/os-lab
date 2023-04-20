CC=gcc
CCFLAGS=-Wall

output: main.o srtf.o 
	gcc -o $@ $?

%.o : %.c %h
	$(CC) $(CCFLAGS) -c -o $@ $?

clean:
	rm -rf *.o output
