
CC=gcc
FLAGS= -Wall -g

all:tries mains

tries:trie.a

trie.a:trie.o trie.h
	 ar rcs trie.a trie.o trie.h

trie.o: trie.c trie.h 
	$(CC) -c trie.c

mains:main.o trie.a
	$(CC) $(FLAGS) -o  ‫‪frequency‬‬ main.o trie.a 

main.o:main.c trie.h
	$(CC) -c main.c

.PHONY:clean  all

clean:
	rm -f *.o *.a *.so frequency‬‬