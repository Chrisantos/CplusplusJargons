#ifndef ANIMAL_H
#define ANIMAL_H


#include<string>
using namespace std;

class Animal
{
    public:
        Animal();
        Animal(int, string);
        void walk();
        void setLegs(int);
        void setCry(string);
        int getLeg() const;
        string getCry() const;
    protected:
    private:
        int legs;
        string cry;

};

#endif // ANIMAL_H
