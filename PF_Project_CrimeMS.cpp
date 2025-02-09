#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

struct Record {
    int id;
    string name;
    string crimeType;
    string date;
    string details;
};

// Global variable to store records
vector<Record> records;

// Function prototypes
void addRecord();
void viewRecords();
void searchRecord();
void updateRecord();
void deleteRecord();

int main() {
    int choice;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,4);
    cout << "**************************************************" << endl;
    SetConsoleTextAttribute(h,1);
    cout << "*  __   _   _          __   ___   _____   _____  *" << endl;
    cout << "* |  \\ | | | |        / /  /   | |  _  \\ |  _  \\ *" << endl;
    cout << "* |   \\| | | |  __   / /  / /| | | |_| | | | | | *" << endl;
    cout << "* | |\\   | | | /  | / /  / /_| | |  ___/ | | | | *" << endl;
    cout << "* | | \\  | | |/   |/ /  / /  | | | |     | |_| | *" << endl;
    cout << "* |_|  \\_| |___/|___/  /_/   |_| |_|     |_____/ *" << endl;
    SetConsoleTextAttribute(h,4);
    cout << "**************************************************" << endl;
    SetConsoleTextAttribute(h,15);

    
    do {
        cout << "\nCrime Records Management System" << endl;
        cout << "1. Add Record\n2. View Records\n3. Search Record\n4. Update Record\n5. Delete Record\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume newline character

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                updateRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void addRecord() {
    Record r;
    cout << "Enter ID: ";
    cin >> r.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, r.name);
    cout << "Enter Crime Type: ";
    getline(cin, r.crimeType);
    cout << "Enter Date: ";
    getline(cin, r.date);
    cout << "Enter Details: ";
    getline(cin, r.details);

    records.push_back(r);
    cout << "Record added successfully!\n";
}

void viewRecords() {
    if (records.empty()) {
        cout << "No records found!\n";
        return;
    }

    cout << "\nAll Records:\n";
    for (size_t i = 0; i < records.size(); i++) {
        Record r = records[i];
        cout << "ID: " << r.id << "\nName: " << r.name << "\nCrime Type: " << r.crimeType
             << "\nDate: " << r.date << "\nDetails: " << r.details << "\n\n";
    }
}

void searchRecord() {
    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    bool found = false;
    for (size_t i = 0; i < records.size(); i++) {
        if (records[i].id == searchId) {
            Record r = records[i];
            cout << "\nRecord Found:\n";
            cout << "ID: " << r.id << "\nName: " << r.name << "\nCrime Type: " << r.crimeType
                 << "\nDate: " << r.date << "\nDetails: " << r.details << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found!\n";
    }
}

void updateRecord() {
    int updateId;
    cout << "Enter ID to update: ";
    cin >> updateId;
    cin.ignore();

    bool found = false;
    for (size_t i = 0; i < records.size(); i++) {
        if (records[i].id == updateId) {
            found = true;
            cout << "\nEnter new details for ID " << updateId << ":\n";
            cout << "Enter Name: ";
            getline(cin, records[i].name);
            cout << "Enter Crime Type: ";
            getline(cin, records[i].crimeType);
            cout << "Enter Date: ";
            getline(cin, records[i].date);
            cout << "Enter Details: ";
            getline(cin, records[i].details);
            cout << "Record updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Record not found!\n";
    }
}

void deleteRecord() {
    int deleteId;
    cout << "Enter ID to delete: ";
    cin >> deleteId;

    for (size_t i = 0; i < records.size(); i++) {
        if (records[i].id == deleteId) {
            records.erase(records.begin() + i);
            cout << "Record deleted successfully!\n";
            return;
        }
    }

    cout << "Record not found!\n";
}
