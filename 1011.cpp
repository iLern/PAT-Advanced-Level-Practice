#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

char s[3] = {'W', 'T', 'L'};

int main() {
    double a[3];
    double ans = 1;
    for (int i = 0; i < 3; i++) {
        int k = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &a[j]);
            if (a[j] > a[k]) k = j;
        }
        printf("%c ", s[k]);
        ans *= a[k];
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}
