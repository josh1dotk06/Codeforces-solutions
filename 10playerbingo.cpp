void solve(){

    vector<int> nums(100);
    for(int i = 0; i < 100; i++){
        cin >> nums[i];
    }

    int ans;
    ans = nums[99]%10;
    if(ans == 0){
        cout << 10 << endl;
        return;
    }

    cout << ans;
}

//last person called is just the units digit of the last number (since they would still be in the game till then)
//ez


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
