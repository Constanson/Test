#include <stdio.h>

int main(void) {
    while(1)
    { for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < i; ++j) {
            printf(" ");
        }
        printf("?");
        printf("\n");
        Sleep(100);
    }
        for (int i = 0; i < 50; ++i) {
            for (int j = 0; j < 50-i; ++j) {
                printf(" ");
            }
            printf("?");
            printf("\n");
            Sleep(100);


        }



    }
}