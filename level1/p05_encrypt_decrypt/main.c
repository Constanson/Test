#include <stdio.h>
#include <string.h>
 char str[1000];
char str1[1000];
    char str2[1000];
void encoder() {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str1[i] = ((str[i] - 32 + 60) % 95 + 32);
    }
}
void decoder() {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str2[i] = ((str[i] - 32 +95- 60) % 95 + 32);
    }
}

int main() {



    printf("Enter a string:\n ");
    gets(str);
    encoder();
    decoder();
    decoder();





    printf("incoded:%s\ndecoded:%s",str1,str2);
    return 0;
}
