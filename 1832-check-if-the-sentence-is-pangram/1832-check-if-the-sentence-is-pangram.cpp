class Solution {
public:   
    bool checkIfPangram(string s) {
        vector<int>v(26);
        for(int p=0;p<s.length();p++){
            v[s[p]-97]++;
        }
        for(int p=0;p<26;p++){
            if(v[p]==0){
                return false;
            }
        }
        return true;
    }
};