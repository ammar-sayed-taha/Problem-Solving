class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> note;
        for(auto c: magazine) note[c]++;
        for(auto c: ransomNote){
            if(note.find(c) != note.end()){
                if(note[c] == 0) return false;
                note[c]--;
            }
            else return false;
        }
        return true;
    }
};
