//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        string ans = "";
        stack<char> st;

        // Traverse given string and push all characters
        // to stack until we see a dot.
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '.')
                st.push(s[i]);
    
            // When we see a dot, we print contents
            // of stack.
            else {
                while (!st.empty()) {
                    ans += st.top();
                    st.pop();
                }
                ans += ".";
            }
        }
    
        // there may not be a dot after the last word.
        while (!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        
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
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends