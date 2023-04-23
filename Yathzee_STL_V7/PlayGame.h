#ifndef PLAYGAME_H
#define PLAYGAME_H
#include <iostream> //Input - Output Library
#include <map>      //Map Library
#include<set>		//Set Library
#include <list>

//User Libraries
#include "Player.h"
#include "Dice.h"
#include "Scorecard.h"
//Function Prototypes
void menu();
//Function the runs the yahtzee game
void playGame(map<int, int>&, set<Players>&,list<Scorecard>&,int []);
//getscores from the player based on dice rolled
void getScores(list<Scorecard>&, int[], list<Scorecard>::iterator, set<Players>::iterator);
//Functions for calculate scorecard for each category
void calScore(list<Scorecard>&);
//Displays scorecard with real time updated scores 
void card(list<Scorecard>&, list<Scorecard>::iterator);
//Functions to calculate final score for reach player 
void finalScore(list<Scorecard>&, set<Players>&);
//getting names
void getPlayers(int&);
void getName(set<Players>&, list<Scorecard>&, int&);
//printing names
void print(set<Players>&);



#endif /* PLAYGAME_H */

