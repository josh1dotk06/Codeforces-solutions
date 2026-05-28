#include <bits/stdc++.h>
#include <cmath>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nope cout << "NO" << endl;
#define yup cout << "YES" << endl;
using namespace std;


ll fixpow(ll a, ll k, ll mod) {
    ll r = 1%mod;
    for(a %= mod; k; k >>= 1){
        if(k & 1) r = (__int128)r*a%mod;
        a = (__int128)a*a % mod;
    }
    return r;
}

void solve(){
   ll n;
   cin >> n;
   
   ll const base = 2;
   cout << fixpow(base, n, (ll)(1e9+7)) << endl;
   
   /* answer is just 2^n since for each
   digit position, it can either be a 1 or 0.
   
   Make sure to use ll and compute mod correctly.
   I already had a function that helps with
   computing this.
   */
   
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 	
    //cin >> t;
    while(t--) solve();
    return 0;
}
