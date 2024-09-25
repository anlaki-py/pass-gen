#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

// Function to generate a random password
string generatePassword(int length, bool includeUppercase, bool includeNumbers, bool includeSymbols) {
    string characters = "abcdefghijklmnopqrstuvwxyz";
    if (includeUppercase) {
        characters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (includeNumbers) {
        characters += "0123456789";
    }
    if (includeSymbols) {
        characters += "!@#$%^&*()_-+={}[]|;:'\",.<>/?";
    }

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, characters.length() - 1);

    string password = "";
    for (int i = 0; i < length; i++) {
        password += characters[distribution(generator)];
    }

    return password;
}

// Function to display help message
void displayHelp() {
    cout << "Usage: pass [options]" << endl;
    cout << "Options:" << endl;
    cout << "  -l, --length <length>      Specify the length of the password (default: 12)" << endl;
    cout << "  -u, --uppercase           Include uppercase letters" << endl;
    cout << "  -n, --numbers             Include numbers" << endl;
    cout << "  -s, --symbols             Include symbols" << endl;
    cout << "  -h, --help                Display this help message" << endl;
    cout << "  -v, --version             Display the version" << endl;
}

// Function to display version
void displayVersion() {
    cout << "Password Generator v1.0" << endl;
}

int main(int argc, char* argv[]) {
    int length = 12;
    bool includeUppercase = true;
    bool includeNumbers = true;
    bool includeSymbols = true;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-l" || arg == "--length") {
            if (i + 1 < argc) {
                length = stoi(argv[i + 1]);
                i++;
            } else {
                cerr << "Error: Missing length argument" << endl;
                return 1;
            }
        } else if (arg == "-u" || arg == "--uppercase") {
            includeUppercase = true;
        } else if (arg == "-n" || arg == "--numbers") {
            includeNumbers = true;
        } else if (arg == "-s" || arg == "--symbols") {
            includeSymbols = true;
        } else if (arg == "-h" || arg == "--help") {
            displayHelp();
            return 0;
        } else if (arg == "-v" || arg == "--version") {
            displayVersion();
            return 0;
        } else {
            cerr << "Error: Invalid argument: " << arg << endl;
            return 1;
        }
    }

    // Generate and print the password
    string password = generatePassword(length, includeUppercase, includeNumbers, includeSymbols);
    cout << password << endl;

    return 0;
}
