#include <cstdio>
#include <list>
#include <set>
#include <algorithm>

const int MAXN = 100000 + 10;

struct Node {
    int address, data, next;
} nodes[MAXN];

int main() {
    int head, n, k;
    scanf("%d%d%d", &head, &n, &k);

    for (int i = 0; i < n; i++) {
        int address;
        scanf("%d", &address);
        nodes[address].address = address;
        scanf("%d%d", &nodes[address].data, &nodes[address].next);
    }

    std::list<Node> l;
    for (int v = head; v != -1; v = nodes[v].next) {
        l.insert(l.end(), nodes[v]);
    }

    // printf("------\n");
    // for (auto it = l.begin(); it != l.end(); it++) {
    //     if (it->next == -1) printf("%05d %d -1\n", it->address, it->data);
    //     else printf("%05d %d %05d\n", it->address, it->data, it->next);
    // }

    int cnt = 0;
    auto st = l.begin();
    for (auto it = l.begin(); it != l.end(); it++) {
        if (cnt == k) {
            std::reverse(st, it);
            cnt = 0;
            st = it;
        }
        cnt++;
    }

    // printf("---\n");
    // printf("*%d*%d*\n", st->data, cnt);
    if (cnt == k) {
        std::reverse(st, l.end());
    }
    // for (auto v : l) {
    //     printf("%d\n", v.data);
    // }

    // printf("------\n");
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


// 00100 6 3
// 00000 4 99999
// 00100 1 12309
// 68237 6 -1
// 33218 3 00000
// 99999 5 68237
// 12309 2 33218