#ifndef MOI_H
#define MOI_H

#include<string>
using namespace std;

class moi
{
    public:
        moi();
        void setName(string);
        void setAge(int);
        string getName();
        int getAge();
    protected:
    private:
        string name;
        int age;
};

#endif // MOI_H
