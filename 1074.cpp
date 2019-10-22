#include <cstdio>
#include <vector>
#include <algorithm>

const int MAXN = 100000 + 10;

struct Node {
    int address, data, next;
    bool flag;

    Node() : address(0), data(0), next(-1), flag(false) {}
} nodes[MAXN];

int main() {
    int head, n, k;
    scanf("%d%d%d", &head, &n, &k);

    for (int i = 0; i < n; i++) {
        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);

        nodes[address].address = address;
        nodes[address].data = data;
        nodes[address].next = next;
    }

    std::vector<Node> vec;

    int cnt = 0;
    for (int v = head; v != -1; v = nodes[v].next) {
        cnt++;
        nodes[v].flag = true;

        if (cnt <= k) vec.push_back(nodes[v]);
    }

    std::reverse(vec.begin(), vec.end());

    // printf("-----------\n");
    // for (auto x : vec) {
    //     printf("%05d %d %05d\n", x.address, x.data, x.next);
    // }

    int tmp = vec[0].next;
    for (int i = 0; i < vec.size(); i++) {
        if (i < vec.size() - 1) vec[i].next = vec[i + 1].address;
        else vec[i].next = tmp;
    }

    // printf("-----------\n");
    for (auto x : vec) {
        if (x.next != -1) printf("%05d %d %05d\n", x.address, x.data, x.next);
        else printf("%05d %d -1\n", x.address, x.data);
    }

    for (int v = tmp; v != -1; v = nodes[v].next) {
        printf("%05d %d ", nodes[v].address, nodes[v].data);
        if (nodes[v].next != -1) printf("%05d\n", nodes[v].next);
        else printf("-1\n");
    }
    return 0;
}
