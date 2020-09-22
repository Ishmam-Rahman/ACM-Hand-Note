#include<bits/stdc++.h>
using namespace std;
vector<long long>adj[100007];
int finishing[100007],discovery[100007];
int vis[100005];
int Time=0;

void dfs(long long source){
  discovery[source]=(++Time);
  vis[source]=1;
  for(int i=0;i<adj[source].size();i++){
    long long u=adj[source][i];
    if(!vis[u]) dfs(u);
  }
  finishing[source]=(++Time);
  return;
}

int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
       long long u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }

    dfs((long long)1);
    for(int i=1;i<=n;i++){
    cout<<"for "<<i<<": DiscoveryTime= "<<discovery[i];
    cout<<"; FinishingTime= "<<finishing[i]<<endl;
    }
}
