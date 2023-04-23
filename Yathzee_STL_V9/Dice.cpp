#include<algorithm>
#include "Dice.h"
//Function generates values that the array of pointers point too
void getVal(map<int, Dice>& d)
{
    int size = 6;
    d.clear();
    for (int i = 1; i < size; i++) {
        d[i].setSide(6);
       // d[i].setSide(rand() % 6 + 1);
    }
}
//Function that displays the dice objects
void roll(map<int, Dice>& d)
{
    //for loop the iterates through each pointer
    for (auto it = d.begin(); it != d.end(); it++)
    {
        cout << it->second.getSide() << " ";
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
void reRoll(map<int, Dice>& d, list<int>& l)
{
    //char variable
    char choice;
    char pos;
    int size = 5;
    //prompting user(s) for which dice to keep and which to re-roll
    cout << "Choose which dice you want to keep. R - reRoll and K - Keep dice." << endl;
    for (int j = 0; j < 2; j++) {
        //displaying dice
        cout << "Roll " << j + 1 << ": ";
        roll(d);
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            do {
                cout << "Die " << i + 1 << ": ";
                cin >> choice;
            } while (toupper(choice) != 'R' && toupper(choice) != 'K');

            //assigns new value to each map by key by which the user choose to re-roll
            if (toupper(choice) == 'R') {
                pos = (i + 1) + '0';
                d.erase(pos - '0');
                d[pos - '0'].setSide(rand() % 6 + 1);
            }
        }

    }
    //calls function to display the dynamic array
    cout << endl << "Roll 3 : ";
    roll(d);
    cout << endl;
    //storing values from the map to array
    int i = 0;
    //clears list before new dices can be store
    l.clear();
    for (auto it = d.begin(); it != d.end(); it++, i++) {
        l.emplace_back(it->second.getSide());
    }
    //calls sort() from algorithm library to sort temp array from 
    l.sort();
}
//Function to get the total values stored in 2D array
int product(list<int>& l)
{
    //temp variable
    int sum = 0;
    //iterates through array and adds values store in memory address to sum
    for (auto i = l.begin(); i != l.end(); i++)
    {
        sum += *i;
    }
    return sum;   //returned the sum of the array
}
//Function for getting the sum of values of a give value
int result(list<int>& l, int p)
{
    //variable to store sum of values chosen set to 0
    int sum = 0;
    //searches for matching values in the array from one passed by player
    for (auto i = l.begin(); i != l.end(); i++)
    {
        if (*i == p)
        {
            sum += *i; // if match is found add value to sum
        }
    }
    return sum;  //return sum
}
//function to check the max frequency of a value
int maxFreq(list<int>& l)
{
    // checking max frequency of a number to see if its 3, 4 or 5
    int max = 0;
    int temp = 0;
    for (int i = 1; i < 7; i++)
    {
        temp = count(l.begin(), l.end(), i); // counting number of times a specific number appears
        if (temp > max) // assign count to max if counter is greater than max
        {
            max = temp; // making max frequency a new max frequency
        }
    }
    return max;   //return the max frequency passed by player
}
//function to verify player has a full house
int full(list<int>& l)
{
    //sum variable
    int sum = 0;
    list<int>::iterator i = l.begin();
    //storing contents to temo value for comparison
    int zero = *i; advance(i, 1);
    int one = *i; i = l.begin(); advance(i, 2);
    int two = *i; i = l.begin(); advance(i, 3);
    int three = *i; i = l.begin(); advance(i, 4);
    int four = *i;

    //checks values for matching pair and three of a kind
    if (((zero == one) && (one == two)) &&
        (three == four) && (two != three) ||
        ((zero == one) && ((two == three) &&
            (three == four)) && (one != two)))
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
int small(list<int>& l)
{
    // sum variable
    int sum = 0;
    list<int>::iterator it = l.begin();
    list<int> temp;
    advance(it, 2);
    //checking for repeated numbers
    l.unique();
    //added outside value to replace duplicate
    if (l.size() < 5) {
        l.emplace_back(7);
    }
    l.sort();
    list<int>::iterator i = l.begin();
    //storing contents to temo value for comparison
    int zero = *i; advance(i, 1);
    int one = *i; i = l.begin(); advance(i, 2);
    int two = *i; i = l.begin(); advance(i, 3);
    int three = *i; i = l.begin(); advance(i, 4);
    int four = *i;

    //checks from small straight in sorted array
    if (((zero == 1) && (one == 2) && (two == 3) && (three == 4)) ||
        ((zero == 2) && (one == 3) && (two == 4) && (three == 5)) ||
        ((zero == 3) && (one == 4) && (two == 5) && (three == 6)) ||
        ((one == 1) && (two == 2) && (three == 3) && (four == 4)) ||
        ((one == 2) && (two == 3) && (three == 4) && (four == 5)) ||
        ((one == 3) && (two == 4) && (three == 5) && (four == 6)))
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
int large(list<int>& l)
{
    int sum = 0;
    list<int>::iterator i = l.begin();
    //storing contents to temo value for comparison
    int zero = *i; advance(i, 1);
    int one = *i; i = l.begin(); advance(i, 2);
    int two = *i; i = l.begin(); advance(i, 3);
    int three = *i; i = l.begin(); advance(i, 4);
    int four = *i;
    //searches for matching
    if (((zero == 1) && (one == 2) && (two == 3)
        && (three == 4) && (four == 5)) ||
        ((zero == 2) && (one == 3) && (two == 4)
            && (three == 5) && (four == 6)))
    {
        sum = 40; // assigns 40 points if player has large straight
    }
    else
    {
        sum = 0; //assigns 0 points if player does not have large straight
    }
    return sum; // returns points
}