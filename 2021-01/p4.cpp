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
    int n;
    cin >> n;
    vector<pii> a(n);
    rep(i,0,n) cin >> a[i].fi >> a[i].se;
    sort(a.begin(), a.end());

    vector<int> lis;
    for(auto [x, y]: a) {
        if(lis.empty() || y >= lis.back()) lis.push_back(y);
        else *upper_bound(lis.begin(), lis.end(), y) = y;
    }
    cout << lis.size() << '\n';
}
