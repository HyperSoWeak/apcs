#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 2e5+5;

int search(int a[], int l, int r, int t, int pos) {
    while(l < r) {
        int m = (l+r)/2;
        if(a[m]-a[pos-1] < t) l = m+1;
        else r = m;
    }
    return l;
}

signed main() {
    hyper;
    int n, m, p[MN];
    cin >> n >> m;
    rep(i,0,n) cin >> p[i];
    
    int ps[MN*2]; ps[0] = 0;
    rep1(i,1,n) ps[i] = ps[i-1] + p[i-1];
    rep1(i,1,n) ps[n+i] = ps[n+i-1] + p[i-1];
    
    int pos = 1;
    while(m--) {
        int q; cin >> q;
        int r = search(ps, pos, n*2, q, pos);
        pos = r % n + 1;
    }
    cout << pos-1 << '\n';
}
