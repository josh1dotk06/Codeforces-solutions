#include <bits/stdc++.h>
#include <cmath>
#define integer int
#define int long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nope cout << "NO" << endl;
#define yup cout << "YES" << endl;
#define FOR(v, n) for (int i = 0; i < (n); i++) cin >> (v)[i]
using namespace std;


template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
    //#ifndef ONLINE_JUDGE
        //cout << "Output: ";
		//
    //#endifi


int gcd(int a, int b) {
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    while(b){
        int t = a%b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / std::gcd(a, b) * b;
}


vector<long long> divisors(long long x) {
    x = abs(x);
    vector<long long> divs;

    for (long long d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            divs.push_back(d);
            divs.push_back(-1*d);

            if (d != x / d) {
                divs.push_back(x / d);
                divs.push_back(-1*(x / d));
            }
        }
    }

    return divs;
}

const int N = 1e7;

vector<bool> isPrime(N + 1, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);

            if (i * i <= N) {
                for (long long j = i * i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
}

int const MOD = 998244353;
long long modpow(long long a, long long e) {
    long long res = 1;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

long long inv(long long x) {
    return modpow(x, MOD - 2);
}

long long nCk(int n, int k) {
    if (k < 0 || k > n) return 0;

    k = min(k, n - k);

    long long res = 1;

    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) % MOD;
        res = res * inv(i) % MOD;
    }

    return res;
}
    

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);

        if (ra == rb) return;

        if (sz[ra] < sz[rb]) swap(ra, rb);

        parent[rb] = ra;
        sz[ra] += sz[rb];
    }
};

int calc(int n){
    return (n*(n+1))/2;
}

long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

//make sure to 0LL 
//LLONG_MAX for long +infinity and LLONG_MIN for long -infinity
// (ll)arr.size() to convert the int into long long (but my ll is auto set to int)
//fermats little theorem: a/b mod CONST = a*(b^(m-2)) mod CONST


void solve(){

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //build();
    //sieve();
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}
