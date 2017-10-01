//523-->151020
#include <stdio.h>
void main()
{
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
}
