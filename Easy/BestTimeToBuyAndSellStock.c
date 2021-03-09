int maxProfit(int* prices, int pricesSize){
    int min = INT_MAX, max_profit = 0;
    
    for(int i=0; i<pricesSize; i++){
        if(prices[i] < min)
            min = prices[i];
        else if(prices[i]-min > max_profit)
            max_profit = prices[i] - min;
    }
    
    return max_profit;
}
