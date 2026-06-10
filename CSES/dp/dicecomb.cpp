void solve(){
    
    int n;
    int MOD = 1e9+7;
    cin >> n;
    vector<int> dp(n+1, 0);
    //base cases
    dp[0] = 1;
    dp[1] = 1;
    vector<int> dice = {1,2,3,4,5,6};
    
    for(int i = 2; i <=n; i++){
        for(auto num : dice){
            if(i-num >= 0) dp[i] = (dp[i] + dp[i-num])%MOD;
            else break;
        }
    }
    
    cout << dp[n] << endl;
    
    /*
    The state: dp[x] = # of ways to compute sum x
    Determine base cases.
    Then the recursive idea is to add on the number of ways to
    calculate dp[x] based on the number of ways to obtain
    dp[x-num] where num = for all sides of the dice, ensuring
    that x-num doesnt go negative (because you can't obtain a 3
    if you roll a 4, 5, or 6)
    */
    
}