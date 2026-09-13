class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        map<pair<int, int>, int> mp;
        int ans = 0;
        
        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                
                if (img1[i1][j1] == 0)
                    continue;
                
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < n; j2++) {
                        
                        if (img2[i2][j2] == 1) {
                            int dx = i1 - i2;
                            int dy = j1 - j2;
                            
                            mp[{dx, dy}]++;
                            
                            ans = max(ans, mp[{dx, dy}]);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};