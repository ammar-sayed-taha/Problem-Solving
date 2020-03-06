class Solution {
public:
    string defangIPaddr(string address) {
        string adds = "";
        for(char s: address){
            if(s == '.') adds += "[.]";
            else adds += s;
        }
        return adds;
                
    }
};
