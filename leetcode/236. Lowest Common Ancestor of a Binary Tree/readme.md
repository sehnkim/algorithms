## Complexity
* Tags: Tree
* Time Complexity: O(n)
* Space Complexity: O(1)

## Note
1. It's recursive and expands the meaning of the function. If the current (sub)tree contains both p and q, then the function result is their LCA. If only one of them is in that subtree, then the result is that one of them. If neither are in that subtree, the result is null.
https://discuss.leetcode.com/topic/18561/4-lines-c-java-python-ruby/78

2. 즉, 현재 노드가 p, q를 양쪽을 가지고 있다면, 그게 답이다. 그렇지 않고, subtree에 p, q중에 한개만 가지고 있다면 그 노드는 그게 그 결과일 것이다. 그렇지 않고, 어떤 노드가 p, q 아무것도 가지고 있지 않다며, 그 결과는 NULL이다.

3. 결국은 각 노드에서 p와 q가 있는 있는지를 체크하는 것이다. 그리고, 노드를 현재 시점까지 못 찾았다면 NULL을 계속 return하게 되며, p와 q 중에 하나를 찾았다면 그것을 상위 노드까지 계속 가지고 다니는 꼴이 된다. 그러다가, 어느 노드에서는 오른쪽으로부터 올라온 p 또는 q값과 결국에는 만나게 될 것이며, 이때가 LCA를 찾게 되는 순간이다.





## Initial code
```
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{    
    if (!root || !p || !q) {
        return NULL;
    }

    if (root == p || root == q) {
        return root;
    }

    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);

    if (l && r) {
        return root;
    }

    return l? l : r;
}

https://discuss.leetcode.com/topic/26396/short-and-clean-c-solution
```
