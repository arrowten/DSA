/*
Given an integer array nums[]. Find the contigous sub array (containing at least one number) that has the maximum sum and return its sum.

Examples:

#Input 1: nums[] = [1, 2, 3, -2, 5]
#Output 1: 9

#Input 2: nums[] = [-1, -2, -3, -4]
#Output 2: -1

#Input 3: nums[] = [5, 4, 7]
#Output 3: 16

#Input 4: nums[] = [-2, -3, 4, -1, -2, 1, 5, -3]
#Output 4: 7
*/

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

auto maximum_subarray_sum(const std::vector<int>& nums) -> int {
    int max_so_far = nums[0]; //Stores the overall maximum sum
    int sum = nums[0]; //Stores the maximum sum ending at the current index
    int size = nums.size();

    //Traverse array from the second element
    for(int i = 1; i < size; i++) {
        //Update sum
        sum = std::max(nums[i], sum + nums[i]);

        //Update the overall maximum sum if necessary
        max_so_far = std::max(max_so_far, sum);
    }

    return max_so_far;
}

TEST(Maximum_subarray_sum, handles_various_cases) {    
    EXPECT_EQ(maximum_subarray_sum({1, 2, 3, -2, 5}), 9);
    EXPECT_EQ(maximum_subarray_sum({-1, -2, -3, -4}), -1);
    EXPECT_EQ(maximum_subarray_sum({5, 4, 7}), 16);
    EXPECT_EQ(maximum_subarray_sum({-2, -3, 4, -1, -2, 1, 5, -3}), 7);
}