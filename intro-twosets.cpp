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
   
   ll n;
   cin >> n;
   ll sm = (n*(n+1))/2;
   
   if(sm%2!=0){
       cout << "NO" << endl;
       return;
   }
   
   unordered_set<ll> has;
   for(ll i = 1; i <=n; i++){
       has.insert(i);
   }
   
   ll group = sm/2;
   vector<ll> set1;
   
   ll j = n;
   while(true){
       if(has.count(group)){
           has.erase(group);
           set1.pb(group);
           break;
       }
       group-=j;
       has.erase(j);
       set1.pb(j);
       j--;
   }
   
   cout << "YES" << endl;
   cout << set1.size() << endl;
   for(auto x : set1){
       cout << x << " ";
   }
   cout << endl;
   
   cout << has.size() << endl;
   for(auto x : has){
       cout << x << " ";
   }
   cout << endl;
   
   /* If the sum is odd, then its impossible.
   That is the trivial case
   
   If it is even, then we can construct a 
   solution in the following manner:
   Divide the sum in half (to represent the
   sum of each sets). This value is called group
   Iterate starting at the largest element, and 
   simulatenously subtract them from group
   while adding them to a vector, Check
   to see if the new value of group is
   contained within the set of all numbers.
   
   Turns out, you will always find a valid set
   this way. The remaining elements within the set
   is the contents of the other set.
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
