#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

const int NO_OF_SALES_PERSON = 6;

struct salesPersonRec{
    string ID;
    double saleByQuarter[4];
    double totalSale;
};

void initialize(ifstream& indata, salesPersonRec list[], int listSize);
void getData(ifstream& infile, salesPersonRec list[], int listSize);
void saleByQuarter(salesPersonRec list[], int listSize, double totalQuarter[]);
void totalSaleByPerson(salesPersonRec list[], int listSize);
void maxSaleByPerson(ofstream& outData, salesPersonRec list[], int listSize);
void maxSaleByQuarter(ofstream& outData, double saleByQuarter[]);
void printReport(ofstream& outfile, salesPersonRec list[], int listSize, double saleByQuarter[]);

int main(){
    ifstream infile;
    ofstream outfile;
    string inputFile;
    string outputFile;

    double totalSaleByQuarter[4];

    salesPersonRec salesPersonList[NO_OF_SALES_PERSON];

    std::cout<<"Enter the salesPerson ID file name: ";
    std::cin>>inputFile;
    std::cout<<"\n";

    infile.open(inputFile.c_str());

    if(!infile){
        std::cout<<"Cannot open the input file.\n";
        return 1;
    }

    initialize(infile, salesPersonList, NO_OF_SALES_PERSON);

    infile.close();
    infile.clear();

    std::cout<<"Enter the sales data file name: ";
    std::cin>>inputFile;
    std::cout<<"\n";

    infile.open(inputFile.c_str());

    if(!infile){
        std::cout<<"Cannot open the input file.\n";
        return 1;
    }

    std::cout<<"Enter the output file name: ";
    std::cin>>outputFile;
    std::cout<<"\n";

    outfile.open(outputFile.c_str());

    outfile<<fixed<<showpoint<<setprecision(2);
    getData(infile, salesPersonList, NO_OF_SALES_PERSON);
    saleByQuarter(salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);
    totalSaleByPerson(salesPersonList, NO_OF_SALES_PERSON);
    printReport(outfile, salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);
    maxSaleByPerson(outfile, salesPersonList, NO_OF_SALES_PERSON);
    maxSaleByQuarter(outfile, totalSaleByQuarter);

    infile.close();
    outfile.close();

    return 0;

}

void initialize(ifstream& indata, salesPersonRec list[], int listSize){
    int index;
    int quarter;
    for(index = 0; index < listSize; index++){
        indata>>list[index].ID;
        for(quarter = 0; quarter < 4; quarter++)
            list[index].saleByQuarter[quarter] = 0.0;
        list[index].totalSale = 0.0;
    }
}

void getData(ifstream& infile, salesPersonRec list[], int listSize){
    int index;
    int quarter;
    string sID;
    int month;
    double amount;

    infile>>sID;

    while(infile){
        infile>>month>>amount;

        for(index = 0; index < listSize; index++){
            if(sID == list[index].ID)
                break;
        }

        if(1 <= month && month <= 3)
            quarter = 0;
        else if(4 <= month && month <= 6)
            quarter = 1;
        else if(7 <= month && month <= 9)
            quarter = 2;
        else
            quarter = 3;

        if(index < listSize)
            list[index].saleByQuarter[quarter] += amount;
        else
            std::cout<<"Invalid salesperson's ID.\n";

        infile>>sID;
    }
}
void saleByQuarter(salesPersonRec list[], int listSize, double totalQuarter[]){
    int index;
    int quarter;

    for(quarter = 0; quarter < 4; quarter++)
        totalQuarter[quarter] = 0.0;
    for(index = 0; index < listSize; index++)
        for(quarter = 0; quarter < 4; quarter++)
            totalQuarter[quarter] += list[index].saleByQuarter[quarter];
}
void totalSaleByPerson(salesPersonRec list[], int listSize){
    int index;
    int quarter;

    for(index = 0; index < listSize; index++)
        for(quarter = 0; quarter < 4; quarter++)
            list[index].totalSale += list[index].saleByQuarter[quarter];

}
void maxSaleByPerson(ofstream& outData, salesPersonRec list[], int listSize){
    int maxIndex = 0;
    int index;

    for(index = 1; index < listSize; index++)
        if(list[maxIndex].totalSale < list[index].totalSale)
            maxIndex = index;

    outData<<"Max Sale by SalesPerson: ID = "<<list[index].ID<<", Amount = $"<<list[maxIndex].totalSale<<endl;
}
void maxSaleByQuarter(ofstream& outData, double saleByQuarter[]){
    int quarter;
    int maxIndex = 0;

    for(quarter = 0; quarter < 4; quarter++)
        if(saleByQuarter[maxIndex] < saleByQuarter[quarter])
            maxIndex = quarter;

    outData<<"Max Sale by Quarter: Quarter = "<<maxIndex + 1<<", Amount = $"<<saleByQuarter[maxIndex]<<endl;

}

void printReport(ofstream& outfile, salesPersonRec list[], int listSize, double saleByQuarter[]){
    int index;
    int quarter;

    outfile<<"------------ Annual Sales Report ---------------"<<endl;
    outfile<<" ID       QT1     QT2     QT3     QT4     Total"<<endl;
    outfile<<"________________________________________________"<<endl;

    for(index = 0; index < listSize; index++){
        outfile<<list[index].ID<<"  ";
        for(quarter = 0; quarter < 4; quarter++)
            outfile<<setw(10)<<list[index].saleByQuarter[quarter];
        outfile<<setw(10)<<list[index].totalSale<<endl;
    }

    outfile<<"Total ";
    for(quarter = 0; quarter < 4; quarter++)
        outfile<<setw(10)<<list[index].saleByQuarter;
    outfile<<endl;
}
