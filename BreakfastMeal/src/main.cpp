#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

const int NO_OF_ITEM = 8;
struct menuItemType{
    string menuList[];
    double menuPrice;
    string menuItem;

};

void getData(ifstream& mealData, ifstream& priceData, menuItemType list[], int listSize);
void showMenu(menuItemType list[], int listSize, string selectedMeal[], double selectedPrice[], int times);
void printCheck(ofstream& mealData, ofstream& priceData,  string selectedMeal[], double selectedPrice[], int listSize);
int main(){

    ifstream mealInfile, priceInfile;
    ofstream mealOutfile, priceOutfile;

    string inputFile;
    string outputFile;

    menuItemType menuItemList[NO_OF_ITEM];

    std::cout<<"Enter the meal file name: ";
    std::cin>>inputFile;
    std::cout<<"\n";

    mealInfile.open(inputFile.c_str());

    if(!infile){
        std::cout<<"Cannot open the input file.\n";
        return 1;
    }

    std::cout<<"Enter the price file name: ";
    std::cin>>inputFile;
    std::cout<<"\n";

    priceInfile.open(inputFile.c_str());

    if(!infile){
        std::cout<<"Cannot open the input file.\n";
        return 1;
    }

    string mealChosen[NO_OF_ITEM];
    double price[NO_OF_ITEM];

    getData(mealInfile, priceInfile, menuItemList, NO_OF_ITEM);
    showMenu(menuItemList, NO_OF_ITEM, mealChosen, price, NO_OF_ITEM);
    printCheck(mealOutfile, priceOutfile, mealChosen, price, NO_OF_ITEM);

    return 0;

}

void getData(ifstream& mealData, ifstream& priceData, menuItemType list[], int listSize){
    int index;
    string meal;
    double price;
    for(index = 0; i < listSize; i < index++){
        mealData>>meal;
        priceData>>price;
        list[index].menuItem = meal;
        list[index].menuPrice = price;
    }

}

void showMenu(menuItemType list[], int listSize, string selectedMeal[], double selectedPrice[]){
    int index;
    int choice;
    char sentinel;
    cout<<"Welcome to Yo Restaurant"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"We have: "<<endl;
    cout<<"_____________________________"<<endl;
    cout<<"   Meal     Price"<<endl;
    for(index = 0; index < listSize; index++){
        cout<<index + 1<<". "<<list[index].menuItem<<setw(7)<<"$"<<list[index].menuPrice<<endl;
    }
    cout<<endl;
    cout<<"To select a meal enter the S/N: "<<endl;
    index = 0;
    do{
        cout<<"Meal: ";
        cin>>choice;
        cout<<endl;

        selectedMeal[index] = list[choice - 1].menuItem;
        selectedPrice[index] = list[choice - 1].menuPrice;

        index++;

        cout<<"Do you want to make another order? (y/n): ";
        cin>>sentinel;


    }
    while(sentinel == 'y' || sentinel == 'Y');


}

void printCheck(ofstream& mealData, ofstream& priceData,  string selectedMeal[], double selectedPrice[], int listSize){
    int index;
    double total = 0;
    cout<<"Invoice:"<<endl;
    cout<<"_____________________________"<<endl;
    cout<<"   Meal     Price"<<endl;
    for(index = 0; index < listSize; index++){
        cout<<index + 1<<". "<<selectedMeal[index]<<setw(7)<<"$"<<selectedPrice[index]<<endl;
        total += selectedPrice[index];
    }
    cout<<endl;
    cout<<"Total: $"<<total<<endl;

    for(index = 0; index < listSize; index++){
        mealData<<selectedMeal[index]<<endl;
        priceData<<selectedPrice[index]<<endl;
    }


}
