#include <stdio.h>
#include "trie.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//insert to the tree
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
// add new node with nulls
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

//print none reverse
void print(node *root, char *str, int index)
{
    if (!StoptheRec(root))
    {
        str[index] = '\0';
        printf("%s %ld \n", str, root->count);
        return;
    }
    if (root->count > 0)
    {
        str[index] = '\0';
        printf("%s %ld \n", str, root->count);
    }
    for (int i = 0; i < Letters; i++)
    {
        if (root->childs[i])
        {
            str[index] = (char)(97 + i);
            print(root->childs[i], str, index + 1);
        }
    }
}
//print reverse
void printR(node *root, char *str, int index)
{

    if (!StoptheRec(root))
    {
        str[index] = '\0';
        printf("%s %ld \n", str, root->count);
        return;
    }

    for (int i = Letters - 1; i >= 0; i--)
    {
        if (root->childs[i])
        {
            str[index] = (char)(97 + i);
            printR(root->childs[i], str, index + 1);
        }
    }
    if (root->count > 0)
    {
        str[index] = '\0';
        if(str[0] == '\0') {return;}

            printf("%s %ld \n", str, root->count);

    }
}
 // stop the rec if you got there
int StoptheRec(node *current)
{
    int flag = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if (current->childs[i])
            flag = 1;
    }
    return flag;
}
//free the bytes in the tree
void FreeTheTree(node *root)
{
    node *pointer = root;
    for (size_t i = 0; i < Letters; i++)
    {
        if (pointer->childs[i] != NULL)
        {
            FreeTheTree((pointer->childs[i]));
        }
    }
    free(pointer);
}
//reset word with / 0 
void resetWord(char *word)
{
    for (int i = 0; i < 256; ++i)
    {
        word[i] = '\n';
    }
}
