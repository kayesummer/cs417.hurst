//
// File:    shopiterator.h
// Author: Kaylee Hurst  
// Purpose:
// iterator pattern for the online shop
//

#include <string>
#include <list>
#include <algorithm>

class Item:
{
    public: 
        //attributes
        std::string name = "";
        int ID;
        std::string departmentID = "";
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
        std::list<Item> *items;

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
        std::string name = "";
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
        std::string name = "";
        ItemList *items;
        std::list<Customer> *customers;
        //observers
        std::string departmentID = "";

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
    public: 
        //attributes 
        std::string name = "";
        std::list<Department> *departments;
        std::list<Customer> *customers;

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

