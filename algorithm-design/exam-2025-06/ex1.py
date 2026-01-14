"""
A directed tree is a rooted tree in which all arches are directed from
parents to children.

Design an algorithm that, given a directed graph represented using
adjacency lists, determines whether the graph is a directed tree, within
a given time bound.

For example, the first graph G is a directed tree; the second graph
is not (because it contains a cycle); and the last graph
is not (because it has two roots).

2-->0---->4
|     |
--->3 -->1-->5


1-->2-->0
|   |
3<---

0--|
   -->2-->3
1--|

To solve this problem we need to check three conditions:
1. The graph must have exactly n-1 arches if it has n nodes.
2. Every node except the root must have exactly one incoming arch.
3. All nodes must be reachable from the root.

The algorithm has complexity O(n), where n is the number of nodes in the graph.
"""

def DFS(u, G, visited):
    visited[u] = 1
    for v in G[u]:
        if not visited[v]:
            DFS(v, G, visited)

def es1(G):
    nNodes = len(G)
    nArches = 0
    # O(n)
    for i in range(nNodes):
        nArches += len(G[i])
    if nArches != nNodes-1:
        print("Number of arches (", nArches, ") is not equal to n-1 (", nNodes-1, ")")
        return False

    # Calculate in-degrees for each node
    # O(n)
    inDegree = [0] * nNodes
    for u in range(nNodes):
        for v in G[u]:
            inDegree[v] += 1
            if inDegree[v] > 1:
                print("Node", v, "has in-degree >", 1)
                return False

    # Search for the root (node with in-degree 0)
    # O(n)
    root = 0
    while inDegree[root] != 0:
        root += 1

    # Check that all nodes are reachable from the root
    # O(n)
    visited = [0] * nNodes
    DFS(root, G, visited)
    if sum(visited) != nNodes:
        print("Not all nodes are reachable from the root")
        return False
    return True

G = [
    [4, 1],   # 0 -> 4, 1
    [5],      # 1 -> 5
    [0, 3],   # 2 -> 0, 3
    [],       # 3 -> none
    [],       # 4 -> none
    []        # 5 -> none
]
print(es1(G))