include "globals.mzn";

int: n;

array[1..n] of var 1..n: X;

constraint
    alldifferent(X);

constraint
    forall(i, j in 1..n where i < j) (
        abs(X[i] - X[j]) != abs(i - j)
    );

solve satisfy;

output [
    "X = ", show(X), "\n"
];