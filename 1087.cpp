//can't pass; same as 1003

#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

const int MAXN = 2000 + 10;

struct Node;
struct Edge;

string id[MAXN];

struct Node {
    int dis;
    vector<Edge> edges;

    int val, cnt, sum_val, num;
    Node *fr;

    Node() : dis(INT_MAX), val(0), cnt(0), sum_val(0), num(0) {
        edges.clear();
        fr = nullptr;
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

using info = pair<int, Node*>;
void dijkstra(Node *x) {
    priority_queue<info> pq;
    
    x->dis = 0;
    x->cnt = 1;
    x->num = 1;
    pq.push(make_pair(0, x));

    while (!pq.empty()) {
        info v = pq.top();
        pq.pop();

        if (v.first != v.second->dis) continue;

        for (auto &e : v.second->edges) {
            if (e.to->dis > e.w + v.second->dis) {
                e.to->cnt = v.second->cnt;

                e.to->dis = e.w + v.second->dis;
                e.to->sum_val = e.to->val + v.second->sum_val;
                e.to->num = v.second->num + 1;
                e.to->fr = v.second;

                pq.push(make_pair(e.to->dis, e.to));
            } else if (e.to->dis == e.w + v.second->dis) {
                e.to->cnt += v.second->cnt;
                if (e.to->sum_val < e.to->val + v.second->sum_val) {
                    e.to->sum_val = e.to->val + v.second->sum_val;
                    e.to->num = v.second->num + 1;
                    e.to->fr = v.second;
                } else if (e.to->sum_val == e.to->val + v.second->sum_val) {
                    if (e.to->num > v.second->num + 1) {
                        e.to->num = v.second->num + 1;
                        e.to->fr = v.second;
                    }
                }
            }
        }
    }
}

void print_path(Node *v, vector<string> &ans) {
    if (!v->fr) ans.push_back(id[v - nodes]);
    else {
        print_path(v->fr, ans);
        ans.push_back(id[v - nodes]);
    }

    return;
}

int main() {
    int n, m;
    string s;

    map<string, int> mp;
    cin >> n >> m >> s;
    
    id[0] = s;
    mp[id[0]] = 0;
    for (int i = 1; i < n; i++) {
        cin >> id[i] >> nodes[i].val;
        mp[id[i]] = i;
    }

    for (int i = 0 ; i < m; i++) {
        string u, v;
        int w;

        cin >> u >> v >> w;
        add_edge(mp[u], mp[v], w);
    }

    dijkstra(&nodes[0]);

    vector<string> ans;
    print_path(&nodes[mp["ROM"]], ans);
    cout << nodes[mp["ROM"]].cnt << ' ' 
         << nodes[mp["ROM"]].dis << ' ' 
         << nodes[mp["ROM"]].sum_val << ' '
         << nodes[mp["ROM"]].sum_val / (ans.size() - 1) << endl;

    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) cout << ans[i] << endl;
        else cout << ans[i] << "->";
    }

    return 0;
}
