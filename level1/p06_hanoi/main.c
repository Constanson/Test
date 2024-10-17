#include <stdio.h>
#include"hanoi.h"

int main(){
        int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
      char a='A';
    char b='B';
    char c='C';


        hanoi(a,b,c,n);

printf("%dtimes in total",k);
        return 0;
    }

