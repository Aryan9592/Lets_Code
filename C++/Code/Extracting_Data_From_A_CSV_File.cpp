#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

// void csv_import(string data[][10], int columns, int records, string filename){
//     ifstream inFile;
//     inFile.open(filename);
//     vector<vector<string>> datas;
//     vector<string> row;
//     string line, word, temp;
//     // inFile>>temp;
//     while(getline(inFile,line)){
//         row.clear();
//         stringstream str(line);
//         while(getline(str,word,',')){
//             row.push_back(word);

//         }
//         datas.push_back(row);
//     }
//      inFile.close();
// }

void csv_import(string data[][10], int columns, int records, string filename){
    ifstream inFile;
    inFile.open(filename);
    string line, word;
    int i = 0;
    int j;
    while(getline(inFile, line)){
        j = 0;
        stringstream str(line);
        while(getline(str,word,',')){
            data[i][j] = word;
            j++;
        }
        i++;
    }
    inFile.close();
}

int main(){
    string data[10][10];
    csv_import(data,3,3,"customers.csv");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (j == 2){
                cout<<data[i][j]<<endl;
            }
            else
                cout<<data[i][j]<<",";
        }
    }
    return 0;
}