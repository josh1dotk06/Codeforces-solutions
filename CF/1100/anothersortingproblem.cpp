void solve(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    int best = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1]){
            best = max(best, a[i-1]-a[i]);
        }
    }
    
    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1]){
            a[i]+=best;
        }
    }
    
    for(int i = 1; i < n; i++){
        if(a[i] >= a[i-1]) continue;
        else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    
    /*
    Since k is fixed, what does this imply?
    Note the invariant/insight: If a[i-1] > a[i],
    take a[i-1]-a[i] = k, you must add a[i]+=k to
    make the pair sorted again. If you do this for the
    entire array and find the max k value, this is
    the smallest k value which can fix the array.
    The greedy approach is thus to loop through
    again, and whenever a[i-1] > a[i], increment a[i]
    by this optimal k value.
    In the end, if the array is sorted, then YES, otherwise, NO
    */
}