class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int vocab[26] = {0};
        for(auto c: magazine)
            vocab[c-'a']++;
        for(auto c: ransomNote){
            if(vocab[c-'a'])
                vocab[c-'a']--;
            else
                return false;
        }
        return true;
    }
};
