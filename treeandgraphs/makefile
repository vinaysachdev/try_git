# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-Wall

all: tree

tree: main.o tree.o
			${CC} main.o tree.o -o tree

main.o: main.cc 
		${CC} ${CFLAGS} -std=c++11 -c main.cc

tree.o: tree.cc
			${CC} ${CFLAGS} -std=c++11 -c tree.cc

clean:
		rm -f *.o tree
