Nice, this is another **classic tree → array transformation** problem.
Let’s *only* focus on the **intuition**, not code yet.

---

## First: what is the question really asking?

You are given:

* A **tree rooted at node 1**
* Each node has a **value**
* Two operations:

  1. **Update** the value of one node
  2. **Query**: sum of values in the **subtree** of a node `s`

👉 The subtree of `s` means:

* `s`
* all descendants of `s` (children, children of children, etc.)

---

## The core difficulty 🤔

In a tree:

* Nodes in a subtree are **not stored contiguously**
* A subtree can have **O(n)** nodes

If for every query you:

* Traverse the subtree and sum values → **too slow**

So the question becomes:

> How can we make *each subtree* look like a **continuous segment**?

---

## Key intuition: Flatten the tree 🌳 → 📏

We do a **DFS traversal** and assign each node a time when we first visit it.

This is called:

* Euler Tour
* DFS order
* Tree flattening

---

## What DFS gives us (magic property ✨)

When you do DFS from the root:

* All nodes in the subtree of `s` are visited **in one continuous interval**
* No interruptions

So for every node `s`, we can record:

* `in[s]` → time when DFS enters `s`
* `out[s]` → time when DFS finishes visiting `s`’s subtree

Then:

```
subtree(s) = nodes with indices in [in[s], out[s]]
```

This is the **entire intuition** of the problem.

---

## Visual example

Tree:

```
    1
   / \
  2   3
     / \
    4   5
```

DFS order:

```
1 → 2 → 3 → 4 → 5
```

Assign times:

```
node : in
1 : 1
2 : 2
3 : 3
4 : 4
5 : 5
```

Subtrees:

* subtree(3) = `{3,4,5}` = interval `[3,5]`

---

## Now the problem becomes an array problem 📦

After flattening:

* Each node’s value is placed at position `in[node]` in an array

Operations become:

1. **Update one index**
2. **Query sum of a range**

That’s it.

---

## What data structure fits perfectly?

You need:

* Point updates
* Range sum queries

Classic choices:

* **Fenwick Tree (BIT)**
* **Segment Tree**

Both work in `O(log n)`.

---

## Why this is efficient 🚀

* DFS preprocessing: `O(n)`
* Each query: `O(log n)`
* Works for `2 × 10^5` easily

---

## One-sentence intuition to remember 🧠

> Flatten the tree with DFS so that every subtree becomes a contiguous array segment, then use a range-sum data structure.

---


You’re thinking in exactly the right direction 👍
This is a **classic subtree query** problem: flatten the tree with DFS + use a Fenwick Tree (or Segment Tree) for range sums.

I’ll show you a **clean, efficient C++ solution** using:

* DFS to assign **entry times** (`tin`)
* Subtree of a node becomes a **contiguous range**
* Fenwick Tree (BIT) for:

  * point update
  * range sum query

This runs in **O((n+q) log n)** and fits the constraints.

---

## Key Idea (quick recap)

After DFS:

* Each node `u` gets a time `tin[u]`
* Subtree of `u` occupies:

  ```
  [ tin[u], tout[u] ]
  ```

So:

* Update node value → update one index in BIT
* Query subtree sum → range sum in BIT

---

## C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200000;
vector<int> tree[MAXN + 1];
int tin[MAXN + 1], tout[MAXN + 1];
int timer = 0;
ll value[MAXN + 1];

/* Segment Tree */
struct SegmentTree {
    int n;
    vector<ll> seg;

    SegmentTree(int n) : n(n) {
        seg.assign(4 * n, 0);
    }

    void build(int idx, int l, int r, vector<ll>& arr) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx, l, mid, arr);
        build(2 * idx + 1, mid + 1, r, arr);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    void update(int idx, int l, int r, int pos, ll val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    ll query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) +
               query(2 * idx + 1, mid + 1, r, ql, qr);
    }
};

void dfs(int u, int parent) {
    tin[u] = ++timer;
    for (int v : tree[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }
    tout[u] = timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // Flatten tree
    dfs(1, 0);

    // Create flattened array
    vector<ll> flat(n + 1);
    for (int i = 1; i <= n; i++) {
        flat[tin[i]] = value[i];
        // basically the nodes are visited in contgous order and indexing them on tin basis make sense.
    }

    // Build segment tree
    SegmentTree st(n);
    st.build(1, 1, n, flat);

    // Process queries
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            ll x;
            cin >> s >> x;
            value[s] = x;
            st.update(1, 1, n, tin[s], x);
        } else {
            int s;
            cin >> s;
            cout << st.query(1, 1, n, tin[s], tout[s]) << '\n';
        }
    }

    return 0;
}

```

---

## Why this works

* DFS turns tree → array
* Subtree = continuous segment
* Fenwick Tree gives fast updates & queries

---

If you want:

* a **Python version**
* a **Segment Tree version**
* or a **step-by-step DFS walkthrough on the example**

just tell me 👌
