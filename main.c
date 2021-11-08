#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "ca.h"


unsigned char aRule( struct ca_data *,int index);
unsigned char bRule( struct ca_data *,int x,int y);


int main(int num, char *argv[]){
	if(num != 3){
	printf("Incorrect input arguements");
	exit(1);
	}
	int dem = atoi(argv[1]);
	
	
	char fn[50];
strcpy( fn, argv[2] );

	
	
	
	
	
	FILE *f = fopen(fn,"r");
	
	if(dem == 1){
		printf("Game of life rule only works for 2D arrays");
	exit(1);
	}
	int h;
	fscanf(f,"%d",&h);
	int w;
	fscanf(f,"%d",&w);
	
	struct ca_data * a = create2DCA( w, h, '0'); 
	int cur;
	for(int i =0; i<w*h;i++){
		fscanf(f,"%d",&cur);
		
		unsigned char val= cur+48;
		set2DCACell(a,i%w,i/w,val);
	}
	a->wrap = '1';
	
	char flag[20] = "\n";
	while (strcmp(flag,"\n") == 0){
		displayCA(a);
		step2DCA( a, bRule);
		printf("\n");
		
		fgets(flag, 20, stdin);
	}
	
	
	
	return 0;
}


unsigned char aRule( struct ca_data * a, int index){
	if( a->cadata[index] != '1' && a->cadata[index] != '0'){
		printf("This rule only works with two states\n");
		exit(0);
	}
	if(a->wrap == '0'){
		unsigned char left,right;
		if((index-1 == -1))
			left = '0';
		else  left = a->cadata[index-1];
		if((index + 1 == a->width))
			 right = '0';
		else  right = a->cadata[index+1];
		
		int val = 1;
	if(a->cadata[index] == '1' && left == '1' && right == '1')
		val = 0;
	else if(a->cadata[index] == '0' && right == '0')
		val = 0;
	
	if(val)
		return '1';
	else return '0';
		
		
		
		
	}
	
	int val = 1;
	if(a->cadata[index] == '1' && a->cadata[(index-1+a->width)%a->width] == '1' && a->cadata[(index+1+a->width)%a->width] == '1')
		val = 0;
	else if(a->cadata[index] == '0' && a->cadata[(index+1+a->width)%a->width] == '0')
		val = 0;
	
	if(val)
		return '1';
	else return '0';
}

unsigned char bRule( struct ca_data * a, int x, int y){
	int index = x+y*a->width; 
	if( a->cadata[index] != '1' && a->cadata[index] != '0'){
		printf("This rule only works with two states\n");
		exit(0);
	}
	int val = 0;
	
	unsigned char left,upleft,downleft,up,down,right,upright,downright;
	if(a->wrap == '0'){
		if(x==0)
			left = '0';
		else left = a->cadata[x-1+y*a->width];
		if(x==0||y==0)
			upleft='0';
		else upleft = a->cadata[x-1+(y-1)*a->width];
		if(x==0||y==a->height-1)
			downleft='0';
		else
			downleft = a->cadata[x-1+(y+1)*(a->width)];
		if(y==0)
			up = '0';
		else up = a->cadata[x+(y-1)*(a->width)];
		if(y==a->height-1)
			down = '0';
		else down = a->cadata[x+(y+1)*(a->width)];
		if(x==a->width-1)
			right = '0';
		else right = a->cadata[x+1+y*a->width];
		if(x==a->width-1||y==0)
			upright = '0';
		else upright = a->cadata[x+1+(y-1)*(a->width)];
		if(x==a->width-1||y==a->height-1)
			downright = '0';
		else downright = a->cadata[x+1+(y+1)*(a->width)];
		
		
		//Any live cell with fewer than two live neighbours dies, as if by underpopulation.
		//Any live cell with two or three live neighbours lives on to the next generation.
		//Any live cell with more than three live neighbours dies, as if by overpopulation.
		//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
		int count = 0;
		if(left == '1')count++;
		if(upleft == '1')count++;
		if(downleft == '1')count++;
		if(up == '1')count++;
		if(down == '1')count++;
		if(right == '1')count++;
		if(upright == '1')count++;
		if(downright == '1')count++;
		
		
		if(a->cadata[index] == '1' && (count <2 ||count >3))
			val = 0;
		else if(a->cadata[index] == '1' && (count == 2 || count == 3))
			val = 1;
		else if(a->cadata[index] == '0' && count == 3)
			val = 1;
		
		
		
	}
	else{
		int count = 0;
		if(a->cadata[(x-1+a->width)%a->width + ((y-1+a->height)%a->height)*a->width] == '1')count++;//upleft
		if(a->cadata[(x+a->width)%a->width + ((y-1+a->height)%a->height)*a->width] == '1')count++;//up
		if(a->cadata[(x+1+a->width)%a->width + ((y-1+a->height)%a->height)*a->width] == '1')count++;//upright
		if(a->cadata[(x+1+a->width)%a->width + ((y+a->height)%a->height)*a->width] == '1')count++;//right
		if(a->cadata[(x+1+a->width)%a->width + ((y+1+a->height)%a->height)*a->width] == '1')count++;//downright
		if(a->cadata[(x+a->width)%a->width + ((y+1+a->height)%a->height)*a->width] == '1')count++;//down
		if(a->cadata[(x-1+a->width)%a->width + ((y+1+a->height)%a->height)*a->width] == '1')count++;//downleft
		if(a->cadata[(x-1+a->width)%a->width + ((y+a->height)%a->height)*a->width] == '1')count++;//left
		
		if(a->cadata[index] == '1' && (count <2 ||count >3))
			val = 0;
		else if(a->cadata[index] == '1' && (count == 2 || count == 3))
			val = 1;
		else if(a->cadata[index] == '0' && count == 3)
			val = 1;
		
	}
	if(val)
		return '1';
	else return '0';
	
	
}