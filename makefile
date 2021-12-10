CC = g++
cell: casimulator.o GraphicsClient.o CellularAutomaton.o
	$(CC) -o cell casimulator.o GraphicsClient.o CellularAutomaton.o
casimulator.o: casimulator.cpp GraphicsClient.hh CellularAutomaton.hh
	$(CC) -c casimulator.cpp
CellularAutomaton.o: CellularAutomaton.cpp GraphicsClient.hh CellularAutomaton.hh
	$(CC) -c CellularAutomaton.cpp
GraphicsClient.o: GraphicsClient.cpp GraphicsClient.hh
	$(CC) -c GraphicsClient.cpp