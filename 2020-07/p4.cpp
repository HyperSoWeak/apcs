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
const int MN = 1005;

int dp[MN][4], mpn[128];
vector<int> e[MN];
string s[MN];

void dfs(int u, int t) {
    rep(i,0,4) dp[u][i] = 0;
    if(s[u][t] != '@') {
        rep(i,0,4) {
            if(mpn[s[u][t]] == i) continue;
            dp[u][i] = INF;
        }
    }
    if(e[u].size() == 0) return;
    for(int v: e[u]) {
        dfs(v, t);
        rep(i,0,4) {
            int mn = INF;
            rep(j,0,4) mn = min(mn, dp[v][j] + (i!=j));
            dp[u][i] += mn;
        }
    }
}

signed main() {
    hyper;
    mpn['A'] = 0, mpn['U'] = 1, mpn['C'] = 2, mpn['G'] = 3;
    int n, m, u, v, root, ans = 0;
    cin >> n >> m;
    rep(i,0,n) {
        cin >> u >> v;
        if(u == v) root = u;
        else e[v].push_back(u);
        cin >> s[u];
    }
    rep(i,0,m) {
        dfs(root, i);
        ans += min({dp[root][0], dp[root][1], dp[root][2], dp[root][3]});
    }
    cout << ans << '\n';
}
