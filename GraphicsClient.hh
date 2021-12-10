#ifndef Graphics_Client_H
#define Graphics_Client_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
using namespace std;

class GraphicsClient {
  public:
    GraphicsClient(std::string, int);
    GraphicsClient(const GraphicsClient &a);
    ~GraphicsClient();
    GraphicsClient& operator=(const GraphicsClient& a);
    void setBackgroundColor( int r, int g, int b);
    void setDrawingColor( int r, int g, int b);
    void clear();
    void setPixel( int x, int y, int r, int g, int b);
    void drawRectangle( int x, int y, int width, int height);
    void fillRectangle( int x, int y, int width, int height);
    void clearRectangle( int x, int y, int width, int height);
    void drawOval( int x, int y, int width, int height);
    void fillOval( int x, int y, int width, int height);
    void drawLine( int x1, int y1, int x2,  int y2);
    void drawstring( int x, int y, string s);
    void repaint();
    void drawButtons();
    int* getInput();
    string getFile();



  private:
    int port;
    string address;
    int sockfd;
    struct sockaddr_in serv_addr;
    unsigned char message[255];




};



#endif
