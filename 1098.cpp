#include <algorithm>
#include <vector>
#include <cstdio>

void downAdjust(std::vector<int> &b, int low, int high) {
    int i = 1, j = i * 2;
    while(j <= high) {
        if(j + 1 <= high && b[j] < b[j + 1]) j = j + 1;
        if (b[i] >= b[j]) break;
        std::swap(b[i], b[j]);
        i = j; j = i * 2;
    }
}

int main() {
    int n, p = 2;
    scanf("%d", &n);
    std::vector<int> a(n + 1), b(n + 1);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    while(p <= n && b[p - 1] <= b[p]) p++;

    int index = p;
    
    while(p <= n && a[p] == b[p]) p++;
    
    if(p == n + 1) {
        printf("Insertion Sort\n");
        std::sort(b.begin() + 1, b.begin() + index + 1);
    } else {
        printf("Heap Sort\n");
        p = n;
        while(p > 2 && b[p] >= b[1]) p--;
        std::swap(b[1], b[p]);
        downAdjust(b, 1, p - 1);
    }

    for (int i = 1; i <= n; i++) {
        if (i == n) printf("%d\n", b[i]);
        else printf("%d ", b[i]);
    }
    return 0;
}