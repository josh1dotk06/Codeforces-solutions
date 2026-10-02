void solve(){
    int r,g,b;
    int cr,cg,cb;
    int rg, gb;
    cin >> r >> g >> b;
    cin >> cr >> cg >> cb;
    cin >> rg >> gb;

    int rNeed = max(0LL, r-cr);
    int gNeed = max(0LL, g-cg);
    int bNeed = max(0LL, b-cb);

    int ans = 0;
    
    ans+=rNeed;
    rg-=rNeed;
    if(rg < 0){
        cout << -1 << endl;
        return;
    }

    ans+=gNeed;

    
    if(rg-gNeed < 0){
        if(gb < (gNeed - rg)){
            //not enough to accomodate greens
            cout << -1 << endl;
            return;
        }
        gNeed-=rg;
        gb-=gNeed;
    }

    ans+=bNeed;
    gb-=bNeed;
    if(gb < 0){
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
    
    //solution
    //just check the reds needed first, the rg consumes them, if not enough rg then -1
    //check greens, consume the rest of the rg, and then consume using gb, if not enough gb, then -1
    //check blue last using the remaining gb, if not enough then -1
    //ans is just the sum that is needed
    
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
