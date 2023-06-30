//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void getPaths(vector<vector<int>> &m, int n, vector<string>& ans, string path, int i, int j){
        
        if(i==n-1 and j==n-1) {
            ans.push_back(path);
            return;
        }
        
        if(i<0 or j<0 or i>=n or j>=n or m[i][j] == 0) return;
        
        m[i][j] = 0;
        getPaths(m, n, ans, path+"D", i+1, j);
        getPaths(m, n, ans, path+"U", i-1, j);
        getPaths(m, n, ans, path+"R", i, j+1);
        getPaths(m, n, ans, path+"L", i, j-1);
        m[i][j] = 1;
        
        return;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        if(m[n-1][n-1] == 0) return {};
        
        vector<string> ans;
        string path;
        getPaths(m, n, ans, path, 0, 0);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends