//
// Created by shreyas on 29/6/19.
//

#ifndef DSA_PRACTICE_SUBSEQUENCEDP_H
#define DSA_PRACTICE_SUBSEQUENCEDP_H

#include "bits/stdc++.h"
#include "constants.h"

using namespace std;

void buildTableLCS(string a, string b, int dp[MAX][MAX]) {

    int dim1 = a.size() + 1;
    int dim2 = b.size() + 1;

    for(auto i = 0; i < dim1; i++) {
        dp[i][0] = 0;
    }

    for(auto i = 0; i < dim2; i++) {
        dp[0][i] = 0;
    }

    for(auto i = 1; i < dim1; i++) {
        for(auto j = 1; j < dim2; j++) {
            if(a.at(i - 1) == b.at(j - 1)) {
                dp[i][j] = 1 + ((i-1 >= 0 && j-1>=0) ? dp[i-1][j-1] : 0);
            } else {
                int sol1 = 0, sol2 = 0;
                if(i-1 >= 0)
                    sol1 = dp[i-1][j];
                if(j-1 >= 0)
                    sol2 = dp[i][j-1];

                dp[i][j] = (sol1 > sol2 ? sol1 : sol2);
            }
        }
    }
}

// Longest Common Subsequence.
void LCS() {
    string a = "ABCDEF";
    string b = "BE";

    int dp[MAX][MAX];

    buildTableLCS(a,b,dp);

    cout << dp[a.size()][b.size()] << endl;
}

#endif //DSA_PRACTICE_SUBSEQUENCEDP_H
