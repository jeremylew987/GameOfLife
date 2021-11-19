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
  bool wrap;
  
  public:
  CellularAutomaton(std::string, int);
  CellularAutomaton(const CellularAutomaton & tocopy);
  ~CellularAutomaton();
  int * getcaData();
  int getHeight();
  int getWidth();
  CellularAutomaton& operator=(const CellularAutomaton& tocopy);
  void step(int (*func)(CellularAutomaton&,int));
  void display(GraphicsClient & d);
  void display();
};


#endif