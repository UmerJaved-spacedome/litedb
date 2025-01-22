#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector <int> integerVector;
    int numberintovector;

    cout<<"Inputting into Vectors type 10 values \n";
    for (int i = 0; i < 10; i++){
        cin>>numberintovector;
        integerVector.push_back(numberintovector);
    }

    cout<<"Getting Output\n";
    for (int i = 0; i < integerVector.size(); i++){
        cout<<integerVector[i]<<" ";
    }


}