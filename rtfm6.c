#include<stdio.h>
#include<string.h>
int main()
{
    int t=5,i,j,k,l,m,n;
     char str[11]={'z','o','t','t','f','f','s','s','e','n','\0'};
     char b[11]={'t','e','t','t','f','f','s','s','e','n','\0'};
    while(t--)
    {

      printf("enter a positive decimal number\n");
      scanf("%d",&k);

      if(k==0)
        printf("%d\n",'z'-97+1);
      else if(k>=10 && k<=19)
      {
          int l=b[k-10] -97;
          printf("%d\n",l+1);
      }
     /* else if(k>=100 && k<200)
      {
          printf("%d\n",'h'-97+1);
      }
      else if(k>=1000)
      {
          printf("%d\n",'t'-97+1);
      }*/

      else
      {n=k;
      int arr[10];
      i=0;
      while(n!=0)
      {
          arr[i++]=n%10;
          n=n/10;
      }
      int l=str[arr[i-1]]-97;
      printf("%d\n",l+1);
      }


    }

    return 0;
}
