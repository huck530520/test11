CC:=gcc

all: test

test: test.o

clean:
	rm -f test.o test
