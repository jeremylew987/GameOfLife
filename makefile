CC = g++
cell: Main.o GraphicsClient.o CellularAutomaton.o
	$(CC) -o cell Main.o GraphicsClient.o CellularAutomaton.o
Main.o: Main.cpp GraphicsClient.hh CellularAutomaton.hh
	$(CC) -c Main.cpp
CellularAutomaton.o: CellularAutomaton.cpp GraphicsClient.hh CellularAutomaton.hh
	$(CC) -c CellularAutomaton.cpp
GraphicsClient.o: GraphicsClient.cpp GraphicsClient.hh
	$(CC) -c GraphicsClient.cpp