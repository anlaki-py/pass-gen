#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Function to get the current time in milliseconds
long long getCurrentTimeMillis() {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
}

// Function to generate a random password
std::string generatePassword(int length, bool includeUppercase, bool includeNumbers, bool includeSymbols) {
    std::string characters = "abcdefghijklmnopqrstuvwxyz";
    if (includeUppercase) {
        characters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (includeNumbers) {
        characters += "0123456789";
    }
    if (includeSymbols) {
        characters += "!@#$%^&*()_-+={}[]|;:'\",.<>/?";
    }

    std::random_device rd;
    std::mt19937 generator(getCurrentTimeMillis()); // Seed with current time
    std::uniform_int_distribution<> distribution(0, characters.length() - 1);

    std::string password;
    for (int i = 0; i < length; i++) {
        password += characters[distribution(generator)];
    }

    return password;
}

// Function to check password strength
int getPasswordStrength(const std::string& password) {
    int strength = 0;
    if (password.length() >= 8) {
        strength++;
    }
    if (std::any_of(password.begin(), password.end(), ::isupper)) {
        strength++;
    }
    if (std::any_of(password.begin(), password.end(), ::isdigit)) {
        strength++;
    }
    if (std::any_of(password.begin(), password.end(), [](char c) { return !isalnum(c); })) {
        strength++;
    }

    if (strength <= 1) {
        return 1; // Weak
    } else if (strength == 2 || strength == 3) {
        return 2; // Medium
    } else {
        return 3; // Strong
    }
}

// Function to print the password in color
void printColoredPassword(const std::string& password, int strength) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (strength == 1) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    } else if (strength == 2) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
    std::cout << password << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset color
#else
    if (strength == 1) {
        std::cout << "\033[1;31m" << password << "\033[0m" << std::endl;
    } else if (strength == 2) {
        std::cout << "\033[1;33m" << password << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[1;32m" << password << "\033[0m" << std::endl;
    }
#endif
}

// Function to generate an easy-to-remember password (modified)
std::string generateEasyPassword(int length) {
    std::string vowels = "aeiouy";
    std::string consonants = "bcdfghjklmnpqrstvwxz";

    std::random_device rd;
    std::mt19937 generator(getCurrentTimeMillis());
    std::uniform_int_distribution<> vowelDistribution(0, vowels.length() - 1);
    std::uniform_int_distribution<> consonantDistribution(0, consonants.length() - 1);

    std::string password;
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            password += consonants[consonantDistribution(generator)];
        } else {
            password += vowels[vowelDistribution(generator)];
        }
    }

    return password;
}

int main(int argc, char* argv[]) {
    int length = 8;
    bool includeUppercase = false;
    bool includeNumbers = false;
    bool includeSymbols = false;
    bool easyToRead = false;

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "  -l <length>         Specify the password length (default: 8)" << std::endl;
            std::cout << "  -u                  Include uppercase letters" << std::endl;
            std::cout << "  -n                  Include numbers" << std::endl;
            std::cout << "  -s                  Include symbols" << std::endl;
            std::cout << "  -e                  Generate an easy-to-remember password" << std::endl;
            std::cout << "  -v                  Show version" << std::endl;
            std::cout << "  -h, --help          Display this help message" << std::endl;
            return 0;
        } else if (arg == "-l") {
            if (i + 1 < argc) {
                length = std::stoi(argv[i + 1]);
                i++;
            } else {
                std::cerr << "Error: -l option requires an argument" << std::endl;
                return 1;
            }
        } else if (arg == "-u") {
            includeUppercase = true;
        } else if (arg == "-n") {
            includeNumbers = true;
        } else if (arg == "-s") {
            includeSymbols = true;
        } else if (arg == "-e") {
            easyToRead = true;
        } else if (arg == "-v") {
            std::cout << "PassGen v1.3" << std::endl;
            return 0;
        } else if (i == 1 && std::isdigit(arg[0])) {
            length = std::stoi(arg);
        } else {
            std::cerr << "Error: Invalid argument: " << arg << std::endl;
            return 1;
        }
    }

    // Generate and print the password
    std::string password;
    if (easyToRead) {
        password = generateEasyPassword(length);
    } else {
        password = generatePassword(length, includeUppercase, includeNumbers, includeSymbols);
    }

    int strength = getPasswordStrength(password);
    printColoredPassword(password, strength);

    return 0;
}

// PASS-GEN by anlaki (@anlaki-py)
