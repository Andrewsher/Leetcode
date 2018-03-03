class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long long tmpDividend = labs(dividend), tmpDivisor = labs(divisor);
        int result = 0;
        while(tmpDividend >= tmpDivisor) {
            long long tmp = tmpDivisor, multiple = 1;// tmp为divisor增大的倍数，也就是dividend已经减小的数。multiple为divisor的倍数，也就是商，至少为1倍。
            // dividend分别尝试减去divisor的1倍，2倍，4倍，8倍，……，直到无法再减少下去，这个倍数就是暂定的商，把这个商加到结果中。
            // 每循环一次，tmpDivisor增大一倍
            while(tmpDividend >= (tmp << 1)) {
                // tmp表示tmpDivisor增大到的数
                tmp = tmp << 1;
                // multiple表示增大的倍数
                multiple = multiple << 1;
            }
            // tmpDividend减去tmpDivisor
            tmpDividend -= tmp;
            // result加上已经减去的duvisor倍数
            result += multiple; 
        }
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        return 1 == sign ? result : -result;
    }
    
};