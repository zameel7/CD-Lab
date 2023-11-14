%{
#include<stdio.h>
int vowel=0;
int con=0;
%}

%%

[aeiouAEIOU] {  
vowel++ ;}
[a-zA-Z] { con++;}
	
%%

int  main()
{
	
	printf("enter your input: ");
	yylex();
	printf("counts of vowels are=%d and consonants=%d" ,vowel,con);
	

}
int yywrap(){
return 1; }
