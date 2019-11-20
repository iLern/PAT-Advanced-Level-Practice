#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <vector>
#include <climits>

const int MAXN = 500 + 10;

struct Node;
struct Edge;

struct Node {
    int val;
    std::vector<Edge> edges;

    int dis, maxVal, cnt;

    Node() : val(0), dis(INT_MAX), maxVal(-1), cnt(0) {
        edges.clear();
    }
} nodes[MAXN];

struct Edge {
    Node *fr, *to;
    int w;

    Edge(Node *fr, Node *to, int w) : fr(fr), to(to), w(w) {}
};

void addEdge(int u, int v, int w) {
    nodes[u].edges.push_back(Edge(&nodes[u], &nodes[v], w));
    nodes[v].edges.push_back(Edge(&nodes[v], &nodes[u], w));
}

using info = std::pair<int, Node*>;
void dijkstra(Node *x) {
    std::priority_queue<info, std::vector<info>, std::greater<info>> pq;

    x->dis = 0;
    x->cnt = 1;
    x->maxVal = x->val;

    pq.push(std::make_pair(0, x));

    while (!pq.empty()) {
        info v = pq.top();
        pq.pop();

        if (v.first != v.second->dis) continue;

        for (auto &e : v.second->edges) {
            if (e.to->dis > v.second->dis + e.w) {
                e.to->dis = v.second->dis + e.w;
                e.to->cnt = v.second->cnt;
                e.to->maxVal = e.to->val + v.second->maxVal;
                pq.push(std::make_pair(e.to->dis, e.to));
            } else if (e.to->dis == v.second->dis + e.w) {
                e.to->cnt += v.second->cnt;
                if (e.to->maxVal < e.to->val + v.second->maxVal) {
                    e.to->maxVal = e.to->val + v.second->maxVal;
                }
            }
        }
    }
}

int main() {
    int n, m, c1, c2;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nodes[i].val);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);

        addEdge(u, v, w);
    }

    dijkstra(&nodes[c1]);

    printf("%d %d\n", nodes[c2].cnt, nodes[c2].maxVal);
    return 0;
}
