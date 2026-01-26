/*
Ahh, this is another one of those problems where the *right mental model* makes it feel obvious instead of scary. Let’s build the intuition step by step.

---

## 1. What are you *really* allowed to do?

* You can start **anywhere**
* You can end **anywhere**
* You move along **directed tunnels**
* You collect **all coins in rooms you visit**
* You want the **maximum possible sum**

⚠️ Important subtlety:
If you can revisit a room, you **don’t get extra coins again**. So looping forever doesn’t help — coins are collected once.

---

## 2. First key realization: cycles change everything 🔄

If the graph had **no cycles**, this would just be:

> “Find the maximum-weight path in a DAG”

But the graph **can have cycles**.

Example:

```
1 → 2
↑   ↓
← ← ←
```

Inside a cycle:

* Once you enter it, you can visit **all rooms in that cycle**
* Order doesn’t matter
* You can grab **all their coins**

👉 So the *best strategy* is:

> If you ever enter a cycle, you should collect **everything in it**

This is the first big insight.

---

## 3. Strongly Connected Components = “super rooms” 🧠

A **Strongly Connected Component (SCC)** is:

> A set of rooms where every room can reach every other room

Inside an SCC:

* You can traverse all rooms
* You can collect all coins
* It behaves like **one big room**

So:

* Collapse each SCC into a single node
* Sum all coins inside it

Now the problem changes shape dramatically.

---

## 4. What does the graph look like after SCC compression?

After collapsing SCCs:

* Each SCC → one node
* Edges between SCCs form a **DAG**
* Each node has a **weight** = sum of coins in that SCC

Why DAG?

* Because SCC compression **removes all cycles**

So now we have:

> A **DAG with weighted nodes**

🎯 Goal:

> Find the **maximum-weight path** in this DAG
> (start and end anywhere)

---

## 5. This becomes a clean DP problem 📈

On a DAG:

* You can do **DP with topological order**

Let:

```
dp[v] = maximum coins collectible ending at SCC v
```

Transition:

```
dp[v] = weight[v] + max(dp[u]) over all u → v
```

If no incoming edges:

```
dp[v] = weight[v]
```

The answer is simply:

```
max(dp[v]) over all SCCs
```

---

## 6. Apply this intuition to the example

### Input

```
Rooms: 4
Coins: [4, 5, 2, 7]

Edges:
1 → 2
2 → 1
1 → 3
2 → 4
```

---

### Step 1: Find SCCs

* {1, 2} is an SCC (cycle)
* {3} alone
* {4} alone

---

### Step 2: Build condensed graph

**SCC weights:**

* SCC(1,2): 4 + 5 = 9
* SCC(3): 2
* SCC(4): 7

**Edges:**

* (1,2) → 3
* (1,2) → 4

Graph:

```
   [1,2:9]
    /   \
 [3:2] [4:7]
```

---

### Step 3: DP on DAG

* dp[1,2] = 9
* dp[3] = 9 + 2 = 11
* dp[4] = 9 + 7 = 16

Answer = **16** ✅

Path:

```
1 → 2 → 4
```

---

## 7. Intuition in one paragraph 🧠✨

Cycles mean “once you enter, you can take everything.”
So collapse cycles into single super-nodes using SCCs.
This turns the graph into a DAG where each node has a coin value.
Then the problem becomes: *what’s the maximum-weight path in a DAG?*
That’s just DP.

---

## 8. One-sentence takeaway

> **SCCs turn a messy cyclic graph into a clean DAG where greedy looping becomes structured DP.**

If you want next, I can:

* walk through **the exact algorithm order**
* show **why starting anywhere matters**
* or compare this to **longest path vs shortest path problems**

*/
