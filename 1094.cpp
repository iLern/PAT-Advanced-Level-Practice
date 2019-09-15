#include <cstdio>
#include <vector>
#include <queue>

const int MAXN = 100 + 10;

struct Node {
    int id;
    std::vector<Node*> ch;

    int depth;
    
    Node() {
        id = depth = 0;
        ch.clear();
    }

    void addChild(Node *ch) {
        this->ch.push_back(ch);
    }
} nodes[MAXN];

int max, maxId;
int cnt[MAXN];
void bfs(Node *root) {
    max = maxId = 0;

    std::queue<Node*> q;

    root->depth = 1;
    q.push(root);

    while (!q.empty()) {
        Node *v = q.front();
        q.pop();

        if (++cnt[v->depth] > max) {
            max = cnt[v->depth];
            maxId = v->depth;
        }

        for (auto &x : v->ch) {
            x->depth = v->depth + 1;
            q.push(x);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) nodes[i].id = i;

    for (int i = 0; i < m; i++) {
        int fa, num;
        scanf("%d%d", &fa, &num);

        for (int j = 0; j < num; j++) {
            int ch;
            scanf("%d", &ch);

            nodes[fa].addChild(&nodes[ch]);
        }
    }

    bfs(&nodes[1]);

    printf("%d %d", max, maxId);

    return 0;
}
