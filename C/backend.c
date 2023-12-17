#include <stdio.h>  // Include the standard input/output library
#include <string.h> // Include the string library

int main() // The main function where the program starts
{
    char icode[10][30], str[20], opr[10] = ""; // Declare character arrays
    int i = 0; // Declare an integer i and initialize it to 0

    // Prompt the user to enter a set of intermediate code
    printf("\nEnter the set of intermediate code (terminated by exit):\n");

    // Loop to read user input until "exit" is entered
    do
    {
        scanf("%s", icode[i]); // Read a string from the user and store it in icode[i]
    } while (strcmp(icode[i++], "exit") != 0); // Continue looping until the user enters "exit"

    printf("\nCorresponding target code generation: "); // Print a message to the console
    i = 0; // Reset i to 0

    // Loop to process the intermediate code
    do
    {
        strcpy(str, icode[i]); // Copy the string from icode[i] to str

        // Switch statement to determine the operation based on the 4th character of str
        switch (str[3])
        {
        case '+':
            strcpy(opr, "ADD"); // If the operator is '+', set opr to "ADD"
            break;
        case '-':
            strcpy(opr, "SUB"); // If the operator is '-', set opr to "SUB"
            break;
        case '*':
            strcpy(opr, "MUL"); // If the operator is '*', set opr to "MUL"
            break;
        case '/':
            strcpy(opr, "DIV"); // If the operator is '/', set opr to "DIV"
            break;
        default:
            // If the operator is not one of the above, print an error message and skip to the next iteration
            printf("\nInvalid operator in icode[%d]: %s", i, icode[i]);
            continue;
        }

        // Print the target code to the console
        printf("\n\tMov %c,R%d", str[2], i);
        printf("\n\t%s%c,R%d", opr, str[4], i);
        printf("\n\tMov R%d,%c", i, str[0]);
    } while (strcmp(icode[++i], "exit") != 0); // Continue looping until "exit" is encountered

    printf("\n"); // Print a newline character to the console
    return 0; // Return 0 to indicate that the program has finished successfully
}

// Example input for this
// a = b + c
// b = a - c
// c = a * b
// exit