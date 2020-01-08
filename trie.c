#include <stdio.h>
#include "trie.h"
#include <string.h>

void insert(node *root, char *newLetter)
{    
    node *capish = root;

}

// int getLetterFromIndex(char *Word, char c)
// {
//     int len = strlen(Word);
//     for (size_t i = 0; i < len; i++)
//     {
//         if (*(Word + i) == c)
//             return i;
//     }
//     return -1;
// }

node* newNode(){
    node* newNodeP = (node*)malloc(sizeof(node));
    newNodeP->letter = NULL;
    newNodeP->count = 0 ;
    for (size_t i = 0; i < 25; i++)
    {
        newNodeP->childs[i] = NULL;
    }
    return newNodeP;
}