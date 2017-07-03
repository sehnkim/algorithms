* Tags:

1. 새로운 string을 만들 필요가 없었다.


(initial)
```
string longestCommonPrefix(vector<string>& strs)
{        
    if (strs.size() == 0)
        return "";

    // for each column.
    string refStr = strs[0];
    string res = "";

    for (int i=0; i<refStr.size(); ++i)
    {
        char c = refStr[i];            
        for (int j=1; j<strs.size(); ++j)
        {
            if (strs[j].size() == i || c != strs[j][i])
                return res;                    
        }
        res += c;
    }

    return res;
}
```

(final)
```
string longestCommonPrefix(vector<string>& strs)
{    
    if (strs.size() == 0)
        return "";

    // for each column.
    for (int i=0; i<strs[0].size(); ++i)
    {
        char c = strs[0][i];            
        for (int j=1; j<strs.size(); ++j)
        {
            if (strs[j].size() == i || c != strs[j][i])
                return strs[0].substr(0, i);  // 인덱스, 길이.
        }
    }

    return strs[0];
}
```
