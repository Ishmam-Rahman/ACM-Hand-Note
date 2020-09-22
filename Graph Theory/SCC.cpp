#include<bits/stdc++.h>
using namespace std;
#define mx 50005
vector<int>adj[mx],radj[mx],path,component[mx];
int visited[mx];

void DFS1(int source)
{
    visited[source]=1;
    for(auto u: adj[source]) {
        if(!visited[u]) DFS1(u);
    }
    path.push_back(source);
}

void DFS2(int source,int sccnum)
{
    component[sccnum].push_back(source);
    visited[source]=1;

    for(auto u: radj[source]) {
        if(!visited[u]) DFS2(u,sccnum);
    }
}

int main()
{
    int n,m; cin>>n>>m;

    for(int i=0;i<m;i++) {
        int a,b; cin>>a>>b;
        //if(start==-1) start=a;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    for(int i=1;i<n;i++) {
        if(!visited[i]) DFS1(i);
    }
    int NumOfCountry=0;
    reverse(path.begin(), path.end());
    memset(visited,0,sizeof(visited));

    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            ++NumOfCountry;
            DFS2(i,NumOfCountry);
        }
    }

    cout<<NumOfCountry<<endl;
    for(int i=1;i<=NumOfCountry;i++) {
        for(auto u: component[i]) cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
