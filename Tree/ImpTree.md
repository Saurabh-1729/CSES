# CSES Tree Problems – Concepts Cheat Sheet

## 1. Subordinates
**Concept:** DFS + Subtree Size

Count number of nodes in each employee's subtree.

---

## 2. Tree Matching
**Concept:** Tree DP

Maximum matching in tree where one node can belong to at most one selected edge.

---

## 3. Tree Diameter
**Concept:** Double DFS / BFS

Run DFS from any node → farthest node A  
Run DFS from A → farthest node B  
Distance(A, B) = Diameter

---

## 4. Tree Distances I
**Concept:** Diameter Endpoints Trick

For every node:

dist[node] = max(distance from endpoint1, distance from endpoint2)

---

## 5. Tree Distances II
**Concept:** Re-rooting DP

Find sum of distances from every node to all others.

Formula:

ans[child] = ans[parent] - size[child] + (n - size[child])

---

## 6. Company Queries I
**Concept:** Binary Lifting

Find k-th ancestor of a node.

2^j ancestor table.

---

## 7. Company Queries II
**Concept:** LCA + Binary Lifting

Find Lowest Common Ancestor of two nodes.

---

## 8. Distance Queries
**Concept:** LCA + Distance Formula

distance(u,v) = depth[u] + depth[v] - 2 * depth[lca]

---

## 9. Counting Paths
**Concept:** Path Contribution + LCA + DFS Accumulation

Mark endpoints and propagate counts upward.

---

## 10. Subtree Queries
**Concept:** Euler Tour + Fenwick Tree / Segment Tree

Flatten subtree into contiguous range.

---

## 11. Path Queries
**Concept:** Euler Tour + Segment Tree

Root-to-node / path updates and queries.

---

## 12. Path Queries II
**Concept:** Heavy Light Decomposition (HLD)

Break tree into chains for path queries.

---

## 13. Distinct Colors
**Concept:** DSU on Tree / Small to Large Merging

Maintain subtree color sets efficiently.

---

## 14. Finding a Centroid
**Concept:** Subtree Size

Node where every child subtree size ≤ n/2.

---

## 15. Fixed-Length Paths I
**Concept:** Centroid Decomposition

Count paths with exact length `k`.

---

## 16. Fixed-Length Paths II
**Concept:** Centroid Decomposition + Range Count

Count paths with length in range [a, b].

---

````md
# CSES Tree Problems (High ROI for Software Engineer Interviews)

## Priority Order

1. **Subordinates**  
   Compute subtree sizes using DFS.

2. **Tree Diameter**  
   Find the longest path in a tree.

3. **Tree Distances I**  
   Distance of each node to the farthest node.

4. **Tree Matching**  
   Tree DP for maximum matching.

5. **Company Queries I**  
   K-th ancestor using Binary Lifting.

6. **Company Queries II**  
   Lowest Common Ancestor (LCA).

7. **Distance Queries**  
   Distance between two nodes using LCA.

8. **Tree Distances II**  
   Sum of distances using rerooting DP.

9. **Subtree Queries**  
   Euler Tour + Segment Tree / Fenwick Tree.

10. **Distinct Colors**  
    DSU on Tree / Small-to-Large merging.

11. **Finding a Centroid**  
    Find balanced center of a tree.

---

# Binary Lifting (Layman Terms)

## Plain English

The `2^j`-th ancestor of node `i` is:

- first jump `2^(j-1)` upward
- then from there jump another `2^(j-1)` upward

## One-Line Memory Trick

> **Jump half the distance twice**

---

# Example

To find the `8th` ancestor:

- jump 4 up
- then another 4 up

To find the `16th` ancestor:

- jump 8 up
- then another 8 up

---

# Why It Is Powerful

Instead of moving one parent at a time:

```text
node -> parent -> parent -> parent ...
````

We precompute jumps:

```text
1 step
2 step
4 step
8 step
16 step
```

So we can move upward in **O(log N)** time.

---

# Core Formula

```cpp
up[node][j] = up[ up[node][j-1] ][j-1];
```

Meaning:

The `2^j` ancestor = ancestor after two `2^(j-1)` jumps.

---

# Used In

* K-th ancestor queries
* Lowest Common Ancestor (LCA)
* Distance between nodes
* Fast tree queries



My Honest Recommendation For You

Do:

Must Solve
Course Schedule II
Network Breakdown
New Flight Routes
If Extra Time
Graph Girth
MST Edge Check
Visiting Cities

Skip rest for now.

