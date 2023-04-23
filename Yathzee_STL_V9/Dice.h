#ifndef DICE_H
#define DICE_H
#include<map>
#include<list>
#include<iostream>
using namespace std;
class Dice {
private:
    int side;
public:
    Dice() { side = 0; }
    void setSide(int s) { side = s; }
    int getSide()const { return side; }
};

void getVal(map<int, Dice>&);
//function for displaying dice roll  
void roll(map<int, Dice>&);
//Function for re-rolling dice  
void reRoll(map<int, Dice>&, list<int>&);
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

