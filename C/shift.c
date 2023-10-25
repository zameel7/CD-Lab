#include<stdio.h>
#include<string.h>
#include<ctype.h>

int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];

void check();
void replaceandprint();

void main()
{
	printf("\nGRAMMAR :\n E->E+E \n E->E*E \n E->E/E \n E->a\n E->b\n");
	puts("Enter input string: ");
	gets(a);
	c=strlen(a);
	strcpy(act,"SHIFT");
	puts("Stack \t Input \t\t Action");
	for(k=0,i=0; j<c; k++,i++,j++) {
		if(a[j]=='i' && a[j+1]=='d') {
			stk[i]=a[j];
			stk[i+1]=a[j+1];
			stk[i+2]='\0';
			a[j]=' ';
			a[j+1]=' ';
			printf("\n$%s\t%s$\t%sid",stk,a,act);
		}
		else {
			stk[i]=a[j];
			stk[i+1]='\0';
			a[j]=' ';
			printf("\n$%s\t%s$\t%s",stk,a,act);
		}
		check();
	}
	printf("\n\n");

	if(strcmp(stk,"E")==0) {
		printf("The input is valid and accepted\n\n");
	} else
		printf("Invalid Input\n\n");

}
void check() {
	strcpy(ac,"REDUCE TO E");
	for(z=0; z<c; z++) {
		if(stk[z]=='a' || stk[z]=='b') {
			replaceandprint();
			i = i+2;
		}
	}
	for(z=0; z<c; z++) {
		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E') {
			replaceandprint();
		}
	}
	for(z=0; z<c; z++) {
		if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E') {
			replaceandprint();
		}
	}		
	for(z=0; z<c; z++) {
		if(stk[z]=='E' && stk[z+1]=='/' && stk[z+2]=='E') {
			replaceandprint();
		}
	}
	for(z=0; z<c; z++) {
		if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
		{
			replaceandprint();
		}
	}
}

void replaceandprint(){
	stk[z]='E';
	stk[z+1]='\0';
	stk[z+2]='\0';
	printf("\n$%s\t%s$\t%s",stk,a,ac);
	i=i-2; 
}

