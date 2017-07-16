## Complexity
* Tags: Binary search, Tree.
* Time Complexity: O(n)
* Space Complexity: O(1)

## Note
1. 아주 어려운 문제는 아니었음. 문제를 푸는 핵심 내용은 이미 숙지하고 있었는데, 이를 어떻게 잘 활용할 것인가. 즉, 문제에서 kth smallest element를 찾으라는 것은 처음에서부터 시작해서 in-order traversal하는 경우 k번째 element를 찾으라는 문제. 즉, 이러한 사실만 알면 쉽게 풀리는 문제였음.

2. 하지만 i를 증가시킨 후에 바로 k==i를 비교해야 하는 논리를 놓쳤음. 그리고, left 또는 right 노드로 들어가기 전에 if (root->left != NULL)와 같은 루틴을 넣어서 괜히 빈 노드로 들어가는 과정을 없애는 것이 효과적임.

3. 방법 2와 같이 스택을 이용할 수도 있다. 재밌는 것은 맨 왼쪽에 있는 노드만을 우선 스택에 넣는다는 것이다. 그리고 pop한 노드에 대한 오른쪽 노드를 고려하고 그 노드에 대해 다시 왼쪽 노드가 있는지를 살펴서 스택에 다시 넣어준다. 이렇게 하다보면 결국에는 각 노드를 in-order traversal의 순서대로 훑어나가는 것을 알 수 있다. 

## Initial code
```
int kthSmallest(TreeNode* root, int k) {
    if (root == NULL)
        return -1;

    int ans;
    int i = 1;
    kthSmallest(root, k, i, ans);
    return ans;
}

void kthSmallest(TreeNode* root, int k, int& i, int& ans)
{
    if (root == NULL)
        return;

    if (k == i)
        ans = root->val;

    kthSmallest(root->left, k, i, ans);        
    ++i;
    kthSmallest(root->right, k, i, ans);        
}
```

## Final code
```
int kthSmallest(TreeNode* root, int k) {
    if (root == NULL)
        return -1;

    int number;
    int count = 0;
    kthSmallest(root, k, count, number);
    return number;
}

void kthSmallest(TreeNode* root, int k, int& count, int& number)
{
    if (root->left != NULL)
        kthSmallest(root->left, k, count, number);

    ++count;
    if (k == count) {
        number = root->val;
        return;
    }            

    if (root->right != NULL)
        kthSmallest(root->right, k, count, number);        
}
```

```
public int kthSmallest(TreeNode root, int k) {
    Stack<TreeNode> st = new Stack<>();

    while (root != null) {
        st.push(root);
        root = root.left;
    }

    while (k != 0) {
        TreeNode n = st.pop();
        k--;
        if (k == 0) return n.val;
        TreeNode right = n.right;
        while (right != null) {
            st.push(right);
            right = right.left;
        }
    }

    return -1; // never hit if k is valid
}
```
