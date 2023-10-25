%{
 #include<stdio.h>
 int valid=1;
%}

%token letter digit

%%
start :letter s
s : letter s | digit s | ;
%%

int yyerror() { 
 printf("\nNot valid identifier\n");
 valid = 0;
 return 0;
}

int main() {
 printf("\n Enter a name to be tested for identifier: ");
 yyparse();
 if(valid) {
  printf("\nIt is valid identifier!\n"); 
 }
}
