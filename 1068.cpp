#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <cstring>

const int MAXN = 10000 + 10;
const int MAXM = 100 + 10;

int a[MAXN], f[MAXN];
bool p[MAXN][MAXM];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    std::sort(a, a + n, [](int a, int b)->bool{return a > b;});
    std::fill(f, f + MAXN, -100000);

    memset(p, false, sizeof(p));

    f[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= a[i]; j--) {
            if (f[j] <= f[j - a[i]] + a[i]) {
                f[j] = f[j - a[i]] + a[i];

                p[i][j] = true;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         printf("%d ", p[i][j]);
    //     }
    //     printf("\n");
    // }

    std::vector<int> ans;
    if (f[m] != m) printf("No Solution\n");
    else {
        int i = n - 1, j = m;
        while (i >= 0 && j > 0) {
            if (p[i][j]) {
                ans.push_back(a[i]);
                j -= a[i];
            }

            i--;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) printf("%d\n", ans[i]);
        else printf("%d ", ans[i]);
    }
    // printf("%d\n", f[m]);
    return 0;
}
