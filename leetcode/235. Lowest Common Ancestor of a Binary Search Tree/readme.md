## Complexity
* Tags: Tree
* Time Complexity: O(n)
* Space Complexity: O(1)

## Note
1. 상당히 쉬운 문제. 루트 노드에서부터 차례로 BST의 특징을 이용하여 푸는 문제.
2. leaf에 도달할 경우가 없기 때문에 base case도 필요없지만, 일단 넣어주는 것이 좋을듯.
3. 가능한 경우들은 다음과 같기 때문에 코드에서 첫번째, 두 번째 경우 이외에는 바로 리턴해야 한다.


root->val > p->val | root->val > q->val | (root->val - p->val) x (root->val > q->val)
-- | -- | --
+ | + | +
- | - | +
0 | +/- | 0 (현재 노드가 답)
+/- | 0 | 0 (현재 노드가 답)
+ | - | - (현재 노드가 답)
- | + | - (현재 노드가 답)


## Initial code
```
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL)
        return NULL;

    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    else if (root->val == p->val || root->val == q->val)
        return root;
    else if ((root->val - p->val ) * (root->val - q->val) < 0)
        return root;
}
```

## Final code
```
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}
```
