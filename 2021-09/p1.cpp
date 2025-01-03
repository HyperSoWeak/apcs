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
    while(n--) {
        int a[2][8];
        rep(i,0,2) rep1(j,1,7) cin >> a[i][j];
        bool f = 0;
        if(a[0][2] == a[0][4] || a[0][2] != a[0][6] ||
           a[1][2] == a[1][4] || a[1][2] != a[1][6]) {
            f = 1;
            cout << 'A';
        }
        if(a[0][7] == 0 || a[1][7] == 1) {
            f = 1;
            cout << 'B';
        }
        if(a[0][2] == a[1][2] || a[0][4] == a[1][4] || a[0][6] == a[1][6]) {
            f = 1;
            cout << 'C';
        }
        if(!f) cout << "None";
        cout << '\n';
    }
}
