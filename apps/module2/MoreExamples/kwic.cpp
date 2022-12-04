//
// File:   kwic.cpp
// Author: Adam.Lewis@athens.edu
// Purpose:
// Generate key word in context information from a text.
//
// The key word in context information is stored in a map indexed by keyword
// and whose values are a list of the context strings.
//
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

list<string> wordlist;
map<string,list<string> > dictionary;
const string articles = "a an A An AN the The";
struct {
  bool noArticles = false;
  bool ignoreCase = false;
  bool dispFreq = false;
  bool ignorePunc = false;
} parms;

//
// void readWords();
// Read list of words from text input to cin.
void readWords() {
  string word;
  while ( cin >> word ) {
    // Sanitize our input string
    if (parms.ignorePunc) {
      transform(word.begin(), word.end(),
                word.begin(),
                [](char ch)
                {
                  if (ispunct(ch)){return(' ');}
                  return(ch);
                });
    }
    if (parms.ignoreCase) {
      transform(word.begin(),
                word.end(),
                word.begin(),
                ::tolower);
    }

    // Add to wordlist
    if (parms.noArticles) {
      if (articles.find(word) == string::npos) {
        wordlist.push_back(word);
      }
    }
    else {
      wordlist.push_back(word);
    }
  }
}

//
// void printList();
// Print the word list
void printWord() {
  for(list<string>::iterator ai = wordlist.begin();
      ai !=wordlist.end();
      ++ai) {
    cout << *ai << " ";
  }
  cout << endl << endl;
}

//
// void getKeyTexts()
// Generate KWIC information.
// We keep a sliding window of words that we use to build the context
// strings. 
void getKeyTexts() {
  string first,second, key, fourth, fifth;
  first = second = key = fourth = fifth = "";
  for (list<string>::iterator ai=wordlist.begin();
       ai !=wordlist.end();
       ++ai) {
    if (first!="") {
      string text = first + " " + second + " " + key + " " + fourth + " " +fifth;
      if (dictionary.count(key) > 0) {
        dictionary[key].push_back(text);
      }
      else {
        list<string> *newList = new list<string>();
        newList->push_back(text);
        dictionary[key] = *newList;
      }
    }
    first=second; second=key; key=fourth; fourth=fifth; fifth = *ai;
  }
}

//
// printKWIC()
// Print the Keyword in Context Table
void printKWIC() {
  map<string, list<string> >::iterator it = dictionary.begin();
  while (it != dictionary.end())  {
    list<string> texts = it->second;
    for (list<string>::iterator wit = texts.begin();
         wit != texts.end();
         ++wit) {
      cout << *wit << endl;
    }
    it++;
  }
}

//
// printFreqTable()
// Print a frequence table
void printFreqTable() {
  map<string,list<string> >::iterator it = dictionary.begin();
  while (it != dictionary.end()) {
    list<string> entries = it->second;
    cout << it->first << "\t" << entries.size() << endl;
    it++;
  }
}

//
// void updateParams();
// Update the parameters depending upon options passed
// from the command line.
void updateParms(int argc, char*argv[]) {
  for (int i = 0; i < argc; i++) {
    string arg(argv[i]);
    if (arg.compare("-na") == 0) {
      parms.noArticles = true;
    }
    if (arg.compare("-f") == 0) {
      parms.dispFreq = true;
    }
    if (arg.compare("-np") == 0) {
      parms.ignorePunc = true;
    }
    if (arg.compare("-lc") == 0) {
      parms.ignoreCase = true;
    }
    if (arg.compare("-h") == 0 ) {
      cout << "Usage: kwic -na -np -lc -f" << endl;
      cout << "  Read from standard input and dump either a " << endl;
      cout << "  key word in context table or frequency table"<< endl;
      cout << "  to standard output." << endl;
      cout << " Parameters:" << endl;
      cout << "  -na: Do not process articles" << endl;
      cout << "  -np: Ignore all punctuation symbols"<<endl;
      cout << "  -lc: Convert all strings to lower case"<<endl;
      cout << "  -f:  Display frequency table rather than context"<<endl;
      exit(0);
    }
  }
}

//
// main(int argc, char *argv[]);
// Process the text based on input requirements
int main (int argc, char *argv[]) {
  // Update the parameters
  updateParms(argc, argv);
  // Get words into a list and build the multimap
  readWords();
  getKeyTexts();
  // Display depending upon cmd-line optoins
  if (parms.dispFreq) {
    printFreqTable();
  }
  else {
    printKWIC();
  }
  return 0;
}