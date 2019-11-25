#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <utility>
#include <climits>
#include <queue>

const int MAXN = 500 + 10;

struct Node;
struct Edge;

struct Node {
    int dis, num;
    std::vector<Edge> edges;
    std::vector<Node*> fr;

    Node() : dis(INT_MAX), num(0) {
        edges.clear();
        fr.clear();
    }
} nodes[MAXN];

struct Edge {
    Node *fr, *to;
    int w;

    Edge(Node *fr, Node *to, int w) : fr(fr), to(to), w(w) {}
};

void add_edge(int u, int v, int w) {
    nodes[u].edges.push_back(Edge(&nodes[u], &nodes[v], w));
    nodes[v].edges.push_back(Edge(&nodes[v], &nodes[u], w));
}

using info = std::pair<int, Node*>;
void dijkstra(Node *x) {
    std::priority_queue<info, std::vector<info>, std::greater<info>> pq;

    x->dis = 0;
    pq.push(std::make_pair(0, x));

    while (!pq.empty()) {
        info v = pq.top();
        pq.pop();

        if (v.first != v.second->dis) continue;

        for (auto &e : v.second->edges) {
            if (e.to->dis > v.second->dis + e.w) {
                e.to->dis = v.second->dis + e.w;
                e.to->fr.clear();
                e.to->fr.push_back(v.second);
                pq.push(std::make_pair(e.to->dis, e.to));
            } else if (e.to->dis == v.second->dis + e.w) {
                e.to->fr.push_back(v.second);
            }
        }
    }
}

void dfs(Node *x, int c, int tmpAns, int &ans) {
    if (x->fr.empty()) {
        printf("%d\n", x - nodes);
    } else {
        printf("%d ", x - nodes);
        for (auto v : x->fr) {
            dfs(v, c, tmpAns + (c / 2 - x->num), ans);
        }
    }
}

int main() {
    int c, n, sp, m;
    scanf("%d%d%d%d", &c, &n, &sp, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nodes[i].num);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);

        add_edge(u, v, w);
    }

    dijkstra(&nodes[0]);

    printf("----\n");
    int ans = 0;
    dfs(&nodes[sp], c, c / 2 - nodes[sp].num, ans);

    printf("%d\n", ans);
    return 0;
}
