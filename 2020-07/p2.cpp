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

struct Dice {
    int f, b, l, r, u, d;
    Dice(): f(4), b(3), l(5), r(2), u(1), d(6) {}
    void rollF() { int t=f; f=u; u=b; b=d; d=t; }
    void rollR() { int t=r; r=u; u=l; l=d; d=t; }
};

signed main() {
    hyper;
    int n, m, x, y;
    Dice a[21];
    cin >> n >> m;
    while(m--) {
        cin >> x >> y;
        if(y == -1) a[x].rollF();
        else if(y == -2) a[x].rollR();
        else swap(a[x], a[y]);
    }
    rep1(i,1,n) cout << a[i].u << ' ';
    cout << '\n';
}
