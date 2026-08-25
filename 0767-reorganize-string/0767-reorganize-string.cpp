class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mpp;
        for(char c:s) mpp[c]++;

        priority_queue<pair<int,char>> pq;
        for(auto it:mpp){
            pq.push({it.second, it.first});
        }

        pair<int,char> prev = {0,'#'};
        string ans = "";
        while(!pq.empty()){
            auto [freq,ch] = pq.top();
            pq.pop();

            ans+=ch;
            freq--;

            if(prev.first>0){
                pq.push(prev);
            }
            prev = {freq,ch};
        }

        if(ans.size()==s.size()) return ans;
        return "";
    }
};