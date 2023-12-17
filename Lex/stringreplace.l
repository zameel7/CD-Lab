%{
    #include<stdio.h>
    int pc=0,sc=0;
%}

%%
"printf" {fprintf(yyout,"writef");pc++;}
"scanf" {fprintf(yyout,"readf");sc++;}
%%

int main(){
    yyin = fopen("inputforstringreplace.txt","r");
    yyout = fopen("outputfile.txt","w");
    yylex();
    printf("\nNo. of printf statement: %d",pc);
    printf("\nNo. of scanf statement:  %d\n",sc);
    return 0;
}

int yywrap(){return 1;}