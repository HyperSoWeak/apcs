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
const int MN = 3e5+5;

signed main() {
    hyper;
    int n, a[MN], ps[MN];
    int idx[MN], ii = 1;
    cin >> n;
    rep1(i,1,n) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
        idx[i] = i;
    }
    sort(idx+1, idx+1+n, [&](int i, int j) {
        return a[i] < a[j];
    });
    int l = 1, r = n;
    while(l < r) {
        while(idx[ii] < l || idx[ii] > r) ++ii;
        int m = idx[ii];
        if(ps[m-1] - ps[l-1] <= ps[r] - ps[m]) l = m+1;
        else r = m-1;
    }
    cout << a[l] << '\n';
}
