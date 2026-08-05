class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> row(numRows,"");
        int idx=0;
        while(idx<s.size()){
            for(int i=0;i<numRows && idx<s.size();i++){
                row[i].push_back(s[idx]);
                idx++;
            }
            for(int i=numRows-2;i>0 && idx<s.size();i--){
                row[i].push_back(s[idx]);
                idx++;
            }
        }
        string ans="";
        for(string str: row){
            ans+=str;
        }
        return ans;
    }
};