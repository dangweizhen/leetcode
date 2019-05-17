class Solution {
public:
    string multiply(string num1, string num2) {
        const int l1 = num1.length();
        const int l2 = num2.length();
        int res[l1+l2] = {0};
        for(int i = l1-1;i >= 0;i --)
        {
            int carry = 0;
            for(int j = l2-1;j >= 0;j --)
            {
                int mul = (num1[i]-'0')*(num2[j]-'0')+carry;
                res[(l1-1-i)+(l2-1-j)] += (mul%10);
                carry = mul/10;
            }
            res[(l1-1-i)+l2]+=carry;
        }
        int l = 0;
        int ca = 0;
        for(int i = 0;i < l1+l2;i ++)
        {
            
            res[i] +=  ca;
            ca = res[i]/10;
            res[i]%=10;
            if(res[i] != 0) l = i;
            //cout << res[i] << " ";
        }
        string r(l+1,'0');
        for(int i = l;i >= 0; i--)
        {
            r[l-i] += res[i];
        }
        return r;
    }
};