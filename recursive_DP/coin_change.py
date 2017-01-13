class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount == 0:
            return 0

        count = [0]*amount
        return self.coinChangeRec(coins, amount, count)

    def coinChangeRec(self, coins, amount, count):
        if amount == 0: return 0
        if amount < 0: return -1
        if count[amount-1] != 0: return count[amount-1]

        min_ = sys.maxint
        for coin in coins:
            res = self.coinChangeRec(coins, amount-coin, count)
            if res >= 0 and res < min_:
                min_ = res + 1

        count[amount-1] = -1 if min_ == sys.maxint else min_
        return count[amount-1]


s = Solution()
coins = [1,2,3]
amount = 12
print s.coinChange(coins, amount)