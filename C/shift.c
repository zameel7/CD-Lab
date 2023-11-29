#include<stdio.h>
#include<string.h>
#include<ctype.h>

int z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];

void check();
void replaceandprint();

void main()
{
	printf("\nGRAMMAR :\n E->E+E \n E->E*E \n E->E/E \n E->a\n E->b\n");

	puts("Enter input string: ");
	gets(a);

	c=strlen(a);

	puts("Stack \t Input \t\t Action");
	for(i=0, j=0; j<c; i++,j++) {
		stk[i]=a[j];
		stk[i+1]='\0';
		a[j]=' ';
		printf("\n$%s\t%s$\t%s",stk,a,"SHIFT");
		check();
	}
	printf("\n\n");

	if(strcmp(stk,"E")==0) {
		printf("The input is valid and accepted\n\n");
	} else
		printf("Invalid Input\n\n");
}

void check() {
	for(z=0; z<c; z++) {
		if(stk[z]=='a' || stk[z]=='b') {
			replaceandprint();
			i = i+2;
		}
	}
	for(z=0; z<c; z++) {
		if((stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E') ||
		   (stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E') ||
		   (stk[z]=='E' && stk[z+1]=='/' && stk[z+2]=='E') ||
		   (stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')') ) {
			replaceandprint();
		}
	}
}

void replaceandprint(){
	stk[z]='E';
	stk[z+1]='\0';
	stk[z+2]='\0';
	printf("\n$%s\t%s$\t%s",stk,a,"REDUCE TO E");
	i=i-2; 
}