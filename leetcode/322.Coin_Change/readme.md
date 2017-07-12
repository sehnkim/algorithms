## Complexity
* Tags: DP, Backtracking
* Time Complexity: O(n*S), n: denominations, S: amount
* Space Complexity: O(S)

## Note
1. 초기의 방법은 맞는 답은 아닌거 같다. MSVC를 이용해서 돌려봤는데 무한루프를 도는 듯. 처음 아이디어는 coins를 크기 순으로 일단 정렬해서 크기가 큰 것들로부터 채워 나가는 방법을 사용하는 것. 하지만, 별 의미가 없다. 왜냐하면, Backtracking을 해서 결국은 전수검사를 할 것이기 때문에 그렇기도 하지만, 생각해보면 크기가 큰 것부터 시작한다고 해도 그 방법이 코인의 수가 가장 적으리라고 장담할 수는 없기 때문일 듯(?).

2. Backtracking을 이용하면서도 DP를 이용해야 한다. 그렇지 않으면 동일한 과정을 반복하기 때문에 제한시간안에 해결이 어려움. DP를 이용하기 위해서는 substructure가 동일해야 함.

3. 이 문제에서 주요했던 것은 min count를 찾을때, 어떤 한 노드를 생각해보면 그 노드에서 어떤 것이 route가 가장 작을지를 모르기 때문에 for each coin에 대한 모든 경우 중에서 가장 적은 것을 찾는다는 것. 그리고 이를 DP에 저장한다는 것. 이를 잘 기억해야 한다.

4. Backtracking을 위해서는 amount < 0인 경우 return -1; 한 것을 볼 수 있다.

5. 아래 코드에서 nums >= 0부분을 보면 결과가 -1인 경우는 제외했다. 그리고 최종결과에 min_nums = nums + 1;와 같이 +1을 했다.

```
for (int i=0; i < coins.size(); ++i) {
  int nums = coinChange(coins, amount - coins[i], dp);
  if (nums >= 0 && nums < min_nums)
    min_nums = nums + 1;
}
```

## Initial code
```
int coinChange(vector<int>& coins, int amount) {
	if (coins.size() == 0 || amount == 0)
		return 0;
	sort(coins.begin(), coins.end(), [](int &a, int &b) { return (a > b); });
	int nums = 0;
	int minNum = INT_MAX;
	coinChange(coins, amount, nums, minNum);

	if (minNum != INT_MAX)
		return minNum;
	else
		return -1;
}

void coinChange(vector<int>& coins, int& amount, int& num, int& minNum)
{
	if (amount < 0)
		return;

	if (amount == 0) {
		if (minNum > num)
			minNum = num;
		return;
	}

	for (int i=0; i < coins.size(); ++i)
	{
		amount -= coins[i];
		++num;

		coinChange(coins, amount, num, minNum);

		amount += coins[i];
		--num;
	}
}
```

## Final code
```
int coinChange(vector<int>& coins, int amount) {        
	int* dp = new int [amount];
	memset(dp, 0, sizeof(int) * amount);
	if (coins.size() == 0 || amount == 0)
		return 0;
	int min_nums = coinChange(coins, amount, dp);
	delete [] dp;
	return min_nums;        
}

int coinChange(vector<int>& coins, int& amount, int* dp)
{
	if (amount < 0) return -1;
	if (amount == 0) return 0;        
	if (dp[amount-1] != 0) return dp[amount-1];

	int min_nums = INT_MAX;
	for (int i=0; i < coins.size(); ++i) {
		int nums = coinChange(coins, amount - coins[i], dp);
		if (nums >= 0 && nums < min_nums)
			min_nums = nums + 1;
	}

	dp[amount-1] = (min_nums == INT_MAX)? -1 : min_nums;
	return dp[amount-1];
}
```
