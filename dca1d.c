#include <stdio.h>

#include "dca1d.h"

int main (){
unsigned char arr[50]; //size is just for this project, might need to be bigger in future, or use malloc
init1DCA(25,arr);
for(int i = 0; i<25; i++){
	if(i%2==0)
		set1DCACell(arr,i,'2');
	else 
		set1DCACell(arr,i,'1');
}
display1DCA(arr,25);
	
	
	return 0;
}

void init1DCA(int numCells, unsigned char * a){//makes all cells '0' up until numCells
	for(int i = 0; i<numCells;i++){
		a[i] = '0';
	}
}
void set1DCACell(unsigned char * a, int index, unsigned char val){//sets cell of an index to a value 
	if(index < 0)return;
	a[index] = val;
}

void display1DCA(unsigned char * a, int num){//prints num values in the array 
	for(int i = 0; i<num;i++){
		printf("%c ", a[i]);
	}
	printf("\n");
}