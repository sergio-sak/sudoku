#include <iostream>

#include "functions.h"

void main_screen() {
    std::cout << " ____            _       _            ____        _\n";
    std::cout << "/ ___| _   _  __| | ___ | | ___   _  / ___|  ___ | |_   _____ _ __\n";
    std::cout << "\\___ \\| | | |/ _` |/ _ \\| |/ / | | | \\___ \\ / _ \\| \\ \\ / / _ \\ '__|\n";
    std::cout << " ___) | |_| | (_| | (_) |   <| |_| |  ___) | (_) | |\\ V /  __/ |\n";
    std::cout << "|____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_| |____/ \\___/|_| \\_/ \\___|_|\n";
    std::cout<<"Hello there!\n";
    std::cout<<"------------------------\n";
    std::cout<<"|Option 1: Enter Sudoku|\n";
    std::cout<<"|----------------------|\n";
    std::cout<<"|Option 2: Exit        |\n";
    std::cout<<"------------------------\n";
    int choice;
    std::cin>>choice;
    if(choice == 1) {

    } else {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        std::cout << " ____             _\n";
        std::cout << "| __ ) _   _  ___| |\n";
        std::cout << "|  _ \\| | | |/ _ \\ |\n";
        std::cout << "| |_) | |_| |  __/_|\n";
        std::cout << "|____/ \\__, |\\___(_)\n";
        std::cout << "       |___/\n";
    }
}



bool is_valid(int sudoku[9][9]) {
    bool numbers[10], numbers_x[10], numbers_y[10], valid = true;

    for(int k = 1; k <= 9; ++k) { //Check if there's double in the same box
        for(int i = 3*((k-1)/3) + 1; i <= 3 + 3*((k-1)/3); ++i) {
            for(int j = 1 + 3*((k-1)%3); j <= 3 + 3*((k-1)%3); ++j) {
                if(sudoku[i][j] != 0) {
                    if(!numbers[sudoku[i][j]])
                        numbers[sudoku[i][j]] = true;
                    else
                        return false;
                }
            }
        }
        for(int i = 0; i <= 9; ++i) {
            numbers[i] = false;
        }
    }

    for(int k = 1; k <= 9; ++k) { //Check if there's double in the same row/column
        for(int i = k; i <= 8 + k; ++i) {
            for(int j = k; j <= 8 + k; ++j) {
                if(sudoku[i][j] != 0) {
                    if(!numbers_x[sudoku[i][j]])
                        numbers_x[sudoku[i][j]] = true;
                    else
                        return false;
                }

                if(sudoku[j][i] != 0) {
                    if(!numbers_y[sudoku[j][i]])
                        numbers_y[sudoku[j][i]] = true;
                    else
                        return false;
                }
            }
        }
        for(int i = 0; i <= 9; ++i) {
            numbers_x[i] = numbers_y[i] = false;
        }
    }
    
    return valid;
}