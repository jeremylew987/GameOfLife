#ifndef CA
#define CA
struct ca_data{
	int numCells;
	unsigned char * arr;

};
void display1DCA(struct ca_data * );
int set1DCACell( struct ca_data*, unsigned int, unsigned char);
void init1DCA( struct ca_data *, int);
struct ca_data *create1DCA( int, unsigned char);
void stepCA( struct ca_data *, unsigned char (*)(struct ca_data *, int), int);


#endif 