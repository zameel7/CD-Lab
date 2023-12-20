#include<stdio.h>
#include<string.h>

char result[20][20],states[20][20];

void display(int n, char states[3]){
	int k=0;
	printf("\n\n\n Epsilon closure of %s = { ",states);
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
    char state1[3],input[3],state2[3], state[3];
    printf("\n Enter the no of states: ");
    scanf("%d",&n);
    printf("\n Enter the states: \n");
    for(k=0;k<n;k++){
        printf("%d: ", k+1);
		scanf("%s",states[k]);
	}
	
	for( k=0;k<n;k++){
		i=0;
		strcpy(state,states[k]);
		strcpy(result[i++], state);
		while(fscanf(INPUT,"%s%s%s",state1,input,state2) != EOF){
			
            printf("\n1: %s, 2: %s, 3: %s", state1, input, state2);

			if( strcmp(state,state1) == 0 ){
				if( strcmp(input,"e") == 0) {
                    printf("\n %s is e of %s", state2, state);
					if(strcmp(state2, states[k]) != 0) strcpy(result[i++], state2);
					strcpy(state, state2);
				}
			}

		}
		display(i, states[k]);
		rewind(INPUT);
	}
  
    return 0;
}