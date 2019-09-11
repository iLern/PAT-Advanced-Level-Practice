#include <cstdio>
#include <vector>
#include <algorithm>

const int MAXN = 100 + 10;

std::vector<int> ans[MAXN];

typedef struct Node {
    struct Node *ch, *next;
    struct Node *fa;
    int weight, sum;
} Node;

Node nodes[MAXN];

void addChild(Node *fa, Node *ch) {
    ch->fa = fa;
    ch->next = fa->ch;
    fa->ch = ch;
}

void dfs(Node *x) {
    if (x->fa) x->sum += x->fa->sum;
    for (Node *c = x->ch; c; c = c->next) {
        dfs(c);
    }
}

void solve(Node *x, int cnt) {
    if (x->fa) solve(x->fa, cnt);
    ans[cnt].push_back(x->weight);
}

bool cmp(std::vector<int> a, std::vector<int> b) {
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] == b[i]) continue;
        else return a[i] > b[i];
    }
    return a.size() > b.size();
}

int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nodes[i].weight);
        nodes[i].sum = nodes[i].weight;
    }

    for (int i = 0; i < m; i++) {
        int fa;
        scanf("%d", &fa);

        int num;
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            int ch;
            scanf("%d", &ch);

            addChild(nodes + fa, nodes + ch);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!nodes[i].fa) {
            dfs(nodes + i);
            break;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!nodes[i].ch && nodes[i].sum == s) {
            solve(nodes + i, cnt);
            cnt++;
        }
    }

    std::sort(ans, ans + cnt, cmp);

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            if (j == ans[i].size() - 1) printf("%d\n", ans[i][j]);
            else printf("%d ", ans[i][j]);
        }
    }
    return 0;
}
