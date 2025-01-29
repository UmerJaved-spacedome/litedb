#include "database.h"

int main(){
    string dbname;
    string tablename;
    cout<<"Enter name For your database : ";
    cin>>dbname;

    Database D(dbname);
    D.create_database();
    cout<<"Enter a Name for your table : ";
    cin>>tablename;
    D.create_table(tablename);


}