#include<iostream>
#include<string>
#include "Animal.h"
#include "Cat.h"
using namespace std;

int main(){
    Cat myCat(4, "meow", "brown");
    Animal animal(4, "meow");
    cout<<myCat.getCatCry();
    //cout<<myCat.getCatColor();
    return 0;
}
