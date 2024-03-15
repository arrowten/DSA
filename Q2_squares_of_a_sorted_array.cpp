//977. Squares of a sorted array
//Given an integer array nums, sorted in increasing order, return an array of the squares of each number in increasing order.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sorted_squares(std::vector<int>& nums) {
	int l = 0, r = nums.size() - 1;
	std::vector<int> result(nums.size());

	for(int i = r; i >= 0; i--) {
		int left = nums[l] * nums[l];
		int right = nums[r] * nums[r];

		if(left > right) {
			result[i] = left;
			l++;
		}
		else {
			result[i] = right;
			r--;
		}
	}

	return result;
}

int main() {
	std::vector<int> v = {-4, -1, 0, 3, 10};
	
	std::vector<int> squared_v = sorted_squares(v);

	for(int i: squared_v) std::cout << i << '\t';
	std::cout << '\n';
}
