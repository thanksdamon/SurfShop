// SurfShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Johnny Utah owns a surf shop on the beach called “Point Break Surf Shop”. 
// Johnny sells surfboards in 3 three sizes: small (2 meters), medium (3 meters), and large (4 meters). 
// The cost of one small surfboard is $175.00, one medium is $190.00, and one large is $200.00.  
// Write a program that will make the surf shop operational.  



#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>        // included for using transform
using namespace std;

void ShowUsage();
void MakePurchase(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);
void DisplayPurchase(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void DisplayTotal(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);

const int XXXSMCOST = 25, SMALLCOST = 175, MEDCOST = 190, LARGECOST = 200; // declaring my constants
int iTotalXXXSmall = 0, iTotalSmall = 0, iTotalMedium = 0, iTotalLarge = 0;    


int main()
{
    cout << setw(56) << setfill('*') << "*" << endl; 
    cout << setfill('*') << setw(3) << ""; 
    cout << " Welcome to my Johnny Utah's PointBreak Surf Shop "; 
    cout << setfill('*') << setw(3) << "" << endl; 
    cout << setw(56) << setfill('*') << "*" << endl;
    ShowUsage();        // displays the usage immediately for the user
    string chc;
    cin >> chc;
    transform(chc.begin(), chc.end(), chc.begin(), ::tolower);      // transforms the users input into lowercase
    while (chc != "q")      // loop to make sure the program doesn't end until the user wants it to
    {
        if (chc == "s")
        {
            ShowUsage();
            cout << "Please make a selection." << endl;
            cin >> chc;
        }
        else if (chc == "p")
        {
            MakePurchase(iTotalXXXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << "Please make a selection." << endl;
            cin >> chc;
        }
        else if (chc == "c")
        {
            DisplayPurchase(iTotalXXXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << "Please make a selection." << endl;
            cin >> chc;
        }
        else if (chc == "t")
        {
            DisplayTotal(iTotalXXXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << "Please make a selection." << endl;
            cin >> chc;
        }
        else if (chc == "q")
        {
            return 0;
        }
        else                           // this block is to make sure the user enters a valid input.
        {
            cout << "error!" << endl;
            cout << "Please make a selection." << endl;
            cin >> chc;
        }
        
    }     
    cout << "Thank you!";
    return 0;
}

void ShowUsage()
{
    cout << "This program is used for buying surfboards. Follow the instructions on screen to complete transaction" << endl;
    cout << "To show program usage press \'S'" << endl;
    cout << "To purchase a surfboard press \'P'" << endl;
    cout << "To display current purchases press \'C'" << endl;
    cout << "To display total amount due press \'T'" << endl;
    cout << "To quit the program press \'Q'" << endl;
}

void MakePurchase(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    cout << "Please enter the quantity and type(X-XXXSmall for squirells, S-Small, L-Large, M-Medium)of surfboard you would like to purchase: ";
    int quantity;
    char type;
    cin >> quantity >> type;
    if (type == 'S' || type == 's')                 // depending on what character the user inputs for the type field 
    {                                               // it will increment the totals for small, med , or large
        iTotalSmall += quantity;
    }
    else if (type == 'M' || type == 'm')
    {
        iTotalMedium += quantity;
    }
    else if (type == 'X' || type == 'x')
    {
        iTotalXXXSmall += quantity;
    }
    else iTotalLarge += quantity;
}

void DisplayTotal(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    if (iTotalXXXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
    {
        cout << "No purchases made yet." << endl;
    }
    int xxxs = 0;
    int sm = 0;
    int med = 0;
    int lg = 0;
    if (iTotalXXXSmall != 0)
    {
        xxxs = iTotalXXXSmall * XXXSMCOST;
        cout << "The total number of squirell surfboards is: " << iTotalXXXSmall << " at a total cost of $" << xxxs << endl;
    }
    if (iTotalSmall != 0)                   // The next block does all the math needed for this
    {
        sm = iTotalSmall * SMALLCOST; 
        cout << "The total number of small surfboards is: " << iTotalSmall << " at a total cost of $" << sm << endl;
    }
    if (iTotalMedium != 0)
    {
        med = iTotalMedium * MEDCOST; 
        cout << "The total number of medium surfboards is: " << iTotalMedium << " at a total cost of $" << med << endl;
    }
    if (iTotalLarge != 0)
    {
        lg = iTotalLarge * LARGECOST; 
        cout << "The total number of large surfboards is: " << iTotalLarge << " at a total cost of $" << lg << endl;
    }
    int total = xxxs + sm + med + lg;              
    cout << "Amount due: $" << total << endl;
}

void DisplayPurchase(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    if (iTotalXXXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
    {
        cout << "No purchases made yet." << endl;
    }
    if (iTotalXXXSmall != 0)
    {
        cout << "The total number of squirell surfboards sold is: " << iTotalXXXSmall << endl;
    }
    if (iTotalSmall != 0)
    {
        cout << "The total number of small surfboards sold is: " << iTotalSmall << endl;
    }
    if (iTotalMedium != 0)
    {
        cout << "The total number of medium surfboards sold is: " << iTotalMedium << endl;
    }
    if (iTotalLarge != 0)
    {
        cout << "The total number of large surfboards sold is: " << iTotalLarge << endl;
    }
}






