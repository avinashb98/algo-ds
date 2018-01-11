#include<iostream>
using namespace std;

int fibDP(long long n, long long memo[]) {
    if(n == 1 || n == 0) return 1;
    if(memo[n] == 0) {
        memo[n] = fibDP(n - 1, memo) + fibDP(n - 2, memo);
    }
    return memo[n];
}

int main() {
    long long memo[100];
    for(int i = 0; i < 100; i++) {
        memo[i] = 0;
    }
    cout << fibDP(66, memo);
    return 0;
}