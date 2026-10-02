void solve(){

    int r,c;
    cin >> r >> c;
    
    int a,b;
    cin >> a >> b;
    int x,y;
    cin >> x >> y;

    //r strings, each element represents a row, consisting of c characters (not defined tho)
    vector<string> grid(r+1);

    
    for(int i = 1; i <= r; i++){
        cin >> grid[i];
    }

    //i guess you just simulate it
    //you can get stuck in an infinite loop of left turns, so you gotta check a upper bound
    //just see if you get within the destination within r*c*100 tries

    int curri = a;
    int currj = b;
    //R L, U, D
    char dir = 'R';

    int upperbound = 0;

    map<char, int> leftCorrespond;
    leftCorrespond['R'].put()

        //some large value, but it doesnt matter
    while(!(curri == x && currj == y)){

        if(upperbound == r*c*100){
            //took too long, is an infinite loop
            cout << 0 << endl;
            return;
        }
        
        //left first
        if(dir == 'R' && i-1 >= 1 && grid[curri-1][currj] == 0){ //go up
            dir = 'U';
            curri--;
        }
        else if(dir == 'U' && j-1 >= 1 && grid[curri][currj-1] == 0){ //go left
            dir = 'L';
            currj--;
        }
        else if(dir == 'D' && i-1 >= 1 && grid[curri][currj+1] == 0){ //go right
            dir = 'R';
            currj++;
        }
        else if(dir == 'L' && i-1 >= 1 && grid[curri+1][currj] == 0){ //go down
            dir = 'D';
            curri++;
        }

            
        //straight
        else if(dir == 'L' && j-1 >= 1 && grid[curri][currj-1] == 0){ //go straight left
            currj--;
        } 
        else if(dir == 'R' && j+1 >= 1 && grid[curri][currj+1] == 0){ //go straight left
            currj++;
        } 
        else if(dir == 'U' && i-1 >= 1 && grid[curri-1][currj] == 0){ //go straight left
            curri--;
        } 
        else if(dir == 'D' && i+1 >= 1 && grid[curri+1][currj] == 0){ //go straight left
            curri++;
        } 


            
        else if(dir == 'U' && j+1 >= 1 && grid[curri][currj+1] == 0){ //go left
            dir = 'R';
            currj++;
        }
        else if(dir == 'D' && i-1 >= 1 && grid[curri][currj-1] == 0){ //go right
            dir = 'L';
            currj--;
        }
        else if(dir == 'L' && i-1 >= 1 && grid[curri-1][currj] == 0){ //go down
            dir = 'U';
            curri--;
        }
        else if(dir == 'R' && i-1 >= 1 && grid[curri+1][currj] == 0){ //go down
            dir = 'D';
            curri++;
        }

        upperbound++;
    }

    //we exited
    cout << 1 << endl;
}


//not finished yet


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
