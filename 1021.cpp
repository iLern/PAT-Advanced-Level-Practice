#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

const int MAXN = 10000 + 10;

bool g[MAXN][MAXN];
bool vis[MAXN];
int depth[MAXN];

void dfs(int n, int x, int cnt, int &maxDepth) {
    depth[x] = cnt;
    vis[x] = true;
    maxDepth = std::max(cnt, maxDepth);
    for (int i = 1; i <= n; i++) {
        if (g[x][i] && !vis[i]) {
            dfs(n, i, cnt + 1, maxDepth);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = true;
    }

    int cnt = 0;
    int maxDepth = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(n, i, 0, maxDepth);
            cnt++;
        }
    }

    if (cnt > 1) {
        printf("Error: %d components", cnt);
    } else {
        std::vector<int> vec;
        for (int i = 1; i <= n; i++) {
            if (depth[i] == maxDepth) {
                vec.push_back(i);
            }
        }

        std::vector<int> ans;
        for (auto x : vec) {
            memset(vis, false, sizeof(vis));
            memset(depth, 0, sizeof(depth));

            dfs(n, x, 0, maxDepth);

            for (int i = 1; i <= n; i++) {
                if (depth[i] == maxDepth) {
                    ans.push_back(i);
                }
            }
        }

        for (auto &x : vec) ans.push_back(x);

        std::sort(ans.begin(), ans.end());

        for (auto &x : ans) {
            printf("%d\n", x);
        }
    }
    return 0;
}
