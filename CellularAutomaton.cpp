#include "CellularAutomaton.hh"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdlib.h> 
using namespace std;


CellularAutomaton::CellularAutomaton(std::string filename, int q){
qState = q;
ifstream myfile (filename);
myfile>>height;
myfile>>width;
caData = new int[height*width];
init = new int[height*width];
for(int i =0;i<height*width;i++){
   myfile>>caData[i];
   init[i] = caData[i];
}
wrap = true;


}
CellularAutomaton::CellularAutomaton( int q){
qState = q;
height = 1;
width = 1;
caData = new int[1];
init = new int[1];
caData[0] = init[0] = 0;
wrap = true;
}
CellularAutomaton::CellularAutomaton(const CellularAutomaton & tocopy){
height = tocopy.height;
width = tocopy.width;
wrap = tocopy.wrap;
qState = tocopy.qState;
caData = new int[height*width];
init = new int[height*width];
for(int i = 0; i<height*width;i++){//deep copy array
    caData[i] = tocopy.caData[i];
    init[i] = tocopy.init[i];
}
}

CellularAutomaton::~CellularAutomaton(){
    delete(caData);
    delete(init);
}
CellularAutomaton& CellularAutomaton::operator=(const CellularAutomaton& tocopy){
if (this != &tocopy){
height = tocopy.height;
width = tocopy.width;
wrap = tocopy.wrap;
qState = tocopy.qState;
delete(caData);
delete(init);
caData = new int[height*width];
init = new int[height*width];
for(int i = 0; i<height*width;i++){//deep copy array
    caData[i] = tocopy.caData[i];
    init[i] = tocopy.init[i];
}
}
return *this;
}

//TODO
void CellularAutomaton::step(int (*rule)(CellularAutomaton&,int)){
CellularAutomaton b = *this;
for(int i = 0; i<height*width;i++){
    caData[i] = rule(b,i);
}

}

void CellularAutomaton::display(GraphicsClient & d){
d.clear();
d.drawButtons();
int csize,gap;
int scale = max(height, width);

if(scale <= 50){
    csize = 10;
    gap = 2;
}
else if(scale <= 100){
    csize = 4;
    gap = 1;
}
else if(scale <= 200){
    csize = 2;
    gap = 1;
}
else{
    csize = 1;
    gap = 0;
}
int x = 0,y = 0;
for(int i = 0;i<height*width;i++){
if(caData[i] == 1){
    d.fillRectangle(x,y,csize,csize);
}
if((i+1)%width == 0){

x = 0;
y += csize+gap;
}
else x+=csize+gap;
}
d.repaint();
}


int * CellularAutomaton::getcaData(){
int * a = new int[height*width];  
for(int i = 0;i<height*width;i++) a[i] = caData[i]; 
return a;
}
int CellularAutomaton::getHeight(){return height;}
int CellularAutomaton::getWidth(){return width;}
void CellularAutomaton::display(){
    for(int i = 0;i<height*width;i++){
        cout<<caData[i]<<" ";
        if((i+1)%width == 0)cout<<endl;
    }
}
void CellularAutomaton::randomize(){
    srand((unsigned)time(NULL));
for(int i = 0; i<(height*width);i++){
caData[i] = rand()%2;
init[i] = caData[i];
}
}
void CellularAutomaton::revert(){
    for(int i =0;i<(height*width);i++){
        caData[i] = init[i];
    }
}
void CellularAutomaton::changeSize(int s){
    delete(caData);
    delete(init);
    if(s == 1){
height = 40;
width = 40;
    }
    else if(s == 2){
height = 150;
width = 150;
    }
    else{
height = 600;
width = 600;
    }
    caData = new int[height*width];
    init = new int[height*width];
    randomize();
}
void CellularAutomaton::flip(int x, int y, GraphicsClient & d){
int csize,gap,tx,ty;
int scale = max(height, width);
if(scale <= 50){
    csize = 10;
    gap = 2;
}
else if(scale <= 100){
    csize = 4;
    gap = 1;
}
else if(scale <= 200){
    csize = 2;
    gap = 1;
}
else{
    csize = 1;
    gap = 0;
}
tx = x/(csize+gap);
ty = y/(csize+gap);

int pos = tx + ty*width;
int cur = caData[pos];
int dx = tx*(csize+gap), dy = ty*(csize+gap);
if(cur == 0){
    caData[pos] = 1;
    d.fillRectangle(dx,dy,csize,csize);
}
else{
    caData[pos] = 0;
    d.clearRectangle(dx,dy,csize,csize);
}

d.repaint();

}