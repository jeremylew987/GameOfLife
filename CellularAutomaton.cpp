#include "CellularAutomaton.hh"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


CellularAutomaton::CellularAutomaton(std::string filename, int q){
qState = q;
ifstream myfile (filename);
myfile>>height;
myfile>>width;
caData = new int[height*width];
for(int i =0;i<height*width;i++){
   myfile>>caData[i];
}
wrap = true;


}
CellularAutomaton::CellularAutomaton(const CellularAutomaton & tocopy){
height = tocopy.height;
width = tocopy.width;
wrap = tocopy.wrap;
qState = tocopy.qState;
caData = new int[height*width];
for(int i = 0; i<height*width;i++){//deep copy array
    caData[i] = tocopy.caData[i];
}
}

CellularAutomaton::~CellularAutomaton(){
    delete(caData);
}
CellularAutomaton& CellularAutomaton::operator=(const CellularAutomaton& tocopy){
if (this != &tocopy){
height = tocopy.height;
width = tocopy.width;
wrap = tocopy.wrap;
qState = tocopy.qState;
delete(caData);
caData = new int[height*width];
for(int i = 0; i<height*width;i++){//deep copy array
    caData[i] = tocopy.caData[i];
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