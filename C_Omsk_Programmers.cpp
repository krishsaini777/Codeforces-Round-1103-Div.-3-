#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Type aliases
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vs = vector<string>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vb = vector<bool>;
using vbb = vector<vector<bool>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// Macros
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define mod 1000000007LL

// Fast IO initialization
static const bool Init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return true;
}();
// Smallest Prime Factor (SPF)
const ll MAX = 1e5+1;
ll spf[MAX];

void spfCompute() {
    for(ll i = 1; i < MAX; i++) spf[i] = i;
    for(ll i = 2; i*i < MAX; i++) {
        if(spf[i] == i) {
            for(ll j = i*i; j < MAX; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

void solve() {
    ll a,b,x;
    cin>>a>>b>>x;
    if(a == b){
        cout<<0<<'\n';
        return;
    }
    ll ans = abs(a-b);
    if(a>b)swap(a,b);
    ll step = 0;

    while(b>0){
        b/=x;
        step++;
        ans = min(ans,step + (ll)abs(a-b));
        if(a>b)swap(a,b);
    }
    
    cout<<ans<<'\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}