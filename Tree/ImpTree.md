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

