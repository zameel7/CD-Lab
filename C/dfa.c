#include<stdio.h>
#include<string.h>

int main() {
    char string[20];
    int n;

    printf("Enter the string to be checked: ");
    gets(string);


    n = strlen(string);
    for(int i=0; i<n; i++) {
        if(string[i] != '1' && string[i] != '0') {
            printf("Invalid string!");
            return 1;
        }
    }

    if (string[n-2] == '1' && string[n-1] == '0')
    {
        printf("\nString is valid!\n");
    } else {
        printf("\nString is invalid!\n");
    }
    return 0;
}