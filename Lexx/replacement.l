%{
#include <stdio.h>
int pc=0, sc=0;    
%}

%%
"printf" {fprintf(yyout,"writef");pc++;}
"scanf" {fprintf(yyout,"readf");sc++;}
%%

int main() {
    yyin = fopen("epsilon.c", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    printf("\nNo. of printf: %d\nNo. of scanf: %d\n", pc, sc);
}