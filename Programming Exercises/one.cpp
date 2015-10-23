/* 1. Provide method definitions for the class described in Chapter Review Question 5
and write a short program that illustrates all the features. */



#include <iostream>
#include <string>
#include "math.h"

using namespace std;
 class BankAccount 
{ 
private:
string name;
string accountno;
double balance;

public:
BankAccount ()
{
name="no_name";
balance=0;
accountno="no_number";
}
string getname ()
{ return name;
}
string getaccountno ()
{ return accountno;
}
double getbalance ()
{ return balance;
}
void setname (string n)
{name=n;
}
void setaccountno (string x)
{accountno=x;
}
void deposit (double d)
{if(d>0)
balance=balance+d;
}
void withdraw(double w)
{ if(balance>w)
balance=balance-w;
}
};
 void main ()
{ 
 BankAccount x;
 
 cout<<x.getname()<< "\n";
 cout<<x.getaccountno()<< "\n";
 cout<<x.getbalance()<< "\n";

 x.setname("Diana");
 x.setaccountno ("1234");
 x.deposit(500);
 x.withdraw(60);

 cout<<x.getname()<< "\n";
 cout<<x.getaccountno()<< "\n";
 cout<<x.getbalance()<< "\n";

}