all:
	gcc -o test test.c
	gcc -o a dira/test.c
	gcc -o b dirb/test.c
	gcc -o c dirc/test.c
