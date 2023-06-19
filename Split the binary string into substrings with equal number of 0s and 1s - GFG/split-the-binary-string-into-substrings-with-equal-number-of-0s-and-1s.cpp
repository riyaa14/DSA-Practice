//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int zeroes = 0, ones = 0, countSubstr = 0;
        for(int i=0; i<str.length(); i++){
            
            if(str[i] == '0') zeroes++;
            else ones++;
            
            if(zeroes == ones){
                countSubstr++;
                zeroes = 0;
                ones = 0;
            }
        }
        
        if(zeroes != ones) return -1;
        
        return countSubstr;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends