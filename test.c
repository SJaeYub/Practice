#include <stdio.h>
#include <stdbool.h>

bool d(int);

int main() {
    int k = 0, cnt = 0;
    scanf("%d", &k);    
    d(k);    
    return 0;
    
}

bool d(int n) {
    int a, b, c, d;

    if(n < 100) {               
        printf("한수입니다 %d\n", n);
        return true;
    }    
    else if(100 <= n && n < 1000) {
        b = ((n - 1000*(n/1000))/100);
        c = (((n - 1000*(n/1000))%100)/10);
        d = (((n - 1000*(n/1000))%100)%10); 

        if((b - c) == (c - d)) {
        printf("한수입니다 %d\n", n);
            return true;
        }
        else {
            printf("한수가 아닙니다 %d\n", n);
            return false;
        }
    }
    else {
        printf("한수가 아닙니다 %d\n", n);
        return false;
    }
    
}