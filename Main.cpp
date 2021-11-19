#include <iostream>
using namespace std;
#include <string>
#include <chrono>
#include <thread>
#include "GraphicsClient.hh"
#include "CellularAutomaton.hh"

int rule(CellularAutomaton&,int);

int main(int argc, char *argv[]){

if(argc != 2){cout<<"Incorrect arguments";exit(1);}
char fn[50];
strcpy( fn, argv[1] );
    using namespace std::this_thread;
    using namespace std::chrono;
GraphicsClient a = GraphicsClient("127.0.0.1",7777);
CellularAutomaton b = CellularAutomaton(fn, 0);
b.display(a);
string t = "";
getline (cin, t);
while(t.compare("") == 0){
b.step(rule);
b.display(a);
getline (cin, t);
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