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
const int MN = 1e5+5;

int m, n, a[55][MN];
int dpl[55][MN], dpr[55][MN];

signed main() {
    hyper;
    cin >> m >> n;
    rep1(i,1,m) rep1(j,1,n) cin >> a[i][j];
    rep1(i,1,m) dpl[i][0] = dpr[i][n+1] = -INF;
    rep1(i,1,m) {
        rep1(j,1,n) dpl[i][j] = max(dpl[i][j-1], max(dpl[i-1][j], dpr[i-1][j])) + a[i][j];
        for(int j=n; j>=1; --j) dpr[i][j] = max(dpr[i][j+1], max(dpl[i-1][j], dpr[i-1][j])) + a[i][j];
    }
    int ans = -INF;
    rep1(j,1,n) ans = max(ans, max(dpl[m][j], dpr[m][j]));
    cout << ans << '\n';
}
