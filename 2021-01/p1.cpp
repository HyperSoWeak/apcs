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
    int n, d, a[3];
    int cnt = 0, sum = 0;
    cin >> n >> d;
    rep(i,0,n) {
        rep(j,0,3) cin >> a[j];
        sort(a, a+3);
        if(a[2] - a[0] >= d) {
            ++cnt;
            sum += (a[0] + a[1] + a[2]) / 3;
        }
    }
    cout << cnt << ' ' << sum << '\n';
}
