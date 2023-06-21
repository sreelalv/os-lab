CC=gcc
CCFLAGS=-Wall

output: 2.o helper.o 
	gcc -o $@ $?

%.o : %.c %h
	$(CC) $(CCFLAGS) -c -o $@ $?

clean:
	rm -rf *.o output
