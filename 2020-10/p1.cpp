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

int f(int a, int b, int c, int x) {
    return a*x*x + b*x + c;
}

signed main() {
    hyper;
    int a1, b1, c1, a2, b2, c2, n;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;
    int ans = -INF;
    rep1(i,0,n) {
        int j = n-i;
        ans = max(ans, f(a1,b1,c1,i) + f(a2,b2,c2,j));
    }
    cout << ans << '\n';
}
