#include<iostream>
using namespace std;

int sequentialSearch(int list[], int listSize, int searchItem);
int binarySearch(int list[], int listSize, int searchItem);
int main(){
    int list[] = {3, 52, 1, 5, 7, 6};
    std::cout<<"The search item is found at index: "<<binarySearch(list, 6, 7);

}

int sequentialSearch(int list[], int listSize, int searchItem){
    bool found = false;
    int loc = 0;

    while(loc < listSize && !found)
        if(list[loc] == searchItem)
            found = true;
        else
            loc++;

    if(found)
        return loc;
    else
        return -1;

}

int binarySearch(int list[], int listSize, int searchItem){
    int first = 0;
    int last = listSize - 1;
    int mid;
    bool found = false;

    while(first <= last && !found){
        mid = (first + last)/2;
        if(searchItem == list[mid])
            found = true;
        else if(searchItem > list[mid])
            first = mid + 1;
        else if(searchItem < list[mid])
            last = mid - 1;
    }

    if(found)
        return mid;
    else
        return -1;

}

