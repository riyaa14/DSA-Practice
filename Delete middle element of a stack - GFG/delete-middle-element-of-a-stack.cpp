//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    
    void deleteMidHelper(stack<int>&s, int sizeOfStack, int currElem){
        if(s.empty()) return;
        
        if(currElem == (sizeOfStack-1)/2){
            s.pop();
            return;
        }
        
        int topElem = s.top();
        s.pop();
        deleteMidHelper(s, sizeOfStack, currElem-1);
        s.push(topElem);
        
        return;
    }
    
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        deleteMidHelper(s, sizeOfStack, sizeOfStack-1);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends