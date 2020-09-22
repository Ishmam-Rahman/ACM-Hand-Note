#include<bits/stdc++.h>
using namespace std;

vector<int>v[10007];
int vis[10007];
int lavel[10007];

 void bfs(int source, int destination)
 {
     queue<int>Q;

     Q.push(source);

     while(!Q.empty())
     {
         int node=Q.front();

         Q.pop();
         vis[node]=1;
         cout<<node<<" ";
         if(node==destination)
         {
             cout<<"Minimum path= "<<lavel[node]<<endl;
             return;
         }

         for(int i=0;i<v[node].size();i++)
         {
             if(vis[v[node][i]]==0)
             {
                 vis[v[node][i]]=1;
                 Q.push(v[node][i]);
                 lavel[v[node][i]]=lavel[node]+1;
             }
         }
     }
    cout<<"Node is not available!! '_' "<<endl;
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
   bfs(1,7);
   return 0;
}
