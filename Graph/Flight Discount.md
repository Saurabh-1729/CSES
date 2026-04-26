````md
# Flight Discount (CSES)

## Problem Idea
Find minimum cost from node `1` to node `n`, where you can apply **50% discount on exactly one edge**.

---

## Core Observation

If discounted edge is:

u -> v (cost = w)

Then total path cost becomes:

dist1[u] + (w / 2) + distN[v]

Where:

- `dist1[u]` = shortest distance from `1` to `u`
- `distN[v]` = shortest distance from `v` to `n`

Take minimum over all edges.

---

## Why Reverse Graph?

We need shortest distance:

v -> n

Instead of running Dijkstra from every node:

- Reverse all edges
- Run Dijkstra from `n`

Then:

distance[n -> v] in reversed graph  
= distance[v -> n] in original graph

So we get all `distN[]` in one run.

---

## Steps

1. Run Dijkstra from `1` on original graph → `dist1[]`
2. Reverse graph
3. Run Dijkstra from `n` on reversed graph → `distN[]`
4. For every edge `(u, v, w)`:

```cpp
answer = min(answer, dist1[u] + w/2 + distN[v]);
````

---

## Complexity

```text
O((N + M) log N)
```

---

## Pattern Learned

```text
Shortest path + preprocess + try each special edge
```

---

## Memory Trick

To know shortest distance **to destination**:

```text
Reverse graph and run from destination.
```

```
```

Yes — **Flight Discount** belongs to an important pattern:

```text id="c4m8p2"
Shortest Path + One Special Operation / Coupon / Modified Edge
```

These are excellent similar problems from different platforms.

---

# 🔥 Very Similar Problems

## 1. LeetCode 2093

**Minimum Cost to Reach City With Discounts**

* You can halve toll cost `k` times.
* State Dijkstra:

```text id="n7q3x1"
(node, discounts_used)
```

Very close to Flight Discount.

---

## 2. LeetCode 787

**Cheapest Flights Within K Stops**

Pattern:

```text id="j6v9t4"
Shortest path with extra state constraint
```

Use BFS / PQ with state.

---

## 3. Codeforces

### Jzzhu and Cities

Shortest path with special train routes.

Need compare normal edges + special edges.

---

## 4. AtCoder

### Shortest Path with Warp / Teleport Once

Many AtCoder problems allow:

```text id="g2p5r8"
use teleport once
use coupon once
change one edge once
```

Same state-Dijkstra pattern.

---

# 🔥 Same Reverse Graph Trick

## 5. CSES Investigation

Shortest path + count routes + min/max edges.

Good after Flight Discount.

---

## 6. Codeforces

Problems asking:

```text id="x8k1m7"
Best path if one edge weight changes
```

Usually solved using:

* dist from source
* dist from destination
* try every edge

Same concept.

---

# 🔥 Advanced Version

## 7. LeetCode 2714 / variants

Use up to K discounts.

State graph:

```text id="u5r2q9"
dist[node][used]
```

---

# Best Practice Order

```text id="v3n6p1"
1. Flight Discount
2. LC 2093
3. LC 787
4. CSES Investigation
5. Any K-discount shortest path
```

---

# Interview Value

This teaches:

```text id="m9w4c7"
Dijkstra + State Compression + Reverse Graph Trick
```

Very useful in product-company rounds.

---

# If you want, I can also give **Top 15 CSES + Leetcode questions grouped by Graph patterns** (Dijkstra, SCC, DSU, Topo, BFS Grid).

