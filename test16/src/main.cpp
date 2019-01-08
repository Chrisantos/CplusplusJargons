#include<iostream>

int main(){

    int list[] = {1,2,3,4,5};
    int maxIndex = 0;

    for(int i = 0; i < 5; i++){
        if(list[maxIndex] < list[i]){
            maxIndex = i;
        }
    }

    std::cout<<"The maximum number is :"<<list[maxIndex]<<"\n";

}
