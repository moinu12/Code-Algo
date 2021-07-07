#include<bits/stdc++.h>
using namespace std;


int main()
{
    int nn = 100 ;
    int ncr[nn+3][nn+3] ;
    for ( int i  = 0 ; i<= nn ; i++ )
    {
        for( int j = 0 ; j <= nn ; j++ ) {

            if( i == 0 || i == j )
                ncr[i][j] = 1 ;
            else
                ncr[i][j] = 0 ;

        }

    }
    for( int i = 2  ;  i <= nn ; i++ )
    {
        for( int j = 1 ; j <= i ; j++ )
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j] ;
    }

 int n , r;
 cin >> n >> r ;
 cout << ncr[n+1][r+1] << endl ;



}


