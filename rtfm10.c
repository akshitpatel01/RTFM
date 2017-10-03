//523-->151020
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
	                int n,a[3],x,y;
	                printf("\nEnter a 3 digit number: ");
	                scanf("%d",&n);
	                for(int i=2;i>=0;i--)
	                {
		                a[i]=n%10;
		                n/=10;
	                }
	                x=a[0]*a[1];
	                y=a[0]*a[2];
	                printf("\n%d%d%d\n",x,y,x+y-a[0]);
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
