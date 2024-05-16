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
    std::string char_set = "";

    if (include_uppercase) {
        char_set += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (include_digits) {
        char_set += "1234567890";
    }
    if (include_symbols) {
        char_set += "!@#$%^&*()_-+=[]{}|;:,.<>? ";
    }

    if (char_set.empty()) {
        char_set = characters;
    }

    std::uniform_int_distribution<size_t> distribution(0, char_set.size() - 1);

    for (int i = 0; i < length; i++) {
        password += char_set[distribution(std::mt19937(std::random_device()()))];
    }

    return password;
}

int main(int argc, char* argv[]) {
    int length = 12;
    bool include_uppercase = true;
    bool include_digits = true;
    bool include_symbols = true;
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
        int c = getopt_long(argc, argv, "l:uds", long_options, &option_index);

        if (c == -1) {
            break;
        }

        switch (c) {
            case 0:
                break;
            case 'l':
                length = std::stoi(optarg);
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
                break;
            case 'h':
                std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
                std::cout << "Options:" << std::endl;
                std::cout << "  -l, --length <length>     Set the length of the generated password (default: 12)" << std::endl;
                std::cout << "  -u, --uppercase          Include uppercase letters in the generated password" << std::endl;
                std::cout << "  -d, --digits            Include digits in the generated password" << std::endl;
                std::cout << "  -s, --symbols 