// sum of squares of factors of a number

#include<stdio.h>
main()
{
    long int n,sum=0;
    int f=1;
    printf(" input positive integer ");
    scanf("%ld",&n);
    while(f<=n)
    {
        if(n%f==0)
            sum=sum+(f*f);
        f++;
    }
    printf("%ld\n",sum);
}
