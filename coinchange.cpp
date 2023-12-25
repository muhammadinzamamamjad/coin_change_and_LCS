#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


bool compareSecond(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}


//This code is  for Greedy Approach
int greedyCoinChange(vector<pair<string, int>>& denominations, int targetSum) {
    int coinsUsed = 0;
    for (const pair<string, int>& coin : denominations) {
        while (coin.second <= targetSum) {
            targetSum = targetSum - coin.second;
            coinsUsed++;
        }
    }
    if (targetSum == 0)
        return coinsUsed;
    else
        return -1;
}

// Dynamic Programming Approach
int dynamicCoinChange(vector<pair<string, int>>& denominations,  int numDenominations, int targetSum)
{

// 2d dp array where numDenominations is the number of coin
// denominations and targetsum is the target sum
vector<vector<int> > dp(numDenominations + 1, vector<int>(targetSum + 1, 0));

// Represents the base case where the target sum is 0,
// and there is only one way to make change: by not
// selecting any coin
dp[0][0] = 1;
for (int i = 1; i <= numDenominations; i++) {
    for (int j = 0; j <= targetSum; j++) {

        // Add the number of ways to make change without
        // using the current coin,
        dp[i][j] += dp[i - 1][j];

        if ((j - denominations[i - 1].second) >= 0) {

            // Add the number of ways to make change
            // using the current coin
            dp[i][j] += dp[i][j - denominations[i - 1].second];
        }
    }
}
if (dp[numDenominations][targetSum] != 0)
return dp[numDenominations][targetSum];
else return -1;
}




int main() {
    ifstream inputFile("input.txt");
    string currencyTitle, currencySymbol;
    int numDenominations;
    inputFile >> currencyTitle >> currencySymbol;
    inputFile >> numDenominations;
    vector<pair<string, int>> denominations(numDenominations);
    for (int i = 0; i < numDenominations; ++i) {
        inputFile >> denominations[i].first >> denominations[i].second;
    }

    inputFile.close();

    int targetSum;
    cout << "Enter the total sum required: ";
    cin >> targetSum;
    sort(denominations.begin(), denominations.end(), compareSecond);
    // Check if the Greedy Algorithm is applicable
    if (denominations[0].second > denominations.back().second * 2) {
        int greedyResult = greedyCoinChange(denominations, targetSum);
        if (greedyResult != -1) {
            cout << "Greedy Approach Result: " << greedyResult << " coins used" << endl;
            return 0;
        }
    }

    // If Greedy is not applicable or doesn't give a valid result, use Dynamic Programming
    int dynamicResult = dynamicCoinChange(denominations, numDenominations, targetSum);
    if (dynamicResult != -1) {
        cout << "Dynamic Programming Result: " << dynamicResult << " coins used " << endl;
    }
    else {
        cout << "No valid combination found." << endl;
    }

    return 0;
}