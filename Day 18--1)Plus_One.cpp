class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1,i=digits.size()-1;
        while(i>=0 and carry)
        {
            digits[i]++;
            carry=digits[i]/10;
            digits[i]%=10;
            i--;
        }
        if(carry)
        {
            reverse(digits.begin(),digits.end());
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};

//Link--https://leetcode.com/problems/plus-one/submissions/