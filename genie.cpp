void solve(){
    int W, K, C;
    cin >> W >> K >> C;

    //pick the largest rank genie K such that K <= currW
    //thats the simple greedy
    //if its impossible then its impossible
    //look at notes to see the process, the code is just long to cover edge cases (and i couldve made it more concise)




    int currW = W;
    for(int i = K; i >= 1; ){
        if(i > currW){
            cout << "no" << endl;
            return;
        }
        if(currW == i){
            cout << "yes" << endl;
            return;
        }

        currW-=(i-1);
        if(i-currW >= C){
            i = currW;
        }
        else{
            if(i < currW){
                i-=C;
                continue;
            }
            while(i >= currW){
                i-=C;
                if(i < 1){
                    cout << "no" << endl;
                    return;
                }
            }
        }
    }

    cout << "no" << endl;

    
    
}


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
