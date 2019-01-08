#include<iostream>
#include "ListType.h"
using namespace std;

int main(){

    ListType<int> myList1(15);
    ListType<int> myList2(15);

    int list[] = {1, 5, 7, 3, 0, 3, 4, 12, 5, 8};

    for(int i = 0; i < 10; i++){
        myList1.insertAt(list[i], i);
        myList2.insertAt(list[i], i);
    }

    myList1.insert(22);
    myList2.insert(25);

    if(myList1 == myList2){
        cout<<"Lists are equal\n";
    } else{
        cout<<"Lists are not equal\n";
    }


}
