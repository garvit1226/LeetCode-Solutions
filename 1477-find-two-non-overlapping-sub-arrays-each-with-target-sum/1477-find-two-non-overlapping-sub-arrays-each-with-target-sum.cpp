class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i=0,j=0;

        int currsum =0;
        vector<int> minBestlen(n,INT_MAX);
        int bestMinlen = INT_MAX, result = INT_MAX;

        while(j<n){
            currsum += arr[j];

            while(i<j && currsum>target){
                currsum -= arr[i];
                i++;
            }

            if(currsum == target){
                int len = j-i+1;

                if(i>0 && minBestlen[i-1]!=INT_MAX){
                result = min(result, len + minBestlen[i-1]);
                }

                bestMinlen = min(bestMinlen , len);
            }
            minBestlen[j] = bestMinlen;
            j++;
        }

        return result == INT_MAX? -1: result;
    }
};