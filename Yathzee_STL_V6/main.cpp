/*
 * File:   main.cpp
 * Author: Steven Contreras
 *
 * Created on April 19, 2023 9:33 PM
 * Purpose: Yahtzee Version V7
 */
 //System Libraries
#include <iostream> //Input - Output Library
#include <ctime>    //Time for rand
#include <cstdlib>  //Srand to set the seed
#include <iomanip>  //Format the output
#include<string>	//String Library
#include <map>      //Map Library
#include<set>		//Set Library
#include <cctype>   //Toupper and tolower functions
#include<iomanip>	//setw()
#include <algorithm> // sort()
#include <list>

using namespace std;
//User Libraries
#include "Player.h"
#include "Dice.h"
#include "Scorecard.h"
//Global Constants - Math/Physics/Chemistry/Conversions/Higher Dimensions

//Function Prototypes
void menu();
//Displayed scorecard function
void getScores(list<Scorecard>&, int[], list<Scorecard>::iterator);
//Functions for calculate scorecard for each category
void calScore(list<Scorecard>&);
//Displays scorecard with real time updated scores 
void card(list<Scorecard>&, list<Scorecard>::iterator);
//Functions to calculate final score for reach player 
void finalScore(list<Scorecard>&);
//getting names
void getName(set<Players>&, list<Scorecard>&, int&);
//printing names
void print(set<Players>&);
//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the Random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Delcare values
    map<int, int> d;
    set<Players> n;
    list<Scorecard> s;
    int dice[5];
    //Initialize Variables
    char c = ' ';
    int size = 0;
    int sum = 0;
    //Map Input to the Outputs - Process
    menu();
    //promting for selection
    do {
        cout << "Make your selection ";
        cin >> c;
    } while (c != '1' && c != '2');

    //starting the game
    if (c == '1') {
        getName(n,s,size);
        cout << endl;
        cout << "Order of the players turn" << endl;
        print(n);
        cout << endl << "Gaming starting..." << endl << endl;
    }
    else {
        cout << "That part of the game does not exist yet, sorry " << endl;
    }
    //prompting the user for dice they want to keep
    int i = 1;
    int j = 1;
    list<Scorecard>::iterator iter = s.begin();
    while (i < 5) {
        //frist round for each player
        cout << "Round: " << i << endl;
        for (auto it = n.begin(); it != n.end(); it++, iter++) {
            cout  << it->getNames() <<"'s turns" << endl;
            getVal(d);// randomly generates a new between 1-6 for all dice
            //starting the re-roll process, up to two re-rolls for each player
            reRoll(d, dice);
            getScores(s,dice,iter);
        }
        i++;
    }
    calScore(s);
    finalScore(s);
    cout << "end of game" << endl;
    //Display the output
    //end of program
    return 0;
}

void menu() {
    //Display menu
    cout << "******************************************" << endl;
    cout << setw(23) << "YAHTZEE" << endl;
    cout << "******************************************" << endl
        << endl;
    cout << "1 .Play Game" << endl;
    cout << "2. Display Rules" << endl
        << endl;
}
void getName(set<Players>& n, list<Scorecard>& s, int& size) {
    //get the number of players in the game
    cout << "Please enter the numbner of players: ";
    cin >> size;
    cin.ignore();
    //get the names of the players
    string name;
    for (int i = 0; i < size; i++) {
        cout << "Enter Player " << i + 1 << ": ";
        getline(cin, name);
        n.emplace(name);
        s.emplace_back();
    }
}
void print(set<Players>& n) {
    //display names
    int i = 1;
    for (auto it = n.begin(); it != n.end(); it++, i++) {
        cout << "Player " << i << ": " << it->getNames() << endl;
    }
}
//function for store points earned by player by passing pointer to array of player and scorecard object and number of players
void getScores(list<Scorecard>& s, int a[], list<Scorecard>::iterator i) {
    //dispay scorecard
    card(s, i);
    //int temp value called max and bool variable set to true
    int pos = 0;
    int max = 0;
    bool tryAgn = true;
    //Start of a do while loop to check is category entered in within bounds.
    do
    {
        cin >> pos;         //choice entered by please
        switch (pos) // switch/case statement
        {
            //while statement to check if condition is true and repeats until condition is false
            while (tryAgn) {
        case 1:             //try catch statement repeated for all 13 cases
            try {
                //if value is -1 which indicates category has yet to be filled out, run functions for storing values
                if (i->getOne() < 0) {
                    //call results function and stores value returned
                    i->setOne(result(a, pos));
                    //outputs value score to verify score was received 
                    cout << "Ones: " << i->getOne() << endl;
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 2:
            try { //if value is -1 which indicates category has yet to be filled out, run functions for storing values
                if (i->getTwo() < 0) {
                    //call results function and stores value returned
                    i->setTwo(result(a, pos));
                    //outputs value score to verify score was received 
                    cout << "Twos: " << i->getTwo() << endl;
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }
                //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 3://if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (i->getThree() < 0) {
                    //call results function and stores value returned
                    i->setThree(result(a, pos));
                    //outputs value score to verify score was received 
                    cout << "Threes: " << i->getThree() << endl;
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 4: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (i->getFour() < 0) {
                    //call results function and stores value returned
                    i->setFour(result(a, pos));
                    //outputs value score to verify score was received 
                    cout << "Fours: " << i->getFour() << endl;
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 5: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (i->getFive() < 0) {
                    //call results function and stores value returned
                    i->setFive(result(a, pos));
                    //outputs value score to verify score was received 
                    cout << "Fives: " << i->getFive() << endl;
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                } //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 6: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            while (tryAgn) {
                try {
                    if (i->getSix() < 0) {
                        //call results function and stores value returned
                        i->setSix(result(a, pos));
                        //outputs value score to verify score was received 
                        cout << "Sixes: " << i->getSix() << endl;
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }//if condition is still true exceptions is thrown
                    else {
                        string taken = "You have already entered score for this category. Choose again: ";
                        throw taken;
                    }
                } //exception handler prompts user to enter again, any category
                catch (string taken) {
                    cout << taken;
                    cin >> pos;
                }
            }
            break;
        case 7: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (i->getTrip() < 0) {
                    //call max frequency function and stores value returned
                    max = maxFreq(a);
                    if (max >= 3)
                    {
                        i->setTrip(result(a, pos));
                        //outputs value score to verify score was received 
                        cout << "Triple: " << i->getTrip() << endl;
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }
                    //max frequency is less than 3, 0 points is stored
                    else {

                        i->setTrip(0);
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 8: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (i->getQuad() < 0) {
                    //call max frequency function and stores value returned
                    max = maxFreq(a);
                    if (max >= 4)
                    {
                        i->setQuad(product(a));
                        //outputs value score to verify score was received 
                        cout << "Quads: " << i->getQuad() << endl;
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }
                    //max frequency is less than 0, 0 points is stored
                    else {
                        i->setQuad(0);
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 9: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (i->getFull() < 0) {
                    //ternary operator for check for full house passed in seFull function
                    i->setFull((full(a) == 25) ? 25 : 0);
                    //outputs value score to verify score was received 
                    cout << "Full House: " << i->getFull() << endl;
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 10:   // checks to make sure the user actually has a small straight
            try { //if value is -1 which indicates category has yet to be filled out, run functions for storing values
                if (i->getSmall() < 0) {
                    //ternary operator for check for small straight passed in set small function

                    i->setSmall((30 == 30) ? 30 : 0);
                    //outputs value score to verify score was received 
                    cout << "Small Straight: " << i->getSmall() << endl;
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 11:  //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (i->getLarge() < 0) {
                    //ternary operator for check for large straight passed in set large function
                    i->setLarge((40 == 40) ? 40 : 0);
                    //outputs value score to verify score was received 
                    cout << "Large Straight: " << i->getLarge() << endl;
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                } //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 12:  //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (i->getYazy() < 0) {
                    //max frequency is greater than 4
                    max = maxFreq(a);
                    if (max >= 4)
                    {
                        //checks to see if the player already has a yazy and will add 100 if so
                        if (i->getYazy() > 0) {
                            //if player gets second yahtzee gets extra 100 points and bonus turn
                            i->setYazy(i->getYazy() + 100);
                            //outputs value score to verify score was received 
                            cout << "Yahtzee " << i->getYazy() << endl;
                            //condition set to false and breaks out of loop and switch case
                            tryAgn = false;
                        }
                        else {
                            //set 50 if first yahtzee
                            i->setYazy(50);
                            cout << "Yahtzee " << i->getYazy() << endl;
                            tryAgn = false;
                        }
                    }
                    else {
                        i->setYazy(0);
                        cout << "Yahtzee " << i->getYazy() << endl;
                        tryAgn = false;
                    }
                }  //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 13://if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (i->getChan() < 0) {
                    i->setChan(product(a));
                    //outputs value score to verify score was received 
                    cout << "Chance " << i->getChan() << endl;
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                } //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        default:
            cout << " Invalid selection: Choose again: ";
            break;
            }
        }
    } while (pos > 13 || pos < 1); // continues if player choice greater than 13/selection options
}
//function for added up all the points for each player by passing pointer to array of player and scorecard object and number of players
void calScore(list<Scorecard>& s)
{
    // Determines the final score with bonus
    for (auto i = s.begin(); i != s.end(); i++)
    {
        if ((i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix()) > 62)
        {
            //populating bonus
            i->setBonus(35);
            //totaling upper before bonus
            i->setTotal(i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix());
            //totaling upper with bonus
            i->setUpper(i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix() + i->getBon());
            //totaling lower score
            i->setLower(i->getTrip() + i->getQuad() + i->getFull() + i->getSmall() + i->getLarge() + i->getYazy() + i->getChan());
            //total the final score
            i->setScore(i->getUpper() + i->getLower());
        }
        // Determine the final score without bonus
        else if ((i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix()) <= 62)
        {
            //poputlating bonus
            i->setBonus(0);
            //totaling upper before bonus
            i->setTotal(i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix());
            //totaling upper with bonus
            i->setUpper(i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix() + i->getBon());
            //totaling lower score
            i->setLower(i->getTrip() + i->getQuad() + i->getFull() + i->getSmall() + i->getLarge() + i->getYazy() + i->getChan());
            //total the final score
            i->setScore(i->getUpper() + i->getLower());
        }
    }
}
//function for output of scorecard by passing pointer to array of player and scorecard object and number of players
void card(list<Scorecard>& s, list<Scorecard>::iterator i)
{
    cout << "Chose any empty category. Values with a -1 have yet to be filled out" << endl << endl;
    cout << " __________________________________________________________________" << endl;
    cout << "|" << setw(20) << "Player: " << "p[i].getName()" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "|" << setw(2) << "Yahtzee" << setw(15) << "Score Card" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| Upper Section                | Lower Section" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 1 - Aces:    " << i->getOne() << setw(33) << "7. 3 of a Kind : " << i->getTrip() << endl;
    cout << "| -----------------------------------------------------------------" << endl;
    cout << "| 2 - Twos:    " << i->getTwo() << setw(32) << "8. 4 of a Kind: " << i->getQuad() << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 3 - Threes:  " << i->getThree() << setw(32) << "9. Full House : " << i->getFull() << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 4 - Fours:   " << i->getFour() << setw(36) << "10. Small Straight : " << i->getSmall() << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 5 - Fives:   " << i->getFive() << setw(36) << "11. Large Straight : " << i->getLarge() << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 6 - Sixes:   " << i->getSix() << setw(28) << "12. Yahtzee: " << i->getYazy() << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 13. Chance:  " << i->getChan() << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "Category? ";
}
//outputting final score by passing pointer to array of player and scorecard object and number of players
void finalScore(list<Scorecard>& s) {
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << endl;
        cout << " __________________________________________________________________" << endl;
        cout << "|" << setw(20) << "Player: " << "p[i].getName()" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|" << setw(2) << "Yahtzee" << setw(15) << "Score Card" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Upper Section" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Aces:    " << i->getOne() << endl;
        cout << "| -----------------------------------------------------------------" << endl;
        cout << "| Twos:    " << i->getTwo() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Threes:  " << i->getThree() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Fours:   " << i->getFour() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Fives:   " << i->getFive() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Sixes:   " << i->getSix() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Chance:  " << i->getChan() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total Score:" << i->getTotal() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Bonus: " << i->getBon() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total with bonus:" << i->getUpper() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| 3 of a Kind : " << i->getTrip() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| 4 of a Kind: " << i->getQuad() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Full House : " << i->getFull() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Small Straight : " << i->getSmall() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Large Straight : " << i->getLarge() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Yahtzee: " << i->getYazy() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total of Upper Section: " << i->getUpper() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total of Lower Section: " << i->getLower() << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Grand Total: " << i->getScore() << endl;
        cout << "|__________________________________________________________________" << endl << endl;
    }
}
