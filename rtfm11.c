
// given 23->twothree->8

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<termios.h>
int main()
{
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
                    int n,i=0,j;
                    printf("Input positive number: ");
                    scanf("%d",&n);
                    int b=0;
                    int a[10]={4,3,3,5,4,4,3,5,5,4};
                    while(n!=0)
                    {
                        b=b+a[(n%10)];
                        n/=10;
                    }
                    printf("%d\n",b);
                break;
                
                case 2:
                    printf("Testcases used: %d\n",testcases);
                    return 0;
                
                default:
                    printf("Wrong choice\n");
            }
        }
    }
    else
        printf("Wrong password\n");
}
