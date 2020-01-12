#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"

#define WORD 256
#define LINE 1024
int main(int argc, char const *argv[])
{
    char word[WORD];
    char buffer[LINE];
    size_t count = 0;
    int buffe_len = 0;
    node *root = newNode();
    //char* line = "aba glida lala";
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        buffer[strlen(buffer)] = ' ';
        count = 0;
        buffe_len = strlen(buffer);
        for (size_t i = 0; i < buffe_len; i++)
        {
            if (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\t' && buffer[i] != '\n' && buffer[i] >= 97 && buffer[i] <= 122)
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
