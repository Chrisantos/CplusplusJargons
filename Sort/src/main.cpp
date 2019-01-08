#include<iostream>

void bubbleSort(int list[], int listSize);
void insertionSort(int list[], int listSize);
int main(){
    int list[] = {7, 3, 2, 7, 8, 11, 9, 4};
    insertionSort(list, 8);
    return 0;
}

void bubbleSort(int list[], int listSize){
    int temp;
    for(int i = 1; i < listSize; i++){
        for(int j = 0; j < listSize - i; j++){
            if(list[j] > list[j+1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < listSize; i++){
        std::cout<<list[i]<<"\n";
    }

}

void insertionSort(int list[], int listSize){
    int temp;
    int pos;
    for(int index = 1; index < listSize; index++){
        if(list[index] < list[index - 1]){
            temp = list[index];
            pos = index;

            do{
                list[pos] = list[pos - 1];
                pos--;
            } while(pos > 0 && list[pos - 1] > temp);

            list[pos] = temp;
        }
    }

    for(int i = 0; i < listSize; i++){
        std::cout<<list[i]<<"\n";
    }

}
