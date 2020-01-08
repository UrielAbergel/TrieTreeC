#ifndef _TRIE_
#define _TRIE_
#define Letters 26



typedef struct node
{
    char letter ;
    struct node* childs[Letters];
    long unsigned int count ;

}node;



void insert(node* root , char* newLetter);

int takeLetterFromIndex(char*);

node* newNode();




#endif 