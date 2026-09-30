int: m = 19;
int: ntri = 8;

array[1..m] of var 1..3: color;

array[1..ntri, 1..3] of int: triangles =
    array2d(1..ntri, 1..3,
    [
        3, 5, 6,       % H-A-E
        4, 5, 7,       % H-I-A
        10, 12, 15,    % B-S-C
        15, 17, 19,    % B-C-G2
        16, 17, 18,    % B-J-G2
        11, 12, 14,     % S-D-C
        1, 2, 3,        % G1-H-E
        3, 5, 6        % H-A-E
    ]);

constraint
    forall(t in 1..ntri) (
        not (
            color[triangles[t,1]] =
            color[triangles[t,2]] /\
            color[triangles[t,2]] =
            color[triangles[t,3]]
        )
    );

solve satisfy;

output [
    "color = ", show(color), "\n"
];