#include <stdio.h>

typedef struct bursa
{
    int buy;
    int sell;
    int profit;
} bursa_t;

bursa_t Bursa(int arr[], int size)
{
    bursa_t bursa;

    for (int buy = 0, sell = 1; sell < size; ++sell)
    {
        int profit = arr[sell] - arr[buy];
        if (profit > bursa.profit)
        {
            bursa.profit = profit;
            bursa.buy = buy;
            bursa.sell = sell;
        }
        else if (arr[sell] < arr[buy])
        {
            buy = sell;
        }
    }

    return bursa;
}

int main(void)
{
    int arr[] = {6,8,3,4,2,9,1,5,7,10};

    bursa_t bursa = Bursa(arr, 10);

    printf("buy: %d, sell: %d, profit: %d\n", bursa.buy, bursa.sell, bursa.profit);

    return 0;
}