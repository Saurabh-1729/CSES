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
