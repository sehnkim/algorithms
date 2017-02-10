"""Thought process

[Prob analysis]
a set of distinct positive integers..
largest subset
every pair (Si, Sj) of elements in this subset
Si % Sj = 0 or Sj % Si = 0

==> largest subset.
가장 큰 것부터 찾아라. 어떻게 하면 가장 큰 것을 찾을수 잇을까??
그리고 거기서 서치를 멈출수 있을까?

1. 가장 쉬운 방법. : 루핑을 두개 쓰는 방법
각 멤버에 대해 페어를 찾아서 그걸 비교해서 가장 큰 집합을 찾는 방법.
for loop
    for loop

2. 회귀법과 반복법.

def f(a):
    if a is 2
        checkDivisible(a)

    # if divisible.
    subsets = findSubsets(a)
    res = product(subsets)
    if res == True:
        get biggest subset
    return res


         F
      1,2,3,4

     T        F
   1,2,4    1,2,3

  (T   T)  (T   F)
 1,2  2,4  1,3  2,3

"""


# input: [1,2,4,8]

import itertools

# input: [1,2,4,8]

arr = [1,2,4,8]

def f(arr, answer):
    if len(arr) == 2:
        if arr[0] % arr[1] == 0 or arr[1] % arr[0] == 0:
            if len(arr) > len(answer):
                answer = arr
            return True
        else:
            return False

    # 1: divisible?
    if (len(arr) > 2):
        subsets = itertools.combinations(arr, len(arr)-1)
        res = [f(s, answer) for s in subsets]
        r = reduce(lambda x, y: x*y, res)
        if r and len(arr) > len(answer):
            answer = arr
        return r


answer = []
f(arr, answer)
print answer


