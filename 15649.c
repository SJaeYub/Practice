#include <stdio.h>
#include <stdbool.h>

void func(int);

int n, m;
int arr[10] = {0,};
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k + 1);
            isused[i] = false;
        }
        
    }
}

int main() {
    
    scanf("%d", &n);
    scanf("%d", &m);
    func(0);
}


