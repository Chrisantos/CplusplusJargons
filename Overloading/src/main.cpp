#include<iostream>
#include "Rectangle.h"
using namespace std;

int main(){
    Rectangle myRec1(12.5, 10.5);
    Rectangle myRec2, myRec3;

    cout<<"myRec1: "<<myRec1<<endl;

    myRec2 = myRec1;

    cout<<"myRec2: "<<myRec2<<endl;

    myRec3 = myRec1 + myRec2;

    cout<<"myRec3: "<<myRec3<<endl;


}
