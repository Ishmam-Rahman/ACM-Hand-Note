#include<bits/stdc++.h>
using namespace std;

struct que{
    int L;
    int R;
    int idx;
};

int n,m;
int blcsz, blcnum;
long long cnt=0;
vector<que>v;
int arr[100007],res[100007];
unordered_map<int,int>mp;


bool cmp(que &q1,que &q2) {
    if(q1.L/blcsz==q2.L/blcsz) return q1.R<q2.R;
    return q1.L<q2.L;
}

void add(int x){
    int m=arr[x];
    if(mp[m]==m) cnt--;
    mp[m]++;
    if(mp[m]==m) cnt++;
}

void del(int x){
    int m=arr[x];
    if(mp[m]==m) cnt--;
    mp[m]--;
    if(mp[m]==m) cnt++;
}

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   cin>>n>>m;
   for(int i=0;i<n;i++) cin>>arr[i];

    blcsz=sqrt(n);


   for(int i=0;i<m;i++){
    int l,r;
    cin>>l>>r;
    l--;r--;
    v.push_back({l,r,i});
   }

   sort(v.begin(),v.end(),cmp);
   int l=0,r=-1;

   for(int i=0;i<m;i++){
    que temp=v[i];

    while(r<temp.R) add(++r);
    while(l<temp.L) del(l++);
    while(r>temp.R) del(r--);
    while(l>temp.L) add(--l);
    res[temp.idx]=cnt;
   }

   for(int i=0;i<m;i++) cout<<res[i]<<endl;
   return 0;
}
