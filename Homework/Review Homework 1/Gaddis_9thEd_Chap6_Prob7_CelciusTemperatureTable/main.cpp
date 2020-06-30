 /* 
 * File: CelciusTempTable
 * Author: Dennis Lang
 * Date: 06/26/20
 * Purpose: HW
 * Version: 1
 */

//System Libraries - Post Here
#include <iostream>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here
float celsius(float fahr)
 {
     float cels;
     cels = (fahr - 32) * 5/9;
     return cels;
 }
//Execution Begins Here
int main() {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    
    //Initialize or input data here
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    //Format and display outputs here
        for(int i=0; i<=20; i++){
            cout << i << "F = " <<celsius(i) << "C" << endl;
        }
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}