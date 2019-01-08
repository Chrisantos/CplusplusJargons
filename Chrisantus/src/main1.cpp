#include<iostream>
using namespace std;

int maxNum(const int list[], int lowerIndex, int listSize);
int main(){

    int list[] = {2, 4, 6, 2, 6};

    cout<<maxNum(list, 0, 4);

return 0;

}

int maxNum(const int list[], int lowerIndex, int listSize){
    int maxN = list[lowerIndex];

    if(listSize == lowerIndex)
        return maxN;
    else{
        maxN = maxNum(list, lowerIndex + 1, listSize);

        if(maxN <= list[lowerIndex])
            return list[lowerIndex];
        else
            return maxN;
    }

}
