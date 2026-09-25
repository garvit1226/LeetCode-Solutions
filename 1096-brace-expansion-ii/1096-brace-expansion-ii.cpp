class Solution {
public:

    set<string> combine(set<string> a, set<string> b) {
        set<string> ans;

        for (string x : a) {
            for (string y : b) {
                ans.insert(x + y);
            }
        }

        return ans;
    }

    set<string> solve(string &s, int &i) {

        set<string> ans;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {

                i++;  

                set<string> temp = solve(s, i);

                i++;  

                current = combine(current, temp);
            }

            else if (s[i] == ',') {

                
                ans.insert(current.begin(), current.end());

                current = {""};

                i++;
            }

            else {

                set<string> temp;
                temp.insert(string(1, s[i]));

                current = combine(current, temp);

                i++;
            }
        }

        
        ans.insert(current.begin(), current.end());

        return ans;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};