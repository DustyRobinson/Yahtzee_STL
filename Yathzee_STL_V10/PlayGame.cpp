//System Libraries
#include<iostream>
#include <string>
#include<iomanip>
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
void playGame(map<int, int>& d, set<Players>& p, list<Scorecard>& s, list<int>& a) {
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
    while (round < 3)
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
    calScore(s);
    finalScore(s, p);
    //end of game
}
void getPlayers(int& num) {
    // Game variables
    bool tryAgn = false;
    //prompts owner for the number of players playing the game
    cout << "How many players: ";
    cin >> num;
    //while loop that will keep running if condition is true
    while (tryAgn) {
        try {
            //if the owner/user enters a non negative value condition is set to false and breaks out of loop
            if (num > 0) {
                tryAgn = true;
            }
            //if condition is still true (user enter a negative number exception is thrown
            else {
                string excep = "Invalid input. Enter again: ";
                throw excep;
            }
        }
        //catch statement catch exception and used exception handles for re-entry
        catch (string excep) {
            cout << excep;
            cin >> num;
        }
    }
}
void getName(set<Players>& p, list<Scorecard>& s, int& size) {
    cin.ignore();
    string n;
    //for loop for getting each players name
    for (int i = 0; i < size; i++) {
        cout << "Enter Player " << i + 1 << " Name: ";
        getline(cin, n);
        p.emplace(n);
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
void card(list<Scorecard>& s, list<Scorecard>::iterator i, set<Players>::iterator j)
{
    cout << "Chose any empty category. Values with a -1 have yet to be filled out" << endl << endl;
    cout << " __________________________________________________________________" << endl;
    cout << "|" << setw(20) << "Player: " << j->getNames() << endl;
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
void getScores(list<Scorecard>& s, list<int>&a, list<Scorecard>::iterator i, set<Players>::iterator j) {
    //dispay scorecard
    card(s, i, j);
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
                        i->setTrip(product(a));
                        //outputs value score to verify score was received 
                        cout << "Triple: " << i->getTrip() << endl;
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }
                    //max frequency is less than 3, 0 points is stored
                    else {

                        i->setTrip(0);
                        //outputs value score to verify score was received 
                        cout << "Quads: " << i->getTrip() << endl;
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
                        //outputs value score to verify score was received 
                        cout << "Quads: " << i->getQuad() << endl;
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

                    i->setSmall((small(a) == 30) ? 30 : 0);
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
                    i->setLarge((large(a) == 40) ? 40 : 0);
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
                    if (max > 4)
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
//outputting final score by passing pointer to array of player and scorecard object and number of players
void finalScore(list<Scorecard>& s, set<Players>& n) {
    set<Players>::iterator it = n.begin();
    for (auto i = s.begin(); i != s.end(); i++, it++)
    {
        cout << endl;
        cout << " __________________________________________________________________" << endl;
        cout << "|" << setw(20) << "Player: " << it->getNames() << endl;
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
