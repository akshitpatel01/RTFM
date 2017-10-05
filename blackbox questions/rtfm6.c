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
                    int i,j,k,l,m,n;
                    char str[11]={'z','o','t','t','f','f','s','s','e','n','\0'};
                    char b[11]={'t','e','t','t','f','f','s','s','e','n','\0'};

                    printf("Enter a positive decimal number: ");
                    scanf("%d",&k);

                    if(k==0)
                      printf("%d\n",'z'-97+1);
                    else if(k>=10 && k<=19)
                    { 
                        int l=b[k-10] -97;
                        printf("%d\n",l+1);
                    }
                    else
                    {
                        n=k;
                        int arr[10];
                        i=0;
                        while(n!=0)
                        {
                            arr[i++]=n%10;
                            n=n/10;
                        }
                        int l=str[arr[i-1]]-97;
                        printf("%d\n",l+1);
                    }
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
