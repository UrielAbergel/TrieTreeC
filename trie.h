#ifndef _TRIE_
#define _TRIE_
#define Letters 26
#include <stdbool.h>
#include <stdio.h>


typedef struct node
{
    bool flag;
    bool flag2;
    struct node* childs[Letters];
    long unsigned int count ;

}node;


void insert(node* root , char* newLetter);

void print(node *root, char * str, int index);

void printR(node *root, char * str, int index);

int StoptheRec(node *current);

node* newNode();

void FreeTheTree(node* );

void resetWord(char *word);


#endif 