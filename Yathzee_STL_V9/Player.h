#ifndef PLAYER_H
#define PLAYER_H
//Libraries
#include<iostream>
#include <set>
#include <list>
using namespace std;
#include "Player.h"
#include "Scorecard.h"

class Players {
    //Protected variables
private:
    string name;
public:
    //Constructor
    Players() { name = " "; };
    Players(string n) { name = n; }
    //Muntator member functions
    void setName(string n) { name = n; }
    //Accessor member functions
     string getNames()const { return name; }
    //Overloaded ++ postfix operator defined in player.cpp
     friend bool operator< (const Players& c1, const Players& c2) { return c1.name < c2.name; };
};


#endif /* PLAYER_H */

