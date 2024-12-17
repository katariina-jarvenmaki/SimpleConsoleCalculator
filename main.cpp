#include <iostream>
#include <limits>  // For input validation
#include <iomanip> // For formatting output

using namespace std;

// Function to safely get a number from the user
double getValidatedNumber() {
    double number;
    while (true) {
        cin >> number;
        if (cin.fail()) { // If input is invalid
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a valid number: ";
        } else {
            return number; // Return valid input
        }
    }
}

// Function to add two numbers
void addNumbers() {
    double x, y;
    cout << "Enter value for x: ";
    x = getValidatedNumber();
    cout << "Enter value for y: ";
    y = getValidatedNumber();

    cout << fixed << setprecision(2); // Set precision to 2 decimal places
    cout << "Calculated x + y, result: " << x + y << endl;
}

// Function to handle basic menu
void showMenu() {
    cout << "\n==== Simple Console Program ====" << endl;
    cout << "1. Add two numbers" << endl;
    cout << "2. Exit" << endl;
    cout << "Choose an option (1-2): ";
}

// Main function
int main() {
    bool running = true;

    while (running) {
        showMenu();
        int choice;
        cin >> choice;

        if (cin.fail()) { // Validate menu input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Please try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addNumbers();
            break;
            case 2:
                cout << "Exiting program. Goodbye!\n";
            running = false;
            break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}