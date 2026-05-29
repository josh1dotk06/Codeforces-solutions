void solve(){
    
    /* The answer is simple, find first instance
    of A, and last instance of B, the insightful
    fact/ionvariant is that every index in betwene must be 
    used, so the answer is just the difference
    between those indices.
    */
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool first = 0;
    int indexA = -1;
    int indexB = -1;
    
    for(int i = 0; i < n; i++){
        if(s[i] == 'A' && !first){
            indexA = i;
            first = 1;
        }
        if(s[i] == 'B'){
            indexB = i;
        }
    }
    
    if(indexB < indexA || indexA == -1 || indexB == -1){
        cout << 0 << endl;
        return;
    }
    cout << indexB - indexA << endl;

}