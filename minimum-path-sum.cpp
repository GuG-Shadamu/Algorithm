/*
 * @Author: Tairan Gao
 * @Date:   2023-06-12 22:12:50
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-12 22:14:40
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
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> path(grid.size(), vector<int>(grid[0].size(), numeric_limits<int>::max()));
        for (int i = grid.size() - 1; i >= 0; i--)
        {
            for (int j = grid[0].size() - 1; j >= 0; j--)
            {
                if (i == grid.size() - 1 && j == grid[0].size() - 1)
                {
                    path[i][j] = grid[i][j];
                    continue;
                }
                if (i + 1 < grid.size())
                {
                    path[i][j] = min(path[i][j], path[i + 1][j] + grid[i][j]);
                }
                if (j + 1 < grid[0].size())
                {
                    path[i][j] = min(path[i][j], path[i][j + 1] + grid[i][j]);
                }
            }
        }
        return path[0][0];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    cout << s.minPathSum(grid) << endl;
    return 0;
}