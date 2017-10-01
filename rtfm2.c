/*
	Program:- Factors of a number
*/

#include "stdio.h"
#include "string.h"
int main()
{
	int i,number,testcases=5;
	while(testcases--)
	{
		int count=0;
		printf("Enter a number: ");
		scanf("%d",&number);
		for(i=1;i<=number;i++)
		{
			if(number%i==0)
				count++;
		}
		printf("%d\n",count);
	}
}
