exec:

compile: \
hello.c 
	gcc hello.c -o hello

hello: hello.c
	gcc hello.c -o hello
