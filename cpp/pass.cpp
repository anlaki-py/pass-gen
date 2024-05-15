#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>

std::string generate_strong_password(int length) {
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    std::string password = "";
    for (int i = 0; i < length; i++) {
        password += characters[rand() % characters.size()];
    }
    return password;
}

int main(int argc, char* argv[]) {
    srand(time(0));
    std::string command;
    if (argc > 1) {
        command = argv[1];
    }
    if (command == "clear") {
        std::remove("pass.log");
    }
    else if (command == "cat") {
        std::ifstream infile("pass.log");
        if (infile.good()) {
            std::string line;
            while (std::getline(infile, line)) {
                std::cout << line << std::endl;
            }
        }
    }
    else if (isalpha(command[0])) {
        std::cout << "Invalid option!" << std::endl;
    }
    else {
        int length = std::stoi(command);
        std::string password = generate_strong_password(length);
        std::cout << password << std::endl;
        std::ofstream outfile;
        outfile.open("pass.log", std::ios_base::app);
        outfile << password << std::endl;
    }
    return 0;
}