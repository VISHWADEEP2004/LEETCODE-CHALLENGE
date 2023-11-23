Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explanation:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explanation:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and returns an integer denoting the minimum number of swaps required to sort the array.
If the array is already sorted, return 0. 


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 105
1 ≤ numsi ≤ 106

  OUTPUT:

	int minSwaps(vector<int>&nums)
	{
	    vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());

    int n = nums.size();
    int swaps = 0;

    unordered_map<int, int> indexMap;
    for (int i = 0; i < n; ++i) {
        indexMap[nums[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] != sortedNums[i]) {
            ++swaps;

            int idx = indexMap[sortedNums[i]];
            swap(nums[i], nums[idx]);

            indexMap[nums[i]] = i;
            indexMap[nums[idx]] = idx;
        }
    }

    return swaps;
	}
