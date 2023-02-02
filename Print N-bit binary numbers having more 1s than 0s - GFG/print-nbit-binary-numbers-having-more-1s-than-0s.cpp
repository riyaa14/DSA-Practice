//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void genNos(int N, int ones, int zeroes, string validNo, vector<string>& result){
    
    if(validNo.size() == N){
        result.push_back(validNo);
        return;
    }
    
    if(ones<N){
        genNos(N, ones+1, zeroes , validNo+"1", result);
    }
    
    if(ones>zeroes){
        genNos(N, ones, zeroes+1, validNo+"0", result);
    }
    
    return;
}

	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> result;
	    genNos(N, 0, 0, "", result);
	    return result;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends