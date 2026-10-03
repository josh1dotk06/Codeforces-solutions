void solve(){

    int r,c;
    cin >> r >> c;
    
    int a,b;
    cin >> a >> b;
    int x,y;
    cin >> x >> y;

    //r strings, each element represents a row, consisting of c characters (not defined tho)
    vector<string> rows(r+1);

    
    for(int i = 1; i <= r; i++){
        cin >> rows[i];
    }

    //i guess you just simulate it
    //you can get stuck in an infinite loop of left turns, so you gotta check a upper bound
    //just see if you get within the destination within r*c*100 tries

    vector<vector<char>> grid(r+1, vector<char>(c+1));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            //fix string 0 indexing to 1 indexing in new vec
            grid[i][j] = rows[i][j-1];
        }
    }

    int curri = a;
    int currj = b;
    //R L, U, D
    char dir = 'R';

    int upperbound = 0;

    // map<char, int> leftCorrespond;
    // leftCorrespond['R'].put()

        //some large value, but it doesnt matter
    while(!(curri == x && currj == y)){

        if(upperbound == r*c*100){
            //took too long, is an infinite loop
            cout << 0 << endl;
            return;
        }
        
        //left first
        if(dir == 'R' && curri-1 >= 1 && grid[curri-1][currj] == '0'){ //go up
            dir = 'U';
            curri--;
        }
        else if(dir == 'U' && currj-1 >= 1 && grid[curri][currj-1] == '0'){ //go left
            dir = 'L';
            currj--;
        }
        else if(dir == 'D' && currj+1 <= c && grid[curri][currj+1] == '0'){ //go right
            dir = 'R';
            currj++;
        }
        else if(dir == 'L' && curri+1 <= r && grid[curri+1][currj] == '0'){ //go down
            dir = 'D';
            curri++;
        }

            
        //straight
        else if(dir == 'L' && currj-1 >= 1 && grid[curri][currj-1] == '0'){ //go straight left
            currj--;
        } 
        else if(dir == 'R' && currj+1 <= c && grid[curri][currj+1] == '0'){ //go straight left
            currj++;
        } 
        else if(dir == 'U' && curri-1 >= 1 && grid[curri-1][currj] == '0'){ //go straight left
            curri--;
        } 
        else if(dir == 'D' && curri+1 <= r && grid[curri+1][currj] == '0'){ //go straight left
            curri++;
        } 


        //must turn right otherwise
        else{
            if(dir == 'R') dir = 'D';
            else if(dir == 'U') dir = 'R';
            else if(dir == 'D') dir = 'L';
            else if(dir == 'L') dir = 'U';
        }

        upperbound++;
    }

    //we exited
    cout << 1 << endl;
}


//just simulate the movements on a 2d grid, the constraints are low enough
//its possible if we exit and reach the desitnatiopn cell
//its impossible if after some upperbound (i chose r*c*100, but r*c*4 is actually sufficient), we are still in the loop
//r*c*4 since for each cell there are 4 directions


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
