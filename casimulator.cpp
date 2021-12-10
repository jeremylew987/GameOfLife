#include <iostream>
using namespace std;
#include <string>
#include <chrono>
#include <thread>
#include "GraphicsClient.hh"
#include "CellularAutomaton.hh"

int rule(CellularAutomaton&,int);

int main(int argc, char *argv[]){
	int quit = 1;
	int run = 0;
	int count = 0;
	struct timespec tim, tim2;
   tim.tv_sec = 0;
   tim.tv_nsec = 100000000L;


using namespace std::this_thread;
using namespace std::chrono;
GraphicsClient a = GraphicsClient("127.0.0.1",7777);
CellularAutomaton b = CellularAutomaton(0);

b.display(a);

int* temp = new int[3];
while(quit){
temp[0] = 0;
temp[1] = 0;
temp[2] = 0;
count++;
nanosleep(&tim , &tim2);
temp = a.getInput();
if(temp[0] == 1){
b.step(rule);
b.display(a);
}
else if(temp[0] == 2){
	run = 1;
}
else if(temp[0] == 3){
	run = 0;
}
else if(temp[0] == 4){
	b.revert();
	b.display(a);
}
else if(temp[0] == 5){
	b.randomize();
	b.display(a);
}
else if(temp[0] == 6){
	string temp = a.getFile();
	b = CellularAutomaton(temp, 0);
	b.display(a);
}
else if(temp[0] == 7){
	quit = 0;
	continue;
}
else if(temp[0] == 8){
	b.changeSize(temp[1]);
	b.display(a);
}
else if(temp[0] == 9){
	b.flip(temp[1],temp[2],a);
}
if(count%10 == 0 && run){
b.step(rule);
b.display(a);
}


}

}

int rule(CellularAutomaton& a,int i){
int * d = a.getcaData();
int height = a.getHeight();
int width = a.getWidth();
int x = i%width;
int y = i/width;
int val = 0;

if( d[i] != 1 && d[i] !=  0){
		cout<<"This rule only works with two states"<<endl;
		exit(0);
	}
int count =0;
if(d[(x-1+width)%width + ((y-1+height)%height)*width] == 1)count++;//upleft
if(d[(x+width)%width + ((y-1+height)%height)*width] == 1)count++;//up
if(d[(x+1+width)%width + ((y-1+height)%height)*width] == 1)count++;//upright
if(d[(x+1+width)%width + ((y+height)%height)*width] == 1)count++;//right
if(d[(x+1+width)%width + ((y+1+height)%height)*width] == 1)count++;//downright
if(d[(x+width)%width + ((y+1+height)%height)*width] == 1)count++;//down
if(d[(x-1+width)%width + ((y+1+height)%height)*width] == 1)count++;//downleft
if(d[(x-1+width)%width + ((y+height)%height)*width] == 1)count++;//left

if(d[i] == 1 && (count <2 ||count >3))
	val = 0;
else if(d[i] == 1 && (count == 2 || count == 3))
	val = 1;
else if(d[i] == 0 && count == 3)
	val = 1;
delete d;
return val;

}