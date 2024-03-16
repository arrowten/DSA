//229. Majority element 2
//Given an integer array of size n, find all elements that appear more than n / 3 times.

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> majority_element(std::vector<int>& nums) {
	if(nums.empty()) return nums;
    
    std::vector<int> result;
    std::unordered_map<int, int> counts;
    int threshold = nums.size() / 3;

    for (int num : nums) {
        if (++counts[num] > threshold) {
            result.push_back(num);
            counts[num] = -threshold - 1;
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    std::vector<int> result = majority_element(nums);
    
    for (int i : result) std::cout << i << '\t';
    std::cout << '\n';

    return 0;
}