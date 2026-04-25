# Coin Collector — Core Idea

This is one of the best **SCC + DAG DP** problems.

---

# Problem Meaning

Each node has coins.

Directed edges allow movement.

You can start anywhere and move along directions.

Need:

```text id="7fgq8y"
maximum coins collectable
```

---

# Why Normal DFS Fails

Graph may contain cycles:

```text id="ov5u4v"
1 -> 2 -> 3 -> 1
```

Inside cycle you can visit all nodes.

So cycle nodes behave like **one component**.

That screams:

```text id="j7zqjx"
SCC
```

---

# Step 1: Compress SCCs

Find strongly connected components.

Inside one SCC:

* every node reachable from every node
* so you can collect all coins in that SCC

Let:

```text id="clye61"
value[SCC] = sum of node coins inside it
```

---

# Step 2: Build SCC DAG

Each SCC becomes one node.

If edge exists:

```text id="b2mb4c"
u in SCC A -> v in SCC B
```

and `A != B`

Then create:

```text id="8upgmy"
A -> B
```

Now graph becomes:

```text id="fmyvfe"
DAG
```

(no cycles)

---

# Step 3: DP on DAG

Now answer becomes:

```text id="z8n55f"
max path sum in DAG
```

Define:

```cpp id="5mgm4r"
dp[x] = max coins collectable starting from SCC x
```

Transition:

```cpp id="n4n6m7"
dp[x] = value[x] + max(dp[child])
```

If no child:

```cpp id="myk4zt"
dp[x] = value[x]
```

Final answer:

```text id="m9f1pm"
max(dp[x]) for all SCCs
```

---

# Full Thought Process

Original hard graph with cycles
⬇
Turn cycles into single nodes
⬇
Now acyclic graph
⬇
Run DP

---

# Example

Coins:

```text id="83q0oz"
1:5  2:3  3:4  4:10
```

Edges:

```text id="23l2qs"
1->2
2->3
3->1
3->4
```

SCC:

```text id="7sww42"
{1,2,3} = 12 coins
{4} = 10 coins
```

DAG:

```text id="5m6zrv"
A -> B
```

Answer:

```text id="w3rk2v"
12 + 10 = 22
```

---

# What This Problem Teaches

* Kosaraju / Tarjan
* Graph compression
* DP on DAG

Very interview-useful pattern.

---
