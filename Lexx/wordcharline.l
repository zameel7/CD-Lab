%{
    #include<stdio.h>
    int words=0;
    int line=0;
    int count=0;
    int space=0;
%}

%%
[\n] {line++;}
[ \t] {space++;}
[^\t\n ]+ { words++;count+=yyleng;}
%%

int main(){
    printf("Enter a sentence: ");
    yylex();
    printf("No. of words: %d",words++);
    printf("\nNo. of character: %d",count);
    printf("\nNo. of lines: %d",line++);
    printf("\nNo. of space: %d",space++);
    return 0;
}

int yywrap(){return 1;}
