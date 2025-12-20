"""
We have a string s of length n and a string s1 of length m
with m <= n. We want to count how many times s1 appears as a subsequence in s.
Remember that a subsequence of s is obtained by deleting an arbitrary
number of characters from s.
For example, for s=babgbag and s1=bag, the answer is 5.
The following are the 5 possible subsequences of s1:
ba[]g[][][], ba[][][][]g, b[][][][]ag, []b[][][]ag, [][][][]bag.
Design an algorithm that, given the s and s1 strings, solve the problem in
O(nm) time.

Solution: the dynamic programming technique
We can minimize the problem starting from "We want to count how many times
s1 appears as a subsequence in s." and breaking it down into smaller 
subproblems: "How many subsequences of s1[:j] (smaller than s1) are in
s[:i] (smaller than s)?".

I'll use a matrix (n+1) x (m+1) where M[i][j] is the number of subsequences
of s[:i] (the first i characters of s) that equals s1[:j] (the first j 
characters of s1).
The final result will be in M[n][m].
We have to define the recursive formula to fill the matrix. We can do the
following considerations:
- If j==0, the only subsequence of s that is equal to the empty string
  is the empty subsequence, so M[i][0] = 1 for every i.
- If i==0 and j>0, there are no subsequences of the empty string s that
  can form a non-empty string s1, so M[0][j] = 0 for every j>0.
- If i>0 and j>0, we have two cases:
  * If s[i-1] == s1[j-1], we can either use this character to form the
    subsequence or not use it. In the first case, the number of subsequences 
    is M[i-1][j-1], in the second case it is M[i-1][j]. So in this case:
    M[i][j] = M[i-1][j] + M[i-1][j-1]
  * If s[i-1] != s1[j-1], we cannot use this character to form 
    the subsequence, so:
    M[i][j] = M[i-1][j]
So M[i][j] is equal to:
- 1                             if j==0 (the number of empty subsequences
                                in s is 1)
- 0                             if i==0 (the number of non-empty
                                subsequences in an empty string is 0)
- M[i-1][j] + M[i-1][j-1]       if s[i-1] == s1[j-1]
- M[i-1][j]                     otherwise

 j -,b,a,g
i 
| [1,0,0,0]
b [1,1,0,0]
a [1,1,1,0]
b [1,2,1,0]
g [1,2,1,1]
b [1,3,1,1]
a [1,3,4,1]
g [1,3,4,5]
"""

def es2(s, s1):
    n, m = len (s), len(s1)
    # M[i][j] is the number of subsequences of s[:i] that equals s1[:j]

""" result = []
s = "babgbag"
s1 = "bag"
for i in range(len(s)):
    temp = [0] * len(s1)
    charSearchedInSubstr = 0
    j = i

    if s[i]==s1[0]:
        temp[0] = s[i]
        charSearchedInSubstr += 1
        j += 1
    
    while j < len(s)-i:
        if s[j] == s1[charSearchedInSubstr]:
            temp[0]
 """
