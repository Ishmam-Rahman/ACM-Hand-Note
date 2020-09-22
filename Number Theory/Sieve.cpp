#include<bits/stdc++.h>
using namespace std;

int mark[100007];
vector<int> prime;

void sieve(int n) {
    for(int i=2;i<=n;i++) {
        if(!mark[i]) {
            prime.push_back(i);
            for(int j=i+i;j<=n;j+=i) mark[j]=1;
        }
    }
}

int main() {
    sieve(100000);
    for(int u: prime) cout<<u<<endl;
    return 0;
}

