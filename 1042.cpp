#include <cstdio>

const int MAXN = 60;

int card[MAXN], order[MAXN], ans[MAXN];
char color[5] = {'S', 'H', 'C', 'D', 'J'};

void shuffle(int card[], int order[], int ans[]) {
    for (int i = 1; i <= 54; i++) {
        ans[order[i]] = card[i];
    }

    for (int i = 1; i <= 54; i++) {
        card[i] = ans[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= 54; i++) {
        card[i] = i;
        scanf("%d", &order[i]);
    }

    while (n--) {
        shuffle(card, order, ans);
    }

    for (int i = 1; i <= 54; i++) {
        printf("%c%d%c", color[(ans[i] - 1) / 13], (ans[i] - 1) % 13 + 1, i == 54 ? '\n' : ' ');
    }
    return 0;
}
