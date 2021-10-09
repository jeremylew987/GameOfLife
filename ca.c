#include <stdio.h>
#include <stdlib.h>
#include "ca.h"




void init1DCA(struct ca_data * a, int numCells){//makes all cells '0' up until numCells
	for(int i = 0; i<numCells;i++){
		a->arr[i] = '0';
	}
}
int set1DCACell(struct ca_data* a, unsigned int index, unsigned char value){//sets cell of an index to a value 
	if(index < 0 || index >= a->numCells)return 0;
	a->arr[index] = value;
	return 1;
}

void display1DCA(struct ca_data * a){//prints num values in the array 
	for(int i = 0; i<a->numCells;i++){
		printf("%c ", a->arr[i]);
	}
	printf("\n");
}
struct ca_data *create1DCA( int numCells, unsigned char value){
	struct ca_data * a = malloc(sizeof(struct ca_data));
	a->numCells= numCells;
	a->arr = malloc(sizeof(unsigned char)*numCells);
	for(int i = 0; i<numCells;i++){
		a->arr[i] = value;
	}
	return a;
}
void stepCA( struct ca_data * a, unsigned char (*rule)(struct ca_data *, int) , int flag){

	
	struct ca_data * b = create1DCA((a->numCells)+2, '0');
	for(int i = 0; i<(a->numCells);i++){
		b->arr[i+1] = a->arr[i];
	}
	if(flag){
		b->arr[0] = a->arr[(a->numCells)-1];
		b->arr[(b->numCells)-1] = a->arr[0];
	}
	for(int i = 1;i<(a->numCells+1);i++){
		a->arr[i-1]= rule(b,i);
	}
	free(b->arr);
	free(b);
	
	
	
	
	
	
	
	
	
}


