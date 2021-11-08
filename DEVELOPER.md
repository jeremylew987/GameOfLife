ca.h:
This file includes the prototypes for:
Struct ca_data which has a array of unsigned chars and a integer to state the height, width, if it's 1D or 2D and a unsigned char to decide if it is wrapped or not

init1DCA which will initialize an array of unsigned chars to '0' with a length as a parameter
Parameters: int, struct ca_data *
Return: void

set1DCACell which will set the unsigned char stored at an index in the unsigned char array in a ca_data struct to a value
Parameters: struct ca_data *, int, unsigned char
Return: int: 1 if it works

set2DCACell which will set the unsigned char stored at an index in the unsigned char array in a ca_data struct to a value
Parameters: struct ca_data *, int, int, unsigned char
Return: int: 1 if it works

displayCA which will display the unsigned char array of a ca_data struct
Parameters: struct ca_data *
Return: void

create1DCA which will make a pointer equal to malloc of size struct ca_data and also malloc the space for its array
of unsigned chars, will also set them to a certain value.
Parameters: int, unsigned char
Return: struct ca_data *

create2DCA which will make a pointer equal to malloc of size struct ca_data and also malloc the space for its array
Parameters: int,int, unsigned char
Return: struct ca_data *



stepCA which will update the struct to the next state based off of a rule
using a rule that is passed in as a parameter 
Parameters: struct ca_data *, unsigned char (*)(struct ca_data *, int)
return: unsigned char

step2DCA which will update the struct to the next state based off of a rule
Parameters:struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int x, int y)

ca.c:
Includes: <stdio.h> <stdlib.h> ca.h

Defines:
init1DCA: Uses a for loop until length desired in parameter to set value in the array in the struct ca_data to 0
set1DCACell: Sets value in the array in struct ca_data at set index to the value in the parameter
set2DCACell:Sets value in the array in struct ca_data at set x and y index to the value in the parameter
displayCA: Uses a for loop until length desired in parameter and prints the value of the array in struct ca_data
 at each index, then prints a new line
create1DCA: mallocs the space for a struct ca_data to a pointer and then mallocs the space of the array in ca_data to the
proper length taken in by the parameter, it then uses a for loop to set all the valies in that array to a set value
create2DCA:mallocs the space for a struct ca_data to a pointer and then mallocs the space of the array in ca_data to the
proper length taken in by the parameters height and width, it then uses a for loop to set all the valies in that array to a set value
stepCA: makes a struct ca_data pointer and mallocs it with size of the orginal struct ca_data, sets the wrap value to the same as orginal, and runs the rule function on each index in the array of the new struct and sets the value returned to the index of the original struct, then frees the new struct
step2DCA: makes a struct ca_data pointer and mallocs it with size of the orginal struct ca_data, sets the wrap value to the same as orginal, and runs the rule function on each index in the array of the new struct and sets the value returned to the index of the original struct, then frees the new struct


main.c:
Takes in an input in the command line of a 1 or 2 as the first value to decide if it is making a 1D or 2D CA struct, for this main function it only allows 2D since the rule applies to 2D so if 1 is put in it exits and informs the user of the error. The second is the path to a file to read. The program reads the file and takes the first to integers as height and width, then there should be h*w more values and these will be the intial states of the Ca struct. It makes the struct then uses a loop to read and set all the intial values. Then looks for user input, anytime the user enters a blank line or hits enter it will display one step of the Ca struct until the user enters a char or string in the console.

