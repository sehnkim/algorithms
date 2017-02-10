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


#         F
#      1,2,3,4
#
#     T        F
#   1,2,4    1,2,3
#
#  (T   T)  (T   F)
# 1,2  2,4  1,3  2,3
#



