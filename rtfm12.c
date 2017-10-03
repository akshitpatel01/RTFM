#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<termios.h>
//169 -> (1x3)(6x2)(9x1) -> 3129

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
                    int n, dig = 0, p = 1;
                    printf("\nEnter number: ");
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
                    printf("\n");
                break;
            
                case 2:
                    printf("Testcases used: %d\n", testcases);
                    return 0;
            
                default:
                    printf("Wrong Choice\n");
            }
        }
    }
    else
        printf("Wrong password\n");
    return 0;
}
