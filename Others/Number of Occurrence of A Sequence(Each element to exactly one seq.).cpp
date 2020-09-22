#include<bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m; cin>>n; vector<long long> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    cin>>m; vector<long long> Seq(m);
    for(int i=0;i<m;i++) cin>>Seq[i];

    map<long long,int>PosOfVal,dp,mark;
    for(int i=0;i<m;i++) PosOfVal[Seq[i]]=i,mark[Seq[i]]=1;

    for(int i=n-1;i>=0;i--) {
        long long val=v[i];
        if(!mark[val]) continue;
        if(val!=Seq[m-1]&&dp[val]+1>dp[Seq[PosOfVal[val]+1]]) continue;
        dp[val]++;
    }
    cout<<dp[Seq[0]]<<endl;
    return 0;
}

