#include<iostream>
#include<cstring>
#include<cctype>
//This program will a class and two structs. The class contains the head of the main LLL and all of the function prototypes. All functions that have head in the argument list are 
//the private section. The structs have deconstructors to deallocate the dynamic memory in them. 
struct nodeamen
{
	~nodeamen();
	nodeamen * nextamen;
	char * nameamen;
	int rating;
		
};

struct nodepark
{
	~nodepark();
	nodepark * nextpark;
	nodeamen * headamen;
	char * name;

};

class dog_parks
{
	public:
	dog_parks();
	~dog_parks();
	int add_dog_park(char * park_name);
	int display_all();
	int add_amenity(int rating, char * park_name, char * amen_name);
	int display_amen(char * park_name);
	int remove_dog_park(char * park_name);
	int search_dog_park(char * amen_name);
	
	private:
	nodepark * headpark;
	int display_all(nodepark * headpark);
	int add_helper(int rating, char * park_name, char *amen_name, nodepark *& headpark);
	int add_amenity(int rating, char * park_name, char * amen_name, nodeamen *&headamen);
	int display_amen(nodeamen * headamen);
	int remove_amen(nodeamen *& hold);
	int remove_all(nodepark *& headpark); 
	int remove_dog_park(char * park_name, nodepark *&headpark);
	int add_dog_park(char * park_name, nodepark *&headpark);
	int search_amen(nodeamen * headamen, char * amen_name);
};
