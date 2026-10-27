class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m);
        string temp1 = "";
        string temp2 = "";
        for(int i=0;i<n-1;i++){
            temp1+= '#';
            temp2+= '.';
        }
        temp1+= '.';
        temp2+= '.';

        ans[0] = temp2;
        for(int i=1;i<m;i++){
            ans[i] = temp1;
        }
        return ans;

    }
};