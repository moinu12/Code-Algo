#include<bits/stdc++.h>
using namespace std ;
#define Max 10000
vector<int> edges[Max] ;
bool visited[Max] ;
void dfs( int node )
{
    cout << node << " " ;
    visited[node] = true ;
    for( int i  = 0 ; i < edges[node].size()  ; i++ )
    {
        if(!visited[edges[node][i] ] )

            dfs( edges[node][i]) ;
    }
}
void addEdge( int a, int b )
{
    edges[a].emplace_back(b) ;
    edges[b].emplace_back(a) ;
}
int main()
{
    int e ;
    cin>> e ;
    for( int i = 1  ; i<= e  ; i++ )
    {
        int a, b ;
        cin >> a >> b ;
        addEdge(a,  b ) ;
    }
    for( int  i = 1 ; i <= 6  ; i++ )
        if(!visited[i])
            dfs(i) ;


    return 0 ;
}
