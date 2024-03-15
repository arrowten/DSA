//152. Maximum subarray product
//Given an integer array nums, find the subarray with the largest product.

#include <iostream>
#include <vector>

int max_subarray_product(std::vector<int>& nums) {
	int max_product = nums[0];
	int min_product = nums[0];
	int result = max_product;
	int size = nums.size();

	for(int i = 1; i < size; i++) {
		if(nums[i] < 0) std::swap(max_product, min_product);

		max_product = std::max(nums[i], max_product * nums[i]);
		min_product = std::min(nums[i], min_product * nums[i]);
		result = std::max(result, max_product);
	}

	return result;
}

int main() {
	std::vector<int> v = {2, 3, -2, 4};
	int result = max_subarray_product(v);

	std::cout << result << '\n';
}
