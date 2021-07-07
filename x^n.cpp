#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll Pow(ll x , ll n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
    {
        ll y=Pow(x,n/2);
        return y*y;
    }
    else

        return x*Pow(x,n-1);

}
int main()
{
    ll n, x ;


        cin >> x >> n ;
        ll a = Pow(x,n);
        cout << a << endl ;




    return 0;
}
