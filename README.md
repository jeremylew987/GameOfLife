Features:
Makes a Struct ca_data which holds an array of unsigned chars as a state and the number of cells.

The ability to initalize a one-dimensional cellular automaton with all values set to a specified state or random ones within
bounds of the state availble of length 10-100 inclusive for our example but could be larger.

The ability to edit valued in the one-dimensional cellular automaton at a given index.

The ability to display the values of the one-dimensional cellular automaton.

The ability to use a set of rules to get the next row of states in a one-dimensional cellular automaton.

The ability to create a pointer to a Struct ca_data using malloc.

Limitations:
The current main function asks for user inputs but doesn't check if the user actually inputs the correct type so if the user inputs
a char in for one of the fields that requests for an integer the program doesn't work and freaks out.
It also only allows for a max of 0-9 states while having numbers, other wise it uses characters
