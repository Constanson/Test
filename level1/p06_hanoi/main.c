#include <stdio.h>

unsigned long long k=0;
void hanoi(char a, char b ,char c ,int m) ;
void print (char a , char b );
int main(){
        int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
      char a='A';
    char b='B';
    char c='C';


        hanoi(a,b,c,n);

printf("%llutimes in total",k);
        return 0;
    }

void hanoi(char a, char b ,char c ,int m) {
    /*
 * 将m个盘从a移动到c
 */if (m == 1) {
        print (a , c);
    } else {
        hanoi(a,c,b,m-1);
        printf("%c->%c \n",a,c);
        k++;
        hanoi(b,a,c,m-1);
    }
}
void print (char a, char b ) {
    printf("%c->%c \n", a, b);
    k++;
}
