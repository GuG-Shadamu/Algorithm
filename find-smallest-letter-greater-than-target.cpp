/*
 * @Author: Tairan Gao
 * @Date:   2023-06-09 11:50:15
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
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0;
        int right = letters.size() - 1;

        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target && letters[mid - 1] <= target)
                return letters[mid];

            if (letters[mid] <= target)
            {
                left = mid;
                continue;
            }
            if (letters[mid] > target)
            {
                right = mid;
                continue;
            }
        }
        if (letters[left] > target)
            return letters[left];

        if (letters[right] > target)
            return letters[right];

        return letters[0];
    }
};

int main()
{
    Solution s;
    vector<char> letters = {'c', 'f', 'j', 'j'};
    char target = 'g';
    cout << s.nextGreatestLetter(letters, target) << endl;
    return 0;
}