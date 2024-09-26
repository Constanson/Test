#include <stdio.h>

int main(void) {
    int a,flag=0;
    scanf("%d",&a);
    if(a%2==0) {
        flag=1;
        printf ("不是");
    }
    else
        for(int i=3;i<a;i=i+2)
            if(a%i==0) {
                flag=1;
                printf("不是");
                break;
            }


    if (flag==0) {
        printf("是");
        return 0;
    }



}
