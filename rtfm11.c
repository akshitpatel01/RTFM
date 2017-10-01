
// given 23->twothree->8

#include<stdio.h>
main()
{
    int n,i=0,j;
    printf("input positive number ");
    scanf("%d",&n);
    int b=0;
    int a[10]={4,3,3,5,4,4,3,5,5,4};
    while(n!=0)
    {
        b=b+a[(n%10)];
        n/=10;
    }
        printf("%d",b);
}
