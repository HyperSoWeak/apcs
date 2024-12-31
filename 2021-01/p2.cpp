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
using vi = vector<int>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 55;

signed main() {
    hyper;
    int n, m, k;
    int q[MN][MN], c[MN];
    cin >> n >> m >> k;
    rep(i,0,n) rep(j,0,m) cin >> q[i][j];
    int mn = INF;
    rep(x,0,k) {
        rep(i,0,n) cin >> c[i];
        int f[MN][MN];
        rr(f,0);
        rep(i,0,n) rep(j,0,m) f[c[i]][j] += q[i][j];
        int sum = 0;
        rep(i,0,m) rep(j,0,m) {
            if(i == j) sum += f[i][j];
            else sum += min(f[i][j], 1000) * 3 + max(f[i][j] - 1000, 0) * 2;
        }
        mn = min(mn, sum);
    }
    cout << mn << '\n';
}
