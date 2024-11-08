class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
        {
            return 0;
        }

        int digits = 0;
        bool neg = false;
        if(x < 0)
        {
            neg = true;
            x *= -1;
        }

        int tmp = x;
        while(tmp > 0)
        {
            tmp /= 10;
            digits++;
        }

        if(digits == 1)
        {
            if(neg)
            {
                x *= -1;
            }
            return x;
        }
        else if(digits == 10 && x % 10 > 2)
        {
            return 0;
        }
        
        int reversedX = 0;
        tmp = x % 10;
        reversedX += tmp * pow(10, digits - 1);

        if(digits < 10)
        {
            for(int i = 1; i < digits; i++)
            {
                tmp = x / (int)pow(10, i) % 10;
                reversedX += tmp * pow(10, digits - 1 - i);
            }
        }
        else
        {
            if(tmp > (INT_MAX / (int)pow(10, digits - 1) % 10))
            {
                return 0;
            }

            bool maxClear = false;
        
            for(int i = 1; i < digits; i++)
            {
                tmp = x / (int)pow(10, i) % 10;
                if(tmp < (INT_MAX / (int)pow(10, digits - 1 - i) % 10) && !maxClear)
                {
                    maxClear = true;
                }

                if(tmp > (INT_MAX / (int)pow(10, digits - 1 - i) % 10) && !maxClear)
                {
                    return 0;
                }
                reversedX += tmp * pow(10, digits - 1 - i);
            }
        }

        if(neg)
        {
            reversedX *= -1;
        }

        return reversedX;
    }
};
