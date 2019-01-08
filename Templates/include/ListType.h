#ifndef LISTTYPE_H
#define LISTTYPE_H

#include<cassert>
using namespace std;

template<class cType>
class ListType
{
    public:
        bool isEmpty() const;
        bool isFull() const;
        int getLength() const;
        void insertAt(cType item, int pos);
        void insert(cType item);
        cType getTop() const;
        void print() const;

        bool operator==(const ListType<cType>&) const;

        /*ListType<cType> operator+(const ListType<cType>&) const;
        ListType<cType> operator++();*/

        ListType();
        ListType(int listSize);
    protected:
    private:
        int maxSize;
        int length;
        cType *list;
};

template<class cType>
bool ListType<cType>::isEmpty() const{
    return (length == 0);
}

template<class cType>
bool ListType<cType>::isFull() const{
    return (length == maxSize);
}

template<class cType>
int ListType<cType>::getLength() const{
    return length;
}

template<class cType>
void ListType<cType>::insertAt(cType item, int pos){
    assert(pos >= 0 && length < maxSize);
    list[pos] = item;
    length++;
}

template<class cType>
void ListType<cType>::insert(cType item){
    assert(length < maxSize);

    list[length] = item;
    length++;
}

template<class cType>
cType ListType<cType>::getTop() const{
    return list[0];
}

template<class cType>
void ListType<cType>::print() const{
    cout<<"The list contains the following items: "<<endl;

    for(int i = 0; i < length; i++){
        cout<<list[i]<<" ";
    }
}

template<class cType>
bool ListType<cType>::operator==(const ListType<cType>& listType) const{
    bool status = false;

    if(length == listType.length){
        for(int i = 0; i < length; i++){
            if(list[i] == listType.list[i]){
                status = true;
            } else{
                status = false;
            }
        }
    }

    return status;
}

template<class cType>
ListType<cType>::ListType(int listSize){
    maxSize = listSize;
    length = 0;
    list = new cType[maxSize];
}

template<class cType>
ListType<cType>::ListType()
{
    //ctor
}

#endif // LISTTYPE_H
