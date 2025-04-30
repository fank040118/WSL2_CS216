/*
 *course: CS216-002
 *Project: Lab 12
 *Purpose: to demonstrate a simple Word Ladder, using four-letter words as examples 
 *         create a graph from reading the collection of words in an input file
 *         each vertex is labeled with a four-letter word. If two words are only different by a single letter, there is an edge between them.
 *         repeatedly ask the user to choose a source vertex(word1), then a destination vertex(word2) (type enter to quit)
 *         and calculate how many steps of the "Word Ladder" from word1 to word2, 
 *         which is the distance of the shortest path from the source to the destination in the Graph
 *         then display the "Word Ladder" from word1 to word2, which is
 *         the shortest path from the source to the destination in the Graph
 *Author: Anthony Wang
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <algorithm>     // for transform() function
#include "Graph.h"

using namespace std;

// declare global variable (constant only)
const int ARGUMENTS = 1;   // define the required command line arguments

// define a function to decide the collection of edges for a graph
// using "Word Buckets Approach"
Graph<string> WordBuckets_addEdges(const vector<string>& words);

int main(int argc, char* argv[])
{
    // Check whether the number of command line arguments match the required one 
    if (argc != ARGUMENTS+1)
    {
        cout << "Warning: need exactly " << ARGUMENTS << " command line argument." << endl;
        cout << "Usage: " << argv[0] << " inputfile_name" << endl;
        return 1;
    }

    ifstream in_file;
    in_file.open(argv[1]);
    // Check whether the input file can be open successfully or not
    if (!in_file.good())
    {
        cout << "Warning: cannot open file named " << argv[1] << "!" << endl;
        return 2;
    }
    
    // Read data from the input file, assume "good data" from the input file
    // each line of the input file constains one four-letter word from English dictionary
    string word;
    vector<string> words;

    while (in_file >> word)
    {
        // convert word to all lower-case letters
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }
    // close the input file
    in_file.close();

    // build the graph based on the collection of words
    // each word in the collection represents a Vertex in the graph
    // there is an edge from one word to another if these two words are only different by a single letter
    Graph<string> wordsG = WordBuckets_addEdges(words);

    string word1, word2;

    while (true)
    {
        cout << endl << endl;
        cout << "Welcome to CS216 Word Ladder!" << endl;
        cout << "Please give me two English words, and I will convert the first into the second by modifying one letter at a time." << endl;
        cout << "For the Demo purpose, let us try four-letter words only." << endl;
        cout << "Please type the FIRST four-letter word (or type Enter to quit): " << endl;
	    getline(cin, word1);
        
        if (word1 == "")
            break;
        
        cout << "Please type the SECOND four-letter word (or type Enter to quit): " << endl;
	    getline(cin, word2);
        
        if (word2 == "")
            break;

        // convert both word1 and word2 to all lower-case letters
        transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
        transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

        map<string,int> distance;
	    map<string, string> go_through;
        int dis = wordsG.BFS(word1, word2, distance, go_through);
        // Display the ladder distance from word1 to word2
        // Display the shortest path on the word ladder from word1 to word2
        // the ladder distance is defined as the number of edges on the shortest path from one vertex to another
        // the ladder distance of the same vertex to itself is 0 
        // if word1 and word2 are the same word, your program should display "Two words should be different." 
        // there is no path from word1 to word2 if its ladder distance is -1
        // there is no path from word1 to word2 if its ladder distance is -2, which means either word1 or/and word2 is invalid
        if ( dis == NOPATH || dis == INVALID_VERTEX)
            cout << "There is no path from [" << word1 << "] to [" << word2 << "]" << endl;
        else if ( dis == 0)
        {
            cout << "Two words should be different." << endl;
        }
        else
        {
            cout << "The ladder distance from [" << word1 << "] to [" << word2 << "] is " << dis << "-step away." << endl;
            cout << "A ladder from [" << word1 << "] to [" << word2 << "]:" << endl;
            // your code starts here...

            stack<string> path; // create a stack to reverse path to word1 to word2
            string currentWord = word2; // push word2 as the last element to path
            while(currentWord != word1){
                path.push(currentWord);
                currentWord = go_through[currentWord];  // push whole path from word2 to word1 into stack
            }
            path.push(word1); // push word1 into stack

            cout << path.top(); // print word1 first
            path.pop();
            while(!path.empty()){ // while path != empty, print path till word2
                cout << " ---> " << path.top();
                path.pop();
            }  
            cout << endl;
        }   
    }

    cout << "Thank you for using this program, bye..." << endl;
    return 0;
}

/* define a function to decide the collection of edges for a graph
 * using "Word Buckets Approach"
 * Purpose: build a graph based on the collection of vertices
 *          each word stored in the vector, represents a Vertex in the graph
 *          there is an edge from one word to another 
 *          if these two words are only different by a single letter
 *@param words vector<string>: representing the collection of vertices, each string stored in the vector forms a vertex
 *@return Graph<string>: representing the graph built by
 *                       (1) the collection of vertices from words;
 *                       (2) the collection of edges are decided by if any two words are only different by a single letter
 *                         e.g. there is an edge between "cool" and "pool", but there is no edge between "cool" and "poll"
 *
 */
Graph<string> WordBuckets_addEdges(const vector<string>& words)
{    
    // build the graph
    // there is an edge from one word to another if the two words are only different by a single letter.
    // use "Word Bucket" solution described in Lab12 to efficiently decide whether an edge between two vertices
    Graph<string> wordsG;
    // decide how many letters in each word
    int wordLength = words[0].length();

    // work on each character position
    // replace with possible a, b..,z
    for (int i=0; i < wordLength; i++)
    {
        // remove one character in specified position, computing representative
        // words with same representatives are adjacent; so first populate a map...
        map<string, set<string> > repBucket;
        for (size_t j=0; j < words.size(); j++)
        {
            string rep = words[j];
            rep[i] = '?';
            repBucket[rep].insert(words[j]);
        }

        // and then create a Graph by adding edges among words in the same representative bucket
        for (auto it = repBucket.begin(); it != repBucket.end(); it++)
        {
            set<string> oneBucket = it->second;
            for (auto itr1 = oneBucket.begin(); itr1 != oneBucket.end(); itr1++)
            {    
                for (auto itr2 = oneBucket.begin(); itr2!= oneBucket.end(); itr2++)
                {
                    if (*itr1 != *itr2)
                    {
                        wordsG.addEdge(*itr1, *itr2);
                    }
                }
            }
        }      
    }
    return wordsG;
}

