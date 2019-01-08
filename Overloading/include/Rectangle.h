#ifndef RECTANGLE_H
#define RECTANGLE_H

#include<iostream>
using namespace std;

class Rectangle
{
    friend istream& operator>>(istream&, Rectangle&);
    friend ostream& operator<<(ostream&, const Rectangle&);
    public:
        void setLength(double&);
        void setWidth(double&);
        double getLength() const;
        double getWidth() const;
        bool operator==(const Rectangle&) const;
        bool operator!=(const Rectangle&) const;
        Rectangle operator+(const Rectangle&) const;
        Rectangle operator-(const Rectangle&) const;
        Rectangle operator*(const Rectangle&) const;

        Rectangle(double, double);
        Rectangle();
    protected:
    private:
        double width, length;
};

#endif // RECTANGLE_H
