#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <memory>

std::string generate_strong_password(int length) {
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_-+=[]{}|;:,.<>?";
    std::string password = "";

    // Use a random device and a better random engine for higher quality randomness
    auto rand_device = std::make_unique<std::random_device>();
    auto rand_engine = std::make_unique<std::mt19937>((*rand_device)());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    for (int i = 0; i < length; i++) {
        password += characters[distribution(*rand_engine)];
    }
    return password;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <length/clear/cat>" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    if (command == "clear") {
        if (std::remove("pass.log") != 0) {
            std::perror("Error clearing the log file");
        }
    } else if (command == "cat") {
        std::ifstream infile("pass.log");
        if (!infile) {
            std::cerr << "Error opening the log file" << std::endl;
            return 1;
        }
        std::string line;
        while (std::getline(infile, line)) {
            std::cout << line << std::endl;
        }
    } else {
        try {
            int length = std::stoi(command);
            if (length <= 0 || length > 128) {
                std::cerr << "Invalid password length. Choose a length between 1 and 128." << std::endl;
                return 1;
            }
            std::string password = generate_strong_password(length);
            std::cout << password << std::endl;
            std::ofstream outfile("pass.log", std::ios_base::app);
            if (!outfile) {
                std::cerr << "Error opening the log file" << std::endl;
                return 1;
            }
            outfile << password << std::endl;
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid argument: " << ia.what() << std::endl;
            return 1;
        } catch (const std::out_of_range& oor) {
            std::cerr << "Argument out of range: " << oor.what() << std::endl;
            return 1;
        }
    }
    return 0;
}
