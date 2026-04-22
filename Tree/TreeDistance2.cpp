````md id="jlwm0j"
# Tree Distances II — Re-rooting DP Explanation

## Problem Goal

For every node in the tree, compute:

```text
sum of distances from that node to all other nodes
````

---

# Core Idea: Re-rooting DP

Instead of running BFS/DFS from every node (`O(n²)`), we solve in:

```text
O(n)
```

using **2 DFS traversals**.

---

# Step 1: Compute Answer for One Root (Node 1)

Assume node `1` is the initial root.

During DFS:

## A. Calculate Distance Sum for Node 1

For each visited node:

```cpp
ans[1] += current_level;
```

Where:

* root level = `0`
* child level = `1`
* grandchild = `2`

So this gives:

```text
sum of distances from node 1 to all nodes
```

---

## B. Calculate Subtree Sizes

For every node `v`:

```text
subtreeSize[v] =
1 + sum of subtree sizes of all children
```

The `1` counts the node itself.

---

# After DFS 1 We Know

* `ans[1]` = total distance sum from node 1
* `subtreeSize[v]` for every node

---

# Step 2: Re-root the Tree

Now move root from parent `u` to child `v`.

We want to compute:

```text
ans[v]
```

from already known:

```text
ans[u]
```

---

# What Changes When Root Moves?

Suppose root shifts:

```text
u  --->  v
```

Then:

## Nodes inside subtree of `v`

Their distance becomes **1 less**

Count:

```text
subtreeSize[v]
```

## Nodes outside subtree of `v`

Their distance becomes **1 more**

Count:

```text
n - subtreeSize[v]
```

---

# Re-root Formula

```cpp
ans[v] = ans[u] - subtreeSize[v] + (n - subtreeSize[v]);
```

---

# Meaning

* subtract nodes getting closer
* add nodes getting farther

---

# Step 3: DFS Again

Run second DFS:

* parent = `u`
* child = `v`

Use formula to compute child answer from parent answer.

---

# Final Complexity

```text
O(n)
```

---

# Memory Trick

When moving root from parent to child:

```text
child subtree gets closer
rest of tree gets farther
```

So:

```cpp
ans[child] = ans[parent] - size[child] + (n - size[child]);
```

---

# Why This Problem Is Important

Teaches:

* Tree DP
* Re-rooting technique
* Subtree size usage
* Interview-grade tree reasoning

```
```
