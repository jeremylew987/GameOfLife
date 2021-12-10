#include "GraphicsClient.hh"
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include  <sys/ioctl.h>
#include <unistd.h>
using namespace std;
#include <string>

GraphicsClient::GraphicsClient(std::string s, int p){
port = p;
address = s;
char * cstr = new char [s.length()+1];
std::strcpy(cstr, s.c_str());

sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf( stderr, "Error creating socket\n");
        exit(-1);
    }
memset(&serv_addr, '0', sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(p);

    if(inet_pton(AF_INET, cstr, &serv_addr.sin_addr)<=0)
    {
        fprintf(stderr, "Invalid address/ Address not supported \n");
        exit(-1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Connection Failed \n");
        exit(-1);
    }
    free(cstr);

}
GraphicsClient::GraphicsClient(const GraphicsClient &a){
GraphicsClient(a.address,a.port);
}

GraphicsClient::~GraphicsClient(){
close(sockfd);
}

GraphicsClient& GraphicsClient::operator=(const GraphicsClient& a){
GraphicsClient g = GraphicsClient(a.address,a.port);
close(sockfd);
*this = g;
return *this;
}
void GraphicsClient::setBackgroundColor( int r, int g, int b){


message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x00;
message[4] = 0x07;
message[5] = 0x02;
message[6] = ((r>>4) & 0b1111);
message[7] = ((r) & 0b1111);
message[8] = ((g>>4) & 0b1111);
message[9] = ((g) & 0b1111);
message[10] = ((b>>4) & 0b1111);
message[11] = ((b) & 0b1111);

send( sockfd, message, 12, 0);



//make char array to send, need to test above code first
//TODO

}
void GraphicsClient::setDrawingColor( int r, int g, int b){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x00;
message[4] = 0x07;
message[5] = 0x06;
message[6] = ((r>>4) & 0b1111);
message[7] = ((r) & 0b1111);
message[8] = ((g>>4) & 0b1111);
message[9] = ((g) & 0b1111);
message[10] = ((b>>4) & 0b1111);
message[11] = ((b) & 0b1111);

send( sockfd, message, 12, 0);
}
void GraphicsClient::clear(){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x00;
message[4] = 0x01;
message[5] = 0x01;

send( sockfd, message, 6, 0);
}
void GraphicsClient::setPixel( int x, int y, int r, int g, int b){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x00;
message[4] = 0x0F;
message[5] = 0x02;
message[6] = ((x>>12) & 0b1111);
message[7] = ((x>>8) & 0b1111);
message[8] = ((x>>4) & 0b1111);
message[9] = ((x) & 0b1111);
message[10] = ((y>>12) & 0b1111);
message[11] = ((y>>8) & 0b1111);
message[12] = ((y>>4) & 0b1111);
message[13] = ((y) & 0b1111);
message[14] = ((r>>4) & 0b1111);
message[15] = ((r) & 0b1111);
message[16] = ((g>>4) & 0b1111);
message[17] = ((g) & 0b1111);
message[18] = ((b>>4) & 0b1111);
message[19] = ((b) & 0b1111);


send( sockfd, message, 20, 0);
}
void GraphicsClient::drawRectangle( int x, int y, int width, int height){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x01;
message[4] = 0x01;
message[5] = 0x07;
message[6] = ((x>>12) & 0b1111);
message[7] = ((x>>8) & 0b1111);
message[8] = ((x>>4) & 0b1111);
message[9] = ((x) & 0b1111);
message[10] = ((y>>12) & 0b1111);
message[11] = ((y>>8) & 0b1111);
message[12] = ((y>>4) & 0b1111);
message[13] = ((y) & 0b1111);
message[14] = ((width>>12) & 0b1111);
message[15] = ((width>>8) & 0b1111);
message[16] = ((width>>4) & 0b1111);
message[17] = ((width) & 0b1111);
message[18] = ((height>>12) & 0b1111);
message[19] = ((height>>8) & 0b1111);
message[20] = ((height>>4) & 0b1111);
message[21] = ((height) & 0b1111);

send( sockfd, message, 22, 0);

}
void GraphicsClient::fillRectangle( int x, int y, int width, int height){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x01;
message[4] = 0x01;
message[5] = 0x08;
message[6] = ((x>>12) & 0b1111);
message[7] = ((x>>8) & 0b1111);
message[8] = ((x>>4) & 0b1111);
message[9] = ((x) & 0b1111);
message[10] = ((y>>12) & 0b1111);
message[11] = ((y>>8) & 0b1111);
message[12] = ((y>>4) & 0b1111);
message[13] = ((y) & 0b1111);
message[14] = ((width>>12) & 0b1111);
message[15] = ((width>>8) & 0b1111);
message[16] = ((width>>4) & 0b1111);
message[17] = ((width) & 0b1111);
message[18] = ((height>>12) & 0b1111);
message[19] = ((height>>8) & 0b1111);
message[20] = ((height>>4) & 0b1111);
message[21] = ((height) & 0b1111);

send( sockfd, message, 22, 0);
}
void GraphicsClient::clearRectangle( int x, int y, int width, int height){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x01;
message[4] = 0x01;
message[5] = 0x09;
message[6] = ((x>>12) & 0b1111);
message[7] = ((x>>8) & 0b1111);
message[8] = ((x>>4) & 0b1111);
message[9] = ((x) & 0b1111);
message[10] = ((y>>12) & 0b1111);
message[11] = ((y>>8) & 0b1111);
message[12] = ((y>>4) & 0b1111);
message[13] = ((y) & 0b1111);
message[14] = ((width>>12) & 0b1111);
message[15] = ((width>>8) & 0b1111);
message[16] = ((width>>4) & 0b1111);
message[17] = ((width) & 0b1111);
message[18] = ((height>>12) & 0b1111);
message[19] = ((height>>8) & 0b1111);
message[20] = ((height>>4) & 0b1111);
message[21] = ((height) & 0b1111);

send( sockfd, message, 22, 0);
}
void GraphicsClient::drawOval( int x, int y, int width, int height){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x01;
message[4] = 0x01;
message[5] = 0x0A;
message[6] = ((x>>12) & 0b1111);
message[7] = ((x>>8) & 0b1111);
message[8] = ((x>>4) & 0b1111);
message[9] = ((x) & 0b1111);
message[10] = ((y>>12) & 0b1111);
message[11] = ((y>>8) & 0b1111);
message[12] = ((y>>4) & 0b1111);
message[13] = ((y) & 0b1111);
message[14] = ((width>>12) & 0b1111);
message[15] = ((width>>8) & 0b1111);
message[16] = ((width>>4) & 0b1111);
message[17] = ((width) & 0b1111);
message[18] = ((height>>12) & 0b1111);
message[19] = ((height>>8) & 0b1111);
message[20] = ((height>>4) & 0b1111);
message[21] = ((height) & 0b1111);

send( sockfd, message, 22, 0);
}
void GraphicsClient::fillOval( int x, int y, int width, int height){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x01;
message[4] = 0x01;
message[5] = 0x0B;
message[6] = ((x>>12) & 0b1111);
message[7] = ((x>>8) & 0b1111);
message[8] = ((x>>4) & 0b1111);
message[9] = ((x) & 0b1111);
message[10] = ((y>>12) & 0b1111);
message[11] = ((y>>8) & 0b1111);
message[12] = ((y>>4) & 0b1111);
message[13] = ((y) & 0b1111);
message[14] = ((width>>12) & 0b1111);
message[15] = ((width>>8) & 0b1111);
message[16] = ((width>>4) & 0b1111);
message[17] = ((width) & 0b1111);
message[18] = ((height>>12) & 0b1111);
message[19] = ((height>>8) & 0b1111);
message[20] = ((height>>4) & 0b1111);
message[21] = ((height) & 0b1111);

send( sockfd, message, 22, 0);
}
void GraphicsClient::drawLine( int x1, int y1, int x2,  int y2){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x01;
message[4] = 0x01;
message[5] = 0x0D;
message[6] = ((x1>>12) & 0b1111);
message[7] = ((x1>>8) & 0b1111);
message[8] = ((x1>>4) & 0b1111);
message[9] = ((x1) & 0b1111);
message[10] = ((y1>>12) & 0b1111);
message[11] = ((y1>>8) & 0b1111);
message[12] = ((y1>>4) & 0b1111);
message[13] = ((y1) & 0b1111);
message[14] = ((x2>>12) & 0b1111);
message[15] = ((x2>>8) & 0b1111);
message[16] = ((x2>>4) & 0b1111);
message[17] = ((x2) & 0b1111);
message[18] = ((y2>>12) & 0b1111);
message[19] = ((y2>>8) & 0b1111);
message[20] = ((y2>>4) & 0b1111);
message[21] = ((y2) & 0b1111);

send( sockfd, message, 22, 0);
}
void GraphicsClient::drawstring( int x, int y, string s){
int size = 14 + 2*(s.length());
int paysize = 9 + 2*(s.length());
char char_array[s.length() + 1];
strcpy(char_array, s.c_str());

message[0] = 0xFF;
message[1] = ((paysize>>12) & 0b1111);
message[2] = ((paysize>>8) & 0b1111);
message[3] = ((paysize>>4) & 0b1111);
message[4] = ((paysize) & 0b1111);
message[5] = 0x05;
message[6] = ((x>>12) & 0b1111);
message[7] = ((x>>8) & 0b1111);
message[8] = ((x>>4) & 0b1111);
message[9] = ((x) & 0b1111);
message[10] = ((y>>12) & 0b1111);
message[11] = ((y>>8) & 0b1111);
message[12] = ((y>>4) & 0b1111);
message[13] = ((y) & 0b1111);
for(int i = 0; i< s.length();i++){
char cur = char_array[i];
message[14+(2*i)] = ((cur>>4) & 0b1111);
message[15+(2*i)] = ((cur) & 0b1111);
}


send( sockfd, message, size, 0);
}
void GraphicsClient::repaint(){

message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x00;
message[4] = 0x01;
message[5] = 0x0C;

send( sockfd, message, 6, 0);
}

void GraphicsClient::drawButtons(){
drawRectangle(625,20,100,40);
drawstring(650,45,"STEP");
drawRectangle(625,80,100,40);
drawstring(650,105,"RUN");
drawRectangle(625,140,100,40);
drawstring(650,165,"PAUSE");
drawRectangle(625,200,100,40);
drawstring(650,225,"RESET");
drawRectangle(625,260,100,40);
drawstring(650,285,"RANDOM");
drawRectangle(625,320,100,40);
drawstring(650,345,"LOAD");
drawRectangle(625,380,100,40);
drawstring(650,405,"QUIT");

drawstring(615,540,"SELECT SIZE");
drawRectangle(625,550,40,40);
drawstring(640,575,"1");
drawRectangle(685,550,40,40);
drawstring(700,575,"2");
drawRectangle(745,550,40,40);
drawstring(760,575,"3");


}
int* GraphicsClient::getInput(){
int count; 
int x,y;
int* r = new int[3];
r[0] = 0;r[1] = 0;r[2]=0;
ioctl(sockfd, FIONREAD, &count); 
cout<<count<<endl;
while(count != 0){
read(sockfd, message, 15);
count -= 15;
int type  = message[5];
cout<<"type of click"<<type<<endl;
if(type == 3){
    
    x = (message[7]<<12) + (message[8]<<8) + (message[9]<<4) + (message[10]);
    y = (message[11]<<12) + (message[12]<<8) + (message[13]<<4) + (message[14]);
    cout<<x<<","<<y<<endl;

if(x>=625 && x<=725){
    if(y>=20 && y<=60){
        r[0] = 1;
    }
    else if(y>=80 && y<=120){
        r[0] = 2;
    }
    else if(y>=140 && y<=180){
        r[0] = 3;
    }
    else if(y>=200 && y<=240){
        r[0] = 4;
    }
    else if(y>=260 && y<=300){
        r[0] = 5;
    }
    else if(y>=320 && y<=360){
        r[0] = 6;
    }
    else if(y>=380 && y<=420){
        r[0] = 7;
    }

}
if(y>=550 && y<=590){
    if(x>=625 && x<=665){
        r[0] = 8;
        r[1] = 1;
    }
    else if(x>=685 && x<=725){
        r[0] = 8;
        r[1] = 2;
    }
    else if(x>=745 && x<=785){
        r[0] = 8;
        r[1] = 3;
    }
}
if(x>=0 && x<=600){
    if(y>=0 && y<=600){
    r[0] = 9;
    r[1] = x;
    r[2] = y;
    }
}
}
}
return r;
}
string GraphicsClient::getFile(){
message[0] = 0xFF;
message[1] = 0x00;
message[2] = 0x00;
message[3] = 0x00;
message[4] = 0x01;
message[5] = 0x0E;

send( sockfd, message, 6, 0);
struct timespec tim, tim2;
   tim.tv_sec = 1;
   tim.tv_nsec = 0;
nanosleep(&tim , &tim2);
int count = 0; 
while(count == 0){
nanosleep(&tim , &tim2);
ioctl(sockfd, FIONREAD, &count);
}
cout<<"Count Test"<<count<<endl;
cout<<"Read Test:"<<read(sockfd, message, count)<<endl;
cout<<message<<endl;
int size = count - 6;
char s[size/2];
for(int i = 0; i<size/2;i++){
    s[i] = (message[(2*i)+6]<<4) + (message[(2*i)+7]);
}
cout<<s[0]<<endl;
string str(s);
cout<<str<<endl;
return str;
}


