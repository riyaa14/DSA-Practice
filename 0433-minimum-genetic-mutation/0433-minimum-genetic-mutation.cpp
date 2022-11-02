class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        set<string> bankSet;
        for(int i=0; i<bank.size(); i++){
            bankSet.insert(bank[i]);
        }
        
        if(bankSet.find(end) == bankSet.end()) return -1;
        
        queue<pair<string, int>> q; 
        q.push({start, 0});
        unordered_set<string> seen;
        seen.insert(start);
        
        while(!q.empty()){
            
            string gene = q.front().first;
            int level = q.front().second;
            
            q.pop();
            
            if(gene == end) return level;
            
            for(int i=0; i<start.size(); i++){
                for(char c: "ACGT"){
                    string newGene = gene;
                    newGene[i] = c;
                    if(seen.find(newGene) == seen.end() and bankSet.find(newGene) != bankSet.end())  {
                        q.push({newGene, level+1});
                        seen.insert(newGene);
                    }
                }
            }
            
        }
        
        return -1;
    }
};