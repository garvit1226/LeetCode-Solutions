class Solution {
public:

    string makePalindrome(string &left, char mid) {
        string right = left;
        reverse(right.begin(), right.end());

        return left + (mid ? string(1, mid) : "") + right;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

       
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

       
        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = freq[i] / 2;

        int m = n / 2;

        string left;

        for (int pos = 0; pos < m; pos++) {

            bool found = false;

            
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;
                left.push_back('a' + c);

              
                string temp = left;

                for (int x = 25; x >= 0; x--)
                    temp += string(half[x], 'a' + x);

                string candidate = makePalindrome(temp, mid);

                if (candidate > target) {
                    found = true;
                    break;
                }

                
                left.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }

        string answer = makePalindrome(left, mid);

        if (answer > target)
            return answer;

        return "";
    }
};