#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>

using namespace std;

class Database {
private:
    string database_name;
    vector<int> number_of_tables;
    vector<string> table_names;

public:
    // Constructor to initialize database with a name
    Database(const string& db_name) : database_name(db_name) {}

    // Function to create a database directory
    void create_database() {
        string parent_database_directory = "Databases";
        string actual_database_path = parent_database_directory + "/" + database_name;

        // Check if the parent directory exists, otherwise create it
        if (!filesystem::exists(parent_database_directory)) {
            filesystem::create_directory(parent_database_directory);
            cout << "'Databases' directory created." << endl;
        }

        // Check if the database directory already exists
        if (filesystem::create_directory(actual_database_path)) {
            cout << "Database: " << database_name << " created successfully." << endl;
        } 
        else if (filesystem::exists(actual_database_path)) {
            cout << "Cannot create database. Database: " << database_name << " already exists." << endl;
        } 
        else {
            cout << "Error creating database." << endl;
        }
    }

    // Function to create a table within the database
   void create_table(const string& table_name) {
    // Check if the database exists
    string database_path = "Databases/" + database_name;
    if (!filesystem::exists(database_path)) {
        cout << "Database does not exist. Please create a database first." << endl;
        return;
    }

    // Ensure the table name has a .csv extension
    string table_name_with_extension = table_name + ".csv";

    // Check if the table already exists
    string table_path = database_path + "/" + table_name_with_extension;
    if (filesystem::exists(table_path)) {
        cout << "Cannot create table. Table: " << table_name_with_extension << " already exists." << endl;
        return;
    }

    // Create the table file (CSV)
    ofstream table_file(table_path);
    if (table_file.is_open()) {
        cout << "Table: " << table_name_with_extension << " created successfully." << endl;
        table_file<< "id,name,email";
        table_file.close();
    } 
    else {
        cout << "Error creating table." << endl;
    }

    // Add table to internal tracking
    table_names.push_back(table_name_with_extension);
    number_of_tables.push_back(0);  // Initializing with 0 records
}

};

#endif
