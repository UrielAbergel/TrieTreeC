#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.c"
#include "trie.h"
#define WORD 256
#define LINE 1024
int main(int argc, char const *argv[])
{
    char word[WORD];
    char buffer[LINE];
    char command;
    int count = 0;
    int buffe_len = 0 ;
    node* root = newNode();
    for (size_t k = 1; k < LINE; k++)
        {
            count = 0 ;
            fgets(buffer, LINE, stdin);
            buffe_len = strlen(buffer);
            for (size_t i = 0; i < buffe_len ; i++)
            {
                if((buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\t' && buffer[i] != '\n' && buffer[i]) && buffer[i] >= 97 && buffer[i] <= 122)
                {
                word[count] = buffer[i];
                count++;
                }
                else (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\t' && buffer[i] != '\n' && buffer[i]);
                {
                    insert(root , word);
                    count = 0 ;
                }
            }
        }


    char k = *argv[1];
    totalPrint(k,root,"",0);
    FreeTheTree(root);
    return 0;

}
