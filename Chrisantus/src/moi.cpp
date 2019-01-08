#include "moi.h"
#include<string>
#include<iostream>
using namespace std;

moi::moi(){
    age = 0;
    name = "";
}

void moi::setAge(int myAge){
    age = myAge;
}

void moi::setName(string myName){
    name = myName;
}

int moi::getAge(){
    return age;
}

string moi::getName(){
    return name;
}
