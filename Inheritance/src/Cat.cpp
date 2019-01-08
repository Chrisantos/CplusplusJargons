#include "Cat.h"

Cat::Cat()
{
    legs = 0;
    cry = "";
    color = "";
}

Cat::Cat(int legss, string crys, string colors)
    :Animal(legss, crys)
{
    color = colors;

}

int Cat::getCatLegs() const{
    return legs;
}

string Cat::getCatCry() const{
    return Animal::getCry();
}

string Cat::getCatColor() const{
    return color;
}
