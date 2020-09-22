#include<bits/stdc++.h>
using namespace std;
int MOD=1000000007;
//**********************************************************
int bigmod(long long x, long long y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
//************************************************************
//************************************************************
long long recursive_mod(long long a , long long p){
	if(p == 0) return 1 % MOD;
	if(p % 2 == 0){
		long long ans = recursive_mod(a , p / 2);
		return ((long long)ans * ans) % MOD;
	}
	else {
		return (a * recursive_mod(a , p - 1)) % MOD;
	}
}
//************************************************************
int main(){
	long long n , m;
	cin >> n >> m;
	cout << bigmod(n, m,1000000007)% 1000000007 << endl;
	cout << recursive_mod(n,m) % 1000000007 << endl;
	return 0;
}
