//53. Maximum subarray sum
//Given an integer array nums, find the subarray with the largest sum, and return its sum.

#include <iostream>
#include <vector>

int max_subarray_sum(std::vector<int>& nums) {
    int max_ending_here = nums[0];
    int max_so_far = nums[0];
    int size = nums.size();

    for(int i = 1; i < size; i++) { 
        max_ending_here = std::max(nums[i], max_ending_here + nums[i]);
        max_so_far = std::max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = max_subarray_sum(v);

    std::cout << result << '\n';
}
