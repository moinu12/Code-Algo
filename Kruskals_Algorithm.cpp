#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int source,dest,weight;

};
int parent[101];
int findparent(int v)
{
    if(parent[v]==v) return v;
    else return findparent(parent[v]);
}
bool cmp(Edge a,Edge b)
{
    return a.weight<b.weight;
}
void kruskals(Edge a[],int n,int e)
{
    Edge mst[n-1];
    sort(a,a+e,cmp);
    for(int i=0; i<n; i++) parent[i]=i;
    int count=0,i=0;
    while(count!=n-1)
    {
        Edge ce=a[i];
        int sp=findparent(ce.source);
        int dp=findparent(ce.dest);
        if(sp!=dp)
        {
            mst[count]=ce;
            count++;
            parent[dp]=sp;
        }
        i++;
    }

    printf("The MST is: \n");
    for(i=0; i<n-1; i++)
    {
        cout<<mst[i].source<<" "<<mst[i].dest<<" "<<mst[i].weight;
        cout<<endl;
    }

}

int main()
{

    int i,n,E,s,d,w;

    printf("Enter the number of nodes and edges: ");
    cin>>n>>E;
    Edge a[E];

    printf("Enter the source , destination and weight for each edges: \n");
    for(i=0; i<E; i++)
    {
        cin>>s>>d>>w;
        a[i].source=s;
        a[i].dest=d;
        a[i].weight=w;
    }
    kruskals(a,n,E);

    return 0;
}
