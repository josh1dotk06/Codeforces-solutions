void solve(){
    int n;
    cin >> n;
    vector<double> more(n);
    vector<double> problems(n);
    for(int i = 0; i < n; i++) cin >> more[i];
    for(int i = 0; i < n; i++) cin >> problems[i];

    double bestavg = 0;
    double curravg = 0;
    double currsum = 0;
    double j = 1;
    
    for(int i = n-1; i >= 0; i--){
        currsum+=problems[i];
        curravg = (currsum+more[j-1])/j;
        if(curravg > bestavg) bestavg = curravg;
        j++;
    }

    cout << fixed << setprecision(1) << bestavg << endl;
}

//extremely basic greedy, just start with most solved problem players, and find the max


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
