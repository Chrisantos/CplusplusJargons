#include<iostream>
#include "moi.h"
#include<string>
using namespace std;

int maxNum(int list[], int listSize);
int main(){

/*moi me;

me.setName("Chrisantus");
me.setAge(19); */

cout<<me.getAge();

    int list[] = {2, 4, 6, 2, 6};

    cout<<maxNum(list, 5);

return 0;

}

int maxNum(int list[], int listSize){
    int maxN = list[0];

    for(int i = 0; i < listSize; i++){
        if(maxN > list[i])
            maxN = list[i];
    }

    return maxN;

}
