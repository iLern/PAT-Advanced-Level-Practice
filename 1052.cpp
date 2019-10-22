#include <cstdio>
#include <algorithm>

const int MAXN = 100000 + 10;

struct Node {
    int address, data, next;
    bool flag;

    Node() : address(0), data(0), next(-1), flag(false) {}
} nodes[MAXN];

int main() {
    int n, head;
    scanf("%d%d", &n, &head);

    for (int i = 0; i < n; i++) {
        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);

        nodes[address].address = address;
        nodes[address].data = data;
        nodes[address].next = next;
    }

    int cnt = 0;
    for (int v = head; v != -1; v = nodes[v].next) {
        nodes[v].flag = true;
        cnt++;
    }

    if (cnt == 0) {
        printf("0 -1\n");
    } else {
        std::sort(nodes, nodes + MAXN, [](Node a, Node b)->bool{return !a.flag || !b.flag ? a.flag > b.flag : a.data < b.data;});
        printf("%d %05d\n", cnt, nodes[0].address);
        for (int i = 0; i < cnt; i++) {
            printf("%05d %d ", nodes[i].address, nodes[i].data);
            if (i != cnt - 1) printf("%05d\n", nodes[i + 1].address);
            else printf("-1\n");
        }
    }

    return 0;
}
