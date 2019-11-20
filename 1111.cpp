#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

const int MAXN = 500 + 10;

struct Node;
struct Edge;

struct Node {
    int dis[2];
    Node *fr[2];
    std::vector<Edge> edges;

    Node() {
        dis[0] = dis[1] = INT_MAX;
        fr[0] = fr[1] = nullptr;
        edges.clear();
    }
} nodes[MAXN];

struct Edge {
    Node *fr, *to;
    int w[2];

    Edge(Node *fr, Node *to, int w, int t) : fr(fr), to(to) {
        this->w[0] = w;
        this->w[1] = t;
    }
};

void add_edge(int u, int v, int l, int t) {
    nodes[u].edges.push_back(Edge(&nodes[u], &nodes[v], l, t));
}

using info = std::pair<int, Node*>;

//type: 0->dis, 1->time
void dijkstra(Node *x, int type) {
    std::priority_queue<info> pq;

    x->dis[0] = x->dis[1] = 0;
    pq.push(std::make_pair(0, x));

    while (!pq.empty()) {
        info v = pq.top();
        pq.pop();

        if (v.first != v.second->dis[type]) continue;
        for (auto &e : v.second->edges) {
            if (e.to->dis[type] > e.w[type] + v.second->dis[type]) {
                e.to->dis[type] = e.w[type] + v.second->dis[type];
                if (type == 0) e.to->dis[type ^ 1] = e.w[type ^ 1] + v.second->dis[type ^ 1];
                else if (type == 1) e.to->dis[type ^ 1] = v.second->dis[type ^ 1] + 1;
                e.to->fr[type] = v.second;

                pq.push(std::make_pair(e.to->dis[type], e.to));
            } else if (e.to->dis[type] == e.w[type] + v.second->dis[type]) {
                if (type == 0 && e.to->dis[type ^ 1] > e.w[type ^ 1] + v.second->dis[type ^ 1]) {
                    e.to->dis[type ^ 1] = e.w[type ^ 1] + v.second->dis[type ^ 1];
                    e.to->fr[type] = v.second;
                } else if (type == 1 && e.to->dis[type ^ 1] > v.second->dis[type ^ 1] + 1) {
                    e.to->dis[type ^ 1] = v.second->dis[type ^ 1] + 1;
                    e.to->fr[type] = v.second;
                }
            }
        }
    }
}

std::vector<int> p[2];
void print_path(int v, int type) {
    if (nodes[v].fr[type]) print_path(nodes[v].fr[type] - nodes, type);
    p[type].push_back(v);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, is_one_way, l, t;
        scanf("%d%d%d%d%d", &u, &v, &is_one_way, &l, &t);

        add_edge(u, v, l, t);
        if (!is_one_way) add_edge(v, u, l, t);
    }

    int s, e;
    scanf("%d%d", &s, &e);

    dijkstra(&nodes[s], 0);
    int ans1 = nodes[e].dis[0];
    print_path(e, 0);

    for (int i = 0; i < n; i++) {
        nodes[i].dis[0] = nodes[i].dis[1] = INT_MAX;
        nodes[i].fr[0] = nodes[i].fr[1] = nullptr;
    }

    dijkstra(&nodes[s], 1);
    int ans2 = nodes[e].dis[1];
    print_path(e, 1);

    if (p[0] == p[1]) {
        printf("Distance = %d; Time = %d:", ans1, ans2);
        if (p[1].size() == 1) printf(" %d -> %d\n", p[1][0], p[1][0]);
        else {
            for (int i = 0; i < p[1].size(); i++) {
                if (i == p[1].size() - 1) printf(" %d\n", p[1][i]);
                else printf(" %d ->", p[1][i]);
            }
        }
    } else {
        printf("Distance = %d:", ans1);
        if (p[0].size() == 1) printf(" %d -> %d\n", p[0][0], p[0][0]);
        else {
            for (int i = 0; i < p[0].size(); i++) {
                if (i == p[0].size() - 1) printf(" %d\n", p[0][i]);
                else printf(" %d ->", p[0][i]);
            }
        }

        printf("Time = %d:", ans2);
        if (p[1].size() == 1) printf(" %d -> %d\n", p[1][0], p[1][0]);
        else {
            for (int i = 0; i < p[1].size(); i++) {
                if (i == p[1].size() - 1) printf(" %d\n", p[1][i]);
                else printf(" %d ->", p[1][i]);
            }
        }
    }
    return 0;
}
