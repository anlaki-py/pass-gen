#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <memory>
#include <getopt.h>

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

int main(int argc, char* argv[]) {
    int length = 12;
    bool include_uppercase = false; // Default to false to allow command line control
    bool include_digits = false;
    bool include_symbols = false;
    bool log_password = true;
    bool version = false;
    std::string command = "generate";

    const struct option long_options[] = {
        { "length", required_argument, 0, 'l' },
        { "uppercase", no_argument, 0, 'u' },
        { "digits", no_argument, 0, 'd' },
        { "symbols", no_argument, 0, 's' },
        { "no-log", no_argument, 0, 'n' },
        { "version", no_argument, 0, 'v' },
        { "help", no_argument, 0, 'h' },
        { 0, 0, 0, 0 }
    };

    while (1) {
        int option_index = 0;
        int c = getopt_long(argc, argv, "l:udsnvh", long_options, &option_index);

        if (c == -1) {
            break;
        }

        switch (c) {
            case 0:
                break;
            case 'l':
                length = std::stoi(optarg);
                if (length <= 0) {
                    std::cerr << "Error: Length must be greater than 0." << std::endl;
                    return 1;
                }
                break;
            case 'u':
                include_uppercase = true;
                break;
            case 'd':
                include_digits = true;
                break;
            case 's':
                include_symbols = true;
                break;
            case 'n':
                log_password = false;
                break;
            case 'v':
                version = true;
                std::cout << "Password Generator Version 2.5" << std::endl;
                return 0;
            case 'h':
                std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
                std::cout << "Options:" << std::endl;
                std::cout << "  -l, --length <length>     Set the length of the generated password (default: 12)" << std::endl;
                std::cout << "  -u, --uppercase           Include uppercase letters in the generated password" << std::endl;
                std::cout << "  -d, --digits              Include digits in the generated password" << std::endl;
                std::cout << "  -s, --symbols             Include symbols in the generated password" << std::endl;
                std::cout << "  -n, --no-log              Do not log the password to a file" << std::endl;
                std::cout << "  -v, --version             Show version information" << std::endl;
                std::cout << "  -h, --help                Show this help message" << std::endl;
                return 0;
        }
    }

    if (command == "generate") {
        std::string password = generate_strong_password(length, include_uppercase, include_digits, include_symbols);
        std::cout << "Generated Password: " << password << std::endl;

        if (log_password) {
            std::ofstream log_file("password_log", std::ios_base::app);
            if (!log_file) {
                std::cerr << "Error: Could not open log file for writing." << std::endl;
                return 1;
            }
            log_file << password << std::endl;
        }
    }

    return 0;
}
