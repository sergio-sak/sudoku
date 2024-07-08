//Standard Libraries
#include <iostream>

//My header files
#include "functions.h"
#include "misc.h"

//Variables needed

int sudoku[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 5, 0, 0, 8, 0},
    {0, 4, 5, 6, 7, 8, 9, 1, 0, 0},
    {0, 7, 0, 9, 0, 0, 0, 4, 0, 0},
    {0, 2, 1, 4, 3, 0, 0, 8, 9, 7},
    {0, 0, 0, 0, 8, 9, 7, 2, 0, 0},
    {0, 0, 9, 7, 2, 0, 0, 3, 0, 0},
    {0, 0, 3, 0, 0, 4, 2, 9, 7, 8},
    {0, 0, 0, 0, 0, 7, 8, 0, 0, 1},
    {0, 0, 0, 8, 5, 0, 1, 0, 4, 0}
};

int main()
{
    if(main_screen(sudoku)) {
        clear_screen();
        std::cout<<"Answer:\n";
        print_sudoku(sudoku);
    } else {
        std::cout<<"Solution Not Possible!\n";
    }

    return 0;
}
