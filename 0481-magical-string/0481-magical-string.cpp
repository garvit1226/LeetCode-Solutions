class Solution {
public:
    int magicalString(int n) {
        if(n==0) return 0;
        if(n<=3) return 1;
        vector<int> arr(n+1);
        arr[0]=1;
        arr[1]=2;
        arr[2]=2;
        int i=2;
        int j=3;
        int ans =1;
        int dig=1;
        while(j<n){
            int times = arr[i];
            for(int k=0;k<times && j<n;k++){
                arr[j] = dig;
                if(arr[j]==1) ans++;
                j++;
            }
            i++;
            dig=3-dig;
        }
        return ans;
    }
};