#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000000
int main() {
    char string[MAX_LEN] = {0,};
    fgets(string, MAX_LEN, stdin);

    char *p;
    int cnt = 0;
    p = strtok(string, " ");
    while(p != NULL) {
        if(p != " ") {
            cnt++;
        }
        else {
            cnt--;
        }
        
        printf("%s\n", p);
        p = strtok(NULL, " ");
        
    }

    printf("%d\n", cnt);
}