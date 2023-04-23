#ifndef DICE_H
#define DICE_H
#include<map>
#include<list>
#include<iostream>
using namespace std;
const int DIE_SIZE = 5;

void getVal(map<int, int>&);
//function for displaying dice roll  
void roll(map<int, int>&);
//Function for re-rolling dice  
void reRoll(map<int, int>&, list<int>&);
//function for total dice values  
int result(list<int>&, int);
//function for a full house 
int full(list<int>&);
//function for a small straight 
int small(list<int>&);
//function for a large straight
int large(list<int>&);
//function for a getting max frequency if dice values selected defined 
int maxFreq(list<int>&);
//function for a total all dice values selected 
int product(list<int>&);
#endif /* DICE_H */

