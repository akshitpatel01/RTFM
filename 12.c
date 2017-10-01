#include<stdio.h>
//169 -> (1x3)(6x2)(9x1) -> 3129

int main() {
    int n, dig = 0, p = 1;
    printf("\nEnter number");
    scanf("%d", &n);
    int m = n;
    while(m != 0) {
        dig++;
        p *= 10;
        m /= 10;
    }
    p /= 10;

    while(dig != 0){
        printf("%d ", (n/p)*dig);
        n = n%p;
        p /= 10;
        dig--;
    }

    return 0;
}
