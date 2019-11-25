#include <cstdio>

bool is_prime(int x) {
    if (x == 1 || x == 0) return false;
    if (x == 2) return true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n >= 0) {
        int d = 0;
        scanf("%d", &d);

        int tmp = n, sum = 0;
        while (tmp) {
            sum = sum * d + (tmp % d);
            tmp /= d;
        }

        printf("%s\n", (is_prime(sum) && is_prime(n)) ? "Yes" : "No");
    }
    return 0;
}
