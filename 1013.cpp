#include <cstdio>
#include <cstring>

const int MAXN = 1000 + 10;

bool g[MAXN][MAXN];
bool vis[MAXN];

void dfs(int x, int n) {
    vis[x] = true;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        else if (g[x][i] && !vis[i]) dfs(i, n);
    }
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = true;
    }

    for (int i = 0; i < k; i++) {
        memset(vis, false, sizeof(vis));

        int x;
        scanf("%d", &x);

        vis[x] = true;

        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                dfs(j, n);
                cnt++;
            }
        }

        printf("%d\n", cnt - 1);
    }
    return 0;
}
