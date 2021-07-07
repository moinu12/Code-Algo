#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll big_mod(ll base, ll power, ll mod)
{
    if(power==0)
        return 1;
    else if(power%2==1)
    {
        int p1 = base % mod;
        int p2 = (big_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else
    {
        int p1 = (big_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}

int main()

{
    ll a,b,M;
    while(cin>>a>>b>>M)
    {
        ll x=big_mod(a,b,M);
        printf("%lld\n", x);
    }

    return 0;
}
