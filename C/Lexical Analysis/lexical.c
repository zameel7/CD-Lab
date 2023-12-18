#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char keywords[32][10];
    char fileread[100];
    char identifiers[20][10], constants[20][10], punctuators[20][1], keywordused[20][10];
    int punctuatorCount=0, keywordCount=0, identifierCount=0;
    FILE *keywordFile, *sampleFile;
    keywordFile = fopen("keywords.txt", "r");

    int i=0;
    printf("Reading keywords:\n");
    // (&keywords[i++][10], 10, keywordFile)
    while(fscanf(keywordFile, "%s", &keywords[i++][10]) == 1)
    {
        printf("-");
    }
    printf("-> Keywords read\n");

    fclose(keywordFile);

    sampleFile = fopen("sample.c", "r");
    int comment = 0;
    while(fscanf(sampleFile, "%s", fileread) != EOF)
    {
        char *pch;
        int iskeyword = 0, punct = 0;

        for (i=0; i < strlen(fileread); i++) {
            char letter = fileread[i];
            if (letter == '"')
            {
                comment = (comment - 1)*-1;
            }
            
            if (ispunct(letter)) {
                int unique = 1;
                punct = 1;
                for (int j=0; j<20; j++) {
                    if (punctuators[j][0] == letter) {
                        unique = 0;
                        break;
                    }
                }
                if (unique) {
                    punctuators[punctuatorCount++][0] = letter;
                }
            }
        }

        if(punct == 1 || comment == 1) {
            continue;
        } 

        pch = strtok(fileread, " ,;#%{}()");
        if (pch != NULL) {
            for (i=0; i<32; i++) {
                if (strcmp(pch, keywords[i]) == 0) {
                    strncpy(&keywordused[keywordCount++][10], keywords[i], 10);
                    iskeyword = 1;
                    break;
                }
            }
        }
        if(!iskeyword) {
            strncpy(&identifiers[identifierCount++][10], pch, 10);
        }
    }
    
    printf("\n\nPunctuators: ");
    for(i=0; i<punctuatorCount; i++) {
        printf("%c ", punctuators[i][0]);
    }
    printf("\n");

    printf("\n\nKeywords: ");
    for(i=0; i<keywordCount+1; i++) {
        printf("%s ", keywordused[i]);
    }
    printf("\n");

    printf("\nIdentifiers: ");
    for(i=0; i<identifierCount+1; i++) {
        printf("%s ", identifiers[i]);
    }
    printf("\n");

    fclose(sampleFile);
    return 0;
}