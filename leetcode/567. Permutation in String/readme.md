## Complexity
* Tags: sliding window
* Time Complexity: O(l1 + 26x(l2-l1))
* Space Complexity: O(1)

## Note
1. 초기의 답을 보면 완전히 삽질한 것을 알수 있다. 하지만, Editorial을 보니 가능한 답 중의 하나. 물론 시간 제한에 걸리는 답.
https://leetcode.com/articles/short-permutation-in-a-long-string/

2. 제안된 답들을 보니 O(l1 + (l2-l1))에 해결되는 답도 있지만, 일단은 O(l1 + 26x(l2-l1))에 해결되는 답을 시도함.

3. 기본 개념은 permutation을 직접 구해서 이를 각각 비교하는 것보다 sliding window를 이용해서 s2의 한 문자씩을 마지막에서 없애서 처음에서 추가하는 식으로 비교하는 것이다.

## Initial code
```
bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;

    string soFar = "";
    string remaining = s1;

    unordered_map<char, int> map;
    for (auto c : s2)
    {
        if (map.find(c) == map.end())
            map[c] = 1;
        else
            map[c] += 1;
    }

    return permute(soFar, remaining, map);    
}

bool permute(string soFar, string remaining, unordered_map<char, int> map)
{
    if (remaining.compare("") == 0) {
        //cout << soFar << endl;
        return (s2.find(soFar) != string::npos);
    }

    for (int i=0; i<remaining.size(); ++i) {
        string now = soFar + remaining[i];
        string remains = remaining.substr(0, i) + remaining.substr(i+1, remaining.size() - i - 1);

        if (permute(now, remains, s2))
            return true;
    }

    return false;
}  
```

## Final code
```
bool checkInclusion(string s1, string s2)
{   
    if (s1.size() > s2.size())
        return false;

    int a1[26] = {0};
    int a2[26] = {0};

    for (char c: s1)
        a1[c - 'a']++;
    for (int i=0; i<s1.size(); ++i)
        a2[s2[i] - 'a']++;

    if (match(a1, a2))
        return true;

    for (int i=0; i<s2.size() - s1.size(); ++i)
    {
        a2[ s2[i] - 'a']--;
        a2[ s2[i + s1.size()] - 'a']++;

        if (match(a1, a2))
            return true;
    }

    return false;
}

bool match(int* a1, int* a2)
{
    for (int i=0; i<26; ++i) {
        if (a1[i] != a2[i])
            return false;
    }
    return true;
}
```

```
class Solution {
public:    
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        if (s1.size() == 0)
            return true;

        unordered_map<char, int> map;
        int n1 = s1.size();

        // Fill out the map with s1 - (char, add)
        for (int j=0; j<n1; ++j) {
            char c = s1[j];
            if (map.find(c) == map.end())
                map[c] = 1;
            else
                ++map[c];
        }

        // Fill out the map with s2 - but (char, subtract)
        for (int j=0; j<n1; ++j) {
            char c = s2[j];
            if (map.find(c) == map.end())
                map[c] = -1;
            else
                --map[c];         
        }

        // (*1)
        // bool success = areAllZeros(map);
        // if (success)
        //     return true;

        for (int i=0; i<s2.size()-n1+1; ++i) {
            // (*2)
            bool success = areAllZeros(map);
            if (success)
                return true;

            // 저 위에서 map에 이미 넣은 것에 대해 areAllZeros를 안하고 바로 위의 for 루프에서 수행하기 때문에
            // 결국은 니가 얘기한대로 s2.size()-n1번의 areAllZeros를 해야 하는데, 그렇게 하려면 아래의 break가 있어야 할듯.
            // 이러한 break를 넣기 싫으면 (*1)과 (*3)을 넣고, (*2)는 빼면 되겠다.
            if (i == s2.size() - n1)
                break;

            // update map
            char c = s2[i];
            char c2 = s2[i+n1];

            ++map[c];       // Add the char back again.

            if (map.find(c2) == map.end())
                map[c2] = -1;
            else
                --map[c2];      // subtract and then check if all are zeros.

            // (*3)
            // success = areAllZeros(map);
            // if (success)
            //     return true;
        }

        return false;
    }

    bool areAllZeros(unordered_map<char, int>& map) {
        unordered_map<char, int>::iterator it;
        for (it=map.begin(); it!=map.end(); ++it) {
            if (it->second != 0)
                return false;
        }
        return true;
    }
};
```
