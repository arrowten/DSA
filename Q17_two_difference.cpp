//Given an array of integer nums and an integer target, return indices of the 2 numbers such that they have the difference of the target. You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> two_difference(std::vector<int>& nums, int target) {
    std::vector<std::pair<int, int>> sorted_nums;
    int size = nums.size();
    int left = 0, right = size - 1;

    for(int i = 0; i < size; i++) {
        sorted_nums.push_back({nums[i], i});
    }

    std::sort(sorted_nums.begin(), sorted_nums.end());

    while(left < right) {
		int difference = sorted_nums[right].first - sorted_nums[left].first;

		if(difference == target) {
			return {sorted_nums[left].second, sorted_nums[right].second};
		}
		else if(difference > target) left++;
		else right--;
	}

	return {};
}

int main() {
    std::vector<int> nums = {5, 20, 3, 2, 50, 80};
    int target = 78;
    std::vector<int> indices = two_difference(nums, target);

    for(int i: indices) std::cout << i << '\t';
    std::cout << '\n';
}