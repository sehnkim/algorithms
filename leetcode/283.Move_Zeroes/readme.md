* Tags: **Array, two pointers**
1. 새로운 배열을 하나 만들고, 0이 아닌 값을 체크해서 그 값으로 그 배열을 앞에서부터 채우고, 다시 나머지는 0으로 채운다. space O(n), time O(n)

2. 새로운 배열을 만들지 말고, 0이 아닌 값을 체크해서 그 값으로 현재 배열의 앞에서부터 채우고, 나머지는 0으로 채운다. 나머지는 모두 0으로 채워질 것이므로, 0이 아닌 값들만 순서대로 앞으로 옮기는 것이므로 문제될 것은 없다. space O(1), time O(n)

3. [0,0,0,0,0,1]과 같은 경우가 생기므로 0이 아닌 값들을 찾아 swap하는 방법. space O(1), time O(n)


(initial)
``` 
void moveZeroes(vector<int>& nums) {
	// corner cases.
	// if the size is zero, return
	int size = nums.size();
	if (size == 0)
		return;
		
	int i = 0, j;
	// if size > 0, find the ith index where nums[i] is 0.
	while (i < size && nums[i] != 0)
		++i;
	if (i == size)
		return;
	
	// find i and then j = i;
	j = i+1;
	
	// while i<size and j < size
	while (i < size && j < size)
	{
		// find a new jth index where nums[j] is non-zero.
		while(j < size && nums[j] == 0)
			++j;
		if (j == size)
			break;
		
		// swap two numbers. 
		swap(nums[i], nums[j]);
		// move i by 1
		++i;
		++j;
	}
	
	return;
}
```

(final)
```
void moveZeroes(vector<int>& nums) {
	int i=0, j=0;
	for (j=0; j<nums.size(); ++j)
		if (nums[j] != 0)
			swap(nums[i++], nums[j]);
}
```