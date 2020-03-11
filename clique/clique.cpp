#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <utility>
#include <string>
using namespace std;


vector<int> quickSort(vector<int>& nums) {

	if (nums.size() == 0) return nums;
	if (nums.size() == 1) return nums;
	int pivot = nums[0];

	int left = 0;

	for (int right = 0; right < nums.size() - 1; right++) {
		if (nums[right + 1] < pivot) {
			int tmp = nums[left + 1];
			nums[left + 1] = nums[right + 1];
			nums[right + 1] = tmp;
			left++;
		}
	}

	int tmp = nums[0];
	nums[0] = nums[left];
	nums[left] = tmp;
	vector<int> left_part(nums.begin(), nums.begin() + left);
	vector<int> left_ans = quickSort(left_part);
	vector<int> right_part(nums.begin() + left + 1, nums.end());
	vector<int> right_ans = quickSort(right_part);

	left_ans.insert(left_ans.end(), nums[left]);
	left_ans.insert(left_ans.end(), right_ans.begin(), right_ans.end());

	return left_ans;

}


vector<vector<int>> generate(int numRows) {

	vector<vector<int>> res(numRows);

	for (int i = 1; i <= numRows; ++i) {
		res[i - 1].resize(i);
		res[i - 1][0] = 1;
		res[i - 1][i - 1] = 1;
	}

	for (int i = 2; i < numRows; ++i) {
		for (int j = 1; j < i; ++j) {
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}

	return res;
}


vector<int> turnLeft(vector<int>& direction) {
	vector<int> newDirection(2, 0);
	if (direction[0] == 1 && direction[1] == 0) {
		newDirection[0] = 0;
		newDirection[1] = -1;
	}
	else if (direction[0] == 0 && direction[1] == -1) {
		newDirection[0] = -1;
		newDirection[1] = 0;
	}
	else if (direction[0] == -1 && direction[1] == 0) {
		newDirection[0] = 0;
		newDirection[1] = 1;
	}
	else {
		newDirection[0] = 1;
		newDirection[1] = 0;
	}
	return newDirection;
}


vector<int> turnRight(vector<int>& direction) {
	vector<int> newDirection(2, 0);
	if (direction[0] == 1 && direction[1] == 0) {
		newDirection[0] = 0;
		newDirection[1] = 1;
	}
	else if (direction[0] == 0 && direction[1] == -1) {
		newDirection[0] = 1;
		newDirection[1] = 0;
	}
	else if (direction[0] == -1 && direction[1] == 0) {
		newDirection[0] = 0;
		newDirection[1] = -1;
	}
	else {
		newDirection[0] = -1;
		newDirection[1] = 0;
	}
	return newDirection;
}


bool circular(string commands) {
	vector<vector<int>> memo;
	vector<int> posCur{ 0, 0 };
	vector<int> dirCur{ 0, 1 };
	memo.push_back(posCur);
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < commands.length(); i++) {
			if (commands[i] == 'G') {
				posCur[0] += dirCur[0];
				posCur[1] += dirCur[1];
				memo.push_back(posCur);
			}
			else if (commands[i] == 'L') {
				dirCur = turnLeft(dirCur);
			}
			else {
				dirCur = turnRight(dirCur);
			}
		}
		if (memo[0] == memo.back()) {
			return true;
		}
	}
	return false;
}


int validate(int r, int n, int m)
{
	int x1 = n % r;
	int x2 = r - x1;
	int x3 = n / r;
	return x2 * (x2 - 1) / 2 * x3 * x3 + x1 * (x1 - 1) / 2 * (x3 + 1) * (x3 + 1) + x2 * x1 * x3 * (x3 + 1);
}


// https://www.hackerrank.com/challenges/clique/editorial
long strongRelation(int n, int m) {
	int left = 1;
	int right = n;
	int r;
	while (left < right)
	{
		r = (left + right) / 2;
		if (validate(r, n, m) >= m) right = r;
		else left = r + 1;
	}
	return (long)left;
}


int main() {

	long ans = strongRelation(4, 6);
	cout << ans << endl;
	return 0;

}