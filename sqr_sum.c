/*
	program to find the sum of the squaresof the integers of the given digit
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
 int n,t=0,r,q;
 printf("Enter the number to be tested: ");
 scanf("%d",&n);
 q=n;
 do
 {
      r=q%10;
      t+=r*r;
      q=q/10;
 }
 while(q!=0);
 printf("%d",t);
 getch();


}
