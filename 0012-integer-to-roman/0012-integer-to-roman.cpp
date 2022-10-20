class Solution {
public:
    string intToRoman(int num) {
        
        // Breaking the given no.
        // string map[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string roman = "";
        int n = num, i = 1;  // i basically keeps track of place of digit : ones, tens, hundreds, etc.
        while(n > 0){
            int digit = (n%10)*i;
            
            if(digit >= 1000){
                
                int x = digit/1000;
                while(x != 0) { roman.insert(0, "M"); x--; }
                
            }else if(digit >= 100){
                
                if(digit == 400) roman.insert(0, "CD");
                else if(digit == 900) roman.insert(0, "CM");
                else if(digit >= 500) {
                    int x = (digit-500)/100;
                    while(x != 0) { roman.insert(0, "C"); x--; } 
                    roman.insert(0, "D");
                }else{
                    int x = digit/100;
                    while(x != 0){ roman.insert(0, "C"); x--; }
                }
                
            }else if(digit >= 10){
                 
                if(digit == 40) roman.insert(0, "XL");
                else if(digit == 90) roman.insert(0, "XC");
                else if(digit >= 50) {
                    int x = (digit-50)/10;
                    while(x != 0) { roman.insert(0, "X"); x--; } 
                    roman.insert(0, "L");
                }else{
                    int x = digit/10;
                    while(x != 0){ roman.insert(0, "X"); x--; }
                }
                
            }else{
                
                if(digit == 4) roman.insert(0, "IV");
                else if(digit == 9) roman.insert(0, "IX");
                else if(digit >= 5) {
                    int x = (digit-5);
                    while(x != 0) { roman.insert(0, "I"); x--; }
                    roman.insert(0, "V");
                }else{
                    int x = digit;
                    while(x != 0){ roman.insert(0, "I"); x--; }
                }
                
            }
            
        
            n /= 10;
            i *= 10;
        }
        
        return roman;
        
    }
};