#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

const int MAXN = 10000 + 5;

std::vector<int> g[MAXN];
bool vis[MAXN];
int depth[MAXN];

void dfs(int n, int x, int cnt, int &maxDepth) {
    depth[x] = cnt;
    vis[x] = true;
    maxDepth = std::max(cnt, maxDepth);

    for (auto ch : g[x]) {
        if (!vis[ch]) dfs(n, ch, cnt + 1, maxDepth);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
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
        std::set<int> ans;
        for (int i = 1; i <= n; i++) {
            if (depth[i] == maxDepth) {
                ans.insert(i);
            }
        }

        int x = *ans.begin();
        memset(vis, false, sizeof(vis));
        memset(depth, 0, sizeof(depth));

        dfs(n, x, 0, maxDepth);

        for (int i = 1; i <= n; i++) {
            if (depth[i] == maxDepth) {
                ans.insert(i);
            }
        }

        for (auto &x : ans) {
            printf("%d\n", x);
        }
    }
    return 0;
}
