//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
	    int S = 0;
	    for(int i=0; i<n; i++){
	        S+=arr[i];
	    }
	    
	    vector<vector<int>> dp(n+1, vector<int>(S+1, INT_MAX));
	    
	    for(int s=0; s<S+1; s++){
	        dp[n][s] = abs(s-(S-s));
	    }
	    
	    for(int i=0; i<n+1; i++){
	        dp[i][S] = S;
	    }
	    
	    for(int i=n-1; i>=0; i--){
	        for(int j=S-arr[i]; j>=0; j--){
	           // int diff = abs(j+arr[i]-(S-j-arr[i]));
	            dp[i][j] = min(dp[i+1][j+arr[i]], dp[i+1][j]);
	        }
	    }
	    
	    return dp[0][0];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends