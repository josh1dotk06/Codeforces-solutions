void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if(n == 1){
        nope
        return;
    }
    
    int first = s.length();
    
    for(int k = 0; k < n-1; k++){
        
    for(int i = 0; i < n-1; i++){
        
        if(s[i] == s[i+1]){
            s.erase(i, 2);
            i--;
        }
    }
    
    if(s.length() == 0) break;
    else if(s.length() == first) break;
    first = s.length();
    }
    
    if(s.length() != 0){
        nope
        return;
    }
    yup
    
    /* The key insight here is that if the string
    does not initially contain 2 consecutive letters
    which are same, then its a NO. We can apply a 
    solution that has a recursive idea. The greedy is
    the moment we see
    a consecutive string XX, then we remove those,
    and repeat. Aks wins if the string at the end is
    empty.
    */
}