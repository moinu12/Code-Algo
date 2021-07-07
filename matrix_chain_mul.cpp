#include<bits/stdc++.h>
using namespace std;

#define MAX 9999
#define INF 1e9

int cost [ MAX ][ MAX ], path[ MAX ][ MAX ], mat[ MAX ], n ;

void Matrix_Chain_Order( )
{
    for( int l = 2; l <= n; l++ )
    {
        for( int i = 1; i <= n-l+1; i++ )
        {
            int j = i+l-1;
            cost[ i ][ j ] = INF;
            for( int k = i; k <= j-1; k++ )
            {
                int q = cost[ i ][ k ] + cost[ k+1 ][ j ] + mat[ i-1 ] * mat[ k ] * mat[ j ];
                if( q < cost[ i ][ j ] )
                {
                    cost[ i ][ j ] = q;
                    path[ i ][ j ] = k;
                }
            }
        }
    }
}

void Print( int i, int j )
{
    if( i == j )
    {
        cout << " A" << i ;
        return ;
    }
    else
    {
        cout << " ( ";
        Print( i, path[ i ][ j ] );
        Print( path[ i ][ j ] + 1, j );
        cout << " ) ";
    }
}

int main()
{
    cout<<"Enter The Number of Matrix : "<<endl;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cout << "Dimension for matrix A" << i << ":\n" << endl ;
        cin >> mat [ i-1 ] >> mat [ i ] ;
    }
    Matrix_Chain_Order( );
    cout << "Minimum number of multiplication : " << cost[ 1 ][ n ] << endl ;
    Print( 1, n );
    return 0;
}

