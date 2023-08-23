/*
 * @Author: Tairan Gao
 * @Date:   2023-06-07 11:18:50
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-09 13:26:18
 */
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        map<int, string> roman_map({
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"},
        });
        string res;
        for (auto it = roman_map.rbegin(); it != roman_map.rend(); it++)
        {
            while (num >= it->first)
            {
                int repeat = num / it->first;
                num = num % it->first;
                for (int i = 0; i < repeat; i++)
                {
                    res += it->second;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(3) << endl;
    cout << s.intToRoman(4) << endl;
    cout << s.intToRoman(9) << endl;
    cout << s.intToRoman(58) << endl;
    cout << s.intToRoman(1994) << endl;
    cout << s.intToRoman(3999) << endl;

    return 0;
}
