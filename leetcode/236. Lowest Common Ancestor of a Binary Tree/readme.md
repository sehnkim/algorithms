## Complexity
* Tags: Tree
* Time Complexity: O(n)
* Space Complexity: O(1)

## Note
1. 상당히 쉬운 문제. 루트 노드에서부터 차례로 BST의 특징을 이용하여 푸는 문제.
2. leaf에 도달할 경우가 없기 때문에 base case도 필요없지만, 일단 넣어주는 것이 좋을듯.
3. 가능한 경우들은 다음과 같기 때문에 코드에서 첫번째, 두 번째 경우 이외에는 바로 리턴해야 한다.


cases | root->val > p->val | root->val > q->val | (root->val - p->val) x (root->val > q->val)
  -- | -- | -- | --
1 | + | + | +
2  | - | - | +
3  | 0 | +/- | 0 (현재 노드가 답)
4  | +/- | 0 | 0 (현재 노드가 답)
5  | + | - | - (현재 노드가 답)
6  | - | + | - (현재 노드가 답)


## Initial code
```
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;

        if (root == NULL)
            return NULL;

        inorderTraversal(root, p, v1);
        for (int i=0; i < v1.size() ; ++i)
            cout << v1[i]->val << endl;

        inorderTraversal(root, q, v2);
        for (int i=0; i < v2.size() ; ++i)
            cout << v2[i]->val << endl;

        if (v1.size() > v2.size())
        {
            return v1[v2.size()-1];
        }
        else
            return v2[v1.size()-1];


        // int j = v1.size() > v2.size() ? v1.size() : v2.size();
        // for (int i=0; i < j ; ++i)
        // {
        //     cout << v1[i]->val << " " << v2[i]->val << endl;
        //     if (v1[i] != v2[i]) {
        //         return v1[i-1];
        //     }                
        // }
    }

    bool inorderTraversal(TreeNode* root, TreeNode* n, vector<TreeNode*>& vec)
    {
        if (root == NULL)
            return false;

        if (root == n)
            return true;

        vec.push_back(root);        

        if (inorderTraversal(root->left, n, vec))
            return true;        

        if (inorderTraversal(root->right, n, vec))
            return true;

        return false;
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
