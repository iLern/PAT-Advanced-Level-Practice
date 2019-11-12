#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

const int MAXN = 1000 + 10;

std::vector<int> vec[MAXN];
int depth[MAXN];
bool vis[MAXN];

int bfs(int x, int l) {
    std::queue<int> q;
    q.push(x);

    depth[x] = 0;
    vis[x] = true;

    int ans = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto ele : vec[v]) {
            if (vis[ele]) continue;
            else {
                depth[ele] = depth[v] + 1;
                vis[ele] = true;
                if (depth[ele] <= l) {
                    ans++;
                    q.push(ele);
                }
            }
        }
    }

    return ans;
}

int main() {
    int n, l;
    scanf("%d%d", &n, &l);

    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        for (int j = 1; j <= num; j++) {
            int x;
            scanf("%d", &x);
            vec[x].push_back(i);
        }
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);

        memset(vis, false, sizeof(vis));
        memset(depth, 0, sizeof(depth));

        printf("%d\n", bfs(x, l));

        // for (int i = 1; i <= n; i++) {
        //     printf("depth[%d] = %d\n", i, depth[i]);
        // }
    }
    return 0;
}
