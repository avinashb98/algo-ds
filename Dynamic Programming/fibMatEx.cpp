#include<iostream>
#include<vector>
using namespace std;

void setBits(long long n, long long* bits) {
    long long i = 0;
    long long temp = n;
    while(temp > 0) {
        if(temp & 1)
            bits[i++] = 1;
        else i++;
        temp >>= 1;        
    }
}

void matMult(long long* a, long long* b, long long* result) {
    //Multiplying 2X2 matrix;
    result[0] = (a[0] * b[0]) + (a[1] * b[2]);
    result[1] = (a[0] * b[1]) + (a[1] * b[3]);
    result[2] = (a[2] * b[0]) + (a[3] * b[2]);
    result[3] = (a[2] * b[1]) + (a[3] * b[3]);
}

long long fibMatEx(long long n) {
    n = n - 1; //Since exponentiation is done till n-1 for the matrix
    
    //Calculate the total number of bits required
    long long max = 0;
    long long temp = n;
    while (temp > 0)
    {
        max++;
        temp /= 2;
    }

    //Initialize to zero
    long long bits[max];
    for (long long i = 0; i < max; i++) {
        bits[i] = 0;
    }
    
    setBits(n, bits);
    
    //Precompute powers of matrix upto max
    long long dp[max][4];
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    dp[0][3] = 0;
    for(long long i = 1; i < max; i++) {
        matMult(dp[i - 1], dp[i - 1], dp[i]);
    }

    //Calculate (n-1)th power of matrix
    long long resMat[4] = {1, 0, 0, 1};
    long long tempMat[4] = {1, 0, 0, 1};
    for(long long i = 0; i < max; i++) {
        if(bits[i] == 1) {
            matMult(tempMat, dp[i], resMat);
            tempMat[0] = resMat[0];
            tempMat[1] = resMat[1];
            tempMat[2] = resMat[2];
            tempMat[3] = resMat[3];
        }
    }

    return resMat[0] + resMat[1];
}

int main() {
    cout << fibMatEx(50);
    return 0;
}