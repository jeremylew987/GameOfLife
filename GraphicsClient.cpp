#include "GraphicsClient.hh"
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
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

