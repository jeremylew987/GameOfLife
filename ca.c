#include <stdio.h>
#include <stdlib.h>
#include "ca.h"




void init1DCA(struct ca_data * a, int numCells){//makes all cells '0' up until numCells
	for(int i = 0; i<numCells;i++){
		a->cadata[i] = '0';
	}
}
int set1DCACell(struct ca_data* a, unsigned int index, unsigned char value){//sets cell of an index to a value 
	if(index < 0 || index >= a->width)return 0;
	a->cadata[index] = value;
	return 1;
}

int set2DCACell( struct ca_data *ca, unsigned int x, unsigned int y, unsigned char state){//TODO
if(x < 0 || x >= ca->width)return 0;
if(y < 0 || y >= ca->height)return 0;
int index = y*ca->width+x;
ca->cadata[index] = state;
	return 1;
	
}

void displayCA(struct ca_data * a){//prints num values in the array 
	for(int i = 0; i<(a->width)*(a->height);i++){
		printf("%c ", a->cadata[i]);
		  if ((i + 1) % a->width == 0)
        {
            printf("\n");
        }
	}
}
struct ca_data *create1DCA( int numCells, unsigned char value){
	struct ca_data * a = malloc(sizeof(struct ca_data));
	a->width= numCells;
	a->height = 1;
	a->dimension = 1;
	a->wrap = '0';
	a->cadata = malloc(sizeof(unsigned char)*numCells);
	for(int i = 0; i<numCells;i++){
		a->cadata[i] = value;
	}
	return a;
}

struct ca_data *create2DCA( int w, int h, unsigned char qstate){
	struct ca_data * a = malloc(sizeof(struct ca_data));
	a->width= w;
	a->height = h;
	a->dimension = 2;
	a->wrap = '0';
	a->cadata = malloc(sizeof(unsigned char)*w*h);
	for(int i = 0; i<(h*w);i++){
		a->cadata[i] = qstate;
	}
	return a;
	
	
	
}

void stepCA( struct ca_data * a, unsigned char (*rule)(struct ca_data *, int)){

	
	/*struct ca_data * b = create1DCA((a->width)+2, '0');
	for(int i = 0; i<(a->width);i++){
		b->cadata[i+1] = a->cadata[i];
	}
	if(0){//change to wrap
		b->cadata[0] = a->cadata[(a->width)-1];
		b->cadata[(b->width)-1] = a->cadata[0];
	}
	for(int i = 1;i<(a->width+1);i++){
		a->cadata[i-1]= rule(b,i);
	}
	free(b->cadata);
	free(b);
	*/
	struct ca_data * b = create1DCA((a->width), '0');
	for(int i = 0; i<(a->width);i++){
		b->cadata[i] = a->cadata[i];
	}
	for(int i = 0;i<(a->width);i++){
		a->cadata[i]= rule(b,i);
	}
	
	
	
	
	
}
void step2DCA( struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int x, int y)){
	struct ca_data * b = create2DCA((ca->width),ca->height, '0');
	for(int i = 0; i<(ca->width*ca->height);i++){
		b->cadata[i] = ca->cadata[i];
	}
	
	b->wrap = ca->wrap;
	for(int i = 0;i<(ca->width*ca->height);i++){
		ca->cadata[i]= rule(b,i%ca->width,i/ca->height);
	}
	
	
}



