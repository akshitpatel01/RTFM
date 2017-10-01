// rtfm question 5
#include<stdio.h>

long long int fastpow(long long int i,long long int n)
{
    if (n==0)
        return 1;
    else if(n==1)
        return i;
    else if(n%2==0)
    {
        long long int k=fastpow(i,n/2);
        return(k*k);

    }
    else
    {
        long long int k=fastpow(i,n/2);
        return(k*k*i);
    }


}
int main()
{
    long long int t=5,a,k,i;

    while(t--)
    {
         long long int ans=0;
         printf("enter a number in the range of 0 to 15\n");
        scanf("%lld",&a);
        k=a;
        for(i=1;i<=a;i++)
        {
            ans=ans + fastpow(i,a);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

