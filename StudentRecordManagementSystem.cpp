#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string rollNumber;
    string name;
    string department;
    int grade;
};

vector<Student> records;

void addRecord() {
    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cin.ignore();  // Clear newline from input buffer

    cout << "Enter Name: ";
    getline(cin, student.name);

    cout << "Enter Department: ";
    getline(cin, student.department);

    cout << "Enter Grade: ";
    cin >> student.grade;

    records.push_back(student);
    cout << "Record added successfully!" << endl;
}

void displayAllRecords() {
    if (records.empty()) {
        cout << "No records found." << endl;
        return;
    }

    for (const auto& student : records) {
        cout << "Roll Number: " << student.rollNumber << ", "
             << "Name: " << student.name << ", "
             << "Department: " << student.department << ", "
             << "Grade: " << student.grade << endl;
    }
}

void searchRecord() {
    string rollNumber;
    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    bool found = false;
    for (const auto& student : records) {
        if (student.rollNumber == rollNumber) {
            cout << "Record Found!" << endl;
            cout << "Roll Number: " << student.rollNumber << ", "
                 << "Name: " << student.name << ", "
                 << "Department: " << student.department << ", "
                 << "Grade: " << student.grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No records found." << endl;
    }
}

void updateRecord() {
    string rollNumber;
    cout << "Enter Roll Number to Update: ";
    cin >> rollNumber;
    cin.ignore();  // Clear newline

    bool found = false;
    for (auto& student : records) {
        if (student.rollNumber == rollNumber) {
            cout << "Enter New Name: ";
            getline(cin, student.name);

            cout << "Enter New Department: ";
            getline(cin, student.department);

            cout << "Enter New Grade: ";
            cin >> student.grade;

            cout << "Record updated successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nStudent Record Management System\n";
        cout << "1. Add Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Record\n";
        cout << "4. Update Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                updateRecord();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}
