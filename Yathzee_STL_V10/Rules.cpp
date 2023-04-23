#include <iostream>
#include<string>
#include<queue>
#include "Rules.h"
using namespace std;

void RuleBook::prtRules(fstream& txt) {
    //intialize member variable
    queue<string> str;
    // opens a text from for reading in data from the file
    txt.open("Rules.txt", ios::in);
    // test if the file opens correctly
    if (!txt.is_open())
    {
        cout << "Error: Cannot open text file" << endl;
    }
    // Reads from text file if it is correctly opened
    else {
        while (!txt.eof())
        {
            // reads into a sting and displays line by line
             getline(txt, text);
             str.push(text);
        }
    }
    // close file after reading and writing to screen
    txt.close();
    //display rules
    while (!str.empty()) {
        cout << str.front();
        str.pop();
        cout << endl;
    }
}
