class Solution {
public:
    string intToRoman(int num) {
        int remain = num;
        string res = "";
        //1000
        int k_n = remain / 1000;
        string k_s(k_n, 'M');
        res += k_s;
        remain %= 1000;
        //900
        if(remain >= 900)
        {
            res += "CM";
            remain -= 900;
        }
        //500
        if(remain >= 500)
        {
            res += "D";
            remain -= 500;
        }
        //400
        if(remain >= 400)
        {
            res += "CD";
            remain -= 400;
        }
        //100
        int h_n = remain/100;
        string h_s(h_n,'C');
        res += h_s;
        remain %= 100;
        //90
        if(remain >= 90)
        {
            res += "XC";
            remain-=90;
        }
        //50
        if(remain >= 50)
        {
            res += "L";
            remain -= 50;
        }
        //40
        if(remain >= 40)
        {
            res += "XL";
            remain -= 40;
        }
        //10
        int t_n = remain/10;
        string t_s(t_n,'X');
        res += t_s;
        remain %= 10;
        //9
        if(remain == 9)
            return res + "IX";
        //5
        if(remain >= 5)
        {
            res += "V";
            remain -= 5;
        }
        //4
        if(remain == 4)
            return res + "IV";
        //1
        string o_s(remain,'I');
        return res+o_s;
    }
};