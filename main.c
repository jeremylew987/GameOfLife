#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "ca.h"


unsigned char aRule( struct ca_data *,int index);


int main(){
	int input = 0;
	while (!(input > 9 && input < 101)){
		printf("Please enter the number of cells: \n");
		scanf("%d",&input);
		
        
		
		if(!(input > 9 && input < 101))
			printf("Not valid input, Enter a number 10 to 100 \n");
	}
	
	int numStates = 0;
	while (!(numStates > 1)){
		printf("Please enter the number of states: \n");
		scanf("%d",&numStates);
		
		
		if(!(numStates > 1))
			printf("Not valid input, Enter a number 2 to some postive number \n");
	}
	
	char *wrap  = malloc(sizeof(char)*7);
	gets(wrap);
	while( !(strcmp("nowrap",wrap) == 0) && !(strcmp("wrap",wrap) == 0)){
		printf("Please enter whether you would like wrap or nowrap: \n");
		gets(wrap);
		if(!(strcmp("nowrap",wrap) == 0) && !(strcmp("wrap",wrap) == 0))
			printf("Not valid input, Enter wrap or nowrap \n");
	}
	int wrapVal;
	if(strcmp("wrap", wrap) == 0)
		wrapVal = 1;
	else 
		wrapVal = 0;
	free(wrap);
	int init = -10;
	while(!(init > -1 && init < numStates || (init == -1))){
		printf("Please enter the initial states: \n");
		scanf("%d",&init);
		
		
		if(!(init > -1 && init < numStates || init == -1))
			printf("Not valid input, 0-%d or -1 for random values \n",numStates-1);
	}
	int numSteps = 0;
	while(!(numSteps>0)){
		printf("Please enter the number of steps: \n");
		scanf("%d",&numSteps);
		
		if(!(numSteps>0)){
			printf("Not valid input, enter a postive value greater than 0 \n");
		}
		
	}
	struct ca_data * c;
	if(init == -1){
		c = create1DCA(input,'0');
		srand(time(0));
		for(int i = 0; i<input;i++){
		unsigned char temp = (rand()%numStates)+48;
		c->arr[i] = temp;
			
		}
	}
	else{
		
		unsigned char temp = 48+init;
		c = create1DCA(input, temp);
	}
	display1DCA(c);
	for(int i = 0; i<numSteps;i++){
		stepCA( c, aRule, wrapVal);
		display1DCA(c);
	}
		
	
	
	
	
	
	
	
	
	return 0;
}


unsigned char aRule( struct ca_data * a, int index){
	if( a->arr[index] != '1' && a->arr[index] != '0'){
		printf("This rule only works with two states\n");
		exit(0);
	}
		
	int val = 1;
	if(a->arr[index] == '1' && a->arr[index-1] == '1' && a->arr[index+1] == '1')
		val = 0;
	else if(a->arr[index] == '0' && a->arr[index+1] == '0')
		val = 0;
	
	if(val)
		return '1';
	else return '0';

	
	
	
	
}