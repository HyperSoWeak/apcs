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

int solve(vector<int> a) {
    int n = a.size() / 2;
    if(n <= 1) return 0;
    int m = n / 2;
    vector<int> x, y;
    int ans = 0, ps = 0;
    bool vis[m+2] = {0};
    for(int t: a) {
        if(t <= m) {
            x.push_back(t);
            ps++;
        } else {
            y.push_back(t-m);
            if(vis[t-m]) ans += ps;
            else ans -= ps, vis[t-m] = 1;
        }
    }
    return solve(x) + solve(y) + ans;
}

signed main() {
    hyper;
    int n, x;
    vector<int> a;
    cin >> n;
    rep(i,0,n*2) {
        cin >> x;
        a.push_back(x);
    }
    cout << solve(a) << '\n';
}
