#include <cstdio>
#include <algorithm>

const int MAXN = 100000 + 10;

int a[MAXN], b[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    int tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i] + b[i - 1];

        tot += a[i];
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        if (u > v) std::swap(u, v);
        int tmp = b[v - 1] - b[u - 1];

        printf("%d\n", tmp * 2 <= tot ? tmp : tot - tmp);
    }
    return 0;
}
