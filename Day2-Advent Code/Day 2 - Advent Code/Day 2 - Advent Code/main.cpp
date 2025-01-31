#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>  // for std::abs

int main() {
    std::vector<std::string> levels;
    std::string line;
    int FinalCount = 0;

    for (int i = 0; i < 1000; i++) {
        std::getline(std::cin, line);

        // Tokenize the line by spaces (ignores extra spaces)
        std::stringstream ss(line);
        std::vector<int> tokens;
        std::string token;

        while (ss >> token) {
            // Convert token to an integer if it's a number
            try {
                tokens.push_back(std::stoi(token)); // This will convert the string to an integer
            }
            catch (const std::invalid_argument& e) {
                continue; // If the token is not a valid number, skip it
            }
        }

        if (tokens.size() < 2) {
            continue; // Skip lines with less than two tokens
        }

        bool Ascending = true;
        bool Descending = true;
        bool DifferenceCheck = true; // Flag to check the difference between tokens

        for (int x = 0; x < tokens.size() - 1; x++) {
            // Check if the sequence is ascending or descending
            if (tokens[x] > tokens[x + 1]) {
                Ascending = false;
            }
            if (tokens[x] < tokens[x + 1]) {
                Descending = false;
            }
            if (std::abs(tokens[x] - tokens[x + 1]) > 3 || (std::abs(tokens[x] - tokens[x + 1]) < 1)) {
                DifferenceCheck = false; 
            }
        }

        if ((Ascending || Descending) && DifferenceCheck) {
            FinalCount++;
        }
    }

    std::cout << "Final Count: " << FinalCount << std::endl;
    return 0;
}
