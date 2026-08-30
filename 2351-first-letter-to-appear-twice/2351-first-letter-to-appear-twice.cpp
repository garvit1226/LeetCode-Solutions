class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> mpp;

        for(char c:s){
            if(mpp.find(c)!=mpp.end()){
                return c;
            }
            mpp.insert(c);
        }
        return 'a';
    }
};