/*
	Program:- Factors of a number
*/

#include "stdio.h"
#include "string.h"
int main()
{
	int i,number;
	while(1)
	{
		printf("Enter a number: ");
		scanf("%d",&number);
		for(i=1;i<=number;i++)
		{
			if(number%i==0)
				printf("%d ",i);
		}
		printf("\n");
	}
}