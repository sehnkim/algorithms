class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int numOfCoins = 0
    
        if (amount <= 0)
            return -1;
            
        reverse(coins.begin(), coins.end());
        
        for (auto coin: coins) {
            if (coin < amount)
            {
                int quotient = amount / coin;
                int remainder = amount % coin;
                numOfCoins += quotient;
                
                if (remainder == 0)
                    return numOfCoins;
                    
                amount = remainder;
            }        
        }
        
        return -1;
        
    }
};