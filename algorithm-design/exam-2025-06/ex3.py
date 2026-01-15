""""
Design an algorithm that, given an integer n, prints all binary
matrices of size n*n in which each row contains an even number
of ones.
For example, for n=2, out of the 16 possible 2*2 binary
matrices, the following 4 must be printed.

0 0     0 0     1 1     1 1
0 0     1 1     0 0     1 1

The algorithm must have time complexity O(n^2 * S(n)), where
S(n) is the number of matrices to be printed.
"""

def printBinMatrixBacktracking(c, r, n, matrix):
    if c == n:
        r += 1
        c = 0

    # If we filled all rows, print the solution
    if r == n:
        # O(n)
        for k in range(n):
            # O(n)
            print(matrix[k])
        print("\n")  # Print a blank line between matrices
        return

    possibleValues = [0, 1]

    # If we are at the last column, we must ensure
    # the row has an even number of 1s
    if c == n-1:
        rowSum = 0
        # Using len(matrix[r]) - 1 to avoid using the value of the last
        # column cell, because it can be contaminated
        # by previous recursive calls.
        # O(n)
        for i in range(len(matrix[r]) - 1):
            if matrix[r][i] == 1:
                rowSum += 1

        if rowSum % 2 == 0:
            # if the sum is even, we can only place 0
            possibleValues = [0]
        else:
            # if the sum is odd, we can only place 1
            possibleValues = [1]

    for val in possibleValues:
        matrix[r][c] = val
        printBinMatrixBacktracking(c + 1, r, n, matrix)

def es3(n):
    matrix = [[0] * n for _ in range(n)]
    printBinMatrixBacktracking(0, 0, n, matrix)

es3(2)

"""
Let's assume that the number of matrices printed is S(n).
To calculate the cost of the algorithm we can observe that:
1. To print the matrix we need O(n) time for n times so the total cost is O(n^2)
2. To check the sum of the row we need O(n) time. This has to be done for each
    of the n rows so the total cost is O(n^2).
3. To assign a value to a cell we need O(1) time. This has to be done for each
    of the n^2 cells so the total cost is O(n^2).
Each of these 3 points has to be done for each of the S(n) matrices printed.
Therefore, the total complexity of the algorithm is: O(n^2) * S(n)
"""