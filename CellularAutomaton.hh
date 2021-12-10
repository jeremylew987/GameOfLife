#ifndef Cell_H
#define Cell_H

#include "GraphicsClient.hh"
using namespace std;
#include <string>

class CellularAutomaton {
  private:
  int height;
  int width;
  int qState;
  int * caData;
  int * init;
  bool wrap;
  
  public:
  CellularAutomaton(std::string, int);
  CellularAutomaton( int);
  CellularAutomaton(const CellularAutomaton & tocopy);
  ~CellularAutomaton();
  int * getcaData();
  int getHeight();
  int getWidth();
  CellularAutomaton& operator=(const CellularAutomaton& tocopy);
  void step(int (*func)(CellularAutomaton&,int));
  void display(GraphicsClient & d);
  void display();
  void randomize();
  void revert();
  void changeSize(int);
  void flip(int, int, GraphicsClient & d);
};


#endif