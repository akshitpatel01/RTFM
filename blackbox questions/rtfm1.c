/*
	Program:- Add positions of vowels in a string
*/

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
		int i,sum,testcases=0,choice;
		char string[100];
		printf("Enter 1 to run testcase\nEnter 2 to exit\n");
		while(1)
		{
			printf("Enter your choice: ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					testcases++;
					sum=0;
					printf("Enter a string: ");
					scanf("%s",string);
					int l=strlen(string);
					for(i=0;i<l;i++)
					{
						if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u')
						{
							sum+=(i+1);
						}
					}
					printf("%d\n",sum);
				break;

				case 2:
					printf("Testcases Used: %d\n",testcases);
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
