#include <stdio.h>  // Include the standard input/output library
#include <stdlib.h> // Include the standard library
#include <string.h> // Include the string library

// Global variables
int i = 1, j = 0, tmpch = 90; // i, j, no are counters, tmpch is a temporary character
char str[100], left[15], right[15]; // str is the input string, left and right are substrings

// Function prototypes
void findopr(); // Function to find operators in the string
void explore(); // Function to explore the string and generate intermediate code
void fleft(int); // Function to find the left part of an expression
void fright(int); // Function to find the right part of an expression

// Structure to hold the position and operator of an expression
struct exp
{
    int pos; // Position of the operator in the string
    char op; // The operator
} k[15]; // Array of expressions

// Main function
int main()
{
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n"); // Print title
    
    printf("Enter the Expression :"); // Prompt for input
    scanf("%s", str); // Read the input string

    printf("The intermediate code:\n"); // Print title for output
    findopr(); // Find the operators in the string
    explore(); // Generate the intermediate code
}

// Function to loop through the string and find a specific operator
void oprloop(char opr)
{
    for (i = 0; str[i] != '\0'; i++) // Loop through the string
        if (str[i] == opr) // If the current character is the operator
        {
            k[j].pos = i; // Store the position
            k[j++].op = opr; // Store the operator and increment the counter
        }
}

// Function to find all operators in the string
void findopr()
{
    oprloop(':'); // Find :
    oprloop('/'); // Find /
    oprloop('*'); // Find *
    oprloop('+'); // Find +
    oprloop('-'); // Find - 
}

// Function to generate the intermediate code
void explore()
{
    i = 1;
    while (k[i].op != '\0') // Loop through the expressions
    {
        fleft(k[i].pos); // Find the left part of the expression
        fright(k[i].pos); // Find the right part of the expression

        str[k[i].pos] = tmpch--; // Replace the operator with a temporary character

        printf("\t%c := %s%c%s\t\t", str[k[i].pos], left, k[i].op, right); // Print the intermediate code
        printf("\n");

        i++; // Increment the counter
    }
    fright(-1);

    fleft(strlen(str));
    printf("\t%s := %s\n", right, left); // Print the final result
    getchar();
    exit(0);
}

// Function to find the left part of an expression
void fleft(int x)
{
    int w = 0; // Initialize counters
    x--; // Decrement the position

    // Loop through the string backwards until an operator or the start of the string is found
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' && str[x] != '\0' && str[x] != '-' && str[x] != '/' && str[x] != ':')
    {
        if (str[x] != '$') // If the current character is not $
        {
            left[w++] = str[x]; // Add the character to the left string and increment the counter
            left[w] = '\0'; // End the string
            str[x] = '$'; // Replace the character in the string with $
            return;
        }
        x--; // Decrement the position
    }
}

// Function to find the right part of an expression
void fright(int x)
{
    int w = 0; // Initialize counters
    x++; // Increment the position

    // Loop through the string forwards until an operator or the end of the string is found
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' && str[x] != '\0' && str[x] != '-' && str[x] != '/' && str[x] != ':')
    {
        if (str[x] != '$') // If the current character is not $
        {
            right[w++] = str[x]; // Add the character to the right string and increment the counter
            right[w] = '\0'; // End the string
            str[x] = '$'; // Replace the character in the string with $
            return;
        }
        x++; // Increment the position
    }
}