#include <cstdio>

const int MAXN = 10000 + 10;

struct UnionFindSet {
    int fa[MAXN], s[MAXN];
    int size;

    UnionFindSet(int size) : size(size) {
        for (int i = 0; i < size; i++) {
            fa[i] = i;
            s[i] = -1;
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

    UnionFindSet ufs(MAXN);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        int root = -1;
        for (int j = 0; j < num; j++) {
            int x;
            scanf("%d", &x);

            if (ufs.s[x] == -1) ufs.s[x] = 1;

            if (j == 0) root = x;
            else ufs.merge(x, root);
        }
    }

    int cnt = 0, cntb = 0;
    for (int i = 0; i < MAXN; i++) {
        if (ufs.s[i] != -1 && ufs.fa[i] == i) cnt++;
        if (ufs.s[i] != -1) cntb++;
    }

    printf("%d %d\n", cnt, cntb);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (ufs.find(x) == ufs.find(y)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
