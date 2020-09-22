#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll  long long
#define pb          push_back
#define mkp         make_pair
#define sz          size()

int trie[100003][52];
int mark[100003],idx=0;

int calc(char c) {
    if(isupper(c)) return c-'A';
    return c-'a'+26;
}
void insert(string s){
    int node=0;
    for(int i=0;i<s.sz;i++) {
            int j=calc(s[i]);
        if(trie[node][j]==-1) {
                trie[node][j]=++idx;
        }
        node=trie[node][j];
    }
    mark[node]=1;
}

bool search(string s){
    int node=0;
    for(int i=0;i<s.size();i++){
        int j=calc(s[i]);
        if(trie[node][j]==-1) return 0;
        node=trie[node][j];
    }
    return true;
}

int main()
{
    int t; cin>>t;
    while(t--) {
            for(int i=0;i<100003;i++) memset(trie[i],-1,sizeof(trie[i]));
            memset(mark,0,sizeof(mark));
            idx=0;

            int n; cin>>n;
            while(n--) {
                string s; cin>>s;
                insert(s);
            }
            cin>>n;
            while(n--){
                string s; cin>>s;
                if(search(s)) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
    }
    return 0;
}
