#include <stdio.h>

int main() {
    int t = 0;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int r = 0;
        scanf("%d", &r);
        char s[20];
        scanf("%s", &s[0]);
        int j = 0;
        while(s[j] != '\0') {
            for(int i = 0; i < r; i ++) {
                printf("%c", s[j]);
            }            
            j++;
        }
        printf("\n");
    }
    return 0;

}