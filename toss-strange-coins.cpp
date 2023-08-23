/*
 * @Author: Tairan Gao
 * @Date:   2023-06-12 11:28:33
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-12 12:15:13
 */
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    double helper(const vector<double> &prob, int target, vector<vector<double>> &dp, int index)
    {

        if (target < 0)
            return 0;

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        if (index == prob.size() - 1)
        {
            if (target == 1)
                dp[index][target] = prob[index];
            else if (target == 0)
                dp[index][target] = 1.0 - prob[index];
            else
                dp[index][target] = 0;

            return dp[index][target];
        }

        dp[index][target] = (1.0 - prob[index]) * helper(prob, target, dp, index + 1) +
                            (prob[index]) * helper(prob, target - 1, dp, index + 1);
        return dp[index][target];
    }

    double probabilityOfHeads(vector<double> &prob, int target)
    {
        vector<vector<double>> dp(prob.size(), vector<double>(target + 1, -1.0));
        return helper(prob, target, dp, 0);
    }
};

int main()
{
    Solution s;
    vector<double> prob = {0.2, 0.8, 0, 0.3, 0.5};
    int target = 3;
    cout << s.probabilityOfHeads(prob, target) << endl;
    return 0;
}