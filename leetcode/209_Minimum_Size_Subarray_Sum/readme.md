## Complexity
* Difficulty: Medium
* Tags: two pointers, binary search, array
* Time Complexity: O(n)
* Space Complexity: O(1)
* New functions:

## Note
1. Until now, we have kept the starting index of subarray fixed, and found the last position. Instead, we could move the starting index of the current subarray as soon as we know that no better could be done with this index as the starting index. We could keep 2 pointer, one for the start and another for the end of the current subarray, and make optimal moves so as to keep the sum greater than s as well as maintain the lowest size possible.

2. fast index의 경우, 배열의 범위를 벗어난 경우에 이에 대한 예외 처리를 해야 함. 그것만 제외하면 slow index를 움직이는 경우와 개념은 거의 동일. 하지만 구현은 더 간단해 보인다.

3. 최종 코드가 훨씬 간단하고 깔끔하다. 개념은 비슷하다. right index를 기준으로 움직이면, 또 다른 경계를 체크하지 않아도 되기 때문에, 코드가 간단해 진다. 오른쪽 인덱스를 증가시키면서 sum에 값을 순서대로 저장하다가 sum >= s의 조건을 만족하면, minLen를 계산하고 left index를 움직여 가면서 sum을 줄여야 한다. 이때 sum >= s의 조건이 만족안되면 다시 right index를 늘려나간다. 즉, start index & end index를 적절히 움직이면서 sum >= s 조건을 계속 체크해 가는 것이다.  

## What I've learned

1. 이제는 어느 정도 DP의 개념을 가지고 sliding window 다루는 방법을 아는거 같다.

2. 이와 같은 경우 왼쪽에서 하나를 빼고 오른쪽에서 값을 채워가면서 조건을 만족시키는 방법도 배워간다.

3. Prob 3. longest substring without repeating characters 문제와 비슷한 유형. 그래서 처음에 왼쪽 인덱스를 움직였다. 하지만 지금 생각해보니 그것도 오른쪽 인덱스를 움직이면서 하는 꼴. 음..



## Initial code
```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {        
        if (nums.size() == 0)
            return 0;

        int minLen = INT_MAX;
        int sum = nums[0];
        int j = 0;

        for (int i=0; i<nums.size(); ++i) {
            // need to make j move on.
            while (sum < s) {
                ++j;

                // This is tricky..  인덱스를 증가시키는 경우에는 항상 배열 크기보다 큰지 확인.
                if (j >= nums.size())
                    return minLen == INT_MAX ? 0 : minLen;

                sum += nums[j];
            }

            // get the local sum and check if it is equal to s
            // if it is, get the local sum,
            if (sum >= s) {
                minLen = min(minLen, j-i+1);
            }
            // subtract the left most element.
            sum -= nums[i];
        }        

        // 못 찾은 경우에는 0, 그렇지 않지 경우에는 minLen 반환.
        return minLen == INT_MAX ? 0 : minLen;
    }
};
```

## Final code
```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {        
        if (nums.size() == 0)
            return 0;

        int minLen = INT_MAX;
        int sum = 0;
        int i = 0 /*left*/, j = 0; /*right*/

        // 1 1 1 2 3 5
        for (int j=0; j< nums.size(); ++j) {
            sum += nums[j];
            while (sum >= s) {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i++];
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
```
