class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        
        if(x / 10 < 0)
        {
            return true;
        }

        int digits = 0;
        int tmp = x;
        while(tmp > 0)
        {
            tmp /= 10;
            digits++;
        }

        int firstDigit;
        int lastDigit;
        tmp = floor(digits / 2);

        for(int i = 0; i < tmp; i++)
        {
            firstDigit = x / (int)pow(10, digits - i - 1) % 10;
            lastDigit = x / (int)pow(10, i) % 10;
            
            if(firstDigit != lastDigit)
            {
                return false;
            }
        }
        return true;
    }
};
