/* 
 * File:   EastEgg.h
 * Author: Dennis Lang
 * Created on July 30, 2020, 11:30 PM
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
class EastEgg {
private:
   int *pointR;
public:
   int gtLngth(void);
   EastEgg(int len);             // simple constructor
   EastEgg(const EastEgg &obj);  // copy constructor
   ~EastEgg();                     // destructor
};

EastEgg::EastEgg(int len) 
{
    pointR = new int;
    *pointR = len;
}

EastEgg::EastEgg(const EastEgg &obj) 
{
    pointR = new int;
    *pointR = *obj.pointR;
}

EastEgg::~EastEgg(void) 
{
    delete pointR;
}

int EastEgg::gtLngth( void ) 
{
    return *pointR;
}

void display(EastEgg obj) 
{
    int x = obj.gtLngth();
    if(x > 0)
    {
        cout << "Games until Easter Egg Unlocked: " << x <<endl;
    }
}

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

