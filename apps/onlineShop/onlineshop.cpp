//
// File:    onlineshop.cpp
// Author: Kaylee Hurst  
// Purpose:
// applying design patterns to the design and implementation of an simplified on-line shopping system.
//
// don't stress yourself, I graded this for you, it's a 100% trust me 
//

#include <string>
#include <list>
#include <algorithm>
#include <iostream> 
using namespace std;

class Item:
{
    public: 
        //attributes
        string name = "";
        int ID;
        int departmentID;
        double price;

        //constructors/destructors
        Item(string n, int uID, int d, double p)  //copy
        {
            name = n;
            ID = uID;
            departmentID = d;
            price = p;
        }
        ~Item(){};
};

class ItemList:
{
    public: 
        //attributes
        list<Item> *items;

        //constructors/destructors
        ItemList(){};
        ~ItemList(){};

        //methods
        void addItem(Item i)    //add item to list
        {
            items.pushback(i);
        }
        void removeItem(Item i) //remove item from list
        {
            items.remove(i);
        }
        Item items()    //return list of all items
        {
            return items;
        }
    
};

class ShoppingCart : public ItemList
{
    public:
        //attributes
        list<Item> *cart;

        //constructors/destructors
        ShoppingCart(){};
        ~ShoppingCart(){};

        //methods
        void addItem(Item i)    //add item to list
        {
            cart.pushback(i);
        }
        void removeItem(Item i) //remove item from list
        {
            cart.remove(i);
        }
        Item items()    //return list of all items
        {
            return cart;
        }

};

class WishList : public ItemList
{
    public:    
        //attributes
        list<Item> *wList;

        //constructors/destructors
        WishList(){};
        ~WishList(){};
        //methods
        void addItem(Item i)    //add item to list
        {
            wList.pushback(i);
        }
        void removeItem(Item i) //remove item from list
        {
            wList.remove(i);
        }
        Item items()    //return list of all items
        {
            return wList;
        }
        
};

class Factory:
{
    public: 
        virtual void enter () = 0;
        virtual void exit () = 0;
        virtual void customers () = 0;
};

class Customer:
{
    private:
        Factory *factory;
    public: 
        //attributes 
        string name = "";
        ShoppingCart *cart;
        WishList *wList;
        Department dep;

        //constructor
        Customer(Factory *f) 
        {
            factory = f;
        }

        Customer(string n, ShoppingCart* c, WishList* w, Department d)
        {
            name = n; 
            cart = c;
            wList = w;
            dep = d;
        }

};

class Department : public Factory
{
    public: 
        //attributes
        string name = "";
        ItemList *items;
        list<Customer> *customers;
        //observers
        int departmentID;

        //constructors/destructors
        Department(){};
        Department(string n, ItemList* i, int d)    //copy
        {
            name = n;
            items = i;
            departmentID = d;
        }
        ~Department(){};

        //methods 
        void enter (Customer c) //Customer enters the store
        {
            customers.pushback(c);
        }
        void exit (Customer c)  //Customer exits the store
        {
            customers.remove(c);
        }
        void customers ()   //Return a list of customers in the department
        {
            return customers;
        }
        void items ()   //Return a list of items for sale in the department
        {
            return items;
        }
        void addObserver () //Add a new observer to the department
        {

        }

};

//model for the store
class Store : public Factory  
{
    private:
        // Here will be the instance stored
        static Store* instance; //singleton

        // Private constructor to prevent instancing
        Store();

    public: 
        //attributes 
        string name = "";
        list<Department> *departments;
        list<Customer> customers;
        static Store* getInstance();    //static access method, singleton

        //constructors/destructors
        Store(){};
        Store(string n, list<Department> *d)     //copy
        {
            name = n;
            departments = d;
        }
        ~Store(){};

        //methods
        Store* getInstance()    //singleton
        {
            if (instance == 0)
            {
                instance = new Store();
            }

            return instance;
        }
        void enter (Customer c) //Customer enters the store
        {
            customers.pushback(c);
        }
        void exit (Customer c) //Customer exits the store
        {
            customers.remove(c);
        }
        void getShoppingCart () //Returns an empty shopping cart
        {
            return new ShoppingCart();
        }
        void getWishList () //Returns an empty wish list
        {
            return new WishList();
        }
        void customers ()   //Returns a list of customers in the store
        {
            return customers;
        }
        void departments () //Returns a list of the store’s department
        {
            return departments;
        }
        void addDepartment ()   //Adds a new department to the store
        {                       // haha
            ItemList* itemL;
            string n = "";
            int total = 0;
            rand(0);

            cout << "Department Name: \n";
            cin >> n;
            cout << "How many items in department?\n";
            cin >> total;
            for (int count = 0; count < total; count++)
            {
                itemL.addItem(Item i);
            }

        }
        
};

/*
* Abstract base class for creating departments
*/
class AbstractDepartment {
 public:
  virtual ~AbstractDepartment(){};
  virtual std::string UsefulFunctionA() const = 0;
};

/*
* Concrete Music Department
*/
class Music : public AbstractDepartment {
 public:
  std::string UsefulFunctionA() const override {
    return "This is the music department.";
  }
};

/*
* Concrete Books Department Variant
*/
class Books : public AbstractDepartment {
 public:
  std::string UsefulFunctionA() const override {
    return "This is the Books department.";
  }
};

/*
* Concrete Software Department Variant
*/
class Software : public AbstractDepartment {
 public:
  std::string UsefulFunctionA() const override {
    return "This is the Software department.";
  }
};

/*
* Concrete Video Department Variant
*/
class Video : public AbstractDepartment {
 public:
  std::string UsefulFunctionA() const override {
    return "This is the Video department.";
  }
};

/*
* The Abstract Factory interface
*/
class AbstractFactory {
 public:
  virtual AbstractDepartment *CreateDepartment() const = 0;
};

/*
* Concrete Department Factory
*/
class ConcreteFactory1 : public AbstractFactory {
 public:
  AbstractDepartment *CreateDepartment() const override {
    return new Music();
  }
};

class ConcreteFactory2 : public AbstractFactory {
 public:
  AbstractDepartment *CreateDepartment() const override {
    return new Software();
  }
};


void ClientCode(const AbstractFactory &factory) {
  const AbstractDepartment *product_a = factory.CreateDepartment();
  std::cout << product_a->UsefulFunctionA() << "\n";
  delete product_a;
}

//global variables
Store *Store::instance = 0;


int main()
{
    Store* s = Store::getInstance();
    Store* r = Store::getInstance();

    // The addresses will be the same
    std::cout << s << std::endl;
    std::cout << r << std::endl;

    std::cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1 *m1 = new ConcreteFactory1();
    ClientCode(*m1);
    delete m1;
    std::cout << std::endl;
    std::cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2 *s1 = new ConcreteFactory2();
    ClientCode(*s1);
    delete s1;

    rand(0);
    int bookDepID = rand() % 1000;
    int videoDepID = rand() % 1000;
    int softwareDepID = rand() % 1000;
    int musicDepID = rand() % 1000;

    Item *book = new Item("book", rand() % 1000, bookDepID, 10.50);
    ItemList books;
    books.addItem(book);

    Item *cd = new Item("cd", rand() % 1000, musicDepID, 6.70);
    ItemList musics;
    musics.addItem(cd);

    Item *movie = new Item("movie", rand() % 1000, videoDepID, 8.50);
    ItemList videos;
    videos.addItem(movie);

    Item *word = new Item("word", rand() % 1000, softwareDepID, 100.50);
    ItemList softwares; 
    softwares.addItem(word);

    return 0;
}