//11. Container with most water
//You are given an integer array height of length n. There are n vertical lines drawn such that the 2 endpoints of the ith line are (i, 0) and (i, height[i]). Find 2 lines that together with the x axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store.

#include <iostream>
#include <vector>

int max_area(std::vector<int>& height) {
	int area = 0, left = 0, right = height.size() - 1;

	while(left < right) {
		int current_area = std::min(height[left], height[right]) * (right - left);
		area = std::max(area, current_area);

		if(height[left] < height[right]) left++;
		else right--;
	}

	return area;
}

int main() {
	std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	
	std::cout << max_area(height) << '\n';
}
