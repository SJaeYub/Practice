#include <stdio.h>

int main() {
    char s[100] = {0,};
    scanf("%s", s);
    char a[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'
    , 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'} ;
    
    int j = 0;
    for(int i = 0; i < 26; i++) {
        int k = 0, j = 0;
        while(s[j] != 0) {
            if(s[j] == a[i]) {
                a[i] = j;
                k++;
            }                        
            j++;
        }
        if(k == 0) {
            printf("-1 ");
        }
        else {
            printf("%d ", a[i]);
        }
    }

        
}