#include <stdio.h>
#include <stdlib.h>
char maze[20][21]={
{'#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','\n'},
{'#','#','#','#','#','#','#','P','#','#','#','#','#','#','#','#','#','#','#','#','\n'},
    }
;
char dir = 0;
int row=19, col=7;
void direction(void) {
    printf("Enter the direction:(wasd) ");
    scanf("\n%c", &dir);
    switch (dir) {
        case 'w': {
            if(maze[row-1][col]==' ') {printf("good\n");
                maze[row-1][col]='P';
                maze[row][col]=' ';
                row--;
            }
            else {printf("sad\n");}
            break;
        }
        case 's': {
            if(maze[row+1][col]==' ') {printf("good\n");
                maze[row+1][col]='P';
                maze[row][col]=' ';
                row++;
            } break;
        }
        case 'a': {
            if(maze[row][col-1]==' ') {printf("good\n");
                maze[row][col-1]='P';
                maze[row][col]=' ';
                col--;
            }break;
        }
        case 'd': {
            if(maze[row][col+1]==' ') {printf("good\n");
                maze[row][col+1]='P';
                maze[row][col]=' ';
                col++;
            } break;
        }
    } printf(maze);
}


int main() {
    printf(maze);
    while (1) {direction();
        if (maze[0][7] == 'P') {
            printf("Win!\n");
            system("pause");
return 0;
        }



    }
}