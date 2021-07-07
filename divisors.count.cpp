#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int div[100007],cnt=0,i;
    cnt=0;
    for( i=1; i*i<n; i++)
    {
        if(n%i==0)
        {
            div[cnt++]=i;
            div[cnt++]=n/i;
        }
    }
    if(i*i==n)
        div[cnt++]=i;

    printf("%d \n",cnt); // divisors count
    sort(div,div+cnt); // sorting
    for(int i=0; i<cnt; i++)
        printf("%d ", div[i]);  // divisors
    printf("\n");



    return 0;
}
