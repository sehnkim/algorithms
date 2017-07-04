## Complexity
* Tags: Linked list.
* Time Complexity: O(n)
* Space Complexity: O(n)

## Note
1. 처음에는 스택을 3개 이용해서 푸는 방법을 생각했다. 가장 쉬운 방법으로. 하지만, 그것보다는 앞쪽에 넣는 방법 (push front)이 생각보다는 쉬웠다. 오히려 push back을 하려면 head를 return해야 하기 때문에 temp를 필요로해서 오히려 extra code가 필요했다.
2. 문제는 생각보다 그렇게 어렵지 않았다. 어떻게 하면 순서를 뒤집을 것인가의 문제였는데, 대부분 스택을 이용해서 풀었더라.
3. 누군가는 reverse list를 먼저 수행하고 풀이를 했는데, 이것도 나쁜 방법은 아닌듯. 결국은 reverse list를 하는데도 O(n)이 소요되기 때문에 O(n) * 3번을 하는 경우에 있어서는 동일함.

4. 해답을 보면 다음과 같은 코드도 있는데, 오히려 코드 읽고, 해석하는데 불편함이 큰거 같다. 코드의 길이는 짧아지지만 carry > 0 인 경우를 따로 고려하는 것이 오히려 보다 명확하다.

  ```
  int sum = 0;
  ListNode list = new ListNode(0);
  while (!s1.empty() || !s2.empty()) {
      if (!s1.empty()) sum += s1.pop();
      if (!s2.empty()) sum += s2.pop();
      list.val = sum % 10;
      ListNode head = new ListNode(sum / 10);
      head.next = list;
      list = head;
      sum /= 10;
  }

  return list.val == 0 ? list.next : list;
  ```

## Initial code
```
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{        
  stack<int> s1, s2, s3;
  int len1 = 0, len2 = 0;
  while (l1 != NULL) {
    s1.push(l1->val);
    l1 = l1->next;
    ++len1;
  }

  while (l2 != NULL) {
    s2.push(l2->val);
    l2 = l2->next;
    ++len2;
  }        

  int carry = 0;        

  while (s1.size() != 0 && s2.size() != 0) {
    int sum = s1.top() + s2.top() + carry;
    carry = sum / 10;
    s3.push(sum % 10);
    s1.pop();
    s2.pop();
  }

  if (len1 > len2) {
    while(s1.size() != 0) {
      int sum = s1.top() + carry;
      carry = sum / 10;
      s3.push(sum % 10);
      s1.pop();
    }            
  }
  else {
    while(s2.size() != 0) {
      int sum = s2.top() + carry;
      carry = sum / 10;
      s3.push(sum % 10);
      s2.pop();
    }
  }
  if (carry == 1)
    s3.push(carry);

  ListNode* res = NULL;
  ListNode* tmp = NULL;
  while (s3.size() != 0) {
    ListNode* cur = new ListNode(s3.top());
    if (res == NULL) {
      res = cur;
      tmp = res;                
    }
    else {
      tmp->next = cur;                
      tmp = tmp->next;
    }           

    s3.pop();
  }

  return res;
}
```

## Final code
```
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
	stack<int> s1, s2, s3;
	while (l1 != NULL) {
		s1.push(l1->val);
		l1 = l1->next;
	}

	while (l2 != NULL) {
		s2.push(l2->val);
		l2 = l2->next;
	}        

	int carry = 0;                
	int sum = 0;
	ListNode* head = NULL;
	while (s1.empty() == false || s2.empty() == false) {
		sum = carry;
		if (s1.empty() == false) {
			sum += s1.top();
			s1.pop();
		}

		if (s2.empty() == false) {
			sum += s2.top();
			s2.pop();
		}

		carry = sum / 10;
		ListNode* n = new ListNode(sum % 10);
		n->next = head;
		head = n;
	}

	if (carry > 0) {            
		ListNode* n = new ListNode(carry);
		n->next = head;
		head = n;
	}

	return head;
}
```
