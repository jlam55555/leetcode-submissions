int maxProfit(int* prices, int pricesSize){
    if(!pricesSize)
        return 0;

    int profit, i;
    
    for(i = 1, profit = 0; i < pricesSize; i++)
        if(prices[i] > prices[i-1])
            profit += prices[i] - prices[i-1];
    
    return profit;
}
