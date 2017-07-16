* Tags: sort,

1. 인터벌을 효과적으로 컨트롤할 수 있는 적당한 방법이 없다. 어떻게해서든간에 각각의 인터벌을 서로 비교할 수 밖에 없는데 이런 경우에는 O(n^2)가 필요하게 된다.
2. 따라서, 이를 조금 줄이기 위해서는 heap sort등을 사용해서 O(1)의 공간만을 이용해서 먼저 sorting을 하고 그 후에 각각을 비교하는 방법이 더욱 효과적이다.

## BST interval tree solution C++ No sorting!
https://discuss.leetcode.com/topic/28787/share-my-bst-interval-tree-solution-c-no-sorting?show=67748

## interval tree solution no sorting
https://discuss.leetcode.com/topic/38633/share-my-interval-tree-solution-no-sorting

(initial)
```
vector<Interval> merge(vector<Interval>& intervals)
{      
    vector<Interval> res;    
    if (intervals.size() == 0)
        return res;

    // sort first since
    sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return (a.start < b.start); });

    res.push_back(intervals[0]);

    // check intersection from the 1st elem.
    for (int i=1; i<intervals.size(); ++i) {
        // if there is no intersection, insert
        if (intervals[i].start > res.back().end)
            res.push_back(intervals[i]);
        else {
            // merge
            res.back().end = max(res.back().end, intervals[i].end);
        }
    }

    return res;
}
```

(final)
```
vector<Interval> merge(vector<Interval>& ins) {
    if (ins.empty()) return vector<Interval>{};
    vector<Interval> res;
    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
    res.push_back(ins[0]);
    for (int i = 1; i < ins.size(); i++) {
        if (res.back().end < ins[i].start) res.push_back(ins[i]);
        else
            res.back().end = max(res.back().end, ins[i].end);
    }
    return res;
}
```
https://discuss.leetcode.com/topic/20263/c-10-line-solution-easing-understanding
