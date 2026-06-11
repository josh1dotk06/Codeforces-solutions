void solve(){
    
    int n,x;
    cin >> n >> x;
    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin >> coin[i];
    sort(all(coin));
    
    //dp[x] = num ways to compute sum x
    
    vector<int> dp(x+1, 0);
    
    int MOD = 1e9+7;
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(auto c : coin){
            if(i-c >= 0) dp[i] = (dp[i] + dp[i-c])%MOD;
        }
    }
    
    cout << dp[x] << endl;
    
    
    /*dp[i] = ways to compute sum of i
    base case: 1 way to compute a sum of 0 (which is to use 0 coins)
    For each dp[i], we just add on i-c for each coin.
    Ans = dp[x]
    */
}