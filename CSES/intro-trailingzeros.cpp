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
       
    vector<int> p5 = {
        5,
        25,
        125,
        625,
        3125,
        15625,
        78125,
        390625,
        1953125,
        9765625,
        48828125,
        244140625
    };
    
    int five = 0;
    for(int i = 0; i < p5.size(); i++){
        if(p5[i] > n) break;
        
        five+=(int)((n/p5[i]));
    }
    int two = (int)(n/2);
    
    cout << min(five,two) << endl;

    /* a 0 is contributed when the number
    is divisible by 10. I.e when the number
    is divisible by 2 and 5.
    
    So you just count how many factors of 2 and 5
    there are (which can be computed using n/2
    and n/5), and take the minimum of it 
    in order to count the amount of valid 2-5 pairs.
    
    You also need to take into account numbers
    that have multiple factors of 5. (you dont
    need to do the same with 2 since there
    will always be more factors of 2 than 5
    even without counting for powers of 2)
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
