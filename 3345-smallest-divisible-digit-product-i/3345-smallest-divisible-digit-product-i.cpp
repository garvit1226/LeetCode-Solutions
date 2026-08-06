class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(true){
            int number =n;
            int ans=1;
            while(number>0){
                ans *= number%10;
                number = number/10;
            }
            if(ans%t==0) return n;
            n++;

        }
        return -1;
    }
};