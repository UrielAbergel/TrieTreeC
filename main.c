#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#define A 65
#define Z 90
#define a 97
#define z 122
#define WORD 1024
#define LINE 1000000
int main(int argc, char const *argv[])
{
    char word[WORD];
    char buffer[LINE];
    size_t count = 0;
    int buffe_len = 0;
    node *root = newNode();
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        buffer[strlen(buffer)] = ' ';
        count = 0;
        buffe_len = strlen(buffer);
        for (size_t i = 0; i < buffe_len; i++)
        {
            if(buffer[i] >= A && buffer[i] <= Z){
                buffer[i] = buffer[i]+32;
            }
            if (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\t' && buffer[i] != '\n' && buffer[i] >= a && buffer[i] <= z)
            {
                word[count] = buffer[i];
                count++;
            }
            else if ((buffer[i] == ' ' || buffer[i] == '\0' || buffer[i] == '\t' || buffer[i] == '\n'))
            {
                if (word[0] != '\n')
                {
                    if (word[0] != '\0')
                    {
                        word[count] = '\0';
                        insert(root, word);
                        resetWord(word);
                        count = 0;
                    }
                }
            }
        }
    }
    if (argc == 2 && strcmp(argv[1], "r")==0)
    {
        printR(root, word, 0);
    }
    else
    {
        print(root, word, 0);
    }
    FreeTheTree(root);
    return 0;
}
