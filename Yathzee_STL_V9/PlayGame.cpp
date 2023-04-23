//System Libraries
#include<iostream>
#include <string>
#include<iomanip>
#include<stack>
using namespace std;
//User Libraries
#include "PlayGame.h"
void menu() {
    //Display menu
    cout << "******************************************" << endl;
    cout << setw(23) << "YAHTZEE" << endl;
    cout << "******************************************" << endl
        << endl;
    cout << "1 .Play Game" << endl;
    cout << "2. Display Rules" << endl
        << endl;
    cout << "Make your selection ";
}
void playGame(map<int, Dice>& d, set<Players>& p, list<Scorecard>& s, list<int>& a) {
    // Game variables
    int round = 0;
    int place = 0;
    int ply = 0;
    //setting up the number of players and there names
    getPlayers(ply);
    getName(p, s, ply);
    cout << "The order of player turns" << endl;
    print(p);
    // start the the Game of 13 rounds, outputs players turn each time and randomly generates a new between 1-6 for all dice
    while (round < 2)
    {
        list<Scorecard>::iterator i = s.begin();
        for (auto j = p.begin(); j != p.end(); j++) {
            cout << j->getNames() << "'s turn" << endl << endl;
            //Genearte random values for the map (dice roll)
            getVal(d); 
            //displays dice roll and prompts user for which dice to re-roll
            reRoll(d,a); 
            //prompts the players to assignes scores to proper catagory on the scorecard
            getScores(s, a, i, j);
            i++;
        }
        round++;
    }
    stack<int> scores;
    stack <string> names;

    calScore(s,scores,names,p);
    finalScore(s, p);
    winner(scores,names);
    //end of game
}
void winner(stack<int>& s, stack<string>& p) {
    //temporary values to store for comparison
    int max = 0;
    int temp = 0;
    string winPly;
    string tempPly;
    //comparing valus to return winning score
    while (!s.empty() && !p.empty())
    {
        temp = s.top();
        tempPly = p.top();
        if (temp > max)
        {
            max = temp;
            winPly = tempPly;
        }
        s.pop();
        p.pop();
    }
    cout << "Gongradualtions: " << winPly << " you won, Winning score: " << max << endl;
}
