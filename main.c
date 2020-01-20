#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#define A 65
#define Z 90
#define a 97
#define z 122
int main(int argc, char const *argv[])
{
    // make a start word in size 256 
    int MAXSIZE = 256;
    //do malloc for the word
    char* word = (char*)malloc(sizeof(char)*MAXSIZE);
    char * buffer = NULL;
    int countToMax = 0;
    int lookForEnd = 0;
    node *root = newNode();
    //get the current char from the buffer
    char CurrentChar = getchar();
    //while you didnt end the buffer
    while ((CurrentChar==EOF&&lookForEnd!=1)||CurrentChar!=EOF)
    {
        //if it is a uppert word transfor to a little letter
        if(CurrentChar >= A && CurrentChar <= Z){
            CurrentChar = CurrentChar+32;
        }
        // if it is a end of word
        if (CurrentChar != ' ' && CurrentChar != '\0' && CurrentChar != '\t' && CurrentChar != '\n' && CurrentChar >= a && CurrentChar <= z)
        {
            //if you bigger then 256 do *2 for size
            if(countToMax==MAXSIZE) {
                buffer = (char *) realloc(word, (MAXSIZE * 2) * sizeof(char));
                MAXSIZE = MAXSIZE * 2;
                //if the buffer is null free word
                if (buffer == NULL && word != NULL) {
                    free(word);
                    return -1;
                }
                //do to all word /0
                word = (char*)calloc(MAXSIZE, sizeof(char));
                strcpy(word,buffer);
                free(buffer);
            }
            // add the current 
            word[countToMax] = CurrentChar;
            countToMax++;

        }
	
        //end of the word
        else if ((CurrentChar == ' ' || CurrentChar == '\0' || CurrentChar == '\t' || CurrentChar == '\n') || CurrentChar == EOF)
        {

            if (word[0] != '\n')
            {
                if (word[0] != '\0')
                {
                    //insert then reset with /0
                    word[countToMax] = '\0';
                    insert(root, word);
                    resetWord(word);
                    countToMax = 0;
                }
            }
        }
        //add the last char of the file
        if(CurrentChar == EOF) lookForEnd = 1;

        CurrentChar = getchar();
    }
    //cases or reverse and none reverse
    if (argc == 2 && strcmp(argv[1], "r")==0)
    {
        printR(root, word, 0);
    }
    else
    {
        print(root, word, 0);
    }
    //free the last word 
	free(word);
    //free all the tree
    FreeTheTree(root);
    return 0;
}
