## Complexity
* Difficulty: Medium
* Tags: Binary search, bitmap, math
* Time Complexity: O(n)
* Space Complexity: O(1)
* New functions: xxx

## Note
1. 예, 17/3.
3 --> 6 --> 12 --> 24
3을 시작으로 두 배씩 증가시켰을때 12가 17을 뺄 수 있는 가장 큰 수. 이때는 몫이 4
17 - 12 = 5
그러면 5/3을 수행.
이때는 3이 5를 뺄 수 있는 가장 큰 수. 이 때는 몫이 1.

따라서 4 + 1 => 5가 정답

예) 19/3
12가 가장 큰 수 : 19-12 = 7, 몴: 4
7/3 : 3--> 6 --> 12..  6이 가장 큰 수, 몫: 2
따라서 4 + 2 ==> 6이 정답.

2. 왜 long long으로 하는지 정확히 이해가 아직 안됨.
3. c

## What I've learned
1. a
2. b
3. c

## Initial code
```
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool plus_sign = true;
        if (divisor < 0) {
            divisor = abs(divisor);
            plus_sign = false;
        }

        if (dividend < 0) {
            dividend = abs(dividend);
            plus_sign = !plus_sign;
        }

        int count = 0;
        while (dividend >= divisor) {
            dividend -= divisor;
            ++count;
        }

        if (plus_sign == false)
            count = -count;

        return count;
    }
};
```

https://discuss.leetcode.com/topic/15568/detailed-explained-8ms-c-solution
## Final code
```
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;

        //  Find the largest multiple so that (divisor * multiple <= dividend),
        //  whereas we are moving with stride 1, 2, 4, 8, 16...2^n for performance reason.
        //  Think this as a binary search.
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;  // multiple: 몫
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Look for additional value for the multiple from the reminder (dividend - sum) recursively.
            dvd -= temp;
            res += multiple;  // 각 단계에서 계산된 몫을 더함.
        }
        return sign == 1 ? res : -res;
    }
};
```
