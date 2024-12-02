#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_ROWS 20
#define MAX_COLS 21
#define MAX_LEVELS 10
#define FILENAME "score.txt"


char maze[MAX_ROWS][MAX_COLS];
int row = 19, col = 7;
int moveCount = 0;
char dir;

int loadLevel(int level) {
    char filename[100];
    sprintf(filename, "C:\\Users\\Constanson\\Documents\\GitHub\\Test\\level1\\p08_push_boxes\\level%d.txt", level);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to load level %d\n", level);
        return 0;
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        fgets(maze[i], MAX_COLS + 1, file);
        maze[i][strlen(maze[i]) - 1] = '\0';
    }

    fclose(file);
    return 1;
}

void printMaze() {
    system("clear");
    for (int i = 0; i < MAX_ROWS; i++) {
        printf("%s\n", maze[i]);
    }
    printf("Moves: %d\n", moveCount);
}

void movePlayer() {
    printf("Enter the direction (wasd): ");
    scanf(" %c", &dir);
    int nextRow = row, nextCol = col;

    switch (dir) {
        case 'w': nextRow--; break;
        case 's': nextRow++; break;
        case 'a': nextCol--; break;
        case 'd': nextCol++; break;
        default: printf("Invalid direction!\n"); return;
    }

    if (nextRow < 0 || nextRow >= MAX_ROWS || nextCol < 0 || nextCol >= MAX_COLS) {
        printf("Out of bounds!\n");
        return;
    }

    char nextCell = maze[nextRow][nextCol];

    if (nextCell == ' ' || nextCell == '@') {
        maze[nextRow][nextCol] = 'P';
        maze[row][col] = ' ';
        row = nextRow;
        col = nextCol;
        moveCount++;
    } else if (nextCell == 'B') {
        int boxNextRow = nextRow + (nextRow - row);
        int boxNextCol = nextCol + (nextCol - col);

        if (maze[boxNextRow][boxNextCol] == ' ' || maze[boxNextRow][boxNextCol] == '@') {
            maze[boxNextRow][boxNextCol] = 'B';
            maze[nextRow][nextCol] = 'P';
            maze[row][col] = ' ';
            row = nextRow;
            col = nextCol;
            moveCount++;
        }
    }
}

int checkWin() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (maze[i][j] == 'B' && maze[i][j] != '@') {
                return 0;
            }
        }
    }
    return 1;
}

void saveScore(int level, int score) {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Failed to save score\n");
        return;
    }
    fprintf(file, "Level %d: %d moves\n", level, score);
    fclose(file);
}

void startGame() {
    int level = 1;
    while (1) {
        if (!loadLevel(level)) {
            break;
        }

        moveCount = 0;
        row = 19; col = 7;

        while (1) {
            printMaze();
            movePlayer();

            if (checkWin()) {
                printf("Level %d completed in %d moves!\n", level, moveCount);
                saveScore(level, moveCount);
                break;
            }
        }
        level++;
    }
}

int main() {


    char cwd[1024];

    printf("Current directory: %s\n", cwd);

    startGame();
    return 0;
}
