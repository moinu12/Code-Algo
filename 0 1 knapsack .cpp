#include<bits/stdc++.h>
using namespace std ;


// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack( int W,  int wt[], int  val[], int n )
{
    int i, w ;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for ( i = 0 ; i  <=  n;   i++ )
    {
        for ( w = 0 ; w  <=  W ;  w++ )
        {
            if (  i == 0 || w == 0 )
                K[i][w] = 0 ;
            else if  ( wt[i - 1] <= w )
                K[i][w] = max( val[i - 1] + K[i - 1][w - wt[i - 1]],   K[i - 1][w]   );
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main()
{
    int n, i ;
    cout << "Enter the Item numbers : " ;
    cin >> n ;
    int  val[n+2], wt[n+2] ;
    cout << "Enter the price of items : " ;
    for( i = 0 ; i < n ; i++ )
        cin >> val[i] ;
    cout << "Enter the weight of items : " ;
    for( i = 0 ; i < n ; i++ )
        cin >> wt[i] ;
    int W  ;
    cout << "Enter the the capacity of knapsack =  " ;
    cin >> W ;

    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
