/*
 * File:   main.cpp
 * Author: Steven Contreras
 *
 * Created on April 16, 2023 6:40 PM
 * Purpose: Yahtzee Version V4
 */
 //System Libraries
#include <iostream> //Input - Output Library
#include <list>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants - Math/Physics/Chemistry/Conversions/Higher Dimensions

//Function Prototypes
 //Displayed scorecard function
void card(list<int>&);
//Functions for calculate scorecard for each category
void calScore(list<int>&, int &);
//Displays scorecard with real time updated scores 
void ScoreCard(list<int>&);
//Functions to calculate final score for reach player 
void finalScore(list<int>&, int &);
//fuinction for generating first roll  


//Execution Begins Here

int main(int argc, char** argv) {
    //Setting the Random number seed

    //Delcare values
    list<int> s;
    int sum = 0;
    //Initialize Variables
    ScoreCard(s);
    card(s);
    calScore(s, sum);
    finalScore(s,sum);
    return 0;
}
//function for store points earned by player by passing pointer to array of player and scorecard object and number of players
void card(list<int>& s) {

    //now for testing out a score card
    cout << "Now created a score card with -1 and the value" << endl;
    for (int i = 0; i < 13; i++) {
        s.emplace_back(-1);
    }
    //empty score card, well with -1 value
    int i = 1;
    for (auto it = s.begin(); it != s.end(); it++, i++) {
        cout << "catagory " << i << ": " << *it << endl;
    }
    //getting values form a user and insert value to scorecard list
    int pos = 0;
    int value = 0;
    list<int>::iterator j;

    for (int i = 0; i < 3; i++) {
        j = s.begin();
        cout << "Enter a value greater than 0 into the scorecard: ";
        cin >> value;
        //switch case to get postition and store value
        do
        {
            cout << "Enter a cataory to store a value for all 13 cataories: ";
            cin >> pos;      //choice entered by please
            switch (pos) {
            case 1:
                s.emplace(j, value);
                s.erase(j);
                break;
            case 2:
                pos = pos - 1;
                advance(j, pos);
                s.emplace(j, value);
                s.erase(j);
                break;
            case 3:
                pos = pos - 1;
                advance(j, pos);
                s.emplace(j, value);
                s.erase(j);
                break;
            case 4:
                pos = pos - 1;
                advance(j, pos);
                s.emplace(j, value);
                s.erase(j);
                break;
            case 5:
                pos = pos - 1;
                advance(j, pos);
                s.emplace(j, value);
                s.erase(j);
                break;
            case 6:
                pos = pos - 1;
                s.emplace(j, value);
                s.erase(j);
                break;
            case 7:
                pos = pos - 1;
                advance(j, pos);
                s.emplace(j, value);
                s.erase(j);
                break;
            case 8:
                pos = pos - 1;
                advance(j, pos);

                s.emplace(j, value);
                s.erase(j);
                break;
                pos = pos - 1;
            case 9:
                advance(j, pos);

                s.emplace(j, value);
                s.erase(j);
                break;
            case 10:
                pos = pos - 1;
                advance(j, pos);

                s.emplace(j, value);
                s.erase(j);
                break;
            case 11:
                pos = pos - 1;
                advance(j, pos);

                s.emplace(j, value);
                s.erase(j);
                break;
            case 12:
                pos = pos - 1;
                advance(j, pos);

                s.emplace(j, value);
                s.erase(j);
                break;
            case 13:
                pos = pos - 1;
                advance(j, pos);
                s.emplace(j, value);
                s.erase(j);
                break;
            default:
                cout << " Invalid selection: Choose again: ";
                break;
            }
        } while (pos > 13 || pos < 0); // continues if player choice greater than 13/selection options
    }
}
//function for added up all the points for each player by passing pointer to array of player and scorecard object and number of players
void calScore(list<int>& s, int &sum)
{
    // Determines the final score with bonus
    sum = 0;
    auto j = s.begin();
    advance(j, 6);
    for (auto i = s.begin(); i != j; i++) {
        sum += *i;
    }
        if (sum > 62)
        {
            sum = 0;
            for (auto i = s.begin(); i != s.end(); i++) {
                sum += *i;
            }
        }
        // Determine the final score without bonus
        else if (sum <= 62)
        {
            sum = 0;
                for (auto i = s.begin(); i != s.end(); i++) {
                    sum += *i;
                }
        }
}
//function for output of scorecard by passing pointer to array of player and scorecard object and number of players
void ScoreCard(list<int>& s)
{


    cout << "Chose any empty category. Values with a -1 have yet to be filled out" << endl << endl;
    cout << " __________________________________________________________________" << endl;
    cout << "|" << setw(20) << "Player: " << 1 << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "|" << setw(2) << "Yahtzee" << setw(15) << "Score Card" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| Upper Section                | Lower Section" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 1 - Aces:    "  << setw(33) << "7. 3 of a Kind : "  << endl;
    cout << "| -----------------------------------------------------------------" << endl;
    cout << "| 2 - Twos:    "  << setw(32) << "8. 4 of a Kind: "  << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 3 - Threes:  "  << setw(32) << "9. Full House : "  << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 4 - Fours:   "<< setw(36) << "10. Small Straight : "  << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 5 - Fives:   " << setw(36) << "11. Large Straight : " << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 6 - Sixes:   "  << setw(28) << "12. Yahtzee: "  << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 13. Chance:  "  << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "Category? ";
}
//outputting final score by passing pointer to array of player and scorecard object and number of players
void finalScore(list<int>& s, int &sum) {
    for (int i = 0; i < 1; i++)
        cout << endl;
        cout << " __________________________________________________________________" << endl;
        cout << "|" << setw(20) << "Player: " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|" << setw(2) << "Yahtzee" << setw(15) << "Score Card" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Upper Section" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Aces:    " << 1 << endl;
        cout << "| -----------------------------------------------------------------" << endl;
        cout << "| Twos:    " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Threes:  " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Fours:   " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Fives:   " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Sixes:   " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Chance:  " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total Score:" << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Bonus: " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total with bonus:" << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| 3 of a Kind : " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| 4 of a Kind: " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Full House : " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Small Straight : " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Large Straight : " <<1<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Yahtzee: " << 1<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total of Upper Section: " << 1<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total of Lower Section: " << 1 << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Grand Total: " << sum << endl;
        cout << "|__________________________________________________________________" << endl << endl;
}