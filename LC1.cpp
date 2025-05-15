#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int value = target - nums[i];
            if (map.find(value) != map.end()) {
                return {map[value], i};
            }
            map[nums[i]] = i;
        }
        return {}; // fallback if no pair found (optional)
    }
};
