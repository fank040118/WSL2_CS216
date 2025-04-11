/* File: autocomplete.cpp
 * Course: CS216-005
 * Project: Project 2
 * Purpose: the implementation of member functions for the class named Autocomplete.
 *
 */
#include <iostream>
#include "autocomplete.h"

using namespace std;

// default constructor
Autocomplete::Autocomplete()
{
    // You can leave it blank
    // since the private data member terms has been initialized through default constructor of SortingList class 
}


// inserts the newterm to the sequence
// note that a SortingList<Term> object, named terms
//          represents the sequence
void Autocomplete::insert(Term newterm)
{
    terms.insert(newterm);
}


// sort all the terms by query in the lexicographical order  
void Autocomplete::sort()
{
    terms.std_sort();
}

// binary search helper function
// as private function
// since it serves binary_search member function only
int Autocomplete::binary_searchHelper(SortingList<Term> terms, string key, int left_index, int right_index)
{
    if(right_index < left_index)
    {
        int KEY_NOT_FOUND = -1;
        return KEY_NOT_FOUND;
    }
    else
    {
        Term keyterm(key, 0);
        int r = key.length();
        int middle = (left_index + right_index) / 2;
        if(Term::compareByPrefix(keyterm,terms[middle],r) > 0)
        {
            return binary_searchHelper(terms, key, left_index, middle - 1);

        }
        else if(Term::compareByPrefix(keyterm,terms[middle],r)  < 0)
        {
            return binary_searchHelper(terms, key, middle + 1, right_index);
        }
        else
        {
            return middle;
        }
    }
}

// return the index number of the term whose query 
// prefix-matches the given prefix, using binary search algorithm
// Note that binary search can only be applied to sorted sequence
// Note that you may want a binary search helper function
int Autocomplete::binary_search(string prefix)
{
    return binary_searchHelper(terms, prefix, 0, terms.size()-1);
}

// first: the index of the first query whose prefix matches
//          the search key, or -1 if no such key
// last: the index of the last query whose prefix matches 
//         the search key, or -1 if no such key
// key: the given prefix to match
// hints: you can call binary_search() first to find one matched index number,
//        say hit, then look up and down from hit, to find first and last respectively
void Autocomplete::search(string key, int& firstIndex, int& lastIndex)
{
    // set first and last Index to -1 as default
    firstIndex = -1;
    lastIndex = -1;

    // search a key by binar_search, if no key term found, return
    int hit = binary_search(key);
    if (hit == -1){return;}

    // if a key was found, set firstIndex and lastInde = hit
    firstIndex = hit;
    lastIndex = hit;
    // create a keyterm to compare for to the terms
    Term keyterm(key, 0);
    // set the length of prefix to the length fo current key length
    int r = key.length();
    
     
    while(firstIndex > 0 && Term::compareByPrefix(keyterm, terms[firstIndex-1], r) == 0){
        firstIndex --;
    }
    
    while(lastIndex < terms.size()-1 && Term::compareByPrefix(keyterm, terms[lastIndex+1], r) == 0){
        lastIndex ++;
    }
    
}

// returns all terms that start with the given prefix, in descending order of weight
SortingList<Term> Autocomplete::allMatches(string prefix)
{
    // create first, last Index
    int firstIndex, lastIndex;
    // use search function to change first, last index to vaild index
    search(prefix, firstIndex, lastIndex);
    // create a result terms
    SortingList<Term> resultTerm;
    // if first or last Index == -1, the index is not vaild, return empty terms
    if (firstIndex == -1 || lastIndex == -1){return resultTerm;}
    // else, add all term from terms to the result term
    for(int i = firstIndex; i <= lastIndex; i++){
        resultTerm.insert(terms[i]);
    }
    // sort terms by descending order of weight
    resultTerm.selection_sort(Term::compareByWeight);
    return resultTerm;
}

void Autocomplete::print()
{
    terms.print();
}
