class Solution {
public:
    int numberOfSteps(int num) {
        int a=0,b=0;
        while(num)
        {
            a += num % 2;
            b++;
            num /= 2;
        }
        return (a + b > 0?a + b - 1:0);
    }
};