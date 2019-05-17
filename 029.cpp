class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) return (dividend==-2147483648?2147483647:-dividend);
        int res = 0;
        int remain = dividend;
        if(dividend > 0)
        {
        	while((divisor > 0 && divisor <= remain) || (divisor < 0 && divisor + remain >= 0))
        	{
        		int sum = divisor;
        		int q = (divisor > 0 ? 1 : -1);
        		while((divisor > 0 && remain-sum >= sum) || (divisor < 0 && remain + sum >= -sum))
        		{
                    if(sum >= 1073741824) break;
        			sum += sum;
        			q += q;
        		}
        		if(sum > 0)
        			remain = remain - sum;
        		else
        			remain = remain + sum;
        		res += q;
        	}
        }
        else
        {
        	while((divisor > 0 && divisor + remain <= 0) || (divisor < 0 && divisor >= remain))
        	{
                //cout << remain << " ";
        		int sum = divisor;
        		int q = (divisor > 0 ? -1 : 1);
        		while((divisor > 0 && remain+sum <= -sum) || (divisor < 0 && remain - sum <= sum))
        		{
                    if(sum >= 1073741824) break;
        			sum += sum;
        			if(q >= 1073741824)
        				q = 2147483647;
        			else
        				q += q;
        		}
        		if(sum > 0)
        			remain = remain + sum;
        		else
        			remain = remain - sum;
        		res += q;
        	}
        }
        return res;
    }
};