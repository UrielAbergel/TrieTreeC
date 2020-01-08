#include <stdio.h>
#include "trie.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void insert(node *root, char *newLetter)
{
    node *capish = root;
    int len = strlen(newLetter);

    for (size_t i = 0; i < len; i++)
    {
        if (capish->childs[*(newLetter + i) - 97])
        {
            capish = capish->childs[*(newLetter + i) - 97];
        }
        else
        {
            capish->childs[*(newLetter + i) - 97] = (node *)malloc(sizeof(node));
            capish = capish->childs[*(newLetter + i) - 97];
        }
    }
    capish->count = capish->count + 1;
}

node *newNode()
{
    node *newNodeP = (node *)malloc(sizeof(node));
    newNodeP->count = 0;
    newNodeP->flag = false;
    newNodeP->flag2 = false;
    for (size_t i = 0; i < 25; i++)
    {
        newNodeP->childs[i] = NULL;
    }
    return newNodeP;
}


void totalPrint(char c,node *root, char * str, int index){
    if(c == 'r'){
        printR(root,str,index);
    }
    else{
        print(root,str,index);
    }
}

void print(node *root, char * str, int index) {

    if (!StoptheRec(root)) {
        str[index] = '\0';
        printf("%s apper %ld \n", str, root->count);
        return;
    }
    if (root->count > 0) {
        str[index] = '\0';
        printf("%s apper %ld \n", str, root->count);
    }
    for (int i = 0; i < Letters; i++) {
        if (root->childs[i]) {
            str[index] = (char) (97 + i);
            print(root->childs[i], str, index + 1);
        }
    }
}

    void printR(node *root, char * str, int index)
    {

        if(!StoptheRec(root))
        {
            str[index] = '\0';
            printf("%s apper %ld \n",str,root->count);
            return;
        }
        if(root->count>0)
        {
            str[index] = '\0';
            printf("%s apper %ld \n",str,root->count);
        }
        for (int i = Letters-1; i >= 0 ; i-- ) {
            if(root->childs[i]){
                str[index] = (char)(97+i);
                printR(root->childs[i],str,index+1);
            }
        }
}


int StoptheRec(node *current){
    int flag = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if(current->childs[i]) flag = 1;
    }
    return flag;
}

void FreeTheTree(node* root){
    node* pointer = root;
    for (size_t i = 0; i < Letters; i++)
    {
        if(pointer->childs[i]!=NULL)
        {
            FreeTheTree((pointer->childs[i]));
        }
    }
    free(pointer);
}

