//insertion sort
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n ;
    cin >> n ; // input array size
    int a[n+2] ; // array declaration
    for( int i = 0 ; i < n  ; i++ )
        cin >> a[i] ;  // input array value

    for( int i = 0 ; i < n ; i++ )
    {
        int j = i ;
        while( j > 0 && a[j] < a[j-1] )
        {
            // for descending sort ,, we will apply a[j]>a[j-1]
            int temp ;
            temp = a[j] ;
            a[j] = a[j-1] ;
            a[j-1] = temp ;
            j-- ;
            // swap
        }
    }

     cout << "After sorting array : " << endl ;
    for( int  i = 0 ; i < n ; i++ )
        cout << a[i] << " " ;
    cout << endl ;
}
//insertion sort complexity : big O ( n * n )
