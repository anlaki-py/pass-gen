#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cctype>

// ANSI escape codes for colored text
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string GREEN = "\033[32m";
const std::string RESET = "\033[0m";

// Version of the password generator
const std::string VERSION = "1.0.2";

// Helper function to print the help message
void printHelp() {
    std::cout << "SPG - Simple Password Generator\n\n";
    std::cout << "Usage:\n";
    std::cout << "pass [LENGTH] [OPTIONS]\n";
    std::cout << "If no arguments are given, an 8-character, easy-to-remember password is generated.\n\n";
    std::cout << "Options:\n";
    std::cout << "  -l [LENGTH]       Set the length of the password (default is 8).\n";
    std::cout << "  -u                Include uppercase letters.\n";
    std::cout << "  -n                Include numbers.\n";
    std::cout << "  -s                Include symbols.\n";
    std::cout << "  -v, --version     Show the version of the program.\n";
    std::cout << "  -h, --help        Show this help message.\n";
    std::cout << "\nPassword Strength:\n";
    std::cout << "  - Passwords are color-coded based on their strength:\n";
    std::cout << "    \033[31mWeak (red)\033[0m: Less than 8 characters or lacks diversity in character types.\n";
    std::cout << "    \033[33mMedium (yellow)\033[0m: At least 8 characters and includes a mix of character types.\n";
    std::cout << "    \033[32mStrong (green)\033[0m: 12+ characters, includes lowercase, uppercase, numbers, and symbols.\n";
    std::cout << "\nExamples:\n";
    std::cout << "  pass -l 12 -u -n -s     Generate a 12-character password with uppercase letters, numbers, and symbols.\n";
    std::cout << "  pass 16                 Generate a 16-character easy-to-remember password.\n";
}

// Function to generate a random password
std::string generatePassword(int length, bool includeUpper, bool includeNumbers, bool includeSymbols) {
    std::string lower = "abcdefghijklmnopqrstuvwxyz";
    std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string numbers = "0123456789";
    std::string symbols = "!@#$%^&*()_+-=[]{}|;:',.<>?/`~";

    std::string characters = lower;

    if (includeUpper) characters += upper;
    if (includeNumbers) characters += numbers;
    if (includeSymbols) characters += symbols;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> dist(0, characters.size() - 1);

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += characters[dist(generator)];
    }

    return password;
}

// Function to generate an easy-to-remember password (default)
std::string generateEasyPassword(int length) {
    std::string consonants = "bcdfghjklmnpqrstvwxyz";
    std::string vowels = "aeiou";

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distConsonant(0, consonants.size() - 1);
    std::uniform_int_distribution<> distVowel(0, vowels.size() - 1);

    std::string password;
    for (int i = 0; i < length; ++i) {
        if (i % 2 == 0)
            password += consonants[distConsonant(generator)];
        else
            password += vowels[distVowel(generator)];
    }

    return password;
}

// Function to assess password strength
std::string assessPasswordStrength(const std::string& password, bool includeUpper, bool includeNumbers, bool includeSymbols) {
    int length = password.length();
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSymbol = false;

    for (char c : password) {
        if (islower(c)) hasLower = true;
        if (isupper(c)) hasUpper = true;
        if (isdigit(c)) hasDigit = true;
        if (ispunct(c)) hasSymbol = true;
    }

    // Determine password strength
    if (length >= 12 && hasLower && hasUpper && hasDigit && hasSymbol) {
        return GREEN;  // Strong
    } else if (length >= 8 && ((hasUpper && hasLower) || (hasLower && hasDigit) || (hasUpper && hasDigit))) {
        return YELLOW;  // Medium
    } else {
        return RED;  // Weak
    }
}

int main(int argc, char *argv[]) {
    // Default settings
    int length = 8;
    bool includeUpper = false;
    bool includeNumbers = false;
    bool includeSymbols = false;
    bool easyPassword = true;

    // Check arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            printHelp();
            return 0;
        } else if (arg == "-v" || arg == "--version") {
            std::cout << "Version: " << VERSION << std::endl;
            return 0;
        } else if (arg == "-l" && i + 1 < argc) {
            length = std::stoi(argv[++i]);
        } else if (arg == "-u") {
            includeUpper = true;
            easyPassword = false;
        } else if (arg == "-n") {
            includeNumbers = true;
            easyPassword = false;
        } else if (arg == "-s") {
            includeSymbols = true;
            easyPassword = false;
        } else if (isdigit(arg[0])) {
            length = std::stoi(arg);
        } else {
            std::cerr << "Invalid argument: " << arg << "\n";
            return 1;
        }
    }

    // Generate password based on the options
    std::string password;
    if (easyPassword && includeUpper == false && includeNumbers == false && includeSymbols == false) {
        password = generateEasyPassword(length);
    } else {
        password = generatePassword(length, includeUpper, includeNumbers, includeSymbols);
    }

    // Assess password strength and choose the color
    std::string strengthColor = assessPasswordStrength(password, includeUpper, includeNumbers, includeSymbols);

    // Output the generated password with color based on its strength
    std::cout << "\n" << strengthColor << password << RESET << "\n" << std::endl;

    return 0;
}
