/* 6. Here’s a class declaration:
class Move
{
private:
double x;
double y;
public:
Move(double a = 0, double b = 0); // sets x, y to a, b
showmove() const; // shows current x, y values
Move add(const Move & m) const;
// this function adds x of m to x of invoking object to get new x,
// adds y of m to y of invoking object to get new y, creates a new
// move object initialized to new x, y values and returns it
reset(double a = 0, double b = 0); // resets x,y to a, b
};
Create member function definitions and a program that exercises the class.
*/


#include <iostream>
#include <string>
#include "math.h"

using namespace std;


class Move {
private:
double x;
double y;

public:
Move(double a = 0, double b = 0) { 
 x=a;
 y=b;
}

void showmove() const
{cout << "x is: " << x << "\n y is: " <<y << endl;
}


Move add(const Move & m) const
{ Move m1;
m1.x=m.x+this->x;
m1.y=m.y+this->y;
return m1;
}

void reset(double a = 0, double b = 0)
{x=a;
y=b;
}

};

void main ()
{
	Move m1(3,6);
	Move m2(5,8);
	m1.showmove();
	Move m3=m1.add(m2);
	m3.showmove();

}

