//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int S = 0;
        for(int i=0; i<N; i++){
            S+=arr[i];
        }
        
        if(S%2!=0) return false;
        
        vector<vector<bool>> dp(N+1, vector<bool>(S, false));
        
        for(int i=0; i<=N; i++){
            dp[i][S/2] = true;
        }
        
        for(int i=N-1; i>=0; i--){
            for(int j=(S/2) - 1; j>=0; j--){
               dp[i][j] = dp[i+1][j+arr[i]] or dp[i+1][j] ;
            }
        }
        
        return dp[0][0];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends