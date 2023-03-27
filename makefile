# makefile for token
# the filename must be either Makefile or makefile

command: main.o token.o command.o
	gcc main.o token.o command.o -o command

main.o: main.c token.h
	gcc -c main.c

token.o: token.c token.h
	gcc -c token.c
	
command.o: command.c command.h
	gcc -c command.c

clean: 
	rm *.o
