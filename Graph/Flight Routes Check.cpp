/*
This is a **great graph-intuition question**. It’s actually simpler than it first looks once you spot the key idea.

This is **CSES – Flight Routes Check**, and the core concept is **strong connectivity**.

---

## 🧠 Rephrase the problem (important)

> “Can you travel from **any** city to **any other** city using directed flights?”

That is exactly the definition of a **strongly connected directed graph**.

So the question becomes:

> Is the directed graph **strongly connected**?

---

## 💡 Key intuition (the trick)

You **do NOT** need to check every pair of cities (that would be insane).

Instead:

### A directed graph is strongly connected **iff**:

1. From some city `s`, you can reach **all** other cities
2. In the **reversed graph**, from the same `s`, you can reach **all** other cities

That’s it.
This is the whole intuition.

---

## 🔄 Why does this work?

* Condition 1 ensures: `s → every city`
* Condition 2 ensures: `every city → s`
* Combine them ⇒ every city can reach every other city

This is basically **Kosaraju’s idea**, but we don’t even need full SCC computation.

---

## 🪜 Step-by-step plan

1. Pick any city (city `1`)
2. Run DFS/BFS from city `1`

   * If some city `x` is **not visited** → `1 → x` is impossible
     Output: `NO` and `1 x`
3. Reverse all edges
4. Run DFS/BFS again from city `1`

   * If some city `x` is **not visited** → `x → 1` is impossible
     Output: `NO` and `x 1`
5. If both passes succeed → print `YES`

---

## 🔍 Small example

### Example where answer is NO

```
1 → 2 → 3
```

* From `1`, you can reach everyone ✅
* But in reversed graph:

```
1 ← 2 ← 3
```

From `1`, you **cannot** reach `3`

So:

```
NO
3 1
```

---

## 🧠 Mental model

Think of it like:

* Can everyone **hear** city 1?
* Can city 1 **hear** everyone?

If yes → all communication is possible.

---

## ⚡ Complexity

* Two DFS/BFS runs
* **O(n + m)** time
* Very efficient

---

## 🧩 Why not just SCCs?

You *could* use Kosaraju or Tarjan, but:

* Overkill
* Problem only asks **YES/NO + one bad pair**

This 2-DFS trick is cleaner.

---

## ✨ TL;DR Intuition

* This is a **strong connectivity check**
* One DFS on original graph
* One DFS on reversed graph
* If either fails → print a counterexample

---

If you want, next I can:

* give **exact C++ code**
* draw a **visual intuition**
* explain **why this finds a valid a, b**
* compare with SCC approaches

Just say the word 👌

*/
