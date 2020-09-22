#include<bits/stdc++.h>
using namespace std;
vector<int>v(100007);
int tree[4*100007];

void buildtree(int node,int current_strat,int current_end)
{
    if(current_strat==current_end){
        tree[node]=v[current_end];
        return;
    }

    int mid=(current_end+current_strat)>>1;
    buildtree(2*node, current_strat, mid);
    buildtree(2*node+1,mid+1, current_end);
    tree[node]=tree[2*node]+tree[2*node+1];
    return;
}


void update(int node,int current_strat,int current_end,int idx, int val)
{
    if(idx<current_strat||idx>current_end) return;
    if(current_strat==current_end){
        tree[node]=v[idx];
        return;
    }

    int mid=(current_end+current_strat)>>1;
    buildtree(2*node, current_strat, mid);
    buildtree(2*node+1,mid+1, current_end);
    tree[node]=tree[2*node]+tree[2*node+1];
    return;
}

int query(int node,int current_strat,int current_end,int qstart, int qend)
{
    if(current_end<qstart||current_strat>qend) return 0;
    if(current_strat>=qstart&&current_end<=qend) return tree[node];

    int mid=(current_end+current_strat)>>1;
    int sum1=query(2*node,current_strat,mid,qstart,qend);
    int sum2=query(2*node+1,mid+1,current_end,qstart,qend);

    return sum1+sum2;
}

int main()
{
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    buildtree(1,1,n);
    while(q--){
        int l,r; cin>>l>>r;
        cout<<query(1,1,n,l,r)<<endl;
    }
}
