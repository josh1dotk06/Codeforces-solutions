void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    
    sort(all(b));
    
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) continue;
        else{
            cout << 1 << endl;
            return;
        }
    }
    
    cout << n << endl;
    
    /*
    The key invariant to note here is that by being
    able to pick any element to remove, you can
    pick some element, such that you can always keep
    the array remaining unsorted until the very last
    element. The answer is just 1 if the array is
    already unsorted, and n if its sorted.
    */
}