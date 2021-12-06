# Pour le moment je compile tout d'un coup comme j'ai encore des tests à faire

#data.o : data.c data.h
#	gcc -c data.c

#queue.o : queue.c queue.h
#	gcc -c queue.c

#stack.o : stack.c stack.h
#	gcc -c stack.c

#save.o : save.c save.h
#	gcc -c save.c

#rand.o : rand.c rand.h
#	gcc -c rand.c -lm

#main.o : main.c queue.h save.h stack.h data.h rand.h
#	gcc -c main.c

#main : main.o queue.o save.o stack.o data.o rand.o
#	gcc main.o queue.o save.o stack.o data.o rand.o -o main

main :  main.c queue.c save.c stack.c data.c rand.c
	gcc main.c queue.c save.c stack.c data.c rand.c -lm -o main
