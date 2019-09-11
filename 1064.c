#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000 + 10

int num[MAXN], ans[MAXN];

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int n = 0;

int index = 0;
void inOrder(int x) {
    if (x > n) return;
    inOrder(x * 2);
    ans[x] = num[index++];
    inOrder(x * 2 + 1);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    qsort(num, n, sizeof(int), cmp);

    inOrder(1);

    for (int i = 1; i <= n; i++) {
        if (i != n) printf("%d ", ans[i]);
        else printf("%d\n", ans[i]);
    }
    return 0;
}
