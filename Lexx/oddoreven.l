%{
#include<stdio.h>
int n;    
%}

%%
[0-9]+ {n=atoi(yytext); n%2==0 ? printf("\n%d is even", n) : printf("\n%d is odd", n);}
%%

int main() {
    printf("Enter a number: ");
    yylex();
    return 0;
}