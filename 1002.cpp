#include <cstdio>

const int MAXN = 1000 + 10;

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

    int cnt = 0;
    for (int i = 0; i <= 1000; i++) {
        ans[i] = poly1[i] + poly2[i];
        if (ans[i] != 0) cnt++;
    }

    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (ans[i] != 0) printf(" %d %.1lf", i, ans[i]);
    }
    return 0;
}