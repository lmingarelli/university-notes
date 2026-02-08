#include <stdio.h>
#include <unistd.h>

#define GRID_COLS 20
#define GRID_ROWS 20
#define GRID_CELLS (GRID_COLS * GRID_ROWS)
#define ALIVE '*'
#define DEAD '-'

/* Translate the specified x,y grid point into the index in
 * the linear array. This function implements wrapping, so
 * both negative and positive coordinates that are out of the
 * grid will wrap around.*/
int cellToIndex(int x, int y) {
    if (x < 0) {
        x = (-x) % GRID_COLS;
        x = GRID_COLS - x;
    }
    if (y < 0) {
        y = (-y) % GRID_ROWS;
        y = GRID_ROWS - y;
    }
    if (x >= GRID_COLS) x = x % GRID_COLS;
    if (y >= GRID_ROWS) y = y % GRID_ROWS;
    return (GRID_ROWS * y) + x;
}

/* The function sets the specified cell at x,y to the specified state */
void setCell(char* grid, int x, int y, char state) {
    grid[cellToIndex(x,y)] = state;
}

/* The function sets the specified cell at x,y to the specified state */
char getCell(char* grid, int x, int y) {
    return grid[cellToIndex(x,y)];
}

/* Show the grid on the screen, clearing the terminal using the
   required VT100 escape sequence. */
void printGrid(char* grid) {
    printf("\x1b[3J\x1b[H\x1b[2J"); // Clear screen.
    for (int y = 0; y < GRID_ROWS; y++){
        for (int x = 0; x < GRID_COLS; x++){
            printf("%c", getCell(grid, x, y));
        }
        printf("\n");
    }
}

/* Set the grid to a specified value */
void setGrid(char* grid, char state) {
    for (int y = 0; y < GRID_ROWS; y++){
        for (int x = 0; x < GRID_COLS; x++){
            setCell(grid, x, y, state);
        }
        printf("\n");
    }
}

/* Return the number of living neighbor cells of x,y */
int countLivingNeighbors(char* grid, int x, int y) {
    return
        (getCell(grid, x-1, y-1)   == ALIVE) +
        (getCell(grid, x,   y-1)   == ALIVE) +
        (getCell(grid, x+1, y-1)   == ALIVE) +
        (getCell(grid, x-1, y)     == ALIVE) +
        (getCell(grid, x+1, y)     == ALIVE) +
        (getCell(grid, x-1, y+1)   == ALIVE) +
        (getCell(grid, x,   y+1)   == ALIVE) +
        (getCell(grid, x+1, y+1)   == ALIVE);
}

/*  Compute the new state of Game of Life according to its rules */
void computeNewState(char* old, char* new) {
    for (int y = 0; y < GRID_ROWS; y++){
        for (int x = 0; x < GRID_COLS; x++){
            int aliveNeigh = countLivingNeighbors(old, x, y);
            int newState;
            if (getCell(old, x, y) == ALIVE) {
                newState = aliveNeigh == 2 || aliveNeigh == 3 ? ALIVE : DEAD;
            } else {
                newState = aliveNeigh == 3 ? ALIVE : DEAD;
            }
            setCell(new, x, y, newState);
        }
    }
}

int main() {
    char grid1[GRID_CELLS];
    char grid2[GRID_CELLS];
    setGrid(grid1, DEAD);
    // Glider
    /* setCell(grid1, 10, 10, ALIVE);
    setCell(grid1, 8, 10, ALIVE);
    setCell(grid1, 10, 11, ALIVE);
    setCell(grid1, 9, 11, ALIVE);
    setCell(grid1, 9, 12, ALIVE); */
    // 3x3 cube
    /* setCell(grid1, 10, 10, ALIVE);
    setCell(grid1, 10, 11, ALIVE);
    setCell(grid1, 10, 9, ALIVE);
    setCell(grid1, 9, 10, ALIVE);
    setCell(grid1, 9, 11, ALIVE);
    setCell(grid1, 9, 9, ALIVE);
    setCell(grid1, 11, 10, ALIVE);
    setCell(grid1, 11, 9, ALIVE);
    setCell(grid1, 11, 11, ALIVE); */
    // Random
    setCell(grid1, 10, 10, ALIVE);
    setCell(grid1, 11, 10, ALIVE);
    setCell(grid1, 10, 11, ALIVE);
    setCell(grid1, 9, 11, ALIVE);
    setCell(grid1, 9, 12, ALIVE);
    setCell(grid1, 9, 13, ALIVE);
    setCell(grid1, 8, 13, ALIVE);
    char *old = grid1;
    char *new = grid2;
    while (1) {
        computeNewState(old, new);
        printGrid(new);
        usleep(250000);

        // Swap pointers
        char *tmp = old;
        old = new;
        new = tmp;
    }
    return 0;
}