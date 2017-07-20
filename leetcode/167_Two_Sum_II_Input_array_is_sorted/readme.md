## Complexity
* Difficulty: Easy
* Tags: Array, Two pointers, binary search
* Time Complexity: O(n)
* Space Complexity: O(1)
* New functions:
vector<int> indexes;
indexes.push_back(i+1);
indexes.push_back(j+1);
return indexes;

or

vector<int> indexes({i+1, j+1});
return indexes;

or

return vector<int>({i+1, j+1});

## Note
1. 조금 쉬웠던 문제. begin과 end 두 개의 pointers를 taget에 맞게 옮기는 문제.


## What I've learned
1. vector<int>로 return 하는 방법


## Initial code
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        int sum = numbers[i] + numbers[j];  // init

        while (sum != target) {
            if (sum > target) {
                --j;
            }
            else {
                ++i;   
            }
            sum = numbers[i] + numbers[j];
        }

        return vector<int>({i+1, j+1});        
    }
};
```

## Final code
```
vector<int> twoSum(vector<int>& numbers, int target) {
    int lo=0, hi=numbers.size()-1;
    while (numbers[lo]+numbers[hi]!=target){
        if (numbers[lo]+numbers[hi]<target){
            lo++;
        } else {
            hi--;
        }
    }
    return vector<int>({lo+1,hi+1});
}
```
