//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void process(vector<int>& pos, int k, int i){
        if(pos.size() == 1) return;
        
        int index = (k+i-1)%pos.size();
        // if k+i is greater than size toh it will be divided and remainder part will give us the position
        // if k+i is smaller and thus within the range of pos.size() then % operator will return k+i only.
        
        auto it = pos.begin() + index;
        pos.erase(it);
        process(pos, k, index);
        return;
    }
  
    int safePos(int n, int k) {
        
        // code here
        vector<int> pos(n);
        for(int i=1; i<=n; i++){
           pos[i-1] = i; 
        }
        
        process(pos, k, 0);
        
        return pos[0];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends