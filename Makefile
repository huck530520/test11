all:
	gcc -o test test.c
	gcc -o feature-1 feature-1.c
	gcc -o a dira/test.c
	gcc -o b dirb/test.c
	gcc -o c dirc/test.c
