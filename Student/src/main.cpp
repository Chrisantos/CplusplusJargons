#include <iostream>
#include "clockType.h"
using namespace std;

int main()
{
clockType myClock;
clockType yourClock;
int hours;
int minutes;
int seconds;
//Set the time of myClock
myClock.setTime(5, 4, 30); //Line 1
cout << "Line 2: myClock: "; //Line 2
myClock.printTime(); //print the time of myClock Line 3
cout << endl; //Line 4
cout << "Line 5: yourClock: "; //Line 5
yourClock.printTime(); //p
}
