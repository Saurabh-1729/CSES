/*
Ah, this one is a **classic** — and the intuition is very clean once you see the right lens. This is the *postal worker problem*, aka **Eulerian circuit**.

Let’s build the intuition, not jump to algorithms yet.

---

## 1. Read the requirement very literally 📬

You want a route that:

* starts at **post office = node 1**
* ends at **node 1**
* goes through **every street exactly once**
* streets are **undirected**

That sentence *is* the definition of an **Eulerian circuit** in an undirected graph.

So mentally rename the problem as:

> “Does this graph have an Eulerian circuit starting at node 1?
> If yes, print one.”

---

## 2. What makes an Eulerian circuit possible?

Forget algorithms for a second. Think physically:

When you enter a crossing along a street,
you must leave along another unused street —
otherwise you’d get stuck.

So **streets at a crossing must come in pairs**.

That gives the first key rule:

### 🔑 Rule 1: Every vertex must have even degree

* Each crossing has an even number of streets connected to it
* Including the post office

If *any* node has odd degree → **IMPOSSIBLE**

---

## 3. Connectivity intuition 🧠

Even degrees aren’t enough.

Imagine two separate street networks:

* Both have even degrees
* But they’re disconnected

You can’t cover both in one walk.

### 🔑 Rule 2: All crossings with streets must be connected

* Ignoring isolated nodes with degree 0
* From node 1, you must be able to reach all streets

Otherwise → **IMPOSSIBLE**

---

## 4. If both rules hold, why does a route exist?

This is the beautiful part.

Because:

* You can always “enter and leave” each crossing
* You never get stuck early
* When you return to the start, all streets are used

This is not magic — it’s a proven theorem (Euler, 1736 🐐).

So once the conditions hold:

> A solution is *guaranteed* to exist.

---

## 5. How do you actually *find* the route?

Now the algorithm intuition (not code yet):

### Hierholzer’s idea (intuitive version)

1. Start at node 1
2. Keep walking unused streets arbitrarily
3. When you get stuck, you’ve formed a **cycle**
4. If unused streets remain:

   * Jump to a node on your current cycle that still has unused streets
   * Walk another cycle
   * Splice it in
5. Repeat until all streets are used

This works **because degrees are even**, so you can always leave when you enter.

---

## 6. Why the output looks “weird” but valid

Example output:

```
1 2 6 3 2 4 5 3 1
```

Notice:

* Nodes repeat — that’s normal
* Streets do **not** repeat — that’s the rule
* Start and end at 1 ✅
* All 8 streets used exactly once ✅

This is expected for Eulerian circuits.

---

## 7. Mental checklist for this problem ✅

When you see:

* “start and end at same node”
* “use every edge exactly once”
* “undirected graph”

Your brain should immediately say:

> **Eulerian circuit**

Then check:

1. All degrees even?
2. All nonzero-degree nodes reachable from start?

If yes → construct with Hierholzer
If no → `IMPOSSIBLE`

---

## 8. One-sentence intuition takeaway

> **If every crossing lets you enter and leave cleanly, and the city is all connected, you can deliver mail on every street without repeating a single one.**

If you want next, I can:

* show **why odd degree breaks everything**
* walk through **Hierholzer step-by-step on the example**
* or contrast this with **Eulerian path (start ≠ end)**

*/
