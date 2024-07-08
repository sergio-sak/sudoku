#include <iostream>

#include "functions.h"
#include "misc.h"

void main_screen(int (&sudoku)[10][10]) {
    std::cout << " ____            _       _            ____        _\n";
    std::cout << "/ ___| _   _  __| | ___ | | ___   _  / ___|  ___ | |_   _____ _ __\n";
    std::cout << "\\___ \\| | | |/ _` |/ _ \\| |/ / | | | \\___ \\ / _ \\| \\ \\ / / _ \\ '__|\n";
    std::cout << " ___) | |_| | (_| | (_) |   <| |_| |  ___) | (_) | |\\ V /  __/ |\n";
    std::cout << "|____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_| |____/ \\___/|_| \\_/ \\___|_|\n";
    std::cout<<"Hello there!\n";
    std::cout<<"------------------------------------\n";
    std::cout<<"|Option 1: Enter Sudoku            |\n";
    std::cout<<"|----------------------------------|\n";
    std::cout<<"|Option 2: Sudoku's already entered|\n";
    std::cout<<"|----------------------------------|\n";
    std::cout<<"|Option 3: Exit                    |\n";
    std::cout<<"------------------------------------\n";
    std::cout<<"Select option: ";
    int choice;
    std::cin>>choice;
    clear_screen();

    if(choice == 1)
        enter_sudoku(sudoku);
    else if(choice == 2)
        solve_sudoku(sudoku);
    else {
        clear_screen();
        std::cout << " ____             _\n";
        std::cout << "| __ ) _   _  ___| |\n";
        std::cout << "|  _ \\| | | |/ _ \\ |\n";
        std::cout << "| |_) | |_| |  __/_|\n";
        std::cout << "|____/ \\__, |\\___(_)\n";
        std::cout << "       |___/\n";
    }
}

bool is_valid(int (&sudoku)[10][10]) {
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

void print_sudoku(int (&sudoku)[10][10]) {
    clear_screen();
    std::cout<<"_________________________________________\n";
    for(int i = 1; i <= 9; ++i) {
        for(int j = 1; j <= 9; ++j) {
            if((j-1) % 3 == 0)
                std::cout<<"|| "<<sudoku[i][j]<<" ";
            else
                std::cout<<"| "<<sudoku[i][j]<<" ";
        }
        std::cout<<"||\n";
        if(i % 3 == 0 && i != 1 && i != 9)
            std::cout<<"-----------------------------------------\n";
        std::cout<<"-----------------------------------------\n";
    }
}

void enter_sudoku(int (&sudoku)[10][10]) {
    int num;
    std::cout<<"Enter sudoku, must press enter after every number. Warning, it's going to be 81 numbers:()\n";

    for(int i = 1; i <= 9; ++i) {
        for(int j = 1; j <= 9; ++j) {
            std::cin>>num;
            sudoku[i][j] = num;
            print_sudoku(sudoku);
        }
    }
}

void solve_sudoku(int (&sudoku)[10][10]) {
    return;
}