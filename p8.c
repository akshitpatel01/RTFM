//a-z,ab-zy
#include <stdio.h>
#include <string.h>
void main()
{
	char a[20];
	printf("\nEnter characters:");
	scanf("%s",a);
	int n=strlen(a);
	for (int i=0;i<n;i++)
	{
		if (a[i]>96 && a[i]<123)
		{
			a[i]=219-a[i];
		}
	}
	printf("%s\n",a);
}