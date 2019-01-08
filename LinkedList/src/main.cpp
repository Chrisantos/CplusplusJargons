#include<iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    LinkedList<int> myLList;

    myLList.insertNode(2);
    myLList.insertNode(4);
    myLList.insertNode(3);
    myLList.insertNode(6);
    myLList.insertNode(8);
    myLList.insertNode(1);

    myLList.deleteNode(4);
    myLList.printListReverse();
    return 0;
}
