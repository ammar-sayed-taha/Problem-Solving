class Solution {
public:
    int findComplement(int num) {
        string binary =  bitset<128>(num).to_string();
        bool leadzero = true;
        for(char &c: binary){
            if(leadzero && c == '0') continue;
            else if(leadzero && c == '1'){
                leadzero = false;
                c = '0';
            }else
                c = c == '1' ? '0' : '1';
        }
        num = bitset<128>(binary).to_ulong();
        return num;
    }
};
