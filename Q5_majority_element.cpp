//169. Majority element
//Given an array nums of size n, return the majority element.

#include <iostream>
#include <vector>

int majority_element(std::vector<int>& nums) {
	int previous = nums[0];
	int count = 1;
	int size = nums.size();

	for(int i = 1; i < size; i++) {
		if(nums[i] == previous) count++;
		else count--;

		if(count == 0) {
			previous = nums[i];
			count = 1;
		}
	}

	return previous;
}

int main() {
	std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2, 1};
	int result = majority_element(nums);
	
	std::cout << result << '\n';
}
