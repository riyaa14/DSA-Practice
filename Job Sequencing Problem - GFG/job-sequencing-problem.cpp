//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        if(n==0) return {0, 0};
        // sort acc to deadline
        sort(arr, arr+n, cmp);
        
        int maxProfit = 0;
        int deadline = 0, numberOfJobs = 0;
        
        vector<bool> filled(n+1, false);
        
        for(int i=0; i<n; i++){
            
                // int freeslot = arr[i].dead;
                // while(freeslot > 0 and filled.count(freeslot)){
                //     freeslot--;
                // }
                
                // if(freeslot == 0) continue;
                
                // maxProfit += arr[i].profit;
                // filled.insert(freeslot);
                // numberOfJobs++;
                
                int freeslot = arr[i].dead;
                while(freeslot > 0){
                    if(!filled[freeslot]){
                        maxProfit += arr[i].profit;
                        filled[freeslot] = true;;
                        numberOfJobs++;
                        break;
                    }
                    
                    freeslot--;
                }
                
        }
        
        return {numberOfJobs, maxProfit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends