//
// Created by shreyas on 29/6/19.
//

#ifndef DSA_PRACTICE_DP_H
#define DSA_PRACTICE_DP_H

#include "bits/stdc++.h"
#include "constants.h"

using namespace std;

void buildTable(Vec1D& coins, int dp[MAX][MAX], int n) {
    int dim1 = n + 1;
    int dim2 = coins.size();

    // Only one solution for no coins selected.
    for(auto i = 0; i < dim2; i++) {
        dp[0][i] = 1;
    }

    for(auto i = 1; i < dim1; i++) {
        for(auto j = 0; j < dim2; j++) {

            int x = (i - coins[j] >= 0 ? dp[i - coins[j]][j] : 0);
            int y = (j >= 1 ? dp[i][j-1] : 0);

            dp[i][j] = x + y;
        }
    }
}


void coinChange() {
    Vec1D coins;
    coins.emplace_back(1);

    int n = 25;

    int dp[MAX][MAX];

    buildTable(coins,dp,n);

    cout << dp[n][coins.size() - 1] << endl;

}

#endif //DSA_PRACTICE_DP_H
