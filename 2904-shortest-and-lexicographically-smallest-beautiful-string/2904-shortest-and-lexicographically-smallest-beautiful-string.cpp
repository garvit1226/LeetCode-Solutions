class Solution {
public:
    bool compare(string s1, string&s2){
        if(s1.size()!=s2.size()){
            return s1.size()<s2.size();

        }
        return s1<s2;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int ones =0;
        for(char c:s){
            if(c=='1'){
                ones++;
            }
        }
        if(ones<k) return "";
        int start =0;
         ones =0;
        string ans = s;
        for(int end =0;end<s.size();end++){
            if(s[end]=='1') ones++;
            if(ones==k && compare(s.substr(start,end-start+1),ans)){
                ans = s.substr(start,end-start+1);
            }

            while(ones==k || s[start]=='0'){
                if(s[start]=='1') ones--;
                start++;
            }
        }
        return ans;
    }
};