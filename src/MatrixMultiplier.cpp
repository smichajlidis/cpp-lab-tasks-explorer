#include "../include/MatrixMultiplier.hpp"
#include "../include/InvalidInputException.hpp"
#include <iostream>
#include <limits>

MatrixMultiplier::MatrixMultiplier(const std::string& name)
    : Task(name) {}

std::vector<std::vector<int>> MatrixMultiplier::loadMatrix() const {

    int rows, columns;
    std::vector<std::vector<int>> result;

    std::cout << "How many rows does the matrix have? ";
    std::cin >> rows;    
    if (std::cin.fail() || rows<1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InvalidInputException();
    }
    std::cout << "How many columns do you want? ";
    std::cin >> columns;
    if (std::cin.fail() || columns<1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InvalidInputException();
    }
    std::cout << "\nPlease enter " << columns*rows << " numbers to fill the matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        std::vector <int> row;
        int value;
        for (int j = 0; j < columns; j++) {
            std::cin >> value;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            row.push_back(value);
        }
        result.push_back(row);
    }

    return result;
}

void MatrixMultiplier::matrixMultiplier(const std::vector<std::vector<int>>& m1, const std::vector<std::vector<int>>& m2) const {

    int rowsM1 = m1.size();
    int colsM1 = m1[0].size();
    int rowsM2 = m2.size();
    int colsM2 = m2[0].size();
    if (colsM1 != rowsM2) {
        std::cerr << "Error: Incompatible matrix dimensions for multiplication." << std::endl;
        return;
    }
    std::vector<std::vector<int>> result(rowsM1, std::vector<int>(colsM2, 0));
    for (int i = 0; i < rowsM1; ++i) {
        for (int j = 0; j < colsM2; ++j) {
            for (int k = 0; k < colsM1; ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    int rows = result.size();
    int cols = result[0].size();
    std::cout << "\nResulting matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void MatrixMultiplier::execute() const {
    std::vector<std::vector<int>> m1;
    std::vector<std::vector<int>> m2;
    bool done = false;
    do {
        try {
            std::cout << "\n\tFIRST MATRIX CREATION\n" << std::endl;
            m1=loadMatrix();
            std::cout << "\n\tSECOND MATRIX CREATION\n" << std::endl;
            m2=loadMatrix();
            done = true;
        } catch (const InvalidInputException &ex) {
                consoleAnimator.clear();
                std::cerr << ex.what() << std::endl;
        }
    } while (!done);
    matrixMultiplier(m1, m2);
}

#include <fstream>

void MatrixMultiplier::showCode() const {

    std::ifstream file {"../src/MatrixMultiplier.cpp"};

    if (file) {

            std::cout << "#include <iostream>\n" << std::endl;

            std::string line;
            int count = 1;
            while (std::getline(file, line)) {
                if (count>=8 && count<=12) {
                    if (count == 8) std::cout << "int recFunction(int n) {" << std::endl;
                    std::cout << line << std::endl;
                }
                else if (count>=15 && count<=17) {
                    if (count == 15) std::cout << "\nint main() {" << std::endl;
                    std::cout << line << std::endl;
                }
                ++count;
            }
    }
    else
        std::cout << "Error loading file" << std::endl;
}