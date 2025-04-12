/*
 * Course: CS216-002
 * Project: Project2
 * Purpose: repeatedly ask the user to type prefix to match
 *          and generate all the prefix-matched terms 
 *          then display the prefix-matched terms in descending order by weight.
 * Editor: Anthony Wang
 * Last edited date: 4/12/2025
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "term.h"
#include "SortingList.h"
#include "autocomplete.h"

using namespace std;

int main(int argc, char** argv) {
    const int ARGUMENTS = 2;
    
    // check the command line argument, an input file name and a number is needed
    if (argc != ARGUMENTS+1)
    {
        cout << "need exactly " << ARGUMENTS << " command line arguments." << endl;
        cout << "Usage: " << argv[0] << " <filename>" << " number" << endl;
        return 1;
    }    
    
    // check if the input file can be opened successfully
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.good())
    {
        cout << "Warning: Cannot open the file named " << argv[1] << endl;
        return 2;
    }

    // check if the input number is vaild
    const int user_rows = stoi(argv[2]);
    if (user_rows <= 0){
        cout << "Warning: the number of matching terms needs to be a positive number!" << endl;
        return 3;
    }

    //_________________________________________________________________________________
    
    // read in the terms from the input file
    // line by line and store into Autocomplete object
    Autocomplete autocomplete;
    long weight;
    string query;
    
    while (!infile.eof())
    {
        infile >> weight >> ws;
        getline(infile, query);
        if (query != "")
        {    
            Term newterm(query, weight);
            autocomplete.insert(newterm);
        }    
    } 
    
    autocomplete.sort();

    // print welcome info
    cout << "*******       Enjoy CS216 search engine!       *******" << '\n'
         << "*******          You Autocomplete Me           *******" << endl;
    cout << "Please input the search query (type \"exit\" to quit): " << endl;
    // ask for prefix
    string input;
    string prefix;
    getline(cin, input);
    prefix = input;

    while (prefix != "exit")
    {

        SortingList<Term> matchedTerms = autocomplete.allMatches(prefix);

        if (matchedTerms.size() == 0)
        {    
            cout << "No matched query!" << endl;
        }
        else{
            // check if the size of rows in matched terms is smaller than the argv[2]
            // if it is, change the display_rows to size of matched terms
            int display_rows;
            if (matchedTerms.size() < user_rows){display_rows = matchedTerms.size();}
            else{display_rows = user_rows;}
            // print all the matched terms in fisrt display_rows rows
            for(int i = 0; i < display_rows; i++){
                cout << matchedTerms[i] << endl;
            }
        }

        // repeatly ask for prefix
        cout << "*******       Enjoy CS216 search engine!       *******" << '\n'
             << "*******          You Autocomplete Me           *******" << endl;
        cout << "Please input the search query (type \"exit\" to quit): " << endl;
        getline(cin, input);
        prefix = input;
    }

    // print exit info
    cout << "Thank you for using \" You Autocomplete Me \" engine in CS216!" << '\n'
         << "It is written by Anthony Wang in CS216 Section 002." << endl;

    return 0;
}

