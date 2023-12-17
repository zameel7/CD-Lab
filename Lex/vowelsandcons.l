%{
    #include<stdio.h>
    int vowel=0;
    int consonant=0;
%}
%%
[aeiouAEIOU] {vowel++;}
[a-zA-Z] {consonant++;}
%%

int main()
{
    printf("Enter a string: ");
    yylex();
    printf("No. of vowels     = %d\n",vowel);
    printf("No. of consonants = %d\n",consonant);
    return 0;
}
    
int yywrap(){return 1;}
