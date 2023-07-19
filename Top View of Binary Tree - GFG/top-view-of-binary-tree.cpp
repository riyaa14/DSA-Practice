//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
// class Solution
// {
//     public:
//     //Function to return a list of nodes visible from the top view 
//     //from left to right in Binary Tree.
    
//     void helper(Node* root, int &maxLeft, int &maxRight, int curr, map<int, int>& ans){
        
//         if(!root) return;
        
//         if(curr<maxLeft){
//             ans[curr] = root->data;
//             maxLeft = curr;
//         }
        
//         if(curr>maxRight){
//             ans[curr] = root->data;
//             maxRight = curr;
//         }
        
//         helper(root->left, maxLeft, maxRight, curr-1, ans);
//         helper(root->right, maxLeft, maxRight, curr+1, ans);
        
//     }
    
    
//     vector<int> topView(Node *root)
//     {
//         if(!root) return {};
        
//         map<int, int> ans;
//         int maxLeft = 0, maxRight = 0;
//         ans[0] = root->data;
//         helper(root, maxLeft, maxRight, 0, ans);
        
//         vector<int> res;
//         for(auto x: ans){
//             res.push_back(x.second);
//         }
        
//         return res;
        
//     }

// };

class Solution {
public:
    // Function to return a list of nodes visible from the top view 
    // from left to right in Binary Tree.
    
    void helper(Node* root, int curr, int depth, map<int, pair<int, int>>& ans) {
        if (!root) return;
        
        // If the current horizontal distance is not already present in the map,
        // or the current node is at a higher depth than the previously seen node
        // at the same horizontal distance, update the map.
        if (ans.find(curr) == ans.end() || depth < ans[curr].second) {
            ans[curr] = {root->data, depth};
        }
        
        // Traverse the left and right subtrees.
        helper(root->left, curr - 1, depth + 1, ans);
        helper(root->right, curr + 1, depth + 1, ans);
    }
    
    vector<int> topView(Node *root) {
        if (!root) return {};
        
        map<int, pair<int, int>> ans;
        helper(root, 0, 0, ans);
        
        vector<int> res;
        for (auto x: ans) {
            res.push_back(x.second.first);
        }
        
        return res;
    }
};




//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends