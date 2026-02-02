/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

#include <stdio.h>
int prices[50], n;

int main() {
    printf("Enter number of days: ");
    scanf("%d", &n);
    printf("Enter prices for %d days: ", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prices[i]);
    }

    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int  i = 1; i < n; i++)
    {
       if (prices[i] < minPrice)
       {
        minPrice = prices[i];
       }
       else if (prices[i] - minPrice > maxProfit)
       {
        maxProfit = prices[i] - minPrice;
       }
       
    }

    printf("Maximum profit is : %d\n", maxProfit);
    return 0;
    
}

/*#include <stdio.h>

int prices[50], n;

int main() {
    printf("Enter number of days: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of days must be at least 1.\n");
        return 0;
    }

    if (n > 50) {
        printf("Maximum allowed days is 50.\n");
        return 0;
    }

    printf("Enter prices for %d days:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    printf("Maximum profit is: %d\n", maxProfit);
    return 0;
}*/

// using dynamic memory allocation for leetcode style

#include <stdio.h>
#include <stdlib.h>
int* maxProfit(int* prices, int pricesSize, int* returnSize) {
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    
    int* result = (int*)malloc(sizeof(int));
    result[0] = maxProfit;
    *returnSize = 1;
    return result;
} 
