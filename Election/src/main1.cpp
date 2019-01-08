#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

const int ROWS = 5;
const int COLS = 6;

void getCandidateNames(ifstream& inData, string candidateNames[], int rows);
void getCandidateVotes(ifstream& inData, int votesByRegion[ROWS][COLS], int rows, int cols);
void sortCandidateNames(string candidateNames[], int rows);
void processData(int totalCandVotes[], int votesByRegion[ROWS][COLS], int rows, int cols);
void calcTotalVotes(int votesByRegion[ROWS][COLS], int totalRegionVotes[], int rows, int cols);
void print(string candidateNames[], int votesByRegion[ROWS][COLS], int rows, int cols);

int main(){

    string candidateNames[ROWS];
    int votesByRegion[ROWS][COLS];
    int totalCandVotes[ROWS];
    int totalRegionVotes[COLS];

    ifstream infile;
    ofstream outfile;
    infile.open("candidate.txt");
    if(!infile){
        std::cout<<"File cannot be opened!\n";
        return 1;
    }

    getCandidateNames(infile, candidateNames, ROWS);
    sortCandidateNames(candidateNames, ROWS);

    infile.close();
    infile.clear();

    infile.open("results.txt");
    if(!infile){
        std::cout<<"File cannot be opened!\n";
        return 1;
    }

    getCandidateVotes(infile, votesByRegion, ROWS, COLS);

    infile.close();
    infile.clear();


    processData(totalCandVotes, votesByRegion, ROWS, COLS);
    calcTotalVotes(votesByRegion, totalRegionVotes, ROWS, COLS);
    print(candidateNames, votesByRegion, ROWS, COLS);


    return 0;
}

void getCandidateNames(ifstream& inData, string candidateNames[], int rows){
    for(int i = 0; i < rows; i++){
        inData>>candidateNames[i];
    }

}
void getCandidateVotes(ifstream& inData, int votesByRegion[ROWS][COLS], int rows, int cols){
    int i, j;
    string name;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            inData>>name;
            inData>>votesByRegion[i][j];
        }
    }
}
void sortCandidateNames(string candidateNames[], int rows){
    string temp;
    int i, loc;
    for(i = 1; i < rows; i++){
        if(candidateNames[i - 1] > candidateNames[i]){
            temp = candidateNames[i];
            loc = i;
        }
        do{
            candidateNames[loc] = candidateNames[loc - 1];
            loc--;
        } while(loc > 0 && candidateNames[loc - 1] > temp);
        candidateNames[i - 1] = temp;
    }
}
void processData(int totalCandVotes[], int votesByRegion[ROWS][COLS], int rows, int cols){
    int i, j;
    for(i = 0; i < rows; i++){
        totalCandVotes[i] = 0;
    }

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            totalCandVotes[i] += votesByRegion[i][j];
        }
    }
}
void calcTotalVotes(int votesByRegion[ROWS][COLS], int totalRegionVotes[], int rows, int cols){
    int i, j;
    for(i = 0; i < cols; i++){
        totalRegionVotes[i] = 0;
    }

    for(j = 0; j < cols; j++){
        for(i = 0; i < rows; i++){
            totalRegionVotes[j] += votesByRegion[i][j];
        }
    }
}
void print(string candidateNames[], int votesByRegion[ROWS][COLS], int rows, int cols){
    int i, j;
    cout<<setw(8)<<"Election Results\n";
    cout<<"Name"<<setw(5)<<"NC"<<setw(5)<<"NE"<<setw(5)<<"NW"<<setw(5)<<"SE"<<setw(5)<<"SS"<<setw(5)<<"SW\n";
    for(i = 0; i < rows; i++){
        cout<<candidateNames[i];
        for(j = 0; j < cols; j++){
            cout<<setw(5)<<votesByRegion[i][j]<<"\n";
        }
    }
}
