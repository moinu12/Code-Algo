#include<bits/stdc++.h>
using namespace std;
int prime[300000],nprime=0,mark[10000007],num=10000007;

int sieve(int n)
{
    int i,j,lmt=sqrt(n)+2;
    mark[0]=1;
    mark[1]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    prime[nprime++]=2;
    for(i=3; i<=n; i+=2)
    {

        if(mark[i]==0)
        {
            prime[nprime++]= i;
            if(i<=lmt)
            {
                for(j=i*i; j<=n; j+=(2*i))
                    mark[j]=1;

            }
        }

    }

}

int List[5000],list_size=0;

void primeFactorize(int n)
{
    list_size=0;

    for(int i=0; prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
                List[list_size++]=prime[i];


            }
        }
    }
    if(n>1)
        List[list_size++]=n;

}





int main()
{

    sieve(num);
    int n;
    scanf("%d",&n);
    primeFactorize(n);
  //  for(int i=0; i<list_size; i++)
    //    printf("%d ", List[i]);

    int divCount=1,cnt=1;
    for(int i=1; i<list_size; i++)
    {
        if(List[i]==List[i-1])
            cnt++;
        else
        {
            divCount=divCount*(cnt+1);
            cnt=1;
        }

    }
    divCount=divCount*(cnt+1);

    printf("%d\n", divCount);


    return 0;
}






