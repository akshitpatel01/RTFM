// rtfm question 5
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<termios.h>

long long int fastpow(long long int i,long long int n)
{
    if (n==0)
        return 1;
    else if(n==1)
        return i;
    else if(n%2==0)
    {
        long long int k=fastpow(i,n/2);
        return(k*k);
    }
    else
    {
        long long int k=fastpow(i,n/2);
        return(k*k*i);
    }
}
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
                    long long int a,k,i;
                    long long int ans=0;
                    printf("Enter a number in the range of 0 to 15: ");
                    scanf("%lld",&a);
                    k=a;
                    for(i=1;i<=a;i++)
                    {
                        ans=ans + fastpow(i,a);
                    }
                    printf("%lld\n",ans);
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
    return 0;
}


