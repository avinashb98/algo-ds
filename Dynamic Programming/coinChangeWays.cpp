#include<iostream>
using namespace std;

int coinChangeWays(int n, int *d, int k, int** dp ) {
    if(n == 0)
        return 1;
    if(k == 0)
        return 0;
    if(n < 0)
        return 0;
    if(dp[n][k] > 0)
        dp[n][k] = coinChangeWays(n - d[0], d, k, dp) + coinChangeWays(n, d + 1, k - 1, dp);
    return dp[n][k];
}

int main() {
    int d[] = {1, 2};
    int n = 4;
    int k = 2;
    int** dp = new int(n+1);
    for(int i = 0; i < n + 1; i++)
        dp[i] = new int(k + 1);
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 3; j++)
            dp[i][j] = -1;
    cout << coinChangeWays(4, d, 2, dp);
    return 0;
}