#include<iostream>
#include <fstream>
#include<filesystem>
#include <ctime>
#include <vector>

using namespace std;


int main(){

   ofstream WriteToFile("TestFiles/TestFile.csv");
   if(!WriteToFile){
    cerr<<"The File Didn't Opened Successfully"<<endl;
   }
   
   WriteToFile<<"ID,Name,Age\n";
   WriteToFile<<"1,Umer,20\n";
   WriteToFile<<"2,Abdul,21\n";

   WriteToFile.close();

   cout<<"File Written Successfully"<<endl;

   WriteToFile.close();

   //Reading a File Using IfStream
   ifstream ReadFromFile("TestFiles/TestFile.csv");
   if(!ReadFromFile){
    cerr<<"The File Didn't Opened Successfully for File Reading Purpose !!"<<endl;
   }
   string line;

   cout<<"File Contents"<<endl;

   while (getline(ReadFromFile,line))
   {
    cout<<line<<endl;
   }

   cout<<"File Successfully Read"<<endl;
   
   ReadFromFile.close();

   //Appending Data

   cout<<"Appending Data\n";
   WriteToFile.open("TestFiles/TestFile.csv",ios::app);

   if(!WriteToFile){
    cerr<<"The File Didn't Opened Successfully for Appending !"<<endl;
   }

   WriteToFile<<"3,Faizan,25";
   WriteToFile.close(); 


   //Re-Reading the File 

    ReadFromFile.open("TestFiles/TestFile.csv");
    cout<<"Reading File Contents Again !\n";

    while (getline(ReadFromFile,line))
    {
        cout<<line<<endl;
    }
    


    time_t timestamp ;
    time(&timestamp);

    cout<<ctime(&timestamp);




}