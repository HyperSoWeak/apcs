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
const int MN = 2e5+5;

signed main() {
    hyper;
    int n, L;
    cin >> n >> L;
    vi a(n);
    rep(i,0,n) {
        int x, y;
        cin >> x >> y;
        a[y-1] = x;
    }

    int ans = 0;
    set<int> cut;
    cut.insert(0);
    cut.insert(L);
    rep(i,0,n) {
        cut.insert(a[i]);
        auto it = cut.find(a[i]);
        int l = *prev(it), r = *next(it);
        ans += r-l;
    }
    cout << ans << '\n';
}
