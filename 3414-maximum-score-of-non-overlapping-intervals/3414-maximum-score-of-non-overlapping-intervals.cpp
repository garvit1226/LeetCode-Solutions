class Solution {
public:
    struct State {
        long long weight;
        vector<int> ids;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

     
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

    
        sort(intervals.begin(), intervals.end());

        vector<int> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
        }

        
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            next[i] = upper_bound(
                starts.begin(),
                starts.end(),
                intervals[i][1]
            ) - starts.begin();
        }

        
      
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5, {0, {}})
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

            
                State skip = dp[i + 1][k];

             
                State take = dp[next[i]][k - 1];

                take.weight += intervals[i][2];
                take.ids.push_back(intervals[i][3]);

                sort(take.ids.begin(), take.ids.end());

             
                if (take.weight > skip.weight) {
                    dp[i][k] = take;
                }
                else if (take.weight < skip.weight) {
                    dp[i][k] = skip;
                }
                else {
                   
                    dp[i][k] =
                        (take.ids < skip.ids ? take : skip);
                }
            }
        }

        return dp[0][4].ids;
    }
};