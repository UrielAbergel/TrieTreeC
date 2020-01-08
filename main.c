#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.c"
#include "trie.h"

int main(int argc, char const *argv[])
{
    node* root = newNode();
    char* c = "aladin";
    char* t = "aladin";
    char* e = "alad";
    char* r = "ala";
    char* w = "bla";
    char* q = "blab";
    char* qq = "blag";
    char DDD[100000];
    insert(root,w);
    insert(root,t);
    insert(root ,c);
    insert(root,q);
    insert(root,e);
    insert(root,r);
    insert(root,qq);
    //printR(root,DDD,0);
    char k = 'r';
    totalPrint(k,root,DDD,0);
    FreeTheTree(root);
    return 0;

}
