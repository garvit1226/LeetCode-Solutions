class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                stk.push(ch);
            }
            else{
                if(stk.empty()) return false;
                char tch = stk.top();
                stk.pop();
                if((ch==')' && tch!='(') || (ch=='}' && tch!='{') || (ch==']' && tch!='[')){
                    return false;
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};