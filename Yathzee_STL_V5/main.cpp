/*
 * File:   main.cpp
 * Author: Steven Contreras
 *
 * Created on April 16, 2023 7:21 PM
 * Purpose: Yahtzee Version V5
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

//Global Constants - Math/Physics/Chemistry/Conversions/Higher Dimensions
const int DIE_SIZE = 5;

//Function Prototypes
//fuinction for generating first roll  
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
//void function to display the score card
void display();
//void function to check what possible score
void check(int[],list<int>&);
//menu
void menu();
//getting names
void getName(set<string>&, int&);
//printing names
void print(set<string>&);
//Displayed scorecard function
void card(list<int>&);
//Functions for calculate scorecard for each category
void calScore(list<int>&, int&);
//Displays scorecard with real time updated scores 
void ScoreCard(list<int>&);
//Functions to calculate final score for reach player 
void finalScore(list<int>&, int&);
//fuinction for generating first roll  

//Execution Begins Here

int main(int argc, char** argv) {
    //Setting the Random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Delcare values
    map<int, int> d;
    set<string> n;
    list<int> s;
    int dice[DIE_SIZE];
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
        getName(n, size);
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
    while (i < 3) {
        //frist round for each player
        cout << "Round: " << i << endl;
        for (auto it = n.begin(); it != n.end(); it++, i++) {
            cout << "Player " << i << ": " << *it << endl;
            getVal(d);// randomly generates a new between 1-6 for all dice
            //starting the re-roll process, up to two re-rolls for each player
            reRoll(d, dice);
        }
        check(dice, s);
    }
    calScore(s, sum);
    finalScore(s, sum);
    cout << "end of game" << endl;
    //Display the output
    //end of program
    return 0;
}
//Function generates values that the array of pointers point too
void getVal(map<int, int>& dice)
{
    for (int i = 0; i < DIE_SIZE; i++) {
        dice[i + 1] = rand() % 6 + 1;
    }
}
//Function that displays the dice objects
void roll(map<int, int>& d)
{
    //for loop the iterates through each pointer
    for (auto it = d.begin(); it != d.end(); it++)
    {
        cout << it->second << " ";
        //checks values in memory address against switch/case statement to display appropriate dice object 1-6 values 
        /*switch (it->second)
        {
        case 1:
            cout << " _________" << endl;
            cout << "|         |" << endl;
            cout << "|         |" << endl;
            cout << "|    o    |" << endl;
            cout << "|         |" << endl;
            cout << "|_________|" << endl;
            break;
        case 2:
            cout << " _________" << endl;
            cout << "|         |" << endl;
            cout << "|  o      |" << endl;
            cout << "|         |" << endl;
            cout << "|     o   |" << endl;
            cout << "|_________|" << endl;
            break;
        case 3:
            cout << " _________" << endl;
            cout << "|         |" << endl;
            cout << "|      o  |" << endl;
            cout << "|    o    |" << endl;
            cout << "|  o      |" << endl;
            cout << "|_________|" << endl;
            break;
        case 4:
            cout << " _________" << endl;
            cout << "|         |" << endl;
            cout << "|  o   o  |" << endl;
            cout << "|         |" << endl;
            cout << "|  o   o  |" << endl;
            cout << "|_________|" << endl;
            break;
        case 5:
            cout << " _________" << endl;
            cout << "|         |" << endl;
            cout << "| o     o |" << endl;
            cout << "|    o    |" << endl;
            cout << "| o     o |" << endl;
            cout << "|_________|" << endl;
            break;
        case 6:
            cout << " _________" << endl;
            cout << "|         |" << endl;
            cout << "|  o   o  |" << endl;
            cout << "|  o   o  |" << endl;
            cout << "|  o   o  |" << endl;
            cout << "|_________|" << endl;
            break;
        default:
            cout << "Error";
            break;
        }*/
    }
}
//Function for re-rolling dice
void reRoll(map<int, int>& dice, int a[])
{
    //char variable
    char choice;
    char pos;
    //prompting user(s) for which dice to keep and which to re-roll
    cout << "Choose which dice you want to keep. R - reRoll and K - Keep dice." << endl;
    for (int j = 0; j < 2; j++) {
        //displaying dice
        cout << "Roll " << j + 1 << ": ";
        roll(dice);
        cout << endl;
        for (int i = 0; i < DIE_SIZE; i++)
        {
            do {
                cout << "Die " << i + 1 << ": ";
                cin >> choice;
            } while (toupper(choice) != 'R' && toupper(choice) != 'K');

            //assigns new value to each map by key by which the user choose to re-roll
            if (toupper(choice) == 'R') {
                pos = (i + 1) + '0';
                dice.erase(pos - '0');
                dice.emplace(pos - '0', rand() % 6 + 1);
            }
        }

    }
    //calls function to display the dynamic array
    cout << endl << "Roll 3 : ";
    roll(dice);
    cout << endl;
    //storing values from the map to array
    int i = 0;
    for (auto it = dice.begin(); it != dice.end(); it++, i++) {
        a[i] = it->second;
    }
    //calls sort() from algorithm library to sort temp array from 
    sort(a, a + DIE_SIZE);
}
//Function to get the total values stored in 2D array
int product(int dice[])
{
    //temp variable
    int sum = 0;
    //iterates through array and adds values store in memory address to sum
    for (int i = 0; i < DIE_SIZE; i++)
    {
        sum += dice[i];
    }
    return sum;   //returned the sum of the array
}
//Function for getting the sum of values of a give value
int result(int dice[], int p)
{
    //variable to store sum of values chosen set to 0
    int sum = 0;
    //searches for matching values in the array from one passed by player
    for (int i = 0; i < DIE_SIZE; i++)
    {
        if (dice[i] == p)
        {
            sum += dice[i]; // if match is found add value to sum
        }
    }
    return sum;  //return sum
}
//function to check the max frequency of a value
int maxFreq(int dice[])
{
    // checking max frequency of a number to see if its 3, 4 or 5
    int max = 0;
    int count = 0;
    for (int i = 0; i < DIE_SIZE - 1; i++)
    {
        if (dice[i] == dice[i + 1])
        {
            count++; // increasing frequency counters
        }
        if (count > max) // assign count to max if counter is greater than max
        {
            max = count; // making max frequency a new max frequency
        }
    }
    return 5;   //return the max frequency passed by player
}
//function to verify player has a full house
int full(int dice[])
{
    //sum variable
    int sum = 0;
    //checks values for matching pair and three of a kind
    if (((dice[0] == dice[1]) && (dice[1] == dice[2])) &&
        (dice[3] == dice[4]) && (dice[2] != dice[3]) ||
        ((dice[0] == dice[1]) && ((dice[2] == dice[3]) &&
            (dice[3] == dice[4])) && (dice[1] != dice[2])))
    {
        sum = 25; //assigns 25 points if both matches are found
    }
    else
    {
        sum = 0; // assigns 0 if not both matches are not found
    }
    return sum; //return sum
}
//function to check for a small straight
int small(int dice[])
{
    // sum variable
    int sum = 0;
    //checking for repeated numbers
    for (int i = 0; i < DIE_SIZE - 1; i++)
    {
        if (dice[i] == dice[i + 1])
        {
            dice[i] = 7; // need to assign value outside values to check
            sort(dice, dice + DIE_SIZE); //sort function is called to move extra value to end
        }
    }
    //checks from small straight in sorted array
    if (((dice[0] == 1) && (dice[1] == 2) && (dice[2] == 3) && (dice[3] == 4)) ||
        ((dice[0] == 2) && (dice[1] == 3) && (dice[2] == 4) && (dice[3] == 5)) ||
        ((dice[0] == 3) && (dice[1] == 4) && (dice[2] == 5) && (dice[3] == 6)) ||
        ((dice[1] == 1) && (dice[2] == 2) && (dice[3] == 3) && (dice[4] == 4)) ||
        ((dice[1] == 2) && (dice[2] == 3) && (dice[3] == 4) && (dice[4] == 5)) ||
        ((dice[1] == 3) && (dice[2] == 4) && (dice[3] == 5) && (dice[4] == 6)))
    {
        sum = 30; //assigns 30 points to sum if small straight is found
    }
    else
    {
        sum = 0; //assigns 0 points to sum if small straight is not found
    }
    return sum;   //returns sum
}
//checking for large straight functions
int large(int dice[])
{
    int sum = 0;
    //searches for matching
    if (((dice[0] == 1) && (dice[1] == 2) && (dice[2] == 3)
        && (dice[3] == 4) && (dice[4] == 5)) ||
        ((dice[0] == 2) && (dice[1] == 3) && (dice[2] == 4)
            && (dice[3] == 5) && (dice[4] == 6)))
    {
        sum = 40; // assigns 40 points if player has large straight
    }
    else
    {
        sum = 0; //assigns 0 points if player does not have large straight
    }
    return sum; // returns points
}
void display() {
    cout << "Chose any empty category. Values with a -1 have yet to be filled out" << endl << endl;
    cout << " __________________________________________________________________" << endl;
    cout << "|" << setw(20) << "Player: 1" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "|" << setw(2) << "Yahtzee" << setw(15) << "Score Card" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| Upper Section                | Lower Section" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 1 - Aces:    " << setw(33) << "7. 3 of a Kind : " << endl;
    cout << "| -----------------------------------------------------------------" << endl;
    cout << "| 2 - Twos:    " << setw(32) << "8. 4 of a Kind: " << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 3 - Threes:  " << setw(32) << "9. Full House : " << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 4 - Fours:   " << setw(36) << "10. Small Straight : " << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 5 - Fives:   " << setw(36) << "11. Large Straight : " << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 6 - Sixes:   " << setw(28) << "12. Yahtzee: " << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 13. Chance:  " << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "Category? ";
}
void check(int dice[], list<int> &s) {
    //dispay scorecard
    display();
    //int temp value called max and bool variable set to true
    int pos = 0;
    int max = 0;
    list<int>::iterator j;
    //empty score card, well with -1 value
    for (int i = 0; i < 13; i++) {
        s.emplace_back(0);
    }
    do
    {
        j = s.begin();
        cin >> pos;         //choice entered by please
        switch (pos) // switch/case statement
        {
        case 1:             //try catch statement repeated for all 13 cases
            //call results function and stores value returned
            max = (pos);
            s.emplace(j, max);
            s.erase(j);
            //outputs value score to verify score was received 
            cout << "Ones: " << max << endl;
            break;
        case 2:
            max = result(dice, pos);
            pos = pos - 1;
            advance(j, pos);
            s.emplace(j, max);
            s.erase(j);
            //outputs value score to verify score was received 
            cout << "Twos: " << max << endl;
            break;
        case 3://if value is -1 which indicates category has yet to be filled out, run functions for storing values
            max = result(dice, pos);
            pos = pos - 1;
            advance(j, pos);
            s.emplace(j, max);
            s.erase(j);
            //outputs value score to verify score was received 
            cout << "Threes: " << max << endl;
            break;
        case 4: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            //call results function and stores value returned
            max = result(dice, pos);
            pos = pos - 1;
            advance(j, pos);
            s.emplace(j, max);
            s.erase(j);
            //outputs value score to verify score was received 
            cout << "Fours: " << max << endl;
            break;
        case 5: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            max = result(dice, pos);
            pos = pos - 1;
            advance(j, pos);
            s.emplace(j, max);
            s.erase(j);
            //outputs value score to verify score was received 
            cout << "Fives: " << max << endl;
            break;
        case 6: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            //call results function and stores value returned
            max = result(dice, pos);
            pos = pos - 1;
            advance(j, pos);
            s.emplace(j, max);
            s.erase(j);
            //outputs value score to verify score was received 
            cout << "Sixes: " << max << endl;
            break;
        case 7: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            max = maxFreq(dice);
            if (max >= 3)
            {
                max = product(dice);
                //outputs value score to verify score was received 
                cout << "Triple: " << max << endl;
                pos = pos - 1;
                advance(j, pos);
                s.emplace(j, max);
                s.erase(j);
            }
            break;
        case 8: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            max = maxFreq(dice);
            if (max >= 4)
            {
                max = product(dice);
                //outputs value score to verify score was received 
                cout << "Quads: " << max << endl;
                pos = pos - 1;
                advance(j, pos);
                s.emplace(j, max);
                s.erase(j);
            }
            break;
        case 9: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            //ternary operator for check for full house passed in seFull function
            max = (full(dice) == 25) ? 25 : 0;
            pos = pos - 1;
            advance(j, pos);
            s.emplace(j, max);
            s.erase(j);
            //outputs value score to verify score was received 
            cout << "Full House: " << max << endl;

            break;
        case 10:   // checks to make sure the user actually has a small straight
            max = (small(dice) == 30) ? 30 : 0;
            pos = pos - 1;
            advance(j, pos);
            s.emplace(j, max);
            s.erase(j);
            //outputs value score to verify score was received 
            cout << "Small Straight: " << max << endl;
            break;
        case 11:  //if value is -1 which indicates category has yet to be filled out, run functions for storing value
            //ternary operator for check for large straight passed in set large function
            max = (large(dice) == 40) ? 40 : 0;
            //outputs value score to verify score was received 
            cout << "Large Straight: " << max << endl;
            pos = pos - 1;
            advance(j, pos);
            s.emplace(j, max);
            s.erase(j);
            break;
        case 12:  //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            max = maxFreq(dice);
            if (max >= 4)
            {
                pos = pos - 1;
                advance(j, pos);
                s.emplace(j, max);
                s.erase(j);
                //outputs value score to verify score was received 
                cout << "Yahtzee " << max << endl;
            }
                break;
        case 13://if value is -1 which indicates category has yet to be filled out, run functions for storing values
            max = product(dice);
            pos = pos - 1;
            advance(j, pos);
            s.emplace(j, max);
            s.erase(j);
            //outputs value score to verify score was received 
            cout << "Chance " << max << endl;
            break;
        default:
            cout << " Invalid selection: Choose again: ";
            break;
        }
    } while (pos > 13 || pos < 1); // continues if player choice greater than 13/selection options
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
void getName(set<string>& n, int& size) {
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
    }
}
void print(set<string>& n) {
    //display names
    int i = 1;
    for (auto it = n.begin(); it != n.end(); it++, i++) {
        cout << "Player " << i << ": " << *it << endl;
    }
}
//function for added up all the points for each player by passing pointer to array of player and scorecard object and number of players
void calScore(list<int>& s, int& sum)
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
        //added bonus for higher uppper score
        sum += 35;
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
//outputting final score by passing pointer to array of player and scorecard object and number of players
void finalScore(list<int>& s, int& sum) {
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
    cout << "| Large Straight : " << 1 << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| Yahtzee: " << 1 << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| Total of Upper Section: " << 1 << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| Total of Lower Section: " << 1 << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| Grand Total: " << sum << endl;
    cout << "|__________________________________________________________________" << endl << endl;
}