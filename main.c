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
    int MAXSIZE = 256;
    char* word = (char*)malloc(sizeof(char)*MAXSIZE);
    char * buffer = NULL;
    int countToMax = 0;
    int lookForEnd = 0;
    node *root = newNode();
    char CurrentChar = getchar();
    while ((CurrentChar==EOF&&lookForEnd!=1)||CurrentChar!=EOF)
    {

        if(CurrentChar >= A && CurrentChar <= Z){
            CurrentChar = CurrentChar+32;
        }
        if (CurrentChar != ' ' && CurrentChar != '\0' && CurrentChar != '\t' && CurrentChar != '\n' && CurrentChar >= a && CurrentChar <= z)
        {
            if(countToMax==MAXSIZE) {
                buffer = (char *) realloc(word, (MAXSIZE * 2) * sizeof(char));
                MAXSIZE = MAXSIZE * 2;
                if (buffer == NULL && word != NULL) {
                    free(word);
                    return -1;
                }
                word = (char*)calloc(MAXSIZE, sizeof(char));
                strcpy(word,buffer);
                free(buffer);
            }

            word[countToMax] = CurrentChar;
            countToMax++;

        }

        else if ((CurrentChar == ' ' || CurrentChar == '\0' || CurrentChar == '\t' || CurrentChar == '\n') || CurrentChar == EOF)
        {

            if (word[0] != '\n')
            {
                if (word[0] != '\0')
                {
                    word[countToMax] = '\0';
                    insert(root, word);
                    resetWord(word);
                    countToMax = 0;
                }
            }
        }
        if(CurrentChar == EOF) lookForEnd = 1;

        CurrentChar = getchar();
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
