### Theoritical Questions

##### 1. What is a class?
A class is a C++ vehicle for translating an abstraction to a user-defined type. It combines data representation and methods for manipulating that data into one neat package.

##### 2. How does a class accomplish abstraction, encapsulation, and data hiding? 
The class has 2 interfaces, the public interface where we can perform operations on the class objects. Which is abstraction.
The other interface is the private one where data in it can’t be accessed except by the functions. Which is data hiding.
Encapsulation is done by the details of implementing a class, the data representation and the methods.

##### 3. What is the relationship between an object and a class? 
The object is the fundamental data unit of the class.
The class defines a new type. And by declaration, it enables you to declare variables, called objects.
The class is binding of data and methods in a single unit, and creating an object in the class will allow us to use the methods and rules in the class.

##### 4. In what way, aside from being functions, are class function members different from class data members?
By creating objects in the class, each object has its own data members different from the data of another object. But the class function members is the same for any object in the class, all objects use same methods. 
The data members are private, but the functions are public.

##### 5. Define a class to represent a bank account. Data members should include the depositor’s name, the account number (use a string), and the balance. Member functions should allow the following: 
- **Creating an object and initializing it.** 
- **Displaying the depositor’s name, account number, and balance** 
- **Depositing an amount of money given by an argument** 
- **Withdrawing an amount of money given by an argument** 
**Just show the class declaration, not the method implementations. (Programming Exercise 1 provides you with an opportunity to write the implementation.)**
      
        class BankAccount { 
          private:
            string name;
            string accountno;
            double balance;
          public:
            BankAccount () {
              name= no_name;
              Balance=0;
              Accountno=no_number;
            }
            string getname () { 
              return name;
            }
            string getaccountno () { 
              return accountno;
            }
            double getbalance () { 
              return balance;
            }
            void setname (string n) {
              name=n;
            }
            void setaccountno (string x) {
              accountno=x;
            }
            void deposit (double d) {
              if(d>0)
                Balance=balance+d;
            }
            void withdraw(double w) { 
              if(balance>w)
                Balance=balance-w;
            }
        };
      
##### 6. When are class constructors called? When are class destructors called?
Constructors are called when we create a new object in this class. 
Destructors are called when object is destroyed. 

##### 7. Provide code for a constructor for the bank account class from Chapter Review Question 5.
    BankAccount () { 
      name= no_name;
      Balance=0;
      Accountno=no_number;
    }

##### 8. What is a default constructor? What is the advantage of having one? 
Default constructor is the initialization way when we define an object in the class, this default constructor is called automatically and gives initial values to the object data members. We use it to save space in the memory, and to have real values not random ones.

##### 9. Modify the Stock class definition (the version in stock20.h) so that it has member functions that return the values of the individual data members. Note: A member that returns the company name should not provide a weapon for altering the array. That is, it can’t simply return a string reference. It could return a const reference. 
    class Stock {
      private:
        string company;
        int shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }
      public:
        Stock(); 
        Stock(const string & co, long n = 0, double pr = 0.0);
        ~Stock(); // do-nothing destructor
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show()const;
        const Stock & topval(const Stock & s) const;
        string returnname () {
          return company;
        }
         int sharesno () { 
          return shares;
        }
        double shareval () {
          return share _val;
        }
        double totalval() {
          return total_val;
        } 
    };

##### 10. What are this and *this?
this: is a pointer used in classes methods, it points to the address of the object.
*: points to the object data itelf.

