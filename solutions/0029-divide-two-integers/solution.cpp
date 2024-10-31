class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
        {
            return 0;
        }

        if(divisor == 1)
        {
            return dividend;
        }
        else if(divisor == -1)
        {
            if(dividend < 0)
            {
                if(dividend == -2147483648)
                {
                    return 2147483647;
                }
            }
            return dividend - dividend - dividend;
        }

        int quotient = 0;
        uint udivisor = divisor;

        if(dividend > 0 && divisor > 0)
        {
            if(dividend < divisor)
            {
                return 0;
            }

            while(dividend >= divisor)
            {
                dividend -= divisor;
                quotient++;

                if(quotient == 2147483647)
                {
                    return quotient;
                }
            }
            return quotient;
        }
        else if(dividend > 0 && divisor < 0)
        {
            if(divisor == -2147483648 && dividend > divisor - (divisor - divisor - 1))
            {
                return 0;
            }
            else if(dividend < divisor - divisor - divisor)
            {
                return 0;
            }

            while(dividend >= divisor - divisor - divisor)
            {
                dividend += divisor;
                quotient++;

                if(quotient == 2147483647)
                {
                    return quotient - quotient - quotient - 1;
                }
            }
            return quotient - quotient - quotient;
        }
        else if(dividend < 0 && divisor > 0)
        {
            if(dividend > divisor - divisor - divisor)
            {
                return 0;
            }

            while(dividend <= divisor - divisor - divisor)
            {
                dividend += divisor;
                quotient++;

                if(quotient == 2147483647)
                {
                    return quotient - quotient - quotient - 1;
                }
            }
            return quotient - quotient - quotient;
        }
        else if(dividend < 0 && divisor < 0)
        {
            if(dividend > divisor)
            {
                return 0;
            }

            while(dividend <= divisor)
            {
                dividend -= divisor;
                quotient++;

                if(quotient == 2147483647)
                {
                    return quotient;
                }
            }
            return quotient;
        }
        return 0;
    }
};
