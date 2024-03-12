//189. Rotate array
//Given an integer array nums, rotate the array to the right by k steps, where k is non negative.

#include <iostream>
#include <vector>

void reverse(std::vector<int>& nums, int l, int r) {
	while(l < r) {
		nums[l] = nums[l] ^ nums[r];
		nums[r] = nums[l] ^ nums[r];
		nums[l] = nums[l] ^ nums[r];
	
		l++; r--;
	}
}

void rotate(std::vector<int>& nums, int k) {
	if(k > nums.size()) k %= nums.size();

	int n = nums.size();

	//Reverse the whole array
	reverse(nums, 0, n - 1);
	
	//Reverse the first k elements
	reverse(nums, 0, k - 1);

	//Reverse the later n - k elements
	reverse(nums, k, n - 1);
}

int main() {
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7}, v2 = {-1, -100, 3, 99};
	int k = 3, k2 = 2;;
	
	rotate(v, k);

	rotate(v2, k2);

	for(int i: v) std::cout << i << '\t';
	std::cout << "\n\n";

	for(int i: v2) std::cout << i << '\t';
	std::cout << '\n';
}
