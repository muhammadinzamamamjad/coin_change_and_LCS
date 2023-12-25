Qs 1:
## Coin-Change Problem: Greedy and Dynamic Programming Solutions

### Problem Description

Given an array of coins with varying denominations and an integer sum representing the total amount of money,
the task is to find the fewest coins required to make up that sum. If it's impossible to construct the sum using the given denominations, 
return -1.

---Greedy Approach

---Algorithm

1. Sort the array of coin denominations in descending order based on their values.
2. Iterate through the sorted denominations.
3. Greedily use as many coins as possible while staying within or closest to the target sum.

---Pros and Cons

- **Pros:**
  - Simple and easy to implement.
  - Fast and efficient for some scenarios.
- **Cons:**
  - May not always yield an optimal solution.

---Dynamic Programming Approach

---Algorithm

1. Initialize a dynamic programming table with dimensions (number of denominations + 1) x (target sum + 1).
2. Set base cases: `dp[0][j] = 0` (for all j), `dp[i][0] = 0` (for all i).
3. Iterate through the denominations and the target sum.
4. Update the table to store the minimum number of coins needed to make each possible sum.
5. Reconstruct the solution from the dynamic programming table.

---Pros and Cons

- **Pros:**
  - Guarantees an optimal solution.
  - Suitable for cases where greedy approaches fail.
- **Cons:**
  - Higher time and space complexity compared to the greedy approach.

---Asymptotic Upper Bound

1. Greedy Approach:
   - **Time Complexity:** O(n log n)
     - Dominated by the sorting operation.
   - **Space Complexity:** O(1)
     - Constant space is used.

2. Dynamic Programming Approach:
   - **Time Complexity:** O(n * targetsum)
     - Iterating through all denominations and possible sums.
   - **Space Complexity:** O(n * targetsum)
     - Space required for the dynamic programming table.

---Input File Format

1. Title and Symbol of Currency:
   - Example: "PakRupee PKR"

2. Number of Denominations (N):
   - Example: "5"

3. List of Denominations:
   - Example:
     ```
     rupees 50
     rupees 20
     rupees 10
     ```

4. Total Sum Required (for Greedy Algorithm):
   - Example: "120"

5. Output:
   - Output for both algorithms will be displayed, minimum number of coins.

---Running the Code


1. Run the code and input the required information as described in the input file format.
2. If the greedy algorithm is applicable, provide the total sum required for "coin-change."
3. Review the output, which will include the result of both the greedy and dynamic programming approaches.

Note

- The choice between the greedy and dynamic programming approaches depends on specific requirements and the nature of the input. 
Greedy is faster but may not always produce an optimal solution, while dynamic programming guarantees optimality.






Qs 2:

---Longest-Common Subsequence (LCS) Problem

---Problem Description

The Longest Common Subsequence (LCS) problem involves finding the longest subsequence that is common to two given sequences,
denoted as s1 and s2. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements
without changing the order of the remaining elements.

For the LCS problem:
- The common subsequence (denoted as Z) is not required to have consecutive positions within the original sequences.
- Z must be a strictly increasing sequence of indices of both s1 and s2.
- In a strictly increasing sequence, the indices of the chosen elements from the original sequences must be in ascending order in Z.

---Solutions

----Simple Recursion

The simple recursion approach involves recursively exploring all possible subsequences and finding the length of the LCS.
The recursive function compares characters of S1 and S2 and considers both possibilities: including the current character in the LCS or excluding it.

----Dynamic Programming

The dynamic programming approach is more efficient. It uses a 2D array (matrix) to store intermediate results.
The matrix is filled iteratively based on the lengths of common subsequences of prefixes of s1 and s2.
The final element of the matrix contains the length of the LCS.

---- Asymptotic Upper Bound

1. Simple Recursion:
   - **Time Complexity:** O(2^(m+n))
     - Exponential time complexity due to the recursive nature.
   - **Space Complexity:** O(m+n)
     - The recursion depth is proportional to the sum of the lengths of S1 and S2.

2. **Dynamic Programming:
   - Time Complexity: O(m * n)
     - Iterating through the lengths of S1 and S2.
   - Space Complexity: O(m * n)
     - Space required for the dynamic programming matrix.

--- Input

The program takes two input sequences, S1 and S2, for which the LCS needs to be found.

----Running the Code

1. Provide the first sequence, S1.
2. Provide the second sequence, S2.
3. The code will output the length of the LCS using both the simple recursion and dynamic programming approaches.

### Note

- The dynamic programming approach is recommended for larger input sequences due to its polynomial time complexity,
whereas the simple recursion approach may be impractical for larger inputs.