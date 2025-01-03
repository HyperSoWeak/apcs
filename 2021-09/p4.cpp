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
const int MN = 1e6+5;

int n, k, a[MN], dp[25][MN];
int len[MN], last[MN], l = 1;

signed main() {
    hyper;
    cin >> n >> k;
    rep1(i,1,n) cin >> a[i];
    rep1(i,1,n) {
        l = max(l, last[a[i]]+1);
        len[i] = i-l+1;
        last[a[i]] = i;
    }
    rep1(i,1,k) rep1(j,1,n) {
        dp[i][j] = max(dp[i][j-1], dp[i-1][j-len[j]]+len[j]);
    }
    cout << dp[k][n] << '\n';
}
