bool hasmult(long long n) {
    if (n <= 1) return false;
    int unique_factors = 0;
    if (n % 2 == 0) {
        unique_factors++;
 
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            unique_factors++;
 
            if (unique_factors > 1) {
                return true; 
            }
 
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 2) {
        unique_factors++;
    }
    return unique_factors > 1;
}
 
long long getfact(long long n) {
 
    if (n <= 1) return 0; 
 
    if (n % 2 == 0) {
        return 2;
    }
 
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return i;
        }
    }
 
    return n;
}
 

void solve(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++){
       cin >> a[i]; 
    } 
    
    bool presort = true;
    //check presort
    for(int i = 1; i < n; i++){
        if(a[i] >= a[i-1]) continue;
        else{
            presort = false;
            break;
        }
    }
    if(presort){
        cout << "Bob" << endl;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(!hasmult(a[i])) a[i] = getfact(a[i]);
        else{ 
            cout << "Alice" << endl;
            return;
        }
    }
    
    bool postsort = true;
    for(int i = 1; i < n; i++){
        if(a[i] >= a[i-1]) continue;
        else{
            postsort = false;
            break;
        }
    }
    if(postsort){
        cout << "Bob" << endl;
        return;
    }
    
    cout << "Alice" << endl;
    
    /*
    Notice the invariants and mathematical insights
    step by step. First of all, neither player
    can pick a prime number. In these game problems,
    again we question what the most optimal move
    each player cna make is, or figure out if Alice
    /Bob can win automatically, what is the win
    condition? Here is the key invairant: Alice's
    goal is to make the array as unsorted as poss
    if aAlice picks 20, Alice should optimally split
    it up into [10,2]. But the key ism Alice has
    just made the array unsorted forever assuming
    the number she picked has distinct prime factors: 
    20 becomes [2,5,2] after Bob's move. If the number has only 1 distinct prime factor like
    8192, then regardless of anyones optimal moves,
    this get split up into a bunch of 2s, so nothing
    meaningful happens. This means Alice auto
    wins if the array contains a number with
    distinct prime factors
    */
}