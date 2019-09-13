#include <cstdio>
#include <vector>

const int MAXN = 100000 + 10;

double p = 0, r = 0, ans = 0;
struct Node {
    Node *fa;
    double sum;
    int cnt;
    bool isLeave;

    std::vector<Node*> ch;

    Node() : sum(1), cnt(1), isLeave(false) {
        fa = nullptr;
        ch.clear();
    }

    void addChild(Node *ch) {
        ch->fa = this;
        this->ch.push_back(ch);
    }
} nodes[MAXN];

void dfs(Node *root) {
    if (!root->fa) root->sum = p;
    else root->sum = root->fa->sum * (1 + r / 100);

    for (auto x : root->ch) {
        dfs(x);
    }
}

int main() {
    int n;
    scanf("%d%lf%lf", &n, &p, &r);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num == 0) {
            scanf("%d", &nodes[i].cnt);
            nodes[i].isLeave = true;
        } else {
            for (int j = 0; j < num; j++) {
                int x;
                scanf("%d", &x);

                nodes[i].addChild(&nodes[x]);
            }
        }
    }

    dfs(&nodes[0]);

    // for (int i = 0; i < n; i++) {
    //     printf("%lf ", nodes[i].sum);
    // }
    // printf("\n");

    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i].isLeave) ans += (nodes[i].sum * nodes[i].cnt);
    }

    printf("%.1lf\n", ans);
    return 0;
}
