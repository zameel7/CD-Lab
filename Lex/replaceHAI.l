%{
#include<stdio.h>    
%}

%%
"HAI" {printf("hai");}
. {printf("%s",yytext);}
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a string (press Enter to replace HAI and show the new string): \n");
    yylex();
    return 0;
}