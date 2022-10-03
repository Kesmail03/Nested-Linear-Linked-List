#include "dogparks.h"

using namespace std;

//Khaled Esmail, cs163, 4/15/22
//This is where we will be prompting the user and passing the information to the functions to complete the tasks

int main()
{
	
	dog_parks dog_obj;//class object to call the functions
	nodeamen amen_obj;//struct object
	bool stop = true;//to run the loop
	int option = 0;
	const int SIZE = 40;
	char park_name[SIZE];//name of the dog park that we pass in
	char amen_name[SIZE];//name of the amenity that we pass in	
	int rating_copy = 0;//rating of the amenity that we pass in
	while(stop)
	{
		
		cout<<"1.Add dog park"<<endl<<"2.Display all dog parks"<<endl<<"3.Add Amenity"<<endl<<"4.Display Amenities"<<endl<<"5.Remove a dog park"<<endl
			<<"6.Search Amenity"<<endl<<"7.Quit"<<endl;
		cin >> option;
		cin.ignore(100, '\n');
		if(option == 1)
		{
			cout<<"Please enter the dog parks name"<<endl;
			cin.get(park_name, SIZE, '\n');
			cin.ignore(100, '\n');
			int count = dog_obj.add_dog_park(park_name);
			if(count == 0)
				cout<<"You entered the same name twice"<<endl;
		}
		if(option == 2)
		{
			dog_obj.display_all();
		}
		if(option == 3)
		{	         	
			cout<<"Please enter the dog parks name"<<endl;
			cin.get(park_name, SIZE, '\n');
			cin.ignore(100, '\n');
			cout<<"Please enter the amenity name"<<endl;
			cin.get(amen_name, SIZE, '\n');
			cin.ignore(100, '\n');
			cout<<"Please enter the rating of the amenity from 1-10 (10 being the best)"<<endl;
			cin >> rating_copy;
			cin.ignore(100, '\n'); 
			dog_obj.add_amenity(rating_copy, park_name, amen_name);
		}
		if(option == 4)
		{	 
			cout<<"Please enter the dog parks name"<<endl;
			cin.get(park_name, SIZE, '\n');
			cin.ignore(100, '\n');
			dog_obj.display_amen(park_name);
		}
		if(option == 5)
		{
			cout<<"Please enter the dog parks name"<<endl;
			cin.get(park_name, SIZE, '\n');
			cin.ignore(100, '\n');
			dog_obj.remove_dog_park(park_name);
		}
		if(option == 6)
		{
			cout<<"Please enter the amenity name"<<endl;
			cin.get(amen_name, SIZE, '\n');
			cin.ignore(100, '\n');
			dog_obj.search_dog_park(amen_name);
		}
		if(option == 7)
			stop = false;
		

	}
	return 0;
}
