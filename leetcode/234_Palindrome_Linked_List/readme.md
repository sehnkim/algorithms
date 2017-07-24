## Complexity
* Difficulty: easy
* Tags: Linked list, two pointers
* Time Complexity: O(n)
* Space Complexity: O(1)
* New functions:

## Note
1. 처음 시도에서 iterative approach와 recursive approach 두 가지는 모두 생각해 보았음. 반복 방법에서는 slow pointer & fast pointer를 사용하여 중간 지점을 찾은 후에 하나는 다시 앞쪽으로 하나는 뒤쪽으로 움직인다고 생각했는데 앞쪽으로 움직이기기 쉽지 않음.

2. 결국은 중간 지점을 찾은 후에 앞쪽의 반 리스트를 뒤집은 후에 차례로 비교하는 것. 리스트를 reverse하는 것이 어렵지는 않지만, recursion을 이용하면 보다 좋을 것이라 생각.

3. 하지만 recursion을 어떤식으로 적용해야 할지 잘 생각이 정리가 안됨. 처음 생각은 중간 지점을 찾은 후에 1번과 같은 방법을 거친다고 생각함. 하지만, [Link](https://discuss.leetcode.com/topic/27605/my-easy-understand-c-solution/11)에 정리된 방법이 가장 명료한 듯.

## What I've learned
1. a
2. b
3. c

## Initial code
```
class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* n1 = head;
        ListNode* n2 = head;
        // find(n1, n2);

        while (n1->next != NULL && n2->next != NULL && n2->next->next != NULL)
        {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        if (n2->next == NULL) {
            n2 = n1;
        }
        else if (n2->next->next == NULL)
            n2 = n1->next;            

        find(n1, n2);
        return true;
    }

    bool find (ListNode* n1, ListNode* n2)
    {
        if (n2 == NULL) {
            return true;
        }
        find (n1->next, n2->next->next);
        if (n1 != NULL && n2 != NULL) {
            if (n1->val != n2->val)
                return false;
        }       
    }
};
```

## Final code
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }

    // &로 넘기지 않으면 단순한 copy constructor를 실행하는 것이다. *를 사용하기 때문에 주소를 넘기는 것 같지만, caller가 ListNode* 이기 때문에 주소를 넘기는 것은 아니고 주소값 자체를 넘기는 것과 같다. 반면에 &를 사용하는 경우에는 그 주소를 가리키는 포인터를 넘기는 것이기 때문에 주소의 주소를 넘기는 것이다.
    bool check(ListNode*& head, ListNode* p) {
        if (p == NULL)
            return true;

        bool isPal = check(head, p->next);
        if(head->val != p->val)
            return false;

        // 여기서 head를 앞쪽으로 하나 옮겼는데, 스택 프레임이 하나 풀리면서 check(head, p->next) 바로 다음 줄로 되돌아갈때 ListNode*&와 같이 &가 있어서 head를 next한것이 효과가 있게 된다.
        head = head->next;
        return isPal;
    }
};
```
