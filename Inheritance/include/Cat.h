#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include<string>
using namespace std;

class Cat : public Animal
{
    public:
        Cat();
        Cat(int, string, string);
        int getCatLegs() const;
        string getCatCry() const;
        string getCatColor() const;
    protected:
    private:
        int legs;
        string cry;
        string color;
};

#endif // CAT_H
