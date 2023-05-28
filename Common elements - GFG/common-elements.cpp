//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here
            
            vector<int> common;
            int prev1 = INT_MIN, prev2 = INT_MIN, prev3 = INT_MIN;
            int i=0, j=0, k=0;
            while(i<n1 and j<n2 and k<n3){
                
                while(i<n1 and A[i]==prev1) i++;
                while(j<n2 and B[j]==prev2) j++;
                while(k<n3 and C[k]==prev3) k++;
                
                if(A[i]==B[j] and B[j]==C[k]) {
                    common.push_back(A[i]);
                    prev1 = prev2 = prev3 = A[i];
                    i++; 
                    j++; 
                    k++;
                }
                else if(A[i] <= B[j] and A[i] <= C[k]) prev1 = A[i++];
                else if(B[j] <= A[i] and B[j] <= C[k]) prev2 = B[j++];
                else if(C[k] <= A[i] and C[k] <= B[j]) prev3 = C[k++];
                
                //i++;
                
            }
            
            return common;
            
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends