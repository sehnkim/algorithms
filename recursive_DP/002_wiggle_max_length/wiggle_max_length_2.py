def stepCounter (nums, count):
    if len(nums) == 1:
        return abs(count) + 1

    diff = nums[1] -  nums[0]
    if diff: # not zero
        if (count > 0 and diff < 0):
            count = (count + 1) * -1
        elif(count < 0 and diff > 0):
            count = abs(count) + 1
        elif(count == 0 and diff != 0):
            count = int(diff/abs(diff))

    return stepCounter(nums[1:], count)


def wiggleMaxLength(nums):
    if len(nums) < 2:
        return len(nums)

    if len(nums) == 2:
        return 1 if nums[0] == nums[1] else 2

    count = 0
    if nums[1] > nums[0]:
        count = 1
    elif nums[1] < nums[0]:
        count = -1

    return stepCounter (nums[1:], count)