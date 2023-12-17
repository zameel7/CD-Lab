// This is an udayipp code that accepts string with 1 or 0 and ending with '10'.

// #include<stdio.h>
// #include<string.h>

// int main() {
//     char string[20];
//     int n;

//     printf("Enter the string to be checked: ");
//     gets(string);


//     n = strlen(string);
//     for(int i=0; i<n; i++) {
//         if(string[i] != '1' && string[i] != '0') {
//             printf("Invalid string!");
//             return 1;
//         }
//     }

//     if (string[n-2] == '1' && string[n-1] == '0')
//     {
//         printf("\nString is valid!\n");
//     } else {
//         printf("\nString is invalid!\n");
//     }
//     return 0;
// }

// The above code is just a simple DFA that accepts strings ending with 10. It is not how the exact implementation shoud be.
// Correct implementation of DFA is as follows:

// This is a dfa problem that accepts string with 1 or 0 and ending with '11'.

#include<stdio.h>
#include<string.h>  

int main() {
    char string[20];
    int n, state = 0, final_state;

    printf("Enter the string to be checked: ");
    gets(string);

    n = strlen(string);

    for (int i = 0; i < n; i++)
    {
        // The switch case will change based on the DFA diagram.
        // DFA Diagram is uploaded in the DFA Folder.
        switch (string[i])
        {
            case '1':
                if (state == 0)
                {
                    state = 1;
                } else if (state == 1)
                {
                    state = 2;
                }
                break;
            case '0':
                if (state == 0)
                {
                    state = 0;
                } else if (state == 1)
                {
                    state = 0;
                } else if (state == 2)
                {
                    state = 2;
                }
                break;
            
            default:
                printf("Invalid string!");
                return 1;
        }
        if (state == 2 && i == n-1)
        {
            printf("\nString is valid!\n");
            return 0;
        }
    }
    printf("\nString is invalid!\n");
}