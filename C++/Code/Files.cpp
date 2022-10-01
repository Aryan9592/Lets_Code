#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

//For Creating files and writing in the data
// int main(){
//     ofstream outFile; 
//     outFile.open("GodofWar.txt");
//     outFile<<"Come on Boy!!" <<endl;
// }

void openInputFile(ifstream& inFile){
    string filename;
    cout<<"Tell me the name of your file: ";
    cin>>filename;
    inFile.open(filename);
    while(!inFile){
        cout<<"FILE FAILED TO OPEN!!"<<endl;
        cout<<"Please make sure that your file exist...Type the name again: "<<endl;
        cin>>filename;
        inFile.clear();
        inFile.open(filename);
    }
}



int main(){
    ifstream inFile;
    openInputFile(inFile);
    vector<int> v;
    int temp;
    while (inFile>>temp){
        v.push_back(temp);
    }

    double sum;
    for (int item : v){
        sum += item;
    }
    cout<<"The average of the integers in the file is: "<<sum/v.size()<<endl;
    
}