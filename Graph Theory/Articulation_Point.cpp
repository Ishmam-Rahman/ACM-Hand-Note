#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100007];
bool visit[100007];
int low[100007],AP[100007],discovery[100007];
int Time=0;

int dfsAP(int src, int parent){
    low[src]=discovery[src]= (++Time);

    int children=0;
    for(int i=0;i<adj[src].size();i++){
        int w=adj[src][i];

        if(w!=parent){ // don't wanna go back to the before node
            if(discovery[w]==0){
                children++;
                dfsAP(w,src);

                if(discovery[src]<=low[w]) AP[src]=1; //Condition 1
                low[src]=min(low[src],low[w]);
            }

            else{
                low[src]=min(low[src],discovery[w]);
            }
        }
    }
    return children;
}


int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<n;i++){
            if(discovery[i]==0)
        AP[i]=dfsAP(i,i)>1; //Condition 2
    }

    for(int i=1;i<=n;i++) if(AP[i]==1) cout<<i<<" ";
    cout<<endl;
}

/*
7 7
1 2
1 3
3 7
3 4
4 6
4 5
6 7
*/
