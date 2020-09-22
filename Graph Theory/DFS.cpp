#include<bits/stdc++.h>
using namespace std;

vector<int>v[10007];
int vis[10007];
int lavel[10007];

 void dfs(int source)
 {
     vis[source]=1;
     cout<<source<<" ";
     for(int i=0;i<v[source].size();i++){
        int w=v[source][i];
        if(vis[w]==0) dfs(w);
     }
     return;
 }

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int node,edge; cin>>node>>edge;

   for(int i=0;i<edge;i++){
    int x,y; cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
   }
   dfs(1);
   return 0;
}
