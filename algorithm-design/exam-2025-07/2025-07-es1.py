"""
We have an undirected and connected graph G with n nodes and a node s of G.
We want to find out how many nodes are at minimum distance i from s, for 0 < i ≤ n.
Design an algorithm that, given the adjacency matrix M of graph G and the node s,
returns a list A of n elements where A[i] contains the number of nodes at distance i from s.
For example, the graph G in the figure:

3--2--0--5
|    /
4--1
"""

# Adjacency matrix

def minDistancesBFS(s, M):
    # Return a vector containing the distances of every node from s
    nRows = len(M) 
    # Distance of all nodes from s
    minDistances = [-1] * nRows     
    minDistances[s] = 0
    queue = [s]
    i = 0

    while len(queue) > i:
            currentNode = queue[i]
            i += 1
            # Loop every column of the matrix
            for j in range(n):         
                # If there is an arch between currentNode and j and no 
                # distance from s has been registered
                if M[currentNode][j] == 1 and minDistances[j] == -1:       
                    minDistances[j] = minDistances[currentNode] + 1
                    queue.append(j)
    return minDistances                    

M = [
    [0,1,1,0,0,1],
    [1,0,0,0,1,0],
    [1,0,0,1,0,0],
    [0,0,1,0,1,0],
    [0,1,0,1,0,0],
    [1,0,0,0,0,0]
]
startingNode = 2
minDistances = minDistancesBFS(startingNode, M)
# Following the example, and using 2 as a starting node this array should be 
# [1,2,0,1,2,2]
targetDistance = 1

