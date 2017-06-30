https://leetcode.com/problems/maximum-subarray/#/description

* Tags: Array, DP, D&Q
1. 문제의 유형을 잘 살펴보면 DP로 풀 수 있다는 것을 알아차려야 한다.
* 의문점: 어떻게 O(n)을 유지하면서 시작점과 끝점을 찾아내는가가 큰 고민이었다. 결국은 DP를 이용해서 시작점이 되는 부분을 계속 끌고 오고, localMax + 현재값을 현재값과 비교하면서 localMax를 계속 업데이트 하는 방식으로 문제 접근. 그리고, 그 localMax는 finalMax에 계속 저장했다.
* Suppose we've solved the problem for A[1 .. i - 1]; how can we extend that to A[1 .. i]?
* 문제점: 문제를 접했을때 0이상의 값에 대해서만 최대값을 얻는다고 스스로 가정해 버렸다. 결국은 문제를 잘못 해석해서 풀었다.


(initial)

```
int maxSubArray(vector<int>& nums) {
	// find the first + value

	int j = -1;
	for (int i=0; i<nums.size(); ++i)
	{
		if (nums[i] > 0)
		{
			j = i;
			break;
		}
	}
	if (j == )
		return

	int start, end;
	int sum = 0;
	int prevSum = 0;
	int reset = true;

	// for each elem
	for (int i=j; i<nums.size(); ++i)
	{
		sum += nums[i];
		// if sum > presum,
		if (sum > prevSum)
		{
			prevSum = sum;
			if (reset)
				// set j to "start and end"
				start = i;
			end = i;
			reset = false;
		}
		// else if sum < 0
		else if (sum < 0)
		{
			sum = 0;
			reset = true;
		}

		cout << sum << " " << prevSum << endl;
		cout << "test" << endl;
	}

	vector<int> nums2(nums.begin()+start, nums.begin()+end);
	nums = nums2;

	return prevSum;
}
```

(final)
```
int maxSubArray(vector<int>& nums)
{
    if (nums.size() == 0) return 0;
    else if (nums.size() == 1) return nums.at(0);

    int int_local_max = nums.at(0), int_global_max = nums.at(0);
    size_t sz_length  = nums.size();
    for (size_t i = 1; i != sz_length; ++i) {
        int_local_max  = max(int_local_max + nums.at(i), nums.at(i));
        int_global_max = max(int_local_max, int_global_max);
    }

    return int_global_max;
}

https://discuss.leetcode.com/topic/3400/simplest-and-fastest-o-n-c-solution/23
```
