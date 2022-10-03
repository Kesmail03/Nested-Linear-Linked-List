#include"dogparks.h"
using namespace std;

//Khaled Esmail,cs163, 4/8/2022
//This is where all of the functions are implemented. In this program multiple functions will be used to complete one task. Using recursion and the help of a wrapper function.
//It's important to not cin info from the user inside the functions so we receive this info from main and pass it into the functions.
//Deallocating the dynamic memory in the structs
nodeamen::~nodeamen()
{
	nameamen = nullptr;
	

}
nodepark::~nodepark()
{

	name = nullptr;

}
dog_parks::dog_parks()
{
	headpark = nullptr;

}
//The constructor
dog_parks::~dog_parks()
{
	if(headpark == nullptr)
		return;	 
	remove_all(headpark);


}

//wrapper function
int dog_parks::remove_dog_park(char * park_name)
{
	//base case
	if(headpark == nullptr)
		return 0;
	return remove_dog_park(park_name, headpark);
}
int dog_parks::remove_dog_park(char * park_name, nodepark *&headpark)
{

	if(headpark == nullptr)
		return 0;
	if(strcmp(park_name, headpark->name)==0)
	{
		nodepark * hold = headpark;
		headpark = hold->nextpark;
		remove_amen(hold->headamen);
		delete hold;
		return 1;

	}	
	return remove_dog_park(park_name, headpark->nextpark);//recursive call



}
//This function will be called in the destructor to destroy the LLL
int dog_parks::remove_all(nodepark *& headpark)
{
	if(headpark == nullptr) 
		return 0;
	remove_all(headpark->nextpark);
	delete headpark;
	headpark = nullptr;
	return 1;

}
//This function removes all amenities of a certain dog park
int dog_parks::remove_amen(nodeamen *& hold )
{
	if(hold == nullptr) 
		return 0;
	remove_amen(hold->nextamen);
	delete hold;
	hold = nullptr;
	return 1;
}
//wrapper function
int dog_parks::add_dog_park(char * park_name)
{
	return add_dog_park(park_name, headpark);
}
int dog_parks::add_dog_park(char * park_name, nodepark *&headpark)
{
	//empty list
	if(headpark == nullptr)
	{
		headpark = new nodepark;	
		headpark->name = new char[strlen(park_name) +1];
		strcpy(headpark->name, park_name);
		return 1;
	}
	//if the user enters the same name twice
	if(strcmp(park_name, headpark->name) == 0)
		return 0;
	//inserting at the front
	if(strcmp(park_name, headpark->name) < 0)
	{
		nodepark * temp = new nodepark;
		temp->nextpark = headpark;
		headpark = temp;
		temp->name = new char[strlen(park_name) +1];
		strcpy(temp->name, park_name);
		return 1;
	}
	//inserting at the back of the LLL
	if(strcmp(park_name, headpark->name) > 0)
	{
		nodepark * temp = new nodepark;
		temp->nextpark = headpark->nextpark;
		headpark->nextpark = temp;
		temp->name = new char[strlen(park_name) +1];
		strcpy(temp->name, park_name);
		return 1;
	}
	return add_dog_park(park_name, headpark->nextpark);
}
//wrapper function
int dog_parks:: display_all()
{
	//check if list is empty
	if(headpark == nullptr)
		return 0;
	return display_all(headpark);


}

int dog_parks:: display_all(nodepark * headpark)
{
	//stopping condition
	if(headpark == nullptr)
		return 0;
	cout<<headpark->name<<endl;
	return 1 + display_all(headpark->nextpark);


}
//wrapper function to call from main
int dog_parks::add_amenity(int rating, char * park_name, char *amen_name)
{
	if(headpark == nullptr) //if we have nothing in our park list there is no amenity to add
		return 0;
	return add_helper(rating, park_name, amen_name, headpark); //calling recursive function
}
int dog_parks::add_helper(int rating,char * park_name, char * amen_name, nodepark *& headpark) //recursive function
{
	if(headpark == nullptr)
		return 0;
	if(strcmp(headpark->name,park_name) == 0) //stopping condition if we have a match for park name
	{
		add_amenity(rating, park_name, amen_name, headpark->headamen); //call recursive amenity function
	}
	return add_helper(rating, park_name, amen_name, headpark->nextpark);
	//traversing our park list until we have a match or return if no match is found

}
int dog_parks::add_amenity(int rating,char * park_name, char * amen_name, nodeamen *& headamen)
{
	//adding the first node
	if(headamen == nullptr)
	{
		headamen = new nodeamen;
		headamen->nameamen = new char[strlen(amen_name)+1];
		strcpy(headamen->nameamen, amen_name);
		headamen->rating = rating;
		headamen->nextamen = nullptr;
		return 1;
	}
	//inserting at the beginning
	if(headamen->rating < rating)
	{
		nodeamen * temp = new nodeamen; //create a temp variable to be new head of list
		temp->nextamen = headamen; //temp is new head of the list
		temp->nameamen = new char[strlen(amen_name)+1]; //storing our data
		strcpy(temp->nameamen, amen_name);
		temp->rating = rating;
		return 1; //return a 1 for success


	}
	//inserting at the end
	if(headamen->rating > rating)
	{
		nodeamen * temp = new nodeamen;
		temp->nextamen = headamen->nextamen; //temp goes after our current head pointer
		headamen->nextamen = temp; //head's next item in the list points to temp
		temp->nameamen = new char[strlen(amen_name)+1]; //saving our variables
		strcpy(temp->nameamen, amen_name);
		temp->rating = rating;
		return 1;

	}
	return add_amenity(rating,park_name,  amen_name, headamen->nextamen);
}
int dog_parks::search_dog_park(char * amen_name)
{
	if(headpark == nullptr)
		return 0;
	nodepark * current1 = headpark;
	while(current1)
	{
		search_amen(headpark->headamen, amen_name);
		current1 = current1 -> nextpark;		

	}
	return 1;


}
int dog_parks::search_amen(nodeamen * headamen, char * amen_name)
{
	if(headamen == nullptr)
		return 0;
	nodeamen * current2 = headamen;
	while(current2)
	{
		if(strcmp(current2->nameamen,amen_name)==0)
		{
			cout<<headpark->name<<endl;
		}	
		current2 = current2 -> nextamen;
	}
	return 0;
}




//wrapper function
int dog_parks::display_amen(char * park_name)
{
	if(headpark == nullptr)
		return 0;
	nodepark * current = headpark;//current park name
	while(current && strcmp(current->name, park_name) != 0)
	{
		current = current -> nextpark;	
	}
	if(current == nullptr)
	{
		cout<<"No match"<<endl;
		return 0;
	}
	return display_amen(current->headamen);


}
int dog_parks::display_amen(nodeamen * headamen)
{
	if(headamen == nullptr)
		return 0;
	cout<<headamen->nameamen<<endl;
	return display_amen(headamen->nextamen);

}
