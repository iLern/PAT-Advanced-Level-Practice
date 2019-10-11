#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

const int MAXN = 1000 + 10;

struct Node {
    int id, data, rank;

    struct cmp {
        bool operator()(Node *a, Node *b) {
            return a->data > b->data;
        }
    };
} a[MAXN];

int ranks[MAXN];

void getWait(std::priority_queue<Node*, std::vector<Node*>, Node::cmp> &pq, std::queue<Node*> &wait, int turn) {
    while (pq.size() > 1) {
        Node* tmp = pq.top();
        pq.pop();

        tmp->rank = turn;
    }

    if (!pq.empty()) {
        wait.push(pq.top());
        pq.pop();
    }
}

int main() {
    int n, maxSize;
    scanf("%d%d", &n, &maxSize);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].data);
        a[i].id = i;
    }
    
    std::vector<Node*> t;
    std::queue<Node*> wait;
    std::priority_queue<Node*, std::vector<Node*>, Node::cmp> pq;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        t.push_back(&a[x]);
    }

    int turn = 0;
    while (true) {
        if (t.size() == 1) {
            t[0]->rank = turn;
            break;
        }

        int cnt = 0;
        for (auto x : t) {
            pq.push(x);
            cnt++;

            if (cnt >= maxSize) {
                getWait(pq, wait, turn);
                cnt = 0;
            }
        }

        getWait(pq, wait, turn);

        turn++;
        t.clear();
        while (!wait.empty()) {
            t.push_back(wait.front());
            wait.pop();
        }
    }

    std::sort(a, a + n, [](Node a, Node b)->bool{return a.rank > b.rank;});

    int rank = 1, numOfSame = 0, pre = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].rank != pre) {
            rank += numOfSame;
            numOfSame = 1;
        } else {
            numOfSame++;
        }

        ranks[a[i].id] = rank;
        pre = a[i].rank;
    }

    for (int i = 0; i < n; i++) {
        if (i != n - 1) printf("%d ", ranks[i]);
        else printf("%d\n", ranks[i]);
    }
    return 0;
}
