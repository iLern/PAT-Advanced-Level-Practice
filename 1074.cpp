#include <cstdio>

const int MAXN = 100000 + 10;

struct Node {
    int data;
    Node *next;

    Node() {
        data = 0;
        next = nullptr;
    }
} nodes[MAXN];

void reverse(Node *begin, Node *end) {
    
}

int main() {
    int first, n, k;
    scanf("%d%d%d", &first, &n, &k);

    for (int i = 0; i < n; i++) {
        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);
        nodes[address].data = data;

        if (next != -1) nodes[address].next = &nodes[next];
        else nodes[address].next = nullptr;
    }

    int cnt = 0;
    Node *begin = &nodes[first], *end = &nodes[first];
    while (end) {
        if (cnt == 2) reverse(begin, end);
        cnt++;
        
        if (cnt == 3) {
            cnt = 0;
            begin = end;
        }
    }
    return 0;
}
