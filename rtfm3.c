/*
	program to find the immediate next prime no.
*/
#include<stdio.h>

int check_prime(int x)
{
    int i;
    for(i=2;x%i!=0;i++);
        if(x==i) {
            printf("\n%d\n",x);
            return 1;
        }
        else {
            return 0;
        }
}

int main()
{
    int n, i, j;
    printf("Enter a number : ");
    scanf("%d",&n);
    

    for(i=n+1;;i++){
        if(check_prime(i)){
            break;
        }
    }


return 0;
}
