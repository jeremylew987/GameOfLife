dca1d.h:
This file includes the prototypes for:
init1DCA which will initialize an array of unsigned chars to '0' with a length as a parameter
Parameters: int, unsigned char array
Return: void

set1DCACell which will set the unsigned char stored at an index in the unsigned char array to a value
Parameters: unsigned char array, int, unsigned char
Return: void

display1DCA which will display a specficied number of cells in the unsigned char array
Parameters: unsigned char array, int
Return: void


dca1d.c:
Includes: dca1d.h and stdio.h

Defines:
init1DCA: Uses a for loop until length desired in parameter to set value in the array to 0
set1DCACell: Sets value in the array at set index to the value in the parameter
display1DCA: Uses a for loop until length desired in parameter and prints the value of the array at each index, then prints a new line

Main:
Makes a unsigned char array at length 50 and initialized first 25 with init1DCA.
Sets, using set1DCACell, all even indexs to '2' and all odd to '1' with a for loop and if else statments by checking %2 == 0 to check for even numbers.
Displays the 25 values with display1DCA.
