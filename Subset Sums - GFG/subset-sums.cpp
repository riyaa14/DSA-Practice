//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void getSubsetSums(vector<int>&ans, vector<int>& arr, int i, int sum){
        
        if(i==arr.size()){ 
            ans.push_back(sum);
            return;
        }
        
        // pick
        //implicit back tracking
        getSubsetSums(ans, arr, i+1, sum+arr[i]);
        
        // leave
        getSubsetSums(ans, arr, i+1, sum);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        getSubsetSums(ans, arr, 0, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends