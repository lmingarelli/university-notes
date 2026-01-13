"""
We have an undirected and connected graph G with n nodes and a node s of G.
We want to find out how many nodes are at minimum distance i from s, for 0 < i <= n.
Design an algorithm that, given the adjacency matrix M of graph G and the node s,
returns a list A of n elements where A[i] contains the number of nodes at distance i from s.
For example, the graph G in the figure:

3--2--0--5
|    /
4--1

s=2 --> A = [1,2,3,0,0,0]
s=5 --> A = [1,1,2,2,0,0]
"""

def distancesBFS(s, M):
    # Return a vector containing the distances of every node from s
    nRows = len(M)
    # dist[i] is the distance between the the node i and the node s
    dist = [-1] * nRows
    dist[s] = 0
    # Queue of nodes to visit
    queue = [s]
    i = 0

    # This cycle costs O(n) (one cycle for every node in the graph)
    while len(queue) > i:   
            currentNode = queue[i]
            i += 1
            # Loop every column of the matrix
            # Its cost is O(n) 
            for j in range(nRows):      
                # If there is an arch between currentNode and j and no
                # distance from s has been registered
                if M[currentNode][j] == 1 and dist[j] == -1:
                    dist[j] = dist[currentNode] + 1
                    queue.append(j)
    return dist

# Adjacency matrix
M = [
    [0,1,1,0,0,1],
    [1,0,0,0,1,0],
    [1,0,0,1,0,0],
    [0,0,1,0,1,0],
    [0,1,0,1,0,0],
    [1,0,0,0,0,0]
]
startingNode = 2
distances = distancesBFS(startingNode, M)
# Following the example, and using 2 as a starting node this array should be 
# [1,2,0,1,2,2]
targetDistance = 1
# A is the array we have to return
A = [0] * len(M)
for i in range(len(distances)):
    A[ distances[i] ] += 1

"""
Complexity is O(n) * O(n) = O(n^2)
The algorithm correctly calculate the requested list A:
1.  It calculate the vector minDistances containing the minimum distance from 
    s of all the graph nodes.
2.  Create the vector A initializing it with all zeros
3.  Uses the info inside minDistances to insert the values into the array A
"""