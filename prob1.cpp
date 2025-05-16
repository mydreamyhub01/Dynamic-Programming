#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono> 
using namespace __gnu_pbds;
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef set<int> si;
typedef set<char> sc;
typedef map<int, int> mii;


const int INF = 1e9;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);


#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define f(i, s, e) for (int i = s; i <= e; ++i)
#define revf(i, e, s) for (int i = e; i >= s; --i)
#define pb push_back
#define mp make_pair                                                                                                           
#define eb emplace_back                                                             
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define rall(x) (x).rbegin(), (x).rend()

/**
template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl;
    #define debugVec(v) cerr << #v << " = ["; for (auto val : v) cerr << val << " "; cerr << "]" << endl;
#else
    #define debug(x)
    #define debugVec(v)
#endif
**/
inline ll ceil0(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}


int gcd(int a, int b) { return __gcd(a, b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool isPrime(int x){ if (x < 2) return false; for(int i = 2; i * i <= x; i++) if (x % i == 0) return false; return true; } 
bool isPalindrome(string str){ string rev = str; reverse(rev.begin(), rev.end()); return str == rev; }
string toUpperCase(string s) { transform(s.begin(), s.end(), s.begin(), ::toupper); return s; }
string toLowerCase(string s) { transform(s.begin(), s.end(), s.begin(), ::tolower); return s; }


ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_mul(ll a, ll b) { return (a * b) % MOD; }
ll mod_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}


const int MAX_N = 1001; // Max number of items
const int MAX_W = 1001; // Max capacity

ll dp[MAX_N][MAX_W]; // memoization table

ll knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    // Base case
    if (n == 0 || W == 0) return 0;

    if (dp[n][W] != -1) return dp[n][W];

    if (wt[n - 1] <= W) {
        // Choose max of including or excluding current item
        return dp[n][W] = max(
            val[n - 1] + knapsack(n - 1, W - wt[n - 1], wt, val),
            knapsack(n - 1, W, wt, val)
        );
    } else {
        // Cannot include current item
        return dp[n][W] = knapsack(n - 1, W, wt, val);
    }
}

void solve() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);

    for (int i = 0; i < n; ++i) cin >> wt[i];
    for (int i = 0; i < n; ++i) cin >> val[i];

    // Initialize memoization table with -1
    memset(dp, -1, sizeof(dp));

    cout << knapsack(n, W, wt, val) << "\n";
}



int main() {
    /**
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 
    **/
    fastIO();
    int t;
    //t=1;
    cin >> t;
    while (t--) {
        solve();
    }
}
