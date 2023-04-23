/* 
 * File:   Dice.h
 * Author: Steven
 *
 * Created on April 19, 2023, 9:34 PM
 */

#ifndef DICE_H
#define DICE_H
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

const int DIE_SIZE = 5;

void getVal(map<int, int>&);
//function for displaying dice roll  
void roll(map<int, int>&);
//Function for re-rolling dice  
void reRoll(map<int, int>& dice, int[]);
//function for total dice values  
int result(int[], int);
//function for a full house 
int full(int[]);
//function for a small straight 
int small(int[]);
//function for a large straight
int large(int[]);
//function for a getting max frequency if dice values selected defined 
int maxFreq(int[]);
//function for a total all dice values selected 
int product(int[]);


#endif /* DICE_H */

