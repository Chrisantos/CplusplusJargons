#include "Animal.h"

Animal::Animal()
{
    legs = 0;
    cry = "";
}

Animal::Animal(int legss, string crys)
{
    legs = legss;
    cry = crys;
}

void Animal::setLegs(int legs){
    legs = legs;
}

void Animal::setCry(string cry){
    cry = cry;
}

int Animal::getLeg() const{
    return legs;
}

string Animal::getCry() const{
    return cry;
}
