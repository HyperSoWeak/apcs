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
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 2e5+5;

int m, n, h, a[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool in(int x, int y) { return 0 <= x && x < m && 0 <= y && y < n; }

void remove(int x, int y) {
    rep(i,0,4) {
        int nx = x+dx[i], ny = y+dy[i];
        while(in(nx,ny) && (a[nx][ny]==2+(i&1) || a[nx][ny]==4)) {
            if(a[nx][ny] == 4) a[nx][ny] = 3-(i&1);
            else a[nx][ny] = 0;
            nx += dx[i];
            ny += dy[i];
        }
    }
    a[x][y] = 0;
}

void add(int x, int y) {
    remove(x,y);
    a[x][y] = 1;
    vi dir;
    rep(i,0,4) {
        int nx = x+dx[i], ny = y+dy[i];
        while(in(nx,ny)) {
            if(a[nx][ny] == 1) {
                dir.push_back(i);
                break;
            }
            nx += dx[i], ny += dy[i];
        }
    }
    for(auto i: dir) {
        int nx = x+dx[i], ny = y+dy[i];
        while(in(nx,ny) && a[nx][ny] != 1) {
            if(a[nx][ny] == 0) a[nx][ny] = 2+(i&1);
            else a[nx][ny] = 4;
            nx += dx[i], ny += dy[i];
        }
    }
}

int count() {
    int ans = 0;
    rep(i,0,m) rep(j,0,n) if(a[i][j]) ++ans;
    return ans;
}

signed main() {
    hyper;
    cin >> m >> n >> h;
    int mx = 0;
    while(h--) {
        int r, c, t;
        cin >> r >> c >> t;
        if(t == 0) add(r,c);
        else remove(r,c);
        mx = max(mx, count());
    }
    cout << mx << '\n' << count() << '\n';
}
