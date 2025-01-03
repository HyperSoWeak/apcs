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
const int MN = 105;

struct Player {
    int x, y, s, t, die;
};

signed main() {
    hyper;
    int n, m, k, a[MN][MN];
    vector<Player> ps;
    cin >> n >> m >> k;
    rep(i,0,k) {
        int x, y, s, t;
        cin >> x >> y >> s >> t;
        ps.push_back({x,y,s,t,0});
    }
    rr(a,0);
    bool game = 1;
    while(game) {
        // bomb
        for(auto &p: ps) if(!p.die) a[p.x][p.y] = 1;
        // move
        for(auto &p: ps) if(!p.die) {
            p.x += p.s, p.y += p.t;
            if(p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) p.die = 1;
            else if(a[p.x][p.y]) {
                p.die = 1;
                a[p.x][p.y] = 2;
            }
        }
        // remove bomb
        rep(i,0,n) rep(j,0,m) if(a[i][j] == 2) a[i][j] = 0;
        // check
        game = 0;
        for(auto &p: ps) if(!p.die) game = 1;
    }
    int cnt = 0;
    rep(i,0,n) rep(j,0,m) if(a[i][j]) ++cnt;
    cout << cnt << '\n';
}
