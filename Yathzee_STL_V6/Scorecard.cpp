#include<iostream>
#include<iomanip>

using namespace std;

#include "Scorecard.h"
#include "Dice.h"

Scorecard::Scorecard() {
    //empty score card, well with -1 value
    score = -1, one = -1, two = -1, three = -1;
    four = -1, five = -1, six = -1, trip = -1;
    quad = -1, small = -1, large = -1, chance = -1;
    fHouse = -1, yazy = -1, bonus = -1;
    total = -1, upper = -1, lower = -1;
}
