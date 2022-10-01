#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

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

struct Student{
    int id;
    double testscore;
    string name;
};

int main(){
    ifstream inFile;
    openInputFile(inFile);
    vector<Student> vs;
    Student temp;
    while (inFile >> temp.id){
        inFile >> temp.testscore;
        inFile.ignore(4, '\t');
        getline(inFile, temp.name);
        vs.push_back(temp);
    }
    cout<<"Students with marks above than 85 are: "<<endl;
    for (Student s : vs){
        if (s.testscore > 85)
            cout<< s.name <<endl;
    }
}