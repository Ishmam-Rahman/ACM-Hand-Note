#include<bits/stdc++.h>
using namespace std;
vector<long long>adj[200007],st;
int subsz[200007],depth[200007];
int vis[200005];


int dfs(long long source, long long par){
  depth[source]=depth[par]+1;
  vis[source]=1;
  subsz[source]=1;

  for(int i=0;i<adj[source].size();i++){
    long long u=adj[source][i];
    if(!vis[u]) subsz[source]+= dfs(u,source);
  }

  st.push_back(subsz[source]-depth[source]);
  return subsz[source];
}

int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<n-1;i++){
       long long u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    depth[0]=-1;
    dfs((long long)1, 0);
    return 0;
}

