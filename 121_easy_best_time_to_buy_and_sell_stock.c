int maxProfit(int* prices, int pricesSize){
    if(!pricesSize)
        return 0;

    int low = prices[0], maxProfit = 0, i;
    
    for(i = 1; i < pricesSize; i++)
        if(prices[i] < low)
            low = prices[i];
        else if(prices[i] - low > maxProfit) 
            maxProfit = prices[i] - low;
    
    return maxProfit;
}
