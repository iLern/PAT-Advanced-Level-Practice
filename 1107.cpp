#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

const int MAXN = 1000 + 10;

struct UnionFindSet {
    int fa[MAXN], s[MAXN];
    int size;

    UnionFindSet(int size) : size(size) {
        for (int i = 0; i < size; i++) {
            s[i] = 1;
            fa[i] = i;
        }
    }

    int find(int x) {
        if (fa[x] == x) return x;
        else return fa[x] = find(fa[x]);
    }

    void merge(int r1, int r2) {
        int x = find(r1);
        int y = find(r2);

        fa[x] = y;
        s[x] = s[y] = (s[x] + s[y]);
    }
};

int main() {
    int n;
    scanf("%d", &n);

    UnionFindSet ufs(n);
    std::vector<std::set<int>> v(n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d:", &num);

        for (int j = 0; j < num; j++) {
            int x;
            scanf("%d", &x);

            v[i].insert(x);

            for (int k = 0; k < i; k++) {
                if (v[k].count(x) && ufs.find(k) != ufs.find(i)) ufs.merge(k, i);
            }
        }
    }

    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (ufs.fa[i] == i) ans.push_back(ufs.s[i]);
    }

    std::sort(ans.begin(), ans.end(), [](int a, int b)->bool{return a > b;});
    
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) printf("%d\n", ans[i]);
        else printf("%d ", ans[i]);
    }

    return 0;
}
