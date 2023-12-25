//#include <iostream>
//#include <vector>
//using namespace std;
//
//// Using  Recursion
//int LCSUSINGRECURSION(const string& s1, const string& s2, int i, int j) {
//    if (i == 0 || j == 0)  //base case 
//    {
//        return 0;
//    }
//    else if (s1[i - 1] == s2[j - 1]) {
//        return 1 + LCSUSINGRECURSION(s1, s2, i - 1, j - 1);
//    }
//    else {
//        return max(LCSUSINGRECURSION(s1, s2, i - 1, j), LCSUSINGRECURSION(s1, s2, i, j - 1));
//    }
//}
//
//// using Dynamic Programming
//int LCSUSINGDP(const string& s1, const string& s2, string& lcs) {
//    int L1 = s1.length();
//    int L2= s2.length();
//
//    vector<vector<int>> dp(L1 + 1, vector<int>(L2 + 1, 0)); // 2D MATRIX TO STORE PREVIOUS RESULT INITIALIZE WITH 0
//
//    for (int i = 0; i <= L1; ++i)
//    {
//        for (int j = 0; j <= L2; ++j)
//        {
//            if (i == 0 || j == 0) 
//            {
//                dp[i][j] = 0;
//            }
//            else if (s1[i - 1] == s2[j - 1])
//            {
//                dp[i][j] = 1 + dp[i - 1][j - 1];
//            }
//            else 
//            {
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//            }
//        }
//    }
//
//    // Reconstruct string which is LCS
//
//    int i = L1, j = L2;
//    while (i > 0 && j > 0) {
//        if (s1[i - 1] == s2[j - 1]) {
//            lcs = s1[i - 1] + lcs;
//            i--;
//            j--;
//        }
//        else if (dp[i - 1][j] > dp[i][j - 1]) {
//            i--;
//        }
//        else {
//            j--;
//        }
//    }
//
//    return dp[L1][L2]; // THIS IS THE LAST CELL OF MATRIX WHERE RESULT IS STORED
//}
//
//int main() {
//    string s1, s2;
//
//    // Input two strings
//    cout << "Enter the first string: ";
//    cin >> s1;
//
//    cout << "Enter the second sequence: ";
//    cin >> s2;
//    cout << endl;
//    // Using Simple Recursion
//    int len = LCSUSINGRECURSION(s1, s2, s1.length(), s2.length());
//    cout << "LCS Length using Recursion: " << len << endl;
//    cout << endl;
//    // Using Dynamic Programming
//    string lcsString;
//    int lenDP = LCSUSINGDP(s1, s2, lcsString);
//    cout << "LCS Length using Dynamic Programming: " << lenDP << endl;
//    cout << endl;
//    cout << "Longest Common Subsequence String: " << lcsString << endl;
//    return 0;
//}
