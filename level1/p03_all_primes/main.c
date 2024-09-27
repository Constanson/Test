#include <stdio.h>
#include <time.h>


int main(void) {
    struct timeval start, end;
    mingw_gettimeofday(&start,NULL);
    printf("2\n");
    int flag=0;
    for(int a=3;a<1001;a=a+2){
        flag=0;
        if(a%2==0) {
            flag=1;
        }
        else
            for(int i=3;i<a;i=i+2)
                if(a%i==0) {
                    flag=1;

                }


        if (flag==0) {
            printf("%d\n",a);

        }



    }
    mingw_gettimeofday(&end,NULL);
    double m=0.000001*(end.tv_usec-start.tv_usec)+end.tv_sec-start.tv_sec;
    printf("Time used:%fs\n",m);
    return 0;
}
