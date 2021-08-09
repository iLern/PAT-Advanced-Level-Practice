#include <cstdio>

const int MAXN = 2000 + 10;

double poly1[MAXN], poly2[MAXN];
double ans[MAXN];

int main() {
    int k1;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        int x;
        scanf("%d", &x);

        scanf("%lf", &poly1[x]);
    }

    int k2;
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++) {
        int x;
        scanf("%d", &x);

        scanf("%lf", &poly2[x]);
    }

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (poly1[i] != 0 && poly2[j] != 0) {
                ans[i + j] += poly1[i] * poly2[j];
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i <= 2000; i++) {
        if (ans[i] != 0) cnt++;
    }

    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--) {
        if (ans[i] != 0) printf(" %d %.1lf", i, ans[i]);
    }
    return 0;
}