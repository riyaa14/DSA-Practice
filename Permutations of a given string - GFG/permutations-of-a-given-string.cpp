//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    
	    void permutations(string S, set<string>& res, int i){
	        
	        if(i==S.length()-1) {
	            res.insert(S);
	        }
	        
	        for(int j=i; j<S.length(); j++){
	            swap(S[i], S[j]);
	            permutations(S, res, i+1);
	            swap(S[i], S[j]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    set<string> res;
		    permutations(S, res, 0);
		    
		    vector<string> ans;
		    for(auto x:res){
		        ans.push_back(x);
		    }
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends