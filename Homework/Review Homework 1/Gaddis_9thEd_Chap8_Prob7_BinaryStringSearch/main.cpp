/* 
 * File: BinaryStringSearch
 * Author: Dennis Lang
 * Date: 06/29/20
 * Purpose: HW
 * Version: 1
 */

//System Libraries - Post Here
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here
int binarySearch(const int [], int, int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill",  "Smith, Bart",
    "Allen, Jim", "Griffin, Jim", "Stamey, Marty",
    "Rose, Geri", "Taylor, Terri", "Johnson, Jill", 
    "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
    "James, Jean", "Weaver, Jim", "Pore, Bob",
    "Rutherford, Greg", "Javens, Renee", "Harrison, Rose",
    "Seltzer, Cathy", "Pike, Gordon", "Holland, Beth" };
    string employee;
    int results;
    //7 characters or less
    
    //Initialize or input data here
    cout << "Enter employee name: " << endl;
    cin >> employee;
    sort(begin(names), end(names));
    for(auto x: names){
        cout << x << endl;
    }
    //results = binarySearch(names, NUM_NAMES, employee);
    if(results == -1)
        cout << "Not found." << endl;
    else{
        cout << "The user " << employee << " was found" << endl;
    }
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}

int binarySearch(string names[], int size, string value)
{
    int first = 0,
        last = size - 1,
        middle,
        position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2; 
        if (names[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
                            