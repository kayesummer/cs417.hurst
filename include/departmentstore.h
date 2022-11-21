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
};

class ItemList:
{
    public: 
        //attributes
        std::list<Item> *items;

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

};

class WishList : public ItemList
{

};

class Customer:
{
    public: 
    
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

class Store:
{
    public: 
    //attributes 
    std::string name = "";
    std::list<Department> *departments;
    std::list<Customer> *customers;

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

