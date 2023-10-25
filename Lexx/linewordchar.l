%{
    #include<stdio.h>
    int words = 0;
    int characters = 0;
    int lines = 0;
%}


%%
[^\t\n ]+ {words++; characters+=yyleng;}
[\n] {lines++; characters+=yyleng;}
%%

int yywrap(void){}
  
int main()
{   
    printf("Enter a string: ");
    yylex();
    printf("\nWords: %d\nCharacters: %d\nLines: %d\n", words, characters-lines, lines);
}