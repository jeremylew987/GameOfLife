#ifndef CA
#define CA
struct ca_data{
	int height;//1 if 1 demensions
	int width;
	unsigned char * cadata;
	int dimension;//1 or 2
	unsigned char wrap;//0 for no wrap
	
	
	

};
void displayCA(struct ca_data * );
int set1DCACell( struct ca_data*, unsigned int, unsigned char);
int set2DCACell( struct ca_data *ca, unsigned int x, unsigned int y, unsigned char state);
void init1DCA( struct ca_data *, int);
struct ca_data *create1DCA( int, unsigned char);
struct ca_data *create2DCA( int w, int h, unsigned char qstate); 
void stepCA( struct ca_data *, unsigned char (*)(struct ca_data *, int));
void step2DCA( struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int x, int y)); 


#endif 