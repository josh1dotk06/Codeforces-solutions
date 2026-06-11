void solve(){
    
    int n;
    cin >> n;
    vector<string> grid(n);
    
    for(int i = 0; i < n; i++) cin >> grid[i];
    
    //dp[x][y] = paths from x,y to n-1,n-1 (lower right)
    //ans is dp[0][0]
    
    vector<vector<int>> dp(n, vector<int>(n,0));
    
    if(grid[n-1][n-1] == '*'){
        cout << 0 << endl;
        return;
    }
    dp[n-1][n-1] = 1;
    
    
    //sweep left-up from the cell to the left of the bottom right
    //all the way to the top left cell
    int MOD = 1e9+7;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(i == n-1 && j == n-1) continue;
            if(grid[i][j] != '*'){
                if(j+1 <= n-1) dp[i][j] = (dp[i][j] + dp[i][j+1])%MOD;
                if(i+1 <= n-1) dp[i][j] = (dp[i][j] + dp[i+1][j])%MOD;
            }
        }
    }
    
    cout << dp[0][0] << endl;
    
    /*
    Let dp[x][y] = the # of paths from x,y to bottom right cell
    This means we need to iterate backwards starting at n-1,n-1 (skip bottom right cell since its the base case)
    The base case is that there is 1 way to reach n-1,n-1 from n-1,n-1
    
    We sweep left-top, starting at i==n-1 j==n-2. The key here
    is to compute dp[x][y] as long as the cell at x,y is not a
    trap, otherwise dp[x][y] is 0. Because if x,y was a trap
    then theres so way to get to the bottom right if you just
    spawn on a trap.
    
    We recursively add by getting the dp values from the cells to
    the bottom and right of x,y (to simulate only being able to
    move down or to the right)
    */
    
}