/* 
 * File:   EastEgg.h
 * Author: Dennis Lang
 * Created on July 30, 2020, 11:30 PM
 * This header file is designed to utilized
 * constructors and copy constructors as well 
 * as destructors in order to show off this 
 * functionality inline. The easter egg
 * has been baked into the previous example of
 * dynamic memory allocation and pointer functions
 * that allow the user to see a random array of 
 * lottery numbers. In order to show off the
 * concept of virtual functions and abstract classes
 * another call of dynamic is used.
 */

#ifndef EASTEGG_H
#define EASTEGG_H
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//Easter egg class with destructor and copy constructor
//pointer allows access with polymorphism if necessary
//credit to cplusplus.org for the template class and con/destructors
class EastEgg {
private:
   int *pointR;
public:
   int gtLngth(void);
   EastEgg(int len);             // simple constructor
   EastEgg(const EastEgg &obj);  // copy constructor
   ~EastEgg();                     // destructor
};

//constructor
//establishes East Egg
EastEgg::EastEgg(int len) 
{
    pointR = new int;
    *pointR = len;
}

//copy constructor
//creates a different instance of constructor for different arguments
EastEgg::EastEgg(const EastEgg &obj) 
{
    pointR = new int;
    *pointR = *obj.pointR;
}

//destructor
//ends the EastEgg upon completion of the program
EastEgg::~EastEgg(void) 
{
    delete pointR;
}

//return statement for pointer
int EastEgg::gtLngth( void ) 
{
    return *pointR;
}

//display counter for easter egg
//int x used as a proof of concept
void display(EastEgg obj) 
{
    int x = obj.gtLngth();
    if(x > 0)
    {
        cout << "Games until Easter Egg Unlocked: " << x <<endl;
    }
}

//template returns largest of two variables 
//used to show largest winTot and return it as retMax
//templating also showcases in the form of STL vector
template <class T>
T retMax (T a, T b) {
    T result;
    if(a > b)
    {
        result = a;
    }else{
        result = b;
    }
    return (result);
}

#endif /* EASTEGG_H */

