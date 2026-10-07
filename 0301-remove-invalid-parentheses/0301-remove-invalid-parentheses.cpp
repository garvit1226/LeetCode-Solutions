class Solution {
public:
    unordered_set<string> st;

    void dfs(string &s, int index, int leftRemove,
             int rightRemove, int open, string curr) {

        if(index == s.size()) {
            if(leftRemove == 0 && rightRemove == 0 && open == 0) {
                st.insert(curr);
            }
            return;
        }

        char c = s[index];

        
        if(c == '(') {

            
            if(leftRemove > 0) {
                dfs(s, index + 1, leftRemove - 1,
                    rightRemove, open, curr);
            }

            
            dfs(s, index + 1, leftRemove,
                rightRemove, open + 1, curr + c);
        }

        else if(c == ')') {

         
            if(rightRemove > 0) {
                dfs(s, index + 1, leftRemove,
                    rightRemove - 1, open, curr);
            }

            
            if(open > 0) {
                dfs(s, index + 1, leftRemove,
                    rightRemove, open - 1, curr + c);
            }
        }

        else {
           
            dfs(s, index + 1, leftRemove,
                rightRemove, open, curr + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

       
        for(char c : s) {

            if(c == '(') {
                leftRemove++;
            }

            else if(c == ')') {

                if(leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        string curr = "";

        dfs(s, 0, leftRemove, rightRemove, 0, curr);

        return vector<string>(st.begin(), st.end());
    }
};