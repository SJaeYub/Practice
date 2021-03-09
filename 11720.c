#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    char k[n];   
    scanf("%s", &k[0]); 
    for(int i = 0; i < n; i++) {
        sum = sum + k[i] - '0';
    }

    printf("%d\n", sum);

    


}