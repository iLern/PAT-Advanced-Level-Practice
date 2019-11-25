#include <cstdio>

void shift(int x, bool flag) {
    if (x == 0 && !flag) return;
    shift(x / 13, false);

    int tmp = x % 13;
    if (flag && x / 13 == 0) printf("0");
    printf("%c", tmp >= 10 ? 'A' + (tmp - 10) : '0' + tmp);
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    printf("#");
    shift(a, true);
    shift(b, true);
    shift(c, true);
    return 0;
}
