* Tags: Array, DP
* Time Complexity: O(n)
* Space Complexity: O(1)

1. 003. Longest Substring Without Repeating Characters의 경우에는 start index하고 end index를 구하고 그 길이는 계산하는 방식이라면, 이 문제의 경우에는

1. 새로운 배열을 하나 만들고, 0이 아닌 값을 체크해서 그 값으로 그 배열을 앞에서부터 채우고, 다시 나머지는 0으로 채운다. space O(n), time O(n)


(initial)
```
int maxProduct(vector<int>& nums) {
		// 0
		// 1 -2 2	==> 2
		// -1 -2 -3 ==> 6

		if (nums.size() == 1)
				return nums[0];

		int gmax;
		int lmin = nums[0];
		int lmax = nums[0];
		gmax = lmax;

		for(int i=1; i<nums.size(); ++i)
		{
				if (nums[i] < 0)
						swap(lmin, lmax);

				//
				lmax = max(nums[i], lmax * nums[i]);	// 음수가 없더라도, 0이 있는 경우를 고려.
				lmin = min(nums[i], lmin * nums[i]);

				gmax = max(gmax, lmax);
		}        

		return gmax;
}
```

(final)
```
int maxProduct(int A[], int n)
{
    // store the result that is the max we have found so far
    int r = A[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}
https://discuss.leetcode.com/topic/4417/possibly-simplest-solution-with-o-n-time-complexity


int maxProduct(int A[], int n)
{
    if (n == 0) return 0;
    int maxProduct = A[0];
    int minProduct = A[0];
    int maxRes = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] >= 0)
        {
            maxProduct = max(maxProduct * A[i], A[i]);
            minProduct = min(minProduct * A[i], A[i]);
        }
        else
        {
            int temp = maxProduct;
            maxProduct = max(minProduct * A[i], A[i]);
            minProduct = min(temp * A[i], A[i]);
        }
        maxRes = max(maxRes, maxProduct);
    }
    return maxRes;
}

https://discuss.leetcode.com/topic/3607/sharing-my-solution-o-1-space-o-n-running-time/34
```
