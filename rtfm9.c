
#include<stdio.h>
#include<string.h>
//abcd -> 1+2+3+4 ->10 -> 1
int digits(int num) {
    int dig = 0;
    while(num != 0) {
        num /= 10;
        dig++;
    }
    return dig;
}

int main() {
    char str[100];
    scanf("%s", str);
    int n = 0, i, s;
    for(i = 0; i < strlen(str); ++i) {
        n += str[i]-'a'+1;
    }

    while(digits(n) != 1) {
        int m = n; s = 0;
        while(m != 0) {
            s += m%10;
            m /= 10;
        }
        n = s;
    }
    printf("\n%d", s);
    return 0;
}
