void solve(){
    
    int n,x;
    cin >> n >> x;
    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin >> coin[i];
    sort(all(coin));
    
    //dp[x] = min coins to compute sum x
    int INF = 1e18 + 4;
    vector<int> dp(x+1, INF);
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(auto c : coin){
            if(i-c >= 0) dp[i] = min(dp[i], dp[i-c] + 1);
            else break;
        }
    }
    
    if(dp[x] == INF){
        cout << -1 << endl;
        return;
    }
    
    cout << dp[x] << endl;
    
    /*
    dp[x] = min coins to compute sum x
    Base case = 0 (since you need 0 coins to compute sum of 0)
    For each sum x, you take the best way to compute it using
    the given coins, i.e the best i-c.
    The answer is just dp[x], but note that it may be imposs
    to compute the sum, this happens if dp[x] never got 
    updated.
    */
}