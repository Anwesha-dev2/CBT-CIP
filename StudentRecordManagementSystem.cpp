#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Student {
public:
    string rollNumber;
    string name;
    string department;
    string grade;

    void inputData(bool askRoll = true) {
        if (askRoll) {
            cout << "Enter Roll Number: ";
            cin >> rollNumber;
            cin.ignore();
        }
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Grade: ";
        getline(cin, grade);
    }

    void displayData() const {
        cout << rollNumber << "\t" << name << "\t" << department << "\t" << grade << endl;
    }

    string toCSV() const {
        return rollNumber + "," + name + "," + department + "," + grade;
    }

    static Student fromCSV(const string& line) {
        Student s;
        stringstream ss(line);
        getline(ss, s.rollNumber, ',');
        getline(ss, s.name, ',');
        getline(ss, s.department, ',');
        getline(ss, s.grade, ',');
        return s;
    }
};

void addRecord() {
    ofstream file("StudentRecords.txt", ios::app);
    Student student;
    student.inputData();
    file << student.toCSV() << endl;
    file.close();
    cout << "Record added successfully!" << endl;
}

void displayRecords() {
    ifstream file("StudentRecords.txt");
    if (!file) {
        cout << "No records found." << endl;
        return;
    }

    string line;
    cout << "RollNo\tName\tDepartment\tGrade" << endl;
    cout << "----------------------------------------" << endl;
    while (getline(file, line)) {
        Student s = Student::fromCSV(line);
        s.displayData();
    }
    file.close();
}

void searchRecord(const string& rollNumber) {
    ifstream file("StudentRecords.txt");
    if (!file) {
        cout << "No records found." << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        Student s = Student::fromCSV(line);
        if (s.rollNumber == rollNumber) {
            cout << "Record Found:\n";
            cout << "Roll Number: " << s.rollNumber << endl;
            cout << "Name: " << s.name << endl;
            cout << "Department: " << s.department << endl;
            cout << "Grade: " << s.grade << endl;
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
    if (!file) {
        cout << "No records to update." << endl;
        return;
    }

    ofstream tempFile("TempRecords.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        Student s = Student::fromCSV(line);
        if (s.rollNumber == rollNumber) {
            found = true;
            cout << "Enter new details (roll number cannot be changed):" << endl;
            s.inputData(false);  // Don't ask for roll number again
        }
        tempFile << s.toCSV() << endl;
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("StudentRecords.txt");
        rename("TempRecords.txt", "StudentRecords.txt");
        cout << "Record updated successfully!" << endl;
    } else {
        remove("TempRecords.txt");
        cout << "Record not found!" << endl;
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
        cin.ignore(); // Clear input buffer for getline()

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                getline(cin, rollNumber);
                searchRecord(rollNumber);
                break;
            case 4:
                cout << "Enter Roll Number to Update: ";
                getline(cin, rollNumber);
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
