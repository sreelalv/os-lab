CC=gcc 
CCFLAGS=-Wall

output: fcfs.o sjfs.o main.o
	gcc -o $@ $?

%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $?

clean:
	rm -rf *.o output
