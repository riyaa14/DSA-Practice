//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
// 	void dfsSort(int node, vector<int>& visited, vector<int> adj[], stack<int>& s){
	    
// 	    if(visited[node]) return;
	    
// 	    for(auto it : adj[node]){
// 	        dfsSort(it, visited, adj, s);
// 	    }
	    
// 	    s.push(node);
// 	    visited[node] = 1;
// 	    return;
	    
// 	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V, 0);
	   // stack<int> s;
	   // // code here
	   // for(int i=0; i<V; i++){
	   //     if(!visited[i]) dfsSort(i, visited, adj, s);
	   // }
	    
	    vector<int> result;
	   // while(!s.empty()){
	   //     result.push_back(s.top());
	   //     s.pop();
	        
	   // }
	   
	   
	   vector<int> inDeg(V, 0);
	   queue<int> q;
	   
	   for(int i=0; i<V; i++){
	      for(auto x: adj[i]) inDeg[x]++; 
	   }
	   
	   for(int i=0; i<V; i++){
	       if(inDeg[i]==0) q.push(i);
	   }
	   
	   while(!q.empty()){
	       int front = q.front();
	       result.push_back(front);
	       q.pop();
	       
	       for(auto curr : adj[front]){
	           inDeg[curr]--;
	           if(inDeg[curr] == 0) q.push(curr);
	       }
	   }
	    
	    return result;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends