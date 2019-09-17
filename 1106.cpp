#include <cstdio>
#include <vector>
#include <cfloat>

const int MAXN = 100000 + 10;

struct Node {
    int id;
    std::vector<Node *> ch;

    double data;

    Node() {
        ch.clear();
        id = 0;
        data = 1;
    }

    void addChild(Node *x) {
        ch.push_back(x);
    }
} nodes[MAXN];

void dfs(Node *root, double r) {
    if (root->ch.empty()) return;
    for (auto &x : root->ch) {
        x->data = root->data * (1 + r / 100);
        dfs(x, r);
    }
}

int main() {
    int n;
    double p, r;

    scanf("%d%lf%lf", &n, &p, &r);

    for (int i = 0; i < n; i++) nodes[i].id = i;

    Node *root = &nodes[0];
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        for (int j = 0; j < num; j++) {
            int ch;
            scanf("%d", &ch);

            nodes[i].addChild(&nodes[ch]);
        }
    }

    root->data = p;
    dfs(root, r);

    double ans = DBL_MAX;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i].ch.empty()) {
            // printf("%.2lf ", nodes[i].data);
            if (nodes[i].data == ans) cnt++;
            else if (nodes[i].data < ans) {
                ans = nodes[i].data;
                cnt = 1;
            }
        }
    }

    printf("%.4lf %d\n", ans, cnt);
    return 0;
}
