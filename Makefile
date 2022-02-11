CC=gcc
CFLAGS=-I.

hellomake: feature-1.o
	$(CC) -o feature-1 feature-1.o

.PHONY: clean

clean:
	rm -f *.o feature-1
