/*
10 13
1 3
1 2
2 4
3 5
3 4
4 5
4 6
5 7
6 7
6 9
7 8
8 10
9 10
*/

#include<bits/stdc++.h>
using namespace std ;
int main()
{

    int numNodes,numEdges ;
    cin >> numNodes >> numEdges ;
    vector<int> edges[numEdges+1] ;
    for( int i = 1 ; i <= numEdges ; i++ )
    {
        int x, y  ;
        cin >> x >> y ;
        edges[x].push_back(y) ;
        edges[y].push_back(x) ;
    }
    int n= numNodes; // number of nodes
    int s= 5 ; // source vertex
    int f = 8 ;

    queue<int> q;
    vector<bool> used(n+1);
    vector<int> level(n+1), p(n+1);

    q.push(s);
    used[s] = true;
    //p[s] = -1;
    level[s] = 0 ;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0 ;  i < edges[v].size() ; i++ )
        {
            int u = edges[v][i] ;
            if (!used[u])
            {

                used[u] = true;
                q.push(u);
                level[u] = level[v] + 1;
                // p[u] = v;
            }
        }
    }
    cout << level[f] << endl; // shortest path  s to f


    return 0 ;

}



