//
// Created by shreyas on 29/6/19.
//

#ifndef DSA_PRACTICE_RODCUT_H
#define DSA_PRACTICE_RODCUT_H

#include "bits/stdc++.h"
#include "constants.h"
using namespace std;

void buildTableRodCut(int prices[], int n, int dp[]) {
    int dim = n+1;

    dp[0] = 0;

    for(auto i = 1; i < dim; i++) {

        // Assume max is when rod is not even cut.
        int max = prices[i - 1];

        for(auto j = 1; j < i; j++) {
            int temp = prices[j - 1] + dp[i - j];
            max = (max < temp ? temp : max);
        }
        dp[i] = max;
    }
}

void rodCut() {
    int prices[8] = {1, 5, 8, 9, 10, 17, 17, 20};
    int dp[9];
    buildTableRodCut(prices,8,dp);
    cout << dp[8] << endl;
}

#endif //DSA_PRACTICE_RODCUT_H
