ca.h:
This file includes the prototypes for:
Struct ca_data which has a array of unsigned chars and a integer to state the length of the array

init1DCA which will initialize an array of unsigned chars to '0' with a length as a parameter
Parameters: int, struct ca_data *
Return: void

set1DCACell which will set the unsigned char stored at an index in the unsigned char array in a ca_data struct to a value
Parameters: struct ca_data *, int, unsigned char
Return: int: 1 if it works

display1DCA which will display the unsigned char array of a ca_data struct
Parameters: struct ca_data *
Return: void

create1DCA which will make a pointer equal to malloc of size struct ca_data and also malloc the space for its array
of unsigned chars, will also set them to a certain value.
Parameters: int, unsigned char
Return: void

stepCA which will return the value of the next state of a spefic unsigned char at a certain index in the array of a ca_data struct
using a rule that is passed in as a parameter while deciding to wrap or not wrap the array through a flag
Parameters: struct ca_data *, unsigned char (*)(struct ca_data *, int), int
return: unsigned char

ca.c:
Includes: <stdio.h> <stdlib.h> ca.h

Defines:
init1DCA: Uses a for loop until length desired in parameter to set value in the array in the struct ca_data to 0
set1DCACell: Sets value in the array in struct ca_data at set index to the value in the parameter
display1DCA: Uses a for loop until length desired in parameter and prints the value of the array in struct ca_data
 at each index, then prints a new line
create1DCA: mallocs the space for a struct ca_data to a pointer and then mallocs the space of the array in ca_data to the
proper length taken in by the parameter, it then uses a for loop to set all the valies in that array to a set value
stepCA: makes a struct ca_data pointer and mallocs it with size of the orginal struct ca_data + 2 so that 
you can use the rule passed in on the edges, if the user wants to wrap the array then the two edge unsigned chars will
be set the the start and end respectively and if they want no wrap then they will just be zero, the rest of the array
in the new struct ca_data index 1 to length of original ca_data +1 will be the values in that array. from there the values 
of the original array will be set to the values returned by the rule function for index 1 to  length of original ca_data +1
then we will free the extra created array and sturct ca_data pointer.


main.c:
Asks for user input of the number of cells 10-100 inclusive and does't allow any number out of that range, stores this num
Asks for number of states above 2 and stores it.
Asks for if the user wants wrap or nowrap and loops until the user enters either of those two values and stores it.
If the user enters wrap it stores a flag int to 1 otherwise it stores it as 0.
Then it asks for an intial value for the cells which can be a number within 0 to numStates-1 or -1 and it will loop
until a value is put in is valid and will store it.
Then it will ask for number of steps which is any number above 1 and will loop until a valid number is entered
and it is stored.
Makes a struct ca_data pointer.
Then it checks if the initial value is -1, if it is negative one then it uses create1DCA with the length stored
and '0' as the intial value and then uses set1DCA on each index to set to a random number within the valid states
by using the ascii table or a (random number % numstates) + 48 to get to numbers, if states go above 10 states it will 
end up being a char that isn't a number.
if the value isn't -1 then it will just use create1DCA with the length and the inital value
it will then display this new sturct ca_data
the program will then loop from 0 to the numSteps inputed earlier and will run stepCA on the struct with the rule set up
and the wrapValue and will display the struct after each stepCA call.

