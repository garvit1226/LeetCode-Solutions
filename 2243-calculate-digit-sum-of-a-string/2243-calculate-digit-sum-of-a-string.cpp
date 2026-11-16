class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string temp = "";
            for(int i=0;i<s.size();i){
                int sum=0;
                for(int j=0;j<k;j++){
                    sum+= s[i] - '0';
                    i++;
                    if(i==s.size()){
                        break;
                    }
                }
                temp += to_string(sum);
            }
            s= temp;
        }
        return s;
    }
};