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

	int getsize()
	{
		//INVARIANT0(getsize() <= 100);
		//int curr_size = size;
		return size;
		//INVARIANT0(getsize() == curr_size);
	}

	string getname(int i)
	{	
		INVARIANT0(getsize() <= 100);
		REQUIRE0(i <= 100);
		string curr_name = names[i];
		return names[i];
		INVARIANT0(curr_name == names[i]);
	}

	string getemail(int i)
	{
		INVARIANT0(getsize() <= 100);
		REQUIRE0(i <= 100);
		string curr_email = emails[i];
		return emails[i];
		INVARIANT0(curr_email == emails[i]);
	}

	void setname(int i, string name)
	{
		INVARIANT0(getsize() <= 100);
		REQUIRE0(findname(name)==false);
		names[i] = name;
		ENSURE0(names[i] == name);
		INVARIANT0(getsize() <= 100);
	}

	void setemail(int i, string email)
	{
		INVARIANT0(getsize() <= 100);
		REQUIRE0(findemail(email) == false);
		emails[i] = email;
		ENSURE0(emails[i] == email);
		INVARIANT0(getsize() <= 100);
	}

	int getindexname(string name)
	{

		for (int i = 0;i<size;i++)
		{
			if (names[i] == name)
			{
				return i;
			}
		}
	}

	int getindexemail(string email)
	{
		int indexemail;

		for (int i = 0;i<size;i++)
		{
			if (emails[i] == email)
			{
				indexemail = i;
				break;
			}
		}
	}

	bool findname(string name)
	{
		for (int i = 0;i < size;i++)
		{
			if (names[i] == name)
			{
				return true;
			}
			
		}
		return false;
	}

	bool findemail(string email)
	{
		for (int i = 0;i < size;i++)
		{
			if (emails[i] == email)
			{
				return true;
			}
			
		}
		return false;
	}

	void Add(string name, string email)
	{
		int curr_size = size;
		INVARIANT0(getsize() < 100);
		REQUIRE0(findname(name) == false);
		REQUIRE0(findemail(email) == false);
		names[size] = name;
		emails[size] = email;
		ENSURE0(getname(size)==name);
		ENSURE0(getemail(size) == email);
		size++;
		ENSURE0(getsize() == curr_size+1);
		ENSURE0(findname(name) == true);
		ENSURE0(findemail(email) == true);
		INVARIANT0(getsize() <= 100);
	}

	void Remove(string name)
	{
		// a simple example on removing array of numbers
		// if the array is  {1,5,3,4,2,6,7,8,9,10}
		// and its size is 10 elements
		// and i want to remove entry "2"
		// i'll find its index first through the following code segment
		INVARIANT0(getsize() <= 100);
		int curr_size=size;
		int indextoberemoved;

		REQUIRE0(findname(name) == true);

		for (int i = 0;i<=size;i++)
		{
			if (names[i] == name)
			{
				indextoberemoved = i;
				break;
			}
		}
		ENSURE0(getindexname(name)==indextoberemoved);

		// then i'll move all elements after that index backword one step
		// and with decrementing the size, this is equivalent to removing that element
		size--;
		ENSURE0(getsize() == curr_size-1);
		for (int i = indextoberemoved;i<size;i++)
		{
			names[i] = names[i + 1];
			emails[i] = emails[i + 1];
		}
		ENSURE0(findname(name) == false);
		ENSURE0(findemail(emails[indextoberemoved]) == false);
		INVARIANT0(getsize() <= 100);

	}

	void printentries()
	{
		int curr_size = size;
		INVARIANT0(getsize() <= 100);
		for (int i = 0;i<size;i++)
		{
			cout << "Entry #" << i + 1 << ":" << endl << names[i] << ": " << emails[i] << endl;
		}
		ENSURE0(getsize() == curr_size);
		INVARIANT0(getsize() <= 100);
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
