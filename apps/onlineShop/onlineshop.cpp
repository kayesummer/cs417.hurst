//
// File:    onlineshop.cpp
// Author: Kaylee Hurst  
// Purpose:
// backend for an online shop
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
        string departmentID = "";
        double price;

        //constructors/destructors
        Item()
        {

        }
        Item()  //copy
        {

        }
        ~Item()
        {

        }
};

class ItemList:
{
    public: 
        //attributes
        list<Item> *items;

        //constructors/destructors
        ItemList()
        {

        }
        ItemList()  //copy
        {

        }
        ~ItemList()
        {

        }

        //methods
        void addItem(Item i)
        {
            //add item to list
        }
        void removeItem(Item i)
        {
            //remove item from list
        }
        Item items()
        {
            //return list of all items
        }
    
};

class ShoppingCart : public ItemList
{
    public:
        //attributes


        //constructors/destructors
        ShoppingCart()
        {

        }
        ShoppingCart()  //copy
        {

        }
        ~ShoppingCart()
        {

        }

};

class WishList : public ItemList
{
    public:    
        //attributes


        //constructors/destructors
        WishList()
        {

        }
        WishList()  //copy
        {

        }
        ~WishList()
        {

        }
        
};

class Customer:
{
    public: 
        //attributes 
        string name = "";
        ShoppingCart *cart;
        WishList *wList;
        Department *dep;

        //constructors/destructors
        Customer()
        {

        }
        Customer()  //copy
        {

        }
        ~Customer()
        {

        }
};

class Department:
{
    public: 
        //attributes
        string name = "";
        ItemList *items;
        list<Customer> *customers;
        //observers
        string departmentID = "";

        //constructors/destructors
        Department()
        {

        }
        Department()    //copy
        {

        }
        ~Department()
        {

        }

        //methods 
        void enter ()
        {

        }
        void exit ()
        {

        }
        void customer ()
        {

        }
        void items ()
        {

        }
        void addObserver ()
        {

        }

};

//model for the store
class Store:   
{
    private:
        /* Here will be the instance stored. */
        static Store* instance;

        /* Private constructor to prevent instancing. */
        Store();

    public: 
        //attributes 
        string name = "";
        list<Department> *departments;
        list<Customer> *customers;
        static Store* getInstance();    //static access method

        //constructors/destructors
        Store()
        {

        }
        Store()     //copy
        {

        }
        ~Store()
        {

        }

        //methods
        Store* getInstance()
        {
            if (instance == 0)
            {
                instance = new Singleton();
            }

            return instance;
        }
        void enter ()
        {

        }
        void exit ()
        {

        }
        void getCart ()
        {

        }
        void wishList ()
        {

        }
        void customers ()
        {

        }
        void departments () 
        {

        }
        void addDepartment ()
        {

        }
        
};

//global variables
Store *Store::instance = 0;


int main()
{
    Store* s = Store::getInstance(); // Ok
    Store* r = Store::getInstance();

    /* The addresses will be the same. */
    std::cout << s << std::endl;
    std::cout << r << std::endl;
    return 0;
}