class Solution {
public:
    int myAtoi(string str) {
        int sign = 0;
        long long num = 0;
        bool foundNum = false;
        bool foundChar;
        
        for(char i : str){
            if(i == ' ' && (sign || foundNum)) break;
            if(i == ' ') continue;
            foundChar = !(i>='0' && i<='9');
            if(foundChar && i != '-' && i != '+' && !foundNum) return 0;
            if(foundChar && foundNum) break;
            if(foundChar) {
                if(sign) return 0;
                sign = (i=='-') ? -1 : 1;
            }
            if(!foundChar){
                if(num*10 >= INT_MAX && sign != -1) return INT_MAX;
                if((num*10*sign) <= INT_MIN) return INT_MIN;
                
                num*=10; 
                num+=(i-48);
                foundNum = true;
            }
             
        }
        
        if(sign) num *= sign;
        
        if(num > INT_MAX) return INT_MAX;
        if(num < INT_MIN) return INT_MIN;
        return num;
    }
};
