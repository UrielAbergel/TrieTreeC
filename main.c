#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#define WORD 256
#define LINE 256
int main(int argc, char const *argv[])
{
    char word[WORD];
    char buffer[LINE];
    char command;
    int count = 0;
    int buffe_len = 0 ;
    node* root = newNode();
    while(fgets(buffer, LINE, stdin))
        {
            count = 0 ;
            buffe_len = strlen(buffer);
            for (size_t i = 0; i < buffe_len ; i++)
            {
                if(buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\t' && buffer[i] != '\n'  && buffer[i] >= 97 && buffer[i] <= 122)
                {
                word[count] = buffer[i];
                count++;
                }
                else if(buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\t' && buffer[i] != '\n')
                {
                    insert(root , word);
                    count = 0 ;
                }
            }
        }


    command = *argv[1];
    totalPrint(command,root,"",0);
    FreeTheTree(root);
    return 0;

}
