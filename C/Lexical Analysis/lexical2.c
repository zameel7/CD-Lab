#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    FILE *input, *output;
    int l=1, t=0,j=0,i,flag;
    char ch,str[20];
    input=fopen("sample.c","r");
    output=fopen("output.txt","w");
    char keyword[30][30]={"int","float","while","if","double"};
    fprintf(output,"Line no\tToken no\t Token\t Lexeme\n");
    while(!feof(input)){
        i=0;
        flag=0;
        ch=fgetc(input);
        if(ch=='+' || ch=='-' ||ch=='*' ||ch=='/'){
            fprintf(output,"\n%7d\t%7d\tOperator\t%7c",l,t,ch);
            t++;
        }
        else if(ch=='<' || ch=='>'){
            fprintf(output,"\n%7d\t%7d\tRelation Operator\t%7c",l,t,ch);
            t++;
        }
        else if(ch=='!' || ch=='@' ||ch=='#' ||ch=='%' || ch=='&' || ch=='(' ||ch==')' ||ch=='?'){
            fprintf(output,"\n%7d\t%7d\tSpecial Symbol\t%7c",l,t,ch);
            t++;
        }
        else if(isdigit(ch)){
            fprintf(output,"\n%7d\t%7d\tDigit\t%7c",l,t,ch);
            t++;
        }
        else if(isalpha(ch)){
            str[i]=ch;
            i++;
            ch=fgetc(input);
            while(isalnum(ch) && ch!=' '){
            str[i]=ch;
            i++;
            ch=fgetc(input);
            }
            str[i]='\0';
            for(j=0;j<30;j++){
                if(strcmp(str,keyword[j])==0){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                fprintf(output,"\n%7d\t%7d\tKeyword\t%7s",l,t,str);
                t++;
            }
            else{
                fprintf(output,"\n%7d\t%7d\tIdentifier\t%7s",l,t,str);
                t++;
            }

        }
        else if(ch=='\0'){
            l++;
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}