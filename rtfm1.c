/*
	Program:- Add positions of vowels in a string
*/

#include "stdio.h"
#include "string.h"
int main()
{
	int i,sum;
	char string[100];
	while(1)
	{
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
	}
}
