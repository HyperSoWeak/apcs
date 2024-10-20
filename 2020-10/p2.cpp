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

int r, c, k, m;
int a[55][55];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

signed main() {
    hyper;
    cin >> r >> c >> k >> m;
    rr(a, -1);
    rep1(i,1,r) rep1(j,1,c) cin >> a[i][j];
    while(m--) {
        int b[55][55] = {0};
        rep1(i,1,r) rep1(j,1,c) {
            int s = a[i][j] / k;
            rep(t,0,4) {
                int x = i+dx[t], y = j+dy[t];
                if(a[x][y] == -1) continue;
                b[x][y] += s, a[i][j] -= s;
            }
        }
        rep1(i,1,r) rep1(j,1,c) a[i][j] += b[i][j];
    }
    int mx = -INF, mn = INF;
    rep1(i,1,r) rep1(j,1,c) {
        mx = max(mx, a[i][j]);
        if(a[i][j] != -1) mn = min(mn, a[i][j]);
    }
    cout << mn << '\n' << mx << '\n';
}
