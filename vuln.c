#include <stdio.h>

int call_gets(){
    char buf[100];
    gets(buf);
    printf("%s\n", buf);
    return 0;
}

int main(){
    call_gets();
    return 0;
}
