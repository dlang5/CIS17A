/* 
 * Author: 
 * Date:
 * Purpose:
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    float num1, num2, num3, num4, num5;
    //Input or initialize values Here
    cout << "Input 5 numbers." << endl;
    cin >> num1;
    cin >> num2; 
    cin >> num3;
    cin >> num4;
    cin >> num5;
    //Process/Calculations Here
    float x = (num1 + num2 + num3 + num4 + num5)/5;
    //Output Located Here
    cout << "The average is " << x;
    //Exit
    return 0;
}