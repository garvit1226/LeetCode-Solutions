class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int deg=0;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                deg++;
                ans[i]= deg%2;
            }
            else{
                ans[i] = deg%2;
                deg--;
            }
        }
        return ans;
    }
};