#include <stdio.h>

int d(int);

int main() {
    int n = 1;
    int a[10000];    
    for(int i = 0; i < 10000; i++) {
        a[i] = i + 1;
    }

    for(int i = 1; i <= 10000; i++) {
        n = i;              
        int sum = d(n);
        // if(sum < 10000) {
            a[sum-1] = 0;  
        // }
        // else {
        //     ;
        // }
           
    }

    for(int i = 0; i < 9999; i++) {
        if(a[i] != 0) {
            printf("%d\n", a[i]);            
        }
    }  
}

int d(int n) {
    int sum = 0;

    if(n < 100) {
        int a = (n/1000);
        int b = ((n - 1000*(n/1000))/100);
        int c = (((n - 1000*(n/1000))%100)/10);
        int d = (((n - 1000*(n/1000))%100)%10);     

        sum = n + a + b + c + d;  
    }
    else if(100 <= n < 1000) {
        int a = (n/1000);
        int b = ((n - 1000*(n/1000))/100);
        int c = (((n - 1000*(n/1000))%100)/10);
        int d = (((n - 1000*(n/1000))%100)%10);     

        sum = n + a + b + c + d;  
    }
    else if(1000 <= n < 10000) {   
        int a = (n/1000);
        int b = ((n - 1000*(n/1000))/100);
        int c = (((n - 1000*(n/1000))%100)/10);
        int d = (((n - 1000*(n/1000))%100)%10);     

        sum = n + a + b + c + d;            
    }
    
    return sum;
}