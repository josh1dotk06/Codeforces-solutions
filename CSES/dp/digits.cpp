void solve(){
    
    int n;
    cin >> n;
    //dp[x] = min steps to get x to 0
    
    const int INF = 1e18+2;
    vector<int> dp(n+1, INF);
    
    for(int i = 0; i <= 9; i++) dp[i] = 1;
    
    int temp;
    int len;
    for(int i = 10; i <= n; i++){
        
        vector<int> digits;
        len = to_string(i).length();
        temp = i;
        
        for(int j = 0; j < len; j++){
            int dig = temp%10;
            digits.pb(dig);
            temp/=10;
        }
        
        for(auto c : digits){
            if(i-c >= 0) dp[i] = min(dp[i], dp[i-c] + 1);
        }
    }
    cout << dp[n] << endl;
    
    /*
    dp[x] = min steps to get to 0 from x
    Note the base cases where ans = 1 for all single digit numbers
    From there on, we take all digits of n and push it
    into a vector. For each digit c in the number i, we
    find the best value for dp[i-c], this way we easily 
    compute the shortest path to 0.
    
    ans = dp[n]
    */
}