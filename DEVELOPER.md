GraphicsClient.hh and GraphicsClient.cpp:
Graphics client stores:
int sockfd, int port, string address, and char message[]

GraphicsClient(std::string, int);
Makes a object with an input of an address and port number to open a connection with

GraphicsClient(const GraphicsClient &a);
makes a deep copy of a by calling GraphicsClient(std::string, int) with the address and port from a

~GraphicsClient();
closes the connection to the server

GraphicsClient& operator=(const GraphicsClient& a);
closes the exsisting connection and calls a constructor with the parameters of a, then sets the current *this to refrence the new object

void setBackgroundColor( int r, int g, int b);
sets the char array message[0] - message[5] to their appropriate values for this message, then divides up r g and b into 4 bytes each and adds them to the message in that order, then uses the sockfd to send it to the server

void setDrawingColor( int r, int g, int b);
sets the char array message[0] - message[5] to their appropriate values for this message, then divides up r g and b into 4 bytes each and adds them to the message in that order, then uses the sockfd to send it to the server

void clear();
sets the char array message[0] - message[5] to their appropriate values for this message, then uses the sockfd to send it to the server

void setPixel( int x, int y, int r, int g, int b);
sets the char array message[0] - message[5] to their appropriate values for this message, then divides up x and y into 4 bytes each and adds it to message, then divides up r g and b into 4 bytes each and adds them to the message in that order, then uses the sockfd to send it to the server

(These ones all work the same way)
void drawRectangle( int x, int y, int width, int height);
void fillRectangle( int x, int y, int width, int height);
void clearRectangle( int x, int y, int width, int height);
void drawOval( int x, int y, int width, int height);
void fillOval( int x, int y, int width, int height);
sets the char array message[0] - message[5] to their appropriate values for this message, then divides up x and y into 4 bytes each and adds it to message, then divides up width and height into 4 bytes each and adds them to the message in that order, then uses the sockfd to send it to the server

void drawLine( int x1, int y1, int x2,  int y2);
sets the char array message[0] - message[5] to their appropriate values for this message, then divides up  the first x and y into 4 bytes each and adds it to message, then divides up  the second x and y into 4 bytes each and adds it to message,, then uses the sockfd to send it to the server

void drawstring( int x, int y, string s);
Finds the total size by 14 + 2(string size) since each char in the string will be two bytes, and finds payload size by 9 + 2(string size) since it doesn't include the payload size and sync bytes
sets sync bit to message[0] and the payload bytes by dividing the payload size into 4 bytes through bitwise operators and sets message[5] to oXo5 for string,
then divides the x and y into 4 bytes each and then adds them
then uses a for loop to get each char from the string, turn them into two bytes each, then add them
lastly it sends the message to the server

void repaint();
sets the char array message[0] - message[5] to their appropriate values for this message, then uses the sockfd to send it to the server

void drawButtons();
This sends the apropriate comands to draw rectangles and strings onto the display for the user to know where to click

int* getinput()
reads the input from the server based on the click input from the user and reads where they clicked to either return a number corisponding to what button they clicked or returns a number and the coordinate points of where they clicked to be able to find the spot to flip the value on the display of the automaton

string getFile()
calls the command to get a file from the server and waits until a response is sent from the server and turns it into a string that is then returned

CellularAutomaton.hh and CellularAutomaton.cpp:
Stores:
int height, int width ,int qState, int * caData, and bool wrap, int * init

CellularAutomaton(std::string, int);
Uses a file name to open a file and get interger values out of it to first get the height and width and then make a new int array size of height*width set to caData, then uses a for loop to loop through heigth*width values from the file to be the values caData, it then setsthe qState to the int taken in as the other parameter and sets wrap to true
Also stores the inital values in init

CellularAutomaton(int)
used to set up a 1 by 1 autmaton for when the program launches, all default values

CellularAutomaton(const CellularAutomaton & tocopy);
This makes a new int array the size of tocopy's height*width
iterates through a loop copying the values of tocopy's caData to this object
copies the init the same way
copys over the height, width, qState and wrap

~CellularAutomaton();
deletes caData and init

int * getcaData();
makes a copy of caData and returns a pointer to it, for step function rule

int getHeight();
returns the height

int getWidth();
returns the width

CellularAutomaton& operator=(const CellularAutomaton& tocopy);
deletes caData
then makes a new int array the size of tocopy's height*width
iterates through a loop copying the values of tocopy's caData to this object
copys over the height, width, qState and wrap

void step(int (*func)(CellularAutomaton&,int));
Use the rule and makes a copy of the object to send into the rule for every index and changes the caData based on the responses

void display(GraphicsClient & d);
clears the graphics client
finds the cell size and cell gap according to the max between height and width
uses a for loop to iterate height*width times, each step changes and x varible by cellsize+cellgap and if at the end of the row it will add cellsize+cellgap to a y varible, for each iteration it will check if the value at this index is a 1 and if it is it will fill a rectangle on the current x and y with a height and width of cellsize.
also calls drawButtons()
at the end it will repaint to refresh the display on the graphics client.

void display();//used for testing the rule
iterates through and prints values to the console of caData

void randomize()
sets the values of cadata to random values 1 or 0 and sets init to these values as well through a loop

void revert()
sets all the values of caData back to whatever init is at that index through a loop

void changeSize(int)
changes the size of the caData and int depending on the input, 1 for small 2 for medium and 3 for large and randomizes the caData


Main.cpp:
Rule takes in a CellularAutomaton refrence and a index, it then checks the surounding 8 indexs using % and adding width or height accordingly and counts the number of active indexs around it and returns the value it should change to based on that.

the main function makes a default cellularAutomaton and then starts looping through as listening for a response by calling get input every 100ms until the user hits quit which changes the flag varible, that function gives back a corisponding int in a int* int the 0th index which then calls the corispoinding command such as run which toggles a run varible so every 10 cycles of 100ms it will re display the screen, if the user clicks a square on the display in the automaton it calls functions to flip the value, it can also request a file and set the cellularAutomaton to that file through copy constructor