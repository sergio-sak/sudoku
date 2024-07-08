void main_screen(int (&sudoku)[10][10]); // Displays the main screen

bool is_valid(int (&sudoku)[10][10]); // Function that returns whether or not given sudoku is valid

bool is_pos_valid(int x, int y, int val, int (&sudoku)[10][10]);

void print_sudoku(int (&sudoku)[10][10]); // Print sudoku

void enter_sudoku(int (&sudoku)[10][10]); // Enter the sudoku

bool solve_sudoku(int (&sudoku)[10][10]); // Print sudoku