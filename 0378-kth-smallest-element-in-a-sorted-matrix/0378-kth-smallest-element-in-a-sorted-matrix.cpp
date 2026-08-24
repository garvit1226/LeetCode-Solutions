class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        // {value, row, column}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        
        for(int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

    
        for(int i = 0; i < k-1; i++) {

            auto [value, row, col] = pq.top();
            pq.pop();

            
            if(col + 1 < n) {
                pq.push({matrix[row][col+1], row, col+1});
            }
        }

        return get<0>(pq.top());
    }
};