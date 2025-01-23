#include <iostream>
#include <filesystem>
#include <vector>


using namespace std;

class Database {
    private:
     string database_name;
     vector<int> number_of_tables;
     vector<string> table_names;


     public:
     void create_database();
     void create_table();
     

};