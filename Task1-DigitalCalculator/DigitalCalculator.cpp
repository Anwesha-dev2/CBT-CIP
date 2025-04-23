#include <iostream>
#include <limits>

using namespace std;

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return numeric_limits<double>::infinity(); // Return infinity
    }
    return a / b;
}

// Function for input validation
double getValidatedInput() {
    double input;
    while (!(cin >> input)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
    return input;
}

int main() {
    int choice;
    double num1, num2;

    do {
        // Display the menu
        cout << "\n===== Simple Calculator =====" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            // Input first number
            cout << "Enter first number: ";
            num1 = getValidatedInput();

            // Input second number
            cout << "Enter second number: ";
            num2 = getValidatedInput();
        }

        switch (choice) {
            case 1:
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please choose a valid option." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
