"""
Design an algorithm that, given an undirected graph G represented using
adjacency lists, returns a list of arches of minimum size needed to make
the graph connected.

If the graph is already connected, the list should be empty.

If the graph has c>1 connected components, the list should contain c-1 arches.

For example, for the graph in the figure, which has 3 connected components, one
possible solution is [ (1,5), (7,6)].

6--3    7--5    1--4
        |  |    |  |
        2--|    0--|

The proposed algorithm must have a running time of Theta(n+m), where
n and m are the number of nodes and arches of the graph, respectively.
"""

def es1(G):
    n = len(G)
    visited = [False] * n
    components = []

    # O(n + m)
    def dfs(node, component):
        visited[node] = True
        component.append(node)
        for neighbor in G[node]:
            if not visited[neighbor]:
                dfs(neighbor, component)

    # O(n)
    for i in range(n):
        if not visited[i]:
            component = []
            dfs(i, component)
            components.append(component)

    # O(n)
    arches_to_add = []
    for i in range(1, len(components)):
        arches_to_add.append((components[i-1][0], components[i][0]))

    return arches_to_add

# Example usage:
G = [
    [4, 1],
    [4, 0],
    [5, 7],
    [6],
    [0, 1],
    [2, 7],
    [3],
    [2, 5]
]
print(es1(G))

