/*
Name: Emma Du
KUID: 3134852
Lab Session: Friday at 1pm
Lab Assignment Number: Extra credit
Program Description: Reads a string from the user and extracts a valid double-precision floating-point number from it 
Collaborators: None
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string& str) {
    bool hasDecimal = false; // Checks if decimal point is encountered
    bool hasSign = false; // Checks if a + or - sign is encountered
    double result = 0.0; // Variable to store the extracted numeric value
    double decimalMultiplier = 0.1; // Multiplier for handling the digits after decimal point
    int i = 0; // Index or iterating through string
    int n = str.length(); // Length of input string
    
    // Check if the string is empty
    if (n == 0) {
        return -999999.99;
    }

    // Handle optional + or - 
    if (str[i] == '+' || str[i] == '-') {
        hasSign = true;
        i++;
    }

    // Traverse the rest of the string
    while (i < n) {
        char c = str[i]; // Current character
        if (c >= '0' && c <= '9') { // Checks if character is a digit
            if (hasDecimal) {
                // Adds digit to fractional part
                result += (c - '0') * decimalMultiplier;
                decimalMultiplier /= 10; // Updates multiplier
            } else {
                // Adds the digit to the integer part
                result = result * 10 + (c - '0');
            }
        } else if (c == '.' && !hasDecimal) {
            // If a decimal point is encountered
            hasDecimal = true;
        } else {
            // Invalid character encountered
            return -999999.99;
        }
        i++;
    }

    if (str[0] == '-') {
        result = -result;
    }
    return result;
}

// Provided main program
int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

