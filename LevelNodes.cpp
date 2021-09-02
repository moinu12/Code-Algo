/*
20
11 1
1 2
13 3
15 4
17 5
11 6
2 7
1 8
15 9
4 10
15 12
5 13
2 14
17 15
15 16
11 17
15 18
9 19
16 20

2
*/

#include<bits/stdc++.h>
using namespace std ;
int main()
{

    int numNodes,numEdges ;
    cin >> numNodes ;
    vector<int>edges[numNodes+1] ;
    for( int i = 1 ; i < numNodes ; i++ )
    {
        int x, y  ;
        cin >> x >> y ;
        edges[x].push_back(y) ;
        edges[y].push_back(x) ;
    }
    int l ;
    cin>>l ;
    int n= numNodes; // number of nodes
    int s= 1 ; // source vertex
    // int f = 8 ;
    queue<int> q;
    vector<bool> used(n+1);
    vector<int> level(n+1),p(n+1); // p(n) level nodes numbers count

    q.push(s);
    used[s] = true;
    p[s] = 1;
    //cout << p[2] << endl ;
    level[s] = 1 ;
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
                int k = level[u] ;
                p[k]=p[k]+1;  // level node numbers count

                // p[u] = v;
            }
        }
    }
    cout << p[l] << endl; // level nodes count


    return 0 ;

}




