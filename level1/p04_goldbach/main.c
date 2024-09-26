#include <stdio.h>

int main() {
    printf("4=2+2\n");
    int arr[24] = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int tem = 0;
    for (int i = 4; i < 102; i=i+2) {
        for (int j = 0; j < 24; j++) {
            tem=i-arr[j];
            for (int k = 0; k < 24; k++) {
                if (arr[k] == tem) {
                    printf("%d=%d+%d\n",i,arr[j], arr[k]);
                    tem=0;
                    goto next1;
                }
            }
        }next1:
    }
    return 0;
}