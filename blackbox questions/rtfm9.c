
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<termios.h>
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

    int start=0;
    struct termios oflags, nflags;
    char password[64];

    /* disabling echo */
    tcgetattr(fileno(stdin), &oflags);
    nflags = oflags;
    nflags.c_lflag &= ~ECHO;
    nflags.c_lflag |= ECHONL;

    if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0) {
        perror("tcsetattr");
        return EXIT_FAILURE;
    }

    printf("password: ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1] = 0;
    if(strcmp(password,"rtfm2k17")==0)
        start=1;

    /* restore terminal */
    if (tcsetattr(fileno(stdin), TCSANOW, &oflags) != 0) {
        perror("tcsetattr");
        return EXIT_FAILURE;
    }
    if(start)
    {
        int choice,testcases=0;
        printf("Enter 1 to run testcase\nEnter 2 to exit\n");
        while(1)
        {
            printf("Enter your choice:- ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    testcases++;
                    char str[100];
                    printf("Enter a string: ");
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
                    printf("%d\n", s);
                break;

                case 2:
                    printf("Testcases used: %d\n", testcases);
                    return 0;

                default:
                    printf("Wrong choice\n");
            }
        }
    }
    else
        printf("Wrong password\n");
    return 0;
}
