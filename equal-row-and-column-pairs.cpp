/*
 * @Author: Tairan Gao
 * @Date:   2023-06-12 21:37:08
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-12 21:39:10
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
    int equalPairs(vector<vector<int>> &grid)
    {
        unordered_map<string, int> col;
        unordered_map<string, int> row;

        string temp;
        for (int i = 0; i < grid.size(); i++)
        {
            temp = "";
            for (int j = 0; j < grid[0].size(); j++)
            {
                temp += to_string(grid[i][j]);
                temp += "+";
            }
            if (row.count(temp) == 0)
            {
                row[temp] = 1;
            }
            else
            {
                row[temp] += 1;
            }
        }

        for (int i = 0; i < grid[0].size(); i++)
        {
            temp = "";
            for (int j = 0; j < grid.size(); j++)
            {
                temp += to_string(grid[j][i]);
                temp += "+";
            }
            if (col.count(temp) == 0)
            {
                col[temp] = 1;
            }
            else
            {
                col[temp] += 1;
            }
        }
        int res = 0;
        for (auto const &[key, val] : row)
        {
            if (col.count(key) != 0)
            {
                res += val * col[key];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{250, 78, 253}, {334, 252, 253}, {250, 253, 253}};
    cout << s.equalPairs(grid) << endl;
    return 0;
}