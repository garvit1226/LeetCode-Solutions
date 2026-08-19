class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mpp;

        for (auto& seats : reservedSeats) {
            mpp[seats[0]].insert(seats[1]);
        }

        int ans = 2 * n;

        for (auto& i : mpp) {
            bool first = true;  
            bool mid = true;    
            bool last = true;   

            for (int num : i.second) {
                if (num >= 2 && num <= 5)
                    first = false;

                if (num >= 4 && num <= 7)
                    mid = false;

                if (num >= 6 && num <= 9)
                    last = false;
            }

            if (!first && !last) {
                
                if (mid)
                    ans -= 1;
                else
                    ans -= 2;
            }
            else if (!first || !last) {
                ans -= 1;
            }
        }

        return ans;
    }
};