/*
題目:
You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.
You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

解析:
目的是找出一組缺失的骰子點數，使得所有骰子（已知的和缺失的）的平均值等於給定的目標平均值。
具體來說，我們有一組已知的骰子點數（每個骰子點數在 1 到 6 之間），並且給定了一個目標平均值和需要補充的骰子數。
我們需要根據已知的骰子數據，推算出缺失骰子的點數，確保整體的平均值符合要求。
*/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total_sum = mean * (n + m); // 总的骰子和
        int current_sum = accumulate(rolls.begin(), rolls.end(), 0); // 已知骰子的和
        int missing_sum = total_sum - current_sum; // 缺失的骰子和
        
        // 如果缺失的骰子和不在合理范围内，返回空数组
        if (missing_sum < n || missing_sum > 6 * n) {
            return {};
        }
        
        // 分配缺失的骰子
        vector<int> result(n, 1); // 先分配每个骰子最小值1
        missing_sum -= n; // 剩余的和还需要分配
        
        // 尽量分配剩余的和
        for (int i = 0; i < n && missing_sum > 0; ++i) {
            int add = min(5, missing_sum); // 每个骰子最多可以再加5
            result[i] += add;
            missing_sum -= add;
        }
        
        return result;
    }
};
