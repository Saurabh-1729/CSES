# Kosaraju SCC Proof (Easiest Intuition)

Kosaraju uses **2 DFS passes**:

1. DFS on original graph → store nodes by finishing time
2. DFS on reversed graph in decreasing finish order

This correctly gives SCCs.

---

# First Understand SCC

An SCC means:

```text
Every node can reach every other node.
```

Inside SCC all nodes are mutually connected.

---

# Collapse SCCs into Super Nodes

Imagine each SCC becomes one big node.

Then graph becomes:

```text
DAG (Directed Acyclic Graph)
```

Because if cycle existed between SCCs, they would merge into one SCC.

This is key.

---

# Why Finishing Time Works

Suppose SCC A has edge to SCC B:

```text
A ---> B
```

Then in DFS of original graph:

* If DFS enters A first, it can go into B and finish B first.
* Then A finishes later.

So:

```text
finish(A) > finish(B)
```

Meaning source SCCs get larger finishing times.

---

# Therefore Stack Order Gives:

Nodes of SCCs are popped in:

```text
sources first
```

(of SCC-DAG)

---

# Why Reverse Graph?

If original had:

```text
A ---> B
```

Reversed graph has:

```text
B ---> A
```

Now when we pop A first (source in original), in reversed graph A has no outgoing edge to other unvisited SCCs.

So DFS from A stays only inside A.

That isolates one SCC exactly.

---

# Then Remove It, Repeat

Next popped SCC is next source among remaining graph.

Again DFS in reversed graph captures exactly that SCC.

Repeat until done.

---

# One-Line Proof

```text
Finish times process SCC-DAG in reverse topological order,
and reverse graph prevents crossing into other SCCs.
```

So each DFS gives one SCC.

---

# Super Easy Example

Original:

```text
1 <-> 2     3 <-> 4
   \        ^
    ---->---
```

SCCs:

```text
{1,2}, {3,4}
```

Finish order pushes `{1,2}` later than `{3,4}`.

Reverse graph removes outgoing path from `{1,2}` to `{3,4}`.

DFS on reverse from top node gives only `{1,2}`.

Then next gives `{3,4}`.

---

# Interview 20-second Answer

Kosaraju works because SCC graph is a DAG.
First DFS stores nodes by finish time, which processes SCCs in reverse topological order.
Running DFS on reversed graph from highest finish-time node cannot escape its SCC, so each DFS extracts exactly one SCC.

---
