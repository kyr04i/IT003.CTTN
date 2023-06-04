# Kruskal's Algorithm for Minimum Spanning Tree
This repository contains an implementation of Kruskal's algorithm in C++ for finding the minimum spanning tree of a weighted graph. The algorithm is implemented in the [kruskal.cpp](https://github.com/w1n-gl0ry/IT003.CTTN/blob/main/Project3/kruskal.cpp) file.

> Kruskal's Algorithm
Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, weighted graph. The MST is a subgraph that connects all the vertices of the graph with the minimum possible total edge weight.

The algorithm works as follows:

Sort all the edges of the graph in non-decreasing order of their weights.
Create an empty graph to store the MST.
Iterate over the sorted edges in the order of their weights.
For each edge, if adding it to the MST does not create a cycle, add it to the MST.
Repeat step 4 until all vertices are connected or there are n-1 edges in the MST (where n is the number of vertices in the original graph).
Kruskal's algorithm uses a disjoint set data structure to efficiently detect cycles in the graph and determine whether two vertices belong to the same connected component.

Input Format

The input graph is read from a text file named [Graph.TXT](https://github.com/w1n-gl0ry/IT003.CTTN/blob/main/Project3/Graph.TXT). The file format is as follows:

The first line contains a single integer, n, which represents the number of vertices in the graph.
The next n lines contain n space-separated integers. The value in the i-th row and j-th column represents the weight of the edge between vertex i and vertex j.

Output Format

The resulting minimum spanning tree is written to a text file named [Kruskal.TXT](https://github.com/w1n-gl0ry/IT003.CTTN/blob/main/Project3/Kruskal.TXT). The file contains a single line with the weight of the MST rounded to two decimal places.

Code Explanation

The provided [kruskal.cpp](https://github.com/w1n-gl0ry/IT003.CTTN/blob/main/Project3/kruskal.cpp) file implements Kruskal's algorithm using the disjoint set data structure. Here's a brief explanation of the code:

The FindRoot function finds the root of a given vertex in the disjoint set.
The UnionSet function merges two disjoint sets by updating their root.
The krus structure represents an edge in the graph, containing its weight and the vertices it connects.
The cmp function is used for sorting the edges based on their weights.
The solve function reads the input graph, sorts the edges, applies Kruskal's algorithm, and writes the result to the output file.

Usage

To run the code and generate the minimum spanning tree:

Make sure you have a C++ compiler installed.
Clone this repository to your local machine.
Place the input graph in a file named Graph.TXT in the same directory.
Compile and run the kruskal.cpp file using your preferred C++ compiler.
The resulting minimum spanning tree weight will be written to the Kruskal.TXT file.
Feel free to modify the input graph and experiment with different scenarios.

If you have any questions or suggestions, feel free to reach out. Happy coding!

> Author: w1n_gl0ry
