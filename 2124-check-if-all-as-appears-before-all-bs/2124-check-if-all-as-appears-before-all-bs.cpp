class Solution {
public:
    bool checkString(string s) {
        bool temp = false;
        for(char c: s){
            if(c=='b'){
                temp = true;
            }
            else if(temp ){
                return false;
            }
        }
        return true;
    }
};