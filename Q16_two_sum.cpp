//1. Two sum
//Given an array of integer nums and an integer target, return indices of the 2 numbers such that they add up to the target. You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> two_sum(std::vector<int>& nums, int target) {
	std::vector<std::pair<int, int>> sorted_nums;
	int size = nums.size();
	int left = 0, right = size - 1;

	for(int i = 0; i < size; i++) {
		sorted_nums.push_back({nums[i], i});
	}

	std::sort(sorted_nums.begin(), sorted_nums.end());

	while(left < right) {
		int sum = sorted_nums[left].first + sorted_nums[right].first;

		if(sum == target) {
			return {sorted_nums[left].second, sorted_nums[right].second};
		}
		else if(sum < target) left++;
		else right--;
	}

	return {};
}

int main() {
	std::vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	std::vector<int> indices = two_sum(nums, target);

	std::vector<int> nums2 = {3, 2, 4};
	int target2 = 6;
	std::vector<int> indices2 = two_sum(nums2, target2);

	for(int i: indices) std::cout << i << '\t';
	std::cout << '\n';

	for(int i: indices2) std::cout << i << '\t';
	std::cout << '\n';

	return 0;
}
