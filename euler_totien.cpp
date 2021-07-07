#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define Max 100000008
ll prime[Max], nprime = 0, mark[ Max ];

ll sieve( ll n )
{
    ll i, j, lmt = sqrt(n) ;
    mark[1] = 1 ;
    for(i = 4 ; i <= n ; i += 2 )
        mark[i] = 1 ;
    prime[nprime++] = 2 ;
    for(i = 3 ; i <= n ;  i += 2 )
    {

        if( mark[i] == 0 )
        {
            prime[ nprime++ ] = i ;
            if( i <= lmt )
            {
                for( j = i*i ; j <= n ; j += ( 2 * i ) )
                    mark[j] = 1 ;

            }
        }

    }

}




ll List[500];
ll listSize ;
void primeFactorize( ll n )
{
    listSize = 0 ;
    ll sqrtN = ( sqrt(n) );
    for( ll i = 0; prime[i] <= sqrtN; i++ )
    {
        if( n % prime[i] == 0 )
        {

            while( n % prime[i] == 0 )
            {
                n /= prime[i];
                List[listSize] = prime[i];
                listSize++;
            }

        }
    }
    if( n > 1 )
    {

        List[listSize] = n;
        listSize++;
    }
}


int main()
{

    sieve(100000008);
    ll n ;
    cin >> n ;

    primeFactorize( n );
    vector<ll> v ;
    for( ll i = 0; i < listSize; i++ )
    {
        v.push_back(List[i]);
        cout << List[i] << endl ;
    }

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    ll ans = n ;
    for(ll i = 0; i < v.size() ; i++ )
    {
        ll x = v[i] -1  ;
        ans = (ans/v[i])*( x );
        cout << x << endl;
    }
    cout << ans << endl ;
    return 0;
}





