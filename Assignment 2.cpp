//Dodda htb2a mo3eeda
#include <iostream>
#include <string>
#include "dbc.h"

using namespace std; 
class Dictionary
{
private:
	string names[100];
	string emails[100];
	int size;
public:
	Dictionary()
	{
		size = 0;
	}
	void Add(string name, string email)
	{
		INVARIANT0(size<100);
		int current_size = size;
		for (int i = 0; i++; i < 100)
		{
			REQUIRE0(name != names[i]);
			REQUIRE0(email != emails[i]);

		}
		names[size] = name;
		emails[size] = email;
		size++;
		for (int i = 0; i++; i < 100)
		{
			ENSURE0(name == names[i]);
			ENSURE0(email == emails[i]);
		}
		ENSURE0(size == current_size + 1);
		INVARIANT0(size <= 100);
		
	}


	void Remove(string name)
	{
		// a simple example on removing array of numbers
		// if the array is  {1,5,3,4,2,6,7,8,9,10}
		// and its size is 10 elements
		// and i want to remove entry "2"
		// i'll find its index first through the following code segment
		INVARIANT0(size<=100);
		int indextoberemoved;

	 	for (int i = 0;i<size;i++)
		{

			if (names[i] == name)
			{
				REQUIRE0();
				indextoberemoved = i;
				break;
			}

		}
		// then i'll move all elements after that index backword one step
		// and with decrementing the size, this is equivalent to removing that element
		size--;
		for (int i = indextoberemoved;i<size;i++)
		{
			names[i] = names[i + 1];
			emails[i] = emails[i + 1];
		}
		INVARIANT0(size <= 100);
	}
	void printentries()
	{
		for (int i = 0;i<size;i++)
		{
			cout << "Entry #" << i + 1 << ":" << endl << names[i] << ": " << emails[i] << endl;
		}
	}
};



void main()
{
	Dictionary x;
	x.Add("omar", "omar@live.com");
	x.Add("hassan", "hassan@live.com");
	cout << "Before Deleting Hassan" << endl;
	x.printentries();
	x.Remove("hassan");
	cout << "After Deleting Hassan" << endl;
	x.printentries();
} 
