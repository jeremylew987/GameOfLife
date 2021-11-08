Input:
first command line is either 1 or 2 for 1D and 2D, second is a string with the file path to the file to read including filetype

Features:
Makes a Struct ca_data which holds an array of unsigned chars as a state, the width, height, a flag to say whether or not it is 1D or 2D, and a flag for whether or not it is wrapped or not.

The ability to initalize a one-dimensional or two-dimensional cellular automaton based off of a command line value with all values set to a specified state based of of a file put in the command line

The ability to edit valued in the one-dimensional cellular automaton at a given index or a two-dimensional one with a x and y index

The ability to display the values of the cellular automaton.

The ability to use a set of rules to get the next row of states in a cellular automaton.

The ability to create a pointer to a Struct ca_data using malloc.

Continues to make steps when the user enters a blank character in the console, anything else stops the program

Limitations:
If the user enters values above 9 on the input file for states it will begin to be letter chars since they come next on the ASCCI table

