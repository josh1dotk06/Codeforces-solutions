void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    for(int i = 1; i <=n; i++){
        cin >> a[i];
    }
    
    int best = 0;
    for(int i = 1; i<=n; i++){
        best = max(best, a[i]);
    }
    
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(a[i] == best) ans++;
    }
    
    cout << ans << endl;
    
    /*
    i mod n + 1 is just the next element, this means
    we're just going around in a circle. The last
    player to eat the dish is whoever has the most,
    so count how many have this max number of
    dishes
    */
    
}