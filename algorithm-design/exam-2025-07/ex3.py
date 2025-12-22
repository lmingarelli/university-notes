"""
Design an algorithm that, given an integer n, prints all quaternary matrices
(that is, matrices containing integers from 0 to 3) of size n x n in which
cells whose index sum is even contain even numbers, while cells whose index
sum is odd contain only odd numbers.
For example, for n = 2, out of the 4^4 possible 2x2 quaternary matrices, the
following 16 must be printed:
[0,1] [0,1] [0,1] [0,1] [0,3] [0,3] [0,3] [0,3]
[1,0] [1,2] [3,0] [3,2] [1,0] [1,2] [3,0] [3,2]

[2,1] [2,1] [2,1] [2,1] [2,3] [2,3] [2,3] [2,3]
[1,0] [1,2] [3,0] [3,2] [1,0] [1,2] [3,0] [3,2]

The algorithm must run in O(n^2 (S(n))) time, where S(n) is the number of 
matrices to be printed.

Solution
Let's use an backtracking approach to generate all valid quaternary matrices.
To have an algorithmic complexity of O(n^2 * S(n)), we will fill the matrix 
cell by cell, using only values that will lead to valid matrices (when
adding following cells during the recursive calls). To achieve that we can
check that for cells which index sum is even contain 0 or 2, while cells whose
index sum is odd contain 1 or 3.
"""

def es3(n):
  sol = [[0]*n for _ in range(n)]
  backtrackPerm(n, 0, 0, sol)

def backtrackPerm(n, r, c, sol):
  # Move to the next row if we reached the end of the current row
  if c == n:
    r += 1
    c = 0

  # If we filled all rows, print the solution
  if r == n:
    for k in range(n):
      print(sol[k])
    return
  
  # Choose possible values based on the sum of indices
  A = [0,2]
  if r+c % 2 == 1:
    A = [1,3]

  # Choose each value and continue the backtracking
  for val in A:
    sol[r][c] = val
    # Calculate all possibile valid permutations choosing val as sol[r][c]
    backtrackPerm(n, r, c+1, sol)

es3(2)