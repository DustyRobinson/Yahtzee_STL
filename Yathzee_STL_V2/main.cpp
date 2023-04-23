/*
 * File:   main.cpp
 * Author: Steven Contreras
 *
 * Created on April 16, 2023 11:52 AM
 * Purpose: Yahtzee Version V2
 */
 //System Libraries
#include<iostream>
#include<iomanip>
#include<string>
#include<set> //unordered set

using namespace std;
//User Libraries

//Global Constants - Math/Physics/Chemistry/Conversions/Higher Dimensions

//Function Prototypes
void menu();
void getName(set<string>&);
void print(set<string>&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the Random number seed

   //Delcare values
    set<string> players;
    //Initialize Variables
    menu();
    //Map Input to the Outputs - Process
    getName(players);
    //Display output
    print(players);
    return 0;
}
void menu() {
    cout << "******************************************" << endl;
    cout << setw(23) << "YAHTZEE" << endl;
    cout << "******************************************" << endl
        << endl;
    cout << "1 .Play Game" << endl;
    cout << "2. Display Rules" << endl
        << endl;
    cout << "Make your selection " << endl;
}
void getName(set<string>& n) {
    //get the number of players in the game
    cout << "Please enter the numbner of players: ";
    int size = 0;
    cin >> size;
    cin.ignore();
    //get the names of the players
    string name;
    for (int i = 0; i < size; i++) {
        cout << "Enter Player " << i + 1 << ": ";
        getline(cin, name);
        n.emplace(name);
    }
}
void print(set<string>& n) {
//display names
    int i = 1;
    for (auto it = n.begin(); it != n.end(); it++, i++) {
        cout << "Player " << i << ": " << *it << endl;
    }
}

