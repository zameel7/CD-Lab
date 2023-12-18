#include <stdio.h>  // Include the standard input/output library
#include <ctype.h>  // Include the library for character handling functions
#include <stdlib.h> // Include the standard library
#include <string.h> // Include the string handling library
#include <unistd.h> // Include the library for POSIX operating system API

int main()
{                                                                                         // Start of the main function
    char keywords[32][10];                                                                // Declare a 2D array for storing keywords
    char fileread[100];                                                                   // Declare an array for reading from a file
    char identifiers[20][10], constants[20][10], punctuators[20][1], keywordused[20][10]; // Declare arrays for identifiers, constants, punctuators, and used keywords
    int punctuatorCount = 0, keywordCount = 0, identifierCount = 0;                       // Declare and initialize counters for punctuators, keywords, and identifiers
    FILE *keywordFile, *sampleFile;                                                       // Declare file pointers for the keyword file and the sample file
    keywordFile = fopen("keywords.txt", "r");                                             // Open the keyword file in read mode

    int i = 0;                                                 // Declare and initialize a counter for the while loop
    printf("Reading keywords:\n");                             // Print a message indicating the start of keyword reading
    while (fscanf(keywordFile, "%s", &keywords[i++][10]) == 1) // Read keywords from the file one by one until EOF
    {
        printf("-"); // Print a dash for each keyword read
    }
    printf("-> Keywords read\n");                              // Print a message indicating the end of keyword reading
    while (fscanf(keywordFile, "%s", &keywords[i++][10]) == 1) // Read keywords from the keyword file until EOF
    {
        printf("-"); // Print a dash for each keyword read
    }
    printf("-> Keywords read\n"); // Print a message indicating the end of keyword reading

    fclose(keywordFile); // Close the keyword file

    sampleFile = fopen("sample.c", "r");              // Open the sample file in read mode
    int comment = 0;                                  // Declare and initialize a variable to track comments
    while (fscanf(sampleFile, "%s", fileread) != EOF) // Read from the sample file until EOF
    {
        char *pch;                    // Declare a pointer to char for tokenizing the read string
        int iskeyword = 0, punct = 0; // Declare and initialize variables to track if the read string is a keyword or a punctuation

        for (i = 0; i < strlen(fileread); i++)
        {                              // Loop through each character of the read string
            char letter = fileread[i]; // Store the current character in a variable
            if (letter == '"')         // If the current character is a double quote
            {
                comment = (comment - 1) * -1; // Toggle the comment variable
            }

            if (ispunct(letter))
            {                   // If the current character is a punctuation
                int unique = 1; // Declare and initialize a variable to track if the punctuation is unique
                punct = 1;      // Set the punctuation variable to 1
                for (int j = 0; j < 20; j++)
                { // Loop through the array of punctuations
                    if (punctuators[j][0] == letter)
                    {               // If the current punctuation is already in the array
                        unique = 0; // Set the unique variable to 0
                        break;      // Break the loop
                    }
                }
                if (unique)
                {                                               // If the punctuation is unique
                    punctuators[punctuatorCount++][0] = letter; // Add it to the array of punctuations
                }
            }
        }

        if (punct == 1 || comment == 1)
        {             // If the read string is a punctuation or a comment
            continue; // Skip the current iteration
        }

        pch = strtok(fileread, " ,;#%{}()"); // Tokenize the read string
        if (pch != NULL)
        { // If the token is not NULL
            for (i = 0; i < 32; i++)
            { // Loop through the array of keywords
                if (strcmp(pch, keywords[i]) == 0)
                {                                                               // If the token is a keyword
                    strncpy(&keywordused[keywordCount++][10], keywords[i], 10); // Add it to the array of used keywords
                    iskeyword = 1;                                              // Set the keyword variable to 1
                    break;                                                      // Break the loop
                }
            }
        }
        if (!iskeyword)
        {                                                          // If the token is not a keyword
            strncpy(&identifiers[identifierCount++][10], pch, 10); // Add it to the array of identifiers
        }
    }

    printf("\n\nPunctuators: "); // Print a message indicating the start of punctuator printing
    for (i = 0; i < punctuatorCount; i++)
    {                                     // Loop through the array of punctuations
        printf("%c ", punctuators[i][0]); // Print each punctuation
    }
    printf("\n"); // Print a newline

    printf("\n\nKeywords: "); // Print a message indicating the start of keyword printing
    for (i = 0; i < keywordCount + 1; i++)
    {                                  // Loop through the array of used keywords
        printf("%s ", keywordused[i]); // Print each keyword
    }
    printf("\n"); // Print a newline

    printf("\nIdentifiers: "); // Print a message indicating the start of identifier printing
    for (i = 0; i < identifierCount + 1; i++)
    {                                  // Loop through the array of identifiers
        printf("%s ", identifiers[i]); // Print each identifier
    }
    printf("\n"); // Print a newline

    fclose(sampleFile); // Close the sample file
    return 0;           // Return 0 indicating successful execution
}