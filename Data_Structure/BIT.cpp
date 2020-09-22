#include<bits/stdc++.h>
using namespace std;
int arr[100000],n,m;

void update(int idx,int val) {
    while(idx<=n) {
        arr[idx]+=val;
        idx+=(idx & -idx);
    }
}

long long query(int idx) {
    long long sum=0;
    while(idx>0) {
        sum+=arr[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)   {
        int c; cin>>c;
        update(i,c);
    }
    while(m--) {
        int l,r; cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }
    return 0;
}
