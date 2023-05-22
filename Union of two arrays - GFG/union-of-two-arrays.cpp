//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        
        // int i=0, j=0, count = 0;
        
        // while(i<n and j<m){
        //     if(a[i]==b[j]){
        //         i++;
        //         j++;
        //         count++;
        //     }else if(a[i] > b[j]){
        //         j++;
        //         count += 2;
        //     }else{
        //         i++;
        //         count += 2;
        //     }
            
        // }
        
        // if(i<n) return count + n-i;
        
        // return count + n-j;
        
        set<int> unionSet;
        
        
        for(int i=0; i<n; i++){
            unionSet.insert(a[i]);
        }
        
        for(int i=0; i<m; i++){
            unionSet.insert(b[i]);
        }
        
        return unionSet.size();
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends