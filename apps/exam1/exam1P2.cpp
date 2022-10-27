//
// File:    exam1P2.cpp
// Author: Kaylee Hurst  
// Purpose:  given a const reference to one of these structures, returns a hash created by first 
// finding hashes h1, h2, and h3 of each of the fields in the structure, and then computes a hash for the structure
// and a function that accepts a reference to a list of S structures and returns a
//  reference to a list of size_t values with hashes for each of the S structures.
//

#include <string>
#include <list>
#include <iterator>
using namespace std; 

size_t& getHash(list<S> *);

struct S {
   string firstName;
   string lastName;
   string customerId;

  bool operator==(const &rhs) {
     return this.customerID == rhs.customerID;
  }
};

auto hashValue = [](const S *custInfo) -> size_t
{
    std::hash<string> myHash;
    auto h1 = myHash(custInfo.firstName);
    auto h2 = myHash(custInfo.lastName);
    auto h3 = myHash(custInfo.customerId);

    return (h1 ^ (h2 << 1) ^ (h3 << 4));
}

size_t& getHash (list<S> *listOfStructs)
{
    list<size_t> *hashPtr = new list<size_t>;
    for (list<S>::iterator it = listOfStructs.begin(); it != listOfStructs.end(); ++it)
    {
        hashes.pushback(hashValue());
    }

    return (hashPtr);
}