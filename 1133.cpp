#include <cstdio>
#include <list>
#include <vector>
#include <algorithm>

const int MAXN = 100000 + 10;

struct Node {
    int address, data, next;
} nodes[MAXN];

std::vector<Node> v1, v2 ,v3;

int main() {
    int head, n, k;
    scanf("%d%d%d", &head, &n, &k);

    for (int i = 0; i < n; i++) {
        int address;
        scanf("%d", &address);
        nodes[address].address = address;
        scanf("%d%d", &nodes[address].data, &nodes[address].next);
    }

    for (int v = head; v != -1; v =  nodes[v].next) {
        if (nodes[v].data < 0) v1.push_back(nodes[v]);
        else if (nodes[v].data <= k) v2.push_back(nodes[v]);
        else v3.push_back(nodes[v]);
    }

    std::list<Node> l;
    for (auto v : v1) l.insert(l.end(), v);
    for (auto v : v2) l.insert(l.end(), v);
    for (auto v : v3) l.insert(l.end(), v);

    // printf("----\n");
    for (auto it = l.begin(); it != l.end(); it++) {
        auto tmp = it;
        tmp++;

        if (tmp != l.end()) it->next = tmp->address;
        else it->next = -1;

        if (it->next == -1) printf("%05d %d -1\n", it->address, it->data);
        else printf("%05d %d %05d\n", it->address, it->data, it->next);
    }

    return 0;
}