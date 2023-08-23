/*
 * @Author: Tairan Gao
 * @Date:   2023-06-12 23:46:54
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-13 00:51:19
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;
class Solution
{
public:
    int min_three(int a, int b, int c)
    {
        return min(a, min(b, c));
    }
    int helper(const vector<vector<char>> &matrix, int i, int j, vector<vector<int>> &dp)
    {
        int val = (matrix[i][j] == '1' ? 1 : 0);
        if (i == 0 || j == 0 || val == 0)
        {
            dp[i][j] = val;
            return val;
        }
        dp[i][j] = min_three(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        return dp[i][j] * dp[i][j];
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int sol = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                sol = max(sol, helper(matrix, i, j, dp));
            }
        }
        return sol;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix = {{'1', '1'}};
    cout << s.maximalSquare(matrix) << endl;
    return 0;
}