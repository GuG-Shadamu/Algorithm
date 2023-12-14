/*
 * @Author: Tairan Gao
 * @Date:   2023-12-14 11:59:18
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-12-14 13:27:06
 */
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <bitset>
#include <bit>
#include <stack>
#include <charconv>

class Solution {
public:

    uint32_t get_int(std::string ip) {
        int idx = ip.find('.');
        int prev = 0, cur;
        uint32_t res = 0;
        while (idx != std::string::npos) {
            cur = stoi(ip.substr(prev, idx - prev));
            res = res * 256 + cur;
            prev = idx + 1;
            idx = ip.find('.', idx + 1);
        }
        cur = stoi(ip.substr(prev, ip.length() - prev));
        res = res * 256 + cur;
        return res;
    }


    std::string getString(unsigned int mask, int prefix) {
        std::stack<std::string> stk;
        int i = 0;
        while (i < 4) {
            int d = mask % 256;
            stk.push(std::to_string(d));
            mask = mask / 256;
            i++;
        }
        std::string res = "";
        while (!stk.empty()) {
            res += stk.top();
            if (stk.size() > 1) res += ".";
            stk.pop();
        }
        res += "/" + std::to_string(prefix);
        return res;
    }


    std::vector<std::string> ipToCIDR(std::string ip, int n) {
        uint32_t mask = get_int(ip);
        std::vector<std::string> res;

        while (n > 0) {
            int maxBits = std::countr_zero(mask);
            int bitVal = 1;
            int count = 0;
            while (bitVal < n && count < maxBits) {
                bitVal <<= 1;
                count += 1;
            }
            if (bitVal > n) {
                bitVal >>= 1;
                count--;
            }

            std::string str = getString(mask, 32 - count);
            res.push_back(str);

            n -= bitVal;
            mask += bitVal;

        }

        return res;
    }
};

int main() {

    auto s = Solution();
    auto res = s.ipToCIDR("100.254.254.254", 100);
    for (const auto& ele : res) {
        std::cout << ele << "\n";
    }


    return 0;
}