class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(auto it : knowledge){
            mp[it[0]] = it[1];
        }
        string res = "";
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                i++;
                string temp ="";
            while(i<s.size() && s[i]!=')'){
                temp += s[i];
                i++;
            }
            i++;
            bool found = false;
           
                if(mp.find(temp)!=mp.end()){
                    res+= mp[temp];
                    found = true;
                    
                }
            if(!found){
                res+="?";
            }
            }
            else{
            res+= s[i];
            i++;
            }
        }
        return res;
    }
};