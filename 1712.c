#include <stdio.h>
#include <stdlib.h>

int main() {
    int fc, vc, price, q = 1;
    scanf("%d", &fc);
    scanf("%d", &vc);
    scanf("%d", &price);
    
    int tc = fc + (vc*q);
    int revenue = price * q;

    if(vc >= price) {
        printf("-1");       
    }
    else {
        
        printf("%d", fc/(price - vc) + 1);
    }
}