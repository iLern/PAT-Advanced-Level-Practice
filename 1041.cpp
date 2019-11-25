#include <cstdio>
#include <cstring>

const int MAXN = 100000 + 10;

bool unique[MAXN], exist[MAXN];
int a[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    memset(unique, true, sizeof(unique));
    memset(exist, false, sizeof(exist));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (exist[a[i]]) unique[a[i]] = false;
        exist[a[i]] = true;
    }

    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (unique[a[i]]) {
            printf("%d\n", a[i]);
            flag = true;
            break;
        }
    }

    if (!flag) printf("None\n");
    return 0;
}
