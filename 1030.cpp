#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>
#include <utility>

const int MAXN = 500 + 10;

struct Node;
struct Edge;

struct Node {
    int dis, cost;
    Node *fr;
    std::vector<Edge> edges;

    Node() : dis(INT_MAX), cost(INT_MAX) {
        fr = nullptr;
        edges.clear();
    }
} nodes[MAXN];

struct Edge {
    Node *fr, *to;
    int w, c;

    Edge(Node *fr, Node *to, int w, int c) : fr(fr), to(to), w(w), c(c) {}
};

void add_edge(int u, int v, int w, int c) {
    nodes[u].edges.push_back(Edge(&nodes[u], &nodes[v], w, c));
    nodes[v].edges.push_back(Edge(&nodes[v], &nodes[u], w, c));
}

using info = std::pair<int, Node*>;
void dijkstra(Node *x) {
    std::priority_queue<info, std::vector<info>, std::greater<info>> pq;

    x->dis = x->cost = 0;
    pq.push(std::make_pair(0, x));

    while (!pq.empty()) {
        info v = pq.top();
        pq.pop();

        if (v.first != v.second->dis) continue;
        for (auto e : v.second->edges) {
            if (e.to->dis > e.w + v.second->dis) {
                e.to->dis = e.w + v.second->dis;
                e.to->cost = e.c + v.second->cost;

                e.to->fr = v.second;

                pq.push(std::make_pair(e.to->dis, e.to));
            } else if (e.to->dis == e.w + v.second->dis) {
                if (e.to->cost > e.c + v.second->cost) {
                    e.to->cost = e.c + v.second->cost;
                    e.to->fr = v.second;
                }
            }
        }
    }
}

void print_path(Node *v) {
    if (!v->fr) printf("%d ", v - nodes);
    else {
        print_path(v->fr);
        printf("%d ", v - nodes);
    }

    return;
}

int main() {
    int n, m, s, d;
    scanf("%d%d%d%d", &n, &m, &s, &d);

    for (int i = 0; i < m; i++) {
        int u, v, d, c;
        scanf("%d%d%d%d", &u, &v, &d, &c);

        nodes[u].edges.push_back(Edge(&nodes[u], &nodes[v], d, c));
        nodes[v].edges.push_back(Edge(&nodes[v], &nodes[u], d, c));
    }

    dijkstra(&nodes[s]);

    print_path(&nodes[d]);

    printf("%d %d\n", nodes[d].dis, nodes[d].cost);
    return 0;
}
