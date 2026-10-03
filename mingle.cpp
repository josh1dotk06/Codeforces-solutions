//fermats little theorem: a/b mod CONST = a*(b^(m-2)) mod CONST


void solve(){
    int n;
    cin >> n;
    int k;
    cin >> k;

    int a = n * modpow(2*k,2*k);
    int baseb = 2*k+1;
    int b = modpow(baseb, 2*k);
    int ans = (a % MOD) * modpow(b, MOD - 2) % MOD; //fermats little
    cout << ans << endl;
}

/*good insight for this one, instead of computing every expected value probability / number of possible states
you instead calculate the probability of one specific person winning, call it p. Since its a symmetric circle
this probability applies to everyone, so the EV is just n*p.

how many times can a person win in the case where they are only in their target room?
combinatorically this comes out to N = (2k)^(2k) * (2k + 1)^(n - 1 - 2k)
it also turns out that this is true for the number of times they can win while inside any of the 2k+1 reachable rooms

note that there are also (2k+1)^n total possible states in the game
this means that p = (2k+1) * (2k)^(2k) * (2k + 1)^(n - 1 - 2k) / (2k+1)^n
simplifies to p = (2k)^(2k) * (2k + 1)^(n - 2k) / (2k+1)^n
simplifies to p = (2k)^(2k) * (2k+1)^-2k
thus EV = n * (2k)^(2k) * (2k+1)^-2k

you can let a = n*(2k)^(2k)
and let b = (2k+1)^2k

then use fermats little theorem to account for modularity

*/


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
