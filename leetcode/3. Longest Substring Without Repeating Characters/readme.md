https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description

* Tags: DP, I think.

1. 문제를 BK과 함께 풀려고 2시간 이상 시간을 보냈지만 결국은 해결 못함.
2. 다음 경우와 같이 b가 반복되는 경우, 그 앞 쪽이 더 긴 경우 혹은 그 뒤쪽이 더 긴 경우가 있지만 이를 어떤 식으로 접근해서 더 긴 경우를 찾아야 하는지 잘 해결이 안됨.
	* z x y s t u a b c d e b k l m n
	* a z x b c d e b k x m n
3. sliding window를 사용해야 하는 것과 char, index를 해쉬 맵에 넣어 사용하면 좋겠다는 생각에까지는 미쳤는데, 이를 정확히 어떻게 구현해야 하는지 생각하는데 실패함.

(initial)
```
Q: longest substring without any repeating characters

length = 8

i
0 1 2 3 4 5 6 7 8 9 10
* * *         * * *
a b c d e f g a b c x
      1 2 3 4 5 6 7 8
  j


z x y s t u a b c d e b k l m n

a z x b c d e b k x m n
0 1 2 3

{
    a:[0],
    z:[1],
    x:[2],
    b:[3,7],
    c:[4],...
}



* _ / *         / * & & * /     * _
a d k a f g h i a b c c a b d e a d


* _ / *   / * & & * /   * _
a d b a 4 a b c c a b 2 a d

     2
    /  \
   3    3
  / \  / \
      4   4
       \
        5

lStep, rStep = 6, 2

while rStep != 0 or lStep != 0:
    step = rand(0,1)
    if not duplicated():
        updateTree()
        if step == 0:
            lStep -= 1
        else
            rStep -= 1
    else:
        moveUp()


N^2 --> NlogN

-hashtable: identify duplicates
-dist(a,b) != 0

//localMax = max (localMax + )
globalMax

```

(final)
```
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>(); // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (map.containsKey(s.charAt(j))) {
                i = Math.max(map.get(s.charAt(j)), i); // i: 현재 j까지 반복이 없는 가장 낮은 index.
            }
            ans = Math.max(ans, j - i + 1);
            map.put(s.charAt(j), j + 1); // j+1: 반복되는 문자의 다음 인덱스
        }
        return ans;
    }
}
```

https://leetcode.com/articles/longest-substring-without-repeating-characters/
