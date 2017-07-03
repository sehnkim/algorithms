* Tags: Array, DP
* Time Complexity: O(n)
* Space Complexity: O(1)

1. #3. Longest Substring Without Repeating Characters의 경우에는 start index하고 end index를 구하고 그 길이는 계산하는 방식이었다. 여기서 end index는 현재 index이기 때문에 바로 구할 수 있는 것이고, start index의 경우에는 이미 그 문자가 있었던 경우, 그 문자의 인덱스보다 하나 앞의 인덱스를 구하는 것이다. 그리고서는 ans 중에서 가장 큰 것과 비교하는 방식.

if (map.containsKey(s.charAt(j))) {
    i = Math.max(map.get(s.charAt(j)), i); // i: 현재 j까지 반복이 없는 가장 낮은 index, 즉 end index
}
ans = Math.max(ans, j - i + 1);

이 문제에서도 비슷한 방식으로 다룬다. 즉, 현재 값이 음수인 경우, maxProduct와 minProduct를 switch하긴 하지만, 중요한 것은 maxProduct = max(minProduct * A[i], A[i]);과 같이 현재 값에 그 이전값들을 고려한 값과, 그냥 현재값과의 최대값을 구하는 것이다. 즉, 위에서와 같이 현재 값에 대한 어떤 결과가 주어지면 그 결과를 가지고 최대값을 계산하여 local max를 구하는 것이다. 이를 배열의 각 값에 대해 수행한다. 그리고 이러한 local max를 다시 한번 global max와 비교하여 계속해서 global max를 업데이트한다.

if (A[i] < 0)
{
		int temp = maxProduct;
		maxProduct = max(minProduct * A[i], A[i]);
		minProduct = min(temp * A[i], A[i]);
}
maxRes = max(maxRes, maxProduct);


2. 이 문제의 특징은 언제 음수가 나오고, 또 다시 음수가 나올지 혹은 안나올지 혹은 0이 나올지 모른다는 것이다. 그래서, 계속  max(minProduct * A[i], A[i]);와 같은 것을 수행하는 이유도 결국 양수와 0만 고려했을 경우 0보다 큰 값을 찾기 위한 것이다.

3. 이 문제의 핵심은 음수가 나왔을때 flip 한다는 것이다.
4. 그리고 다른 특징은 0이 아닌 이상은 어떻게든 계속 값을 곱해간다는 것이다. 그것이 음수이든 양수이든 상관없이.. 그리고서는 계속 최대값을 찾아 헤멘다.

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
