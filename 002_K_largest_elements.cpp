/*
Given an integer array nums[] of N integers and an integer K. Your task is to return K largest elements in decreasing order.

Examples:

#Input 1: nums[] = [1, 23, 12, 9, 30, 2, 50], K = 3
#Output 1: 50 30 23

#Input 2: nums[] = [12, 5, 787, 1, 23], K = 2
#Output 2: 787 23

#Input 3: nums[] = [11, 5, 12, 9, 44, 17, 2], K = 2
#Output 3: 44 17
*/

#include <iostream>
#include <vector>
#include <queue>
#include <gtest/gtest.h>

auto k_largest_elements(const std::vector<int>& nums, int K) -> std::vector<int> {
    if(K == 0) return {};

    int size = nums.size();
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    std::vector<int> res;

    //Push the first K elements from the vector into the min heap
    for(int i = 0; i < K; i++) {
        min_heap.push(nums[i]);
    }

    //Pop the top element if it is smaller than the current element and push the current element into the min heap
    for(int i = K; i < size; i++) {
        if(nums[i] > min_heap.top()) {
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }

    //Push the elements back into a vector
    while(!min_heap.empty()) {
        res.push_back(min_heap.top());
        min_heap.pop();
    }

    //Sort it in decreasing order for the greatest element to be at the start
    std::sort(res.begin(), res.end(), std::greater<>{});

    return res;
}

TEST(K_largest_elements, handles_various_cases) {
    std::vector<int> nums = {1, 23, 12, 9, 30, 2, 50}, nums2 {12, 5, 787, 1, 23}, nums3 = {11, 5, 12, 9, 44, 17, 2};
    std::vector<int> res = k_largest_elements(nums, 3), res2 = k_largest_elements(nums2, 2), res3 = k_largest_elements(nums3, 2);

    EXPECT_EQ(res, (std::vector<int>{50, 30, 23}));
    EXPECT_EQ(res2, (std::vector<int>{787, 23}));
    EXPECT_EQ(res3, (std::vector<int>{44, 17}));
}