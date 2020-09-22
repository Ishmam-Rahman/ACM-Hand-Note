#include<bits/stdc++.h>
using namespace std;
int dis[100005], edge[1000][1000];
vector<int>adj[100007];

void dijkastra(int start,int m)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;

    q.push(make_pair(0,start));
    dis[start]=0;

    while(!q.empty())
    {
        int current=q.top().second;
//        if(current==m) {
//            return dis[m]; // finding distance of a particular node
//        }

        q.pop();
        for(int i=0;i<adj[current].size();i++)
        {
            int u=adj[current][i];

            if(dis[current]+edge[current][u]<dis[u])
            {
                dis[u]=dis[current]+edge[current][u];
                q.push(make_pair(dis[u],u));
            }
        }
    }
}

int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++) {
        int a,b,w; cin>>a>>b>>w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge[a][b]=w;
        edge[a][b]=w;
    }
    for(int i=0;i<100005;i++) dis[i]=1000000;
    dijkastra(1,0);
    while(cin>>m) {
        cout<<dis[m]<<endl;
    }
}

