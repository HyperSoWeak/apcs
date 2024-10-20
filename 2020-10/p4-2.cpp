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
const int MN = 1e5+5;

struct Fenwick {
    vector<int> v;
    int size;
    Fenwick(int n) {
        v.resize(n+2, 0);
        size = n+1;
    }
    int lowbit(int x) { return x & (-x); }
    void modify(int pos, int x) {
        for(int i=pos; i<=size; i+=lowbit(i)) {
            v[i] += x;
        }
    }
    int query(int pos) {
        int sum = 0;
        for(int i=pos; i>0; i-=lowbit(i)) {
            sum += v[i];
        }
        return sum;
    }
    int rsum(int l, int r) {
        return query(r) - query(l-1);
    }
};

signed main() {
    hyper;
    int n, l[MN], r[MN];
    cin >> n;
    Fenwick bit(n*2);
    rep1(i,1,n*2) {
        int x;
        cin >> x;
        if(l[x] == 0) l[x] = i;
        else r[x] = i;
    }
    int ans = 0;
    rep1(i,1,n) {
        ans += bit.rsum(l[i], r[i]);
        bit.modify(l[i], 1);
        bit.modify(r[i], 1);
    }
    cout << ans << '\n';
}
