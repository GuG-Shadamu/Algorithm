/*
 * @Author: Tairan Gao
 * @Date:   2023-06-09 12:44:04
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-09 13:26:18
 */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        int midRow, midCol;

        if (matrix[0][0] > target || matrix[bottom][right] < target)
        {
            return false;
        }

        while (top <= bottom)
        {
            midRow = top + bottom >> 1;
            if (matrix[midRow][0] <= target && matrix[midRow][right] >= target)
            {
                midRow = midRow;
                break;
            }
            if (matrix[midRow][0] < target)
            {
                top = midRow + 1;
                continue;
            }
            if (matrix[midRow][0] > target)
            {
                bottom = midRow - 1;
            }
        }
        auto node = matrix[midRow];
        while (left <= right)
        {
            midCol = left + right >> 1;
            if (node[midCol] == target)
                return true;

            if (node[midCol] > target)
            {
                right = midCol - 1;
                continue;
            }
            if (node[midCol] < target)
            {
                left = midCol + 1;
                continue;
            }
        }
        return false;
    }
};

class Solution2
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0;
        int right = matrix[0].size() * matrix.size() - 1;
        while (left <= right)
        {
            int mid = left + right >> 1;
            int row = mid / matrix[0].size();
            int col = mid % matrix[0].size();
            int val = matrix[row][col];
            if (val == target)
                return true;

            if (val < target)
            {
                left = mid + 1;
                continue;
            }
            if (val > target)
            {
                right = mid - 1;
                continue;
            }
        }

        return false;
    }
};

int main()
{
    Solution2 s;
    vector<vector<int>> matrix = {{1}};
    int target = 1;
    cout << s.searchMatrix(matrix, target) << endl;
    return 0;
}