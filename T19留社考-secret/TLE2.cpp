#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; ++i)
#define RFOR(i,st,en) for (int i=st; i>=en; --i)
using namespace std;
const int N = 1e6+5;
int n,k,q,v;
int x[N],w[N];
bool find(int v) {
	FOR(i,0,k-1) if (x[i]<=v && v<x[i]+w[i]) return 1;
	return 0;
}
main() {
#ifndef XD
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    while (cin>>n>>k>>q) {
        FOR(i,0,k-1) cin>>x[i]>>w[i];
        while (q--) {
            cin>>v;
            cout<<find(v)<<'\n';
        }
    }
    return 0;
}
