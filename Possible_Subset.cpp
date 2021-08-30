#include<bits/stdc++.h>
using namespace std ;

Possible_subset(int a[], int  n )
{
    for( int i = 0 ; i< (1<<n ) ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
            if( i &(1<<j))
                cout << a[j] << " " ;
        cout << endl;
    }
}

int main()
{
    int n ;
    cin >> n ;
    int a[n+2] ;
    for( int i = 0 ; i < n; i++ )
        cin  >> a[i] ;
    Possible_subset(a,n) ;
}
