#include <cstdio>
#include <list>
#include <set>
#include <algorithm>

const int MAXN = 100000 + 10;

struct Node {
    int address, data, next;

    bool operator==(const Node &a) const {
        return (address == a.address && data == a.data && next == a.next);
    }
} nodes[MAXN];

int main() {
    int head, n;
    scanf("%d%d", &head, &n);

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

    std::set<int> st;
    std::list<Node> l2;
    for (auto it = l.begin(); it != l.end(); ) {
        if (st.count(std::abs(it->data))) {
            l2.insert(l2.end(), *it);
            l.erase(it++);
        } else {
            st.insert(std::abs(it->data));
            it++;
        }
    }

    // printf("-----\n");
    for (auto it = l.begin(); it != l.end(); it++) {
        auto tmp = it;
        tmp++;

        if (tmp != l.end()) it->next = tmp->address;
        else it->next = -1;

        if (it->next == -1) printf("%05d %d -1\n", it->address, it->data);
        else printf("%05d %d %05d\n", it->address, it->data, it->next);
    }

    // printf("-----\n");
    for (auto it = l2.begin(); it != l2.end(); it++) {
        auto tmp = it;
        tmp++;

        if (tmp != l2.end()) it->next = tmp->address;
        else it->next = -1;
        
        if (it->next == -1) printf("%05d %d -1\n", it->address, it->data);
        else printf("%05d %d %05d\n", it->address, it->data, it->next);
    }
    return 0;
}
