#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <limits>

const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_-+=[]{}|;:,.<>?";

std::string generate_strong_password(int length, bool include_uppercase, bool include_digits, bool include_symbols) {
    std::string password = "";
    std::string char_set = "abcdefghijklmnopqrstuvwxyz"; // Ensure lowercase letters are included by default

    if (include_uppercase) {
        char_set += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (include_digits) {
        char_set += "1234567890";
    }
    if (include_symbols) {
        char_set += "!@#$%^&*()_-+=[]{}|;:,.<>? ";
    }

    std::random_device rd; // Seed for the random number generator
    std::mt19937 generator(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<size_t> distribution(0, char_set.size() - 1);

    for (int i = 0; i < length; i++) {
        password += char_set[distribution(generator)]; // Use the same generator for all characters
    }

    return password;
}

int main() {
    int length = 12;
    char include_uppercase, include_digits, include_symbols, log_password;
    std::cout << "Welcome to CPass Password Generator!" << std::endl;
    
    // Ask for password length
    std::cout << "Enter password length (default 12): ";
    std::cin >> length;
    if(std::cin.fail() || length <= 0) {
        std::cin.clear(); // clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        length = 12;
        std::cout << "Invalid input. Using default length 12." << std::endl;
    }
    
    // Ask for including uppercase letters
    std::cout << "Include uppercase letters? (y/n): ";
    std::cin >> include_uppercase;
    
    // Ask for including digits
    std::cout << "Include digits? (y/n): ";
    std::cin >> include_digits;
    
    // Ask for including symbols
    std::cout << "Include symbols? (y/n): ";
    std::cin >> include_symbols;
    
    // Ask for logging password
    std::cout << "Log the password to a file? (y/n): ";
    std::cin >> log_password;

    std::string password = generate_strong_password(length, include_uppercase == 'y', include_digits == 'y', include_symbols == 'y');
    std::cout << "Generated Password: " << password << std::endl;

    if (log_password == 'y') {
        std::ofstream log_file("password_log.txt", std::ios_base::app);
        if (!log_file) {
            std::cerr << "Error: Could not open log file for writing." << std::endl;
            return 1;
        }
        log_file << password << std::endl;
    }

    // Wait for user input to close
    std::cout << "Press enter to exit..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore previous newline left in the buffer
    std::cin.get();
    
    return 0;
}