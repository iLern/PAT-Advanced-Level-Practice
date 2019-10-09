#include <cstdio>
#include <algorithm>

const int MAXN = 10000 + 10;

int a[MAXN], f[MAXN], l[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    bool allNeg = true;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) allNeg = false;
    }

    if (a[0] > 0) f[0] = a[0];
    else f[0] = 0;

    for (int i = 1; i < n; i++) {
        if (f[i - 1] + a[i] > a[i]) {
            f[i] = f[i - 1] + a[i];
            l[i] = l[i - 1];
        } else {
            f[i] = a[i];
            l[i] = i;
        }
    }

    int ans = f[0], maxId = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] > ans) {
            ans = f[i];
            maxId = i;
        }
    }

    if (maxId == 0 && n != 1) {
        if (allNeg) printf("%d %d %d\n", ans, a[0], a[n - 1]);
        else printf("0 0 0");
    } else printf("%d %d %d\n", ans, a[l[maxId]], a[maxId]);

    // if (maxId == 0) printf("%d %d %d\n", ans, a[0], a[n - 1]);
    // else printf("%d %d %d\n", ans, a[l[maxId]], a[maxId]);
    return 0;
}
