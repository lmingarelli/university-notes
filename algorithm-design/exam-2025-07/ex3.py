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
"""
global callNumber
callNumber = 0

def es3(n):
  sol = [[0]*n for _ in range(n)]
  backtrackPerm(n, 0, 0, sol, 0)

def backtrackPerm(n, r, c, sol, callNumber):
  if c == n:
    print("Reached end of row", r, "moving to next row")
    r += 1
    c = 0
  if r == n:
    print("Completed matrix:")
    for k in range(n):
      print(sol[k])
    print()
    return
  A = [0,2]
  if r+c % 2 == 1:
    A = [1,3]
  for val in A:
    sol[r][c] = val
    print("Calling backtrackPerm from call number", callNumber, "with r =", r, "c =", c+1, "sol =", sol)
    backtrackPerm(n, r, c+1, sol, callNumber+1)

es3(2)