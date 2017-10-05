/*
	program to find the immediate next prime no.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<termios.h>

int check_prime(int x)
{
    int i;
    for(i=2;x%i!=0;i++);
        if(x==i) {
            printf("\n%d\n",x);
            return 1;
        }
        else {
            return 0;
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
        int n, i, j,testcases=0;
        printf("Enter 1 to run testcase\nEnter 2 to exit\n");
        while(1)
        {
            int count=0,choice;
            printf("Enter your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    testcases++;
                    printf("Enter a number : ");
                    scanf("%d",&n);
    

                    for(i=n+1;;i++){
                        if(check_prime(i)){
                            break;
                        }
                    }
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
