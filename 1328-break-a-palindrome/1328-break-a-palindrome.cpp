class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.length();
        if(palindrome.length() <= 1){
            return "";
        }
        int i;
        for(i=0; i<palindrome.length(); i++){
            if(n%2 != 0 and i == n/2) continue;
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a'; 
                break;
            }
        }
        
        if(i == palindrome.length()) palindrome[palindrome.length()-1] = 'b';
        
        return palindrome;
        
    }
};