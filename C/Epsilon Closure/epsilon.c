#include<stdio.h>
#include<string.h>

char result[20][20],state[3],states[20][20];

void add_state(char a[3],int i){
	strcpy(result[i],a);
}

void display(int n){
	int k=0;
	printf("\n\n\n Epsilon closure of %s = { ",state);
	while(k < n){
		printf(" %s",result[k]);
		k++;
	}
	printf(" } \n\n\n");
}

int main(){
    FILE *INPUT;
    INPUT=fopen("input.txt","r");
    int end,i=0,n,k=0;
    char state1[3],input[3],state2[3];
    printf("\n Enter the no of states: ");
    scanf("%d",&n);
    printf("\n Enter the states: \n");
    for(k=0;k<3;k++){
        printf("%d: ", k+1);
		scanf("%s",states[k]);
	}
	
	for( k=0;k<n;k++){
		i=0;
		strcpy(state,states[k]);
		add_state(state,i++);
		while(1){
			end = fscanf(INPUT,"%s%s%s",state1,input,state2);
			if (end == EOF ){
				break;
			}
            printf("\n1: %s, 2: %s, 3: %s", state1, input, state2);

			if( strcmp(state,state1) == 0 ){
				if( strcmp(input,"e") == 0 ) {
                    printf("\n %s is e of %s", state2, state);
					add_state(state2,i++);
					strcpy(state, state2);
				}
			}

		}
		display(i);
		rewind(INPUT);
	}
  
    return 0;
}