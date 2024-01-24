#include "../include/CezarCipher.hpp"
#include <iostream>
#include <cctype>
#include <string>

CezarCipher::CezarCipher(const std::string& name)
    : Task(name) {}

void CezarCipher::execute() const {
    int shift = 3;
    std::cout << "Enter the text you want to encrypt:" << std::endl;
    std::string text;
    std::cin.ignore();
    std::getline(std::cin, text);

    std::string encryptedText = "";
    for (char ch : text) {
        if (std::isalpha(ch)) {
            bool is_upper = std::isupper(ch);
            ch = static_cast<char>((ch + shift - (is_upper ? 'A' : 'a')) % 26 + (is_upper ? 'A' : 'a'));
        }
        encryptedText += ch;
    }
    std::cout << "Encrypted text: " << encryptedText << std::endl;

    std::string dencryptedText = "";
    for (char ch : encryptedText) {
        if (std::isalpha(ch)) {
            bool is_upper = std::isupper(ch);
            ch = static_cast<char>((ch - shift - (is_upper ? 'A' : 'a') + 26) % 26 + (is_upper ? 'A' : 'a'));
        }
        dencryptedText += ch;
    }
    std::cout << "Decrypted text: " << dencryptedText << std::endl;
}

#include <fstream>

void CezarCipher::showCode() const {

    std::ifstream file {"../src/CezarCipher.cpp"};

    if (file) {
        std::string line;
        int count = 1;
        while (std::getline(file, line)) {
            if (count>=2 && count<=4) {
                std::cout << line << std::endl;
            }
            else if (count>=10 && count<=35) {
                if (count == 10) std::cout << "\nint main() {" << std::endl;
                std::cout << line << std::endl;
            }
            ++count;
        }
    }
    else
        std::cout << "Error loading file" << std::endl;
}