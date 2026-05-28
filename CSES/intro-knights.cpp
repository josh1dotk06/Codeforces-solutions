#include <bits/stdc++.h>
#include <cmath>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nope cout << "NO" << endl;
#define yup cout << "YES" << endl;
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    
    for(int i = 1; i<=n; i++){
        
        if(i==1){
            cout << 0 << endl;
            continue;
        }
        else if(i==2){
            cout << 6 << endl;
            continue;
        }
        else if(i == 3){
            cout << 28 << endl;
            continue;
        }
        
        ll cells = i*i;
        ll total = nChooseK(cells,2);
        ll poss = ((i-2)*(10+4*(i-4)))+(4+2*(i-4));
        cout << total-poss << endl;   
    }

   /* we solve this combinatorically.
   Since there are more attacking positions than non attacking positions, we use indirect counting. Take the total possible combinations - attacking moves.
   
   Total possible combinations on nxn grid is just NChoose2. Then we create a formula of the number of attacking moves by systematically counting all possible ways and formulizing a pattern (the method was to go from left to right top to bottom)
   */
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1; 	
    //cin >> t;
    while(t--) solve();
    return 0;
}