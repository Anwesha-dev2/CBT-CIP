#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string rollNumber;
    string name;
    string department;
    string grade;

    void inputData() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Name: ";
        cin.ignore(); // To ignore leftover newline character
        getline(cin, name);
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Grade: ";
        cin >> grade;
    }

    void displayData() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Grade: " << grade << endl;
    }
};

void addRecord() {
    ofstream file("StudentRecords.txt", ios::app);
    Student student;
    student.inputData();
    file << student.rollNumber << " " << student.name << " " 
         << student.department << " " << student.grade << endl;
    file.close();
    cout << "Record added successfully!" << endl;
}

void displayRecords() {
    ifstream file("StudentRecords.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void searchRecord(const string& rollNumber) {
    ifstream file("StudentRecords.txt");
    string r, n, d, g;
    bool found = false;

    while (file >> r >> n >> d >> g) {
        if (r == rollNumber) {
            cout << "Record Found:\n";
            cout << "Roll Number: " << r << endl;
            cout << "Name: " << n << endl;
            cout << "Department: " << d << endl;
            cout << "Grade: " << g << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Record not found!" << endl;
    }
}

void updateRecord(const string& rollNumber) {
    ifstream file("StudentRecords.txt");
    ofstream tempFile("TempRecords.txt");
    string r, n, d, g;
    bool found = false;

    while (file >> r >> n >> d >> g) {
        if (r == rollNumber) {
            found = true;
            cout << "Enter new details:\n";
            Student student;
            student.inputData();
            tempFile << student.rollNumber << " " << student.name << " " 
                     << student.department << " " << student.grade << endl;
        } else {
            tempFile << r << " " << n << " " << d << " " << g << endl;
        }
    }
    file.close();
    tempFile.close();

    if (found) {
        remove("StudentRecords.txt");
        rename("TempRecords.txt", "StudentRecords.txt");
        cout << "Record updated successfully!" << endl;
    } else {
        cout << "Record not found!" << endl;
        remove("TempRecords.txt");
    }
}

int main() {
    int choice;
    string rollNumber;

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
                displayRecords();
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                cin >> rollNumber;
                searchRecord(rollNumber);
                break;
            case 4:
                cout << "Enter Roll Number to Update: ";
                cin >> rollNumber;
                updateRecord(rollNumber);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}