#include <stdio.h>
#include <stdlib.h>

void swap(char *, char*);

int main() {
    char a[5], b[5];
    scanf("%s", &a[0]);
    scanf("%s", &b[0]);    

    swap(a + 2, a + 0);
    swap(&b[0] + 2, &b[0]);

    int c = atoi(a);
    int d = atoi(b);

    if(c > d) {
        printf("%d\n", c);
    }
    else {
        printf("%d\n", d);
    }
}
void swap(char *c, char*d) {
    char temp = *c;
    *c = *d;
    *d = temp;
}
