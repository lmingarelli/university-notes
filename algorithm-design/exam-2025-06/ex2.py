"""
We want to count ternary strings (composed by 0, 1, and 2)
of length n in which the substrings 12 and 22 do not occur.

For example:
-for n=1 the answer is 3 (the strings are: 0, 1, and 2);
-for n=2 the answer is 6 (the strings are: 00, 01, 02, 10, 11, 20, 21).

Design an algorithm that, given n, solves the problem in O(n) time.

To solve the problem we can use dynamic programming.
Let's use an unidimensional array T of size n + 1 where T[i] contains the number of valid
ternary strings of length i that do not contain the substrings 12 and 22.
T[n] will be our answer.
The base cases are:
-T[0] = 1 (the empty string)
-T[1] = 3 (the strings are: 0, 1, and 2)
For i > 1 we can build valid strings of length i by adding a character to valid strings of length i-1:
-If we add 0 to a valid string of length i-1 we can get a valid string of length i.
-If we add 1 to a valid string of length i-1 we can get a valid string of length i.
-If we add 2 to a valid string of length i-1 we have to make sure that the last character of the string of length i-1 is not 1 or 2.
  Therefore, we can only add 2 to valid strings of length i-2.
This leads us to the recurrence relation:
T[i] = 2 * T[i-1] + T[i-2]
"""

def es2(n):
    if n == 0:
        return 1
    if n == 1:
        return 3
    T = [0] * (n + 1)
    T[0] = 1
    T[1] = 3
    for i in range(2, n + 1):
        T[i] = 2 * T[i-1] + T[i-2]
    return T[n]

# Example usage:
n = 2
print(es2(n))  # Output the number of valid ternary strings of length n
