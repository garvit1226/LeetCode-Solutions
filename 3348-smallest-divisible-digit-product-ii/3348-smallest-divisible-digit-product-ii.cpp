class Solution {
public:

    long gcd(long first, long second){
        while(second!=0){
            long temp = second;
            second = first%second;
            first = temp;
        }
        return first;
    }
    string smallestNumber(string num, long long t) {
        long remainingFactor =t;
        for(int factor=2;factor<=9;factor++){
            while(remainingFactor%factor==0){
                remainingFactor/=factor;
            }
        }
        if(remainingFactor>1){
            return "-1";
        }
        int len = num.length();

        vector<long> requiredFactor(len+1);
        requiredFactor[0] = t;
        int firstZeroIndex = len-1;

        vector<char> digits(num.begin(), num.end());

        for(int i=0;i<len;i++){
            if(digits[i]=='0'){
                firstZeroIndex=i;
                break;
            }

            requiredFactor[i+1] = requiredFactor[i]/ gcd(requiredFactor[i],digits[i]-'0');
        }

        if(requiredFactor[len]==1){
            return num;
        }
        for(int i=firstZeroIndex;i>=0;i--){
            while(++digits[i]<='9'){
                 long currentNeed = requiredFactor[i]/gcd(requiredFactor[i],digits[i]-'0');
                 int candidateDigit =9;
                 for(int j=len-1;j>i;j--){
                    while(currentNeed% candidateDigit!=0){
                        candidateDigit--;

                    }
                    currentNeed/=candidateDigit;
                    digits[j] = char('0'+candidateDigit);
                 }
                 if(currentNeed==1){
                    return string (digits.begin(), digits.end());
                 }
            }
        }
        string answer;
        long remaining =t;
        for(int d=9;d>=2;d--){
            while(remaining%d==0){
                answer.push_back('0'+d);
                remaining/=d;
            }
        }

        int extraone = max(len + 1 - (int)answer.length(), 0);
        while(extraone-->0){
            answer.push_back('1');
        }

        reverse(answer.begin(), answer.end());
        return answer;

    }
};