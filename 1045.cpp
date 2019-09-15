#include <cstdio>
#include <algorithm>

const int MAXN = 200 + 10;
const int MAXM = 200 + 10;
const int MAXL = 10000 + 10;

int a[MAXM], b[MAXL];
int id[MAXN];

int f[MAXL];

int main() {
    int numOftype;
    scanf("%d", &numOftype);

    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (id[a[i]] == 0) id[a[i]] = ++cnt;
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    if (id[b[0]] != 0) f[0] = 1;
    else f[0] = 0;

    for (int i = 1; i < m; i++) {
        if (id[b[i]] == 0) {
            f[i] = 0;
            continue;
        }

        int max = 0;
        for (int j = 0; j < i; j++) {
            if (id[b[j]] != 0 && id[b[j]] <= id[b[i]]) max = std::max(max, f[j]);
        }
        f[i] = max + 1;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = std::max(ans, f[i]);
        // printf("%d ", f[i]);
    }
    // printf("\n");

    printf("%d\n", ans);
    return 0;
}
