#include <stdio.h>

int main() {
    union key {
        int k;
        char ch[2];
    } u;

    u.k = 258;
    printf("%d %d", u.ch[0], u.ch[1]);
}