/*Bismillahir Rahmanir Rahim */

#include<bits/stdc++.h>
#define ll                      long long int
#define ull                     unsigned long long int
#define nl                      printf("\n")
#define pb(a)                   push_back(a)
#define II                      ( { int a ; scanf("%d",&a) ; a; } )
#define LL                      ( { ll a ; scanf("%lld",&a) ; a; } )
#define DD                      ({double a; scanf("%lf", &a); a;})
#define SS                      ( {string st ; cin>> st ; st ; } )

using namespace std;
#define mx 100001
int arr[mx] ;
int tree[4*mx] ;
void init(int node,int b, int e)
{
    if( b == e )
    {
        tree[node] = arr[b] ;
        return ;
    }
    int left = node * 2 ;
    int right = node*2 + 1 ;
    int mid = (b+e)/2 ;
    init(left, b, mid ) ;
    init(right, mid+1, e ) ;
    tree[node] = tree[left] + tree[right] ;
}
int query( int node, int b,  int e, int i, int j )
{
    if( i > e || j < b )
        return 0 ;
    if( b>= i && e<=j )
    {
        return tree[node] ;
    }
    int left = node*2;
    int right = node*2 + 1 ;
    int mid = (b+e) / 2 ;
    int p1 = query(left, b, mid, i, j ) ;
    int p2 = query(right, mid+1, e, i, j ) ;
    return p1+p2 ;
}
void update(int node, int b, int e, int i, int newvalue )
{
    if( i > e || i < b )
        return ;
    if( b >= i && e <= i )
    {
        tree[node] = newvalue ;
        return ;
    }
    int left = node*2 ;
    int right = node*2 + 1 ;
    int mid = (b+e) / 2 ;
    update(left, b, mid, i, newvalue) ;
    update(right, mid+1, e, i, newvalue) ;
    tree[node] = tree[left] + tree[right] ;

}

void read_and_solve()
{
    int n = II ;
    for( int i = 1 ; i <= n ; i++ )
        arr[i] = II  ;
    init(1, 1, n) ;
    update(1 , 1 , n , 2 , 0 ) ;
    cout << query(1, 1,  n, 1, 3 ) << endl;
    update(1, 1, n,2, 2) ;
    cout << query(1, 1, n, 2, 2 ) ;

}


int main()
{
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

    read_and_solve();

    return 0;
}


// bool myComparison(const pair<ll,ll> &a,const pair<ll,ll> &b) {  return  ( a.second < b.second ); }

/*
#define lower_str(name1)         transform(name1.begin() , name1.end() , name1.begin(),::tolower )
#define upper_str(name1)         transform(name1.begin() , name1.end() , name1.begin(),::toupper )

// Binary search Method is as follows :
ll bin( ll a[], ll n, ll  sr   )
{
    ll lo = 0, hi = n, mid   ;
    while(  hi  >  lo  )
    {
        mid = (  lo + hi + 1  ) /  2 ;
        if(  a[mid] <= sr  )  // upper bound
            lo  =   mid  ;    // if lo == mid then ---> mid = (lo + hi + 1 ) / 2 ; else mid = ( lo + hi ) / 2 ;
        else
            hi =  mid - 1 ;

    }
    return hi ;



}

// Power Function Method is as follows :
ll Pow( ll x, ll n , ll M )
{

    ll result = 1 ;
    while( n > 0 )
    {
        if( n % 2 == 1 )
            result = ( result  * x ) % M ;
        x = ( x * x ) % M ;
        n = n / 2 ;
    }
    return result;
}

// modInverse Function Method is as follows :
ll modInverse( ll A , ll M )
{
    return Pow ( A , M - 2 , M ) ;
}

 */



/*
************************************************************
   Md Moin Uddin ( Ruman ) ,
  10th batch CSE ,ID : 11808011 ,
  Comilla University (2017-2018)
  Email : moinruman11@gmail.com, Phone : 01879-238107 .
************************************************************
                                                          */

