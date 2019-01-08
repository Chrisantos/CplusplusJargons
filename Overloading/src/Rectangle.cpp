#include "Rectangle.h"
#include<iostream>
using namespace std;

Rectangle::Rectangle()
{
    width = 0.0;
    length = 0.0;
}

Rectangle::Rectangle(double width_, double length_)
{
    width = width_;
    length = length_;
}

void Rectangle::setLength(double& length_){
    length = length_;
}

void Rectangle::setWidth(double& width_){
    width = width_;
}

double Rectangle::getLength() const{
    return length;
}

double Rectangle::getWidth() const{
    return width;
}

bool Rectangle::operator==(const Rectangle& rec) const{
    return (length == rec.length && width == rec.width);
}

bool Rectangle::operator!=(const Rectangle& rec) const{
    return (length != rec.length || width != rec.width);
}

Rectangle Rectangle::operator+(const Rectangle& rec) const{
    Rectangle tempRec;

    tempRec.length = length + rec.length;
    tempRec.width = width + rec.width;

    return tempRec;
}

Rectangle Rectangle::operator-(const Rectangle& rec) const{
    Rectangle tempRec;

    tempRec.length = length - rec.length;
    tempRec.width = width - rec.width;

    return tempRec;
}

Rectangle Rectangle::operator*(const Rectangle& rec) const{
    Rectangle tempRec;

    tempRec.length = length * rec.length;
    tempRec.width = width * rec.width;

    return tempRec;
}

istream& operator>> (istream& isObject, Rectangle& rec){
    isObject>> rec.length;
    isObject>> rec.width;

    return isObject;
}

ostream& operator<<(ostream& osObject, const Rectangle& rec){
    osObject<<"Length: "<<rec.length;
    osObject<<"\nWidth: "<<rec.width;

    return osObject;
}
