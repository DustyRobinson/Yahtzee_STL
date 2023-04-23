#include "Dice.h"
//Function generates values that the array of pointers point too
void getVal(map<int, int>& dice)
{
    dice.clear();
    for (int i = 0; i < DIE_SIZE; i++) {
        dice[i + 1] = i + 1;//rand() % 6 + 1;
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