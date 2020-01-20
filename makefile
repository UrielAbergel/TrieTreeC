
CC=gcc
FLAGS= -Wall -g

all:frequency 

frequency:main.c trie.c 
	$(CC) $(FLAGS) main.c trie.c -o frequency

main.o:main.c trie.h
	$(CC) $(FLAGS) -c main.c	

clean:
	rm -f *.o *.a *.so frequency