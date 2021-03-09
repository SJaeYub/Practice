#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int b[n];
    for(int i = 0; i < n; i++) {
        int c = scanf("%d", &c);
        b[i] = c;
    }

    int j = 0, sum = 0;
    int v = j + 1, d = j + 2;
    while(j <= (n - 2)) {
        for(int i = 0; i < n; i++) {
            sum = b[j] + b[v] + b[d + i];
        }
    }
}