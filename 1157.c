#include <stdio.h>

int main() {
    char s[1000000] = {0,};
    scanf("%s", &s[0]);

    char a[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'
    , 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char f[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'
    , 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int b[26] = {0,};
    int c[26] = {0,};

    for(int i = 0; i < 26; i++) {
        int k = 0;
        int j = 0;
        while(s[j] != '\0') {
            if(a[i] == s[j]) {
                k++;                
            }
            j++;
        }
        b[i] = k;
         
        int t = 0, h = 0;
        while(s[t] != '\0') {
            if(f[i] == s[t]) {
                h++;
            }
            t++;
        }
        c[i] = h;
    }    

    int sum = 0, final[26] = {0,};
    for(int i = 0; i < 26; i++) {
        final[i] = b[i] + c[i];        
        if(sum < final[i]) {
            sum = final[i];
        }
        // printf("%d ", final[i]);
    }
    // printf("\n");
    // printf("%d\n", sum);

    int check_value = 0;
    char check_char = ' ';
    for(int i = 0; i < 26; i++) {        
        if(sum == final[i]) {
            check_value++;    
            check_char = f[i];        
        }
    }

    if(check_value == 1) {
        printf("%c\n", check_char);
    }
    else if(check_value > 1) {
        printf("?\n");
    }
    else {
        printf("no most alphabet\n");
    }
}