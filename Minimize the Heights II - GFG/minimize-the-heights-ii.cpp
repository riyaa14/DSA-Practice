//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        
        if(n==1) return 0;
        
        sort(arr, arr+n);
        
        int minDiff = INT_MAX, i=0;
        
        while(arr[i]<k) i++;
        
        if(i==0) i++;
        
        int minElem = INT_MAX, maxElem = 0;
        for(; i<n; i++){
            minElem = min(arr[0]+k, arr[i]-k);
            maxElem = max(arr[i-1]+k, arr[n-1]-k);
            minDiff = min(minDiff, maxElem-minElem);
        }
        
        return min(minDiff, arr[n-1]-arr[0]);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends