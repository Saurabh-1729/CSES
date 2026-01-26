/*
This is the 2-SAT Problem: 
2-SAT (2-satisfiability) is a computational problem that determines if a Boolean formula, expressed as a Conjunction of clauses (CNF) where each clause has exactly
two literals (variables or their negations), can be satisfied. Unlike general 3-SAT, 2-SAT is solvable in linear time (\(O(n+m)\)) using strongly connected components.
Key Aspects of 2-SAT Problem Structure: It involves assigning True/False values to variables (\(x_{1},x_{2},\dots ,x_{n}\)) 
to satisfy clauses like \((x_{1}\lor \neg x_{2})\).Implicative Form: 2-SAT problems are often solved by converting them into an implication graph, 
where \((A\lor B)\) is represented as \((\neg A\implies B)\) and \((\neg B\implies A)\).Solvability: A 2-SAT instance is unsatisfiable if and
only if \(x\) and \(\neg x\) exist in the same strongly connected component.Efficiency: It is solvable in linear time \(O(V+E)\) using algorithms like
Kosaraju's or Tarjan's. It is widely used to solve problems involving dependency constraints, such as scheduling or circuit design, where choices are limited
to two options. 


Perfect — let’s do this **end-to-end with a concrete example**, and you’ll see *exactly* how SCCs solve it. I’ll keep it intuitive, not code-heavy.

---

## Problem setup (small example)

**Toppings:**
A, B

**People & wishes:**

1. Person 1:

   * A is good **OR** B is good
     → ( A \lor B )

2. Person 2:

   * A is bad **OR** B is good
     → ( \lnot A \lor B )

3. Person 3:

   * A is good **OR** B is bad
     → ( A \lor \lnot B )

Each person needs **at least one wish satisfied**.

---

## Step 1: Convert each clause to implications

Rule:
[
(x \lor y) ;\Longrightarrow; (\lnot x \Rightarrow y)\ \text{and}\ (\lnot y \Rightarrow x)
]

---

### Clause 1: ( A \lor B )

* ¬A → B
* ¬B → A

---

### Clause 2: ( \lnot A \lor B )

* A → B
* ¬B → ¬A

---

### Clause 3: ( A \lor \lnot B )

* ¬A → ¬B
* B → A

---

## Step 2: Build the implication graph 🧠

**Nodes:**
A, ¬A, B, ¬B

**Edges:**

* ¬A → B
* ¬B → A
* A → B
* ¬B → ¬A
* ¬A → ¬B
* B → A

---

## Step 3: Draw the graph (conceptually)

You’ll notice:

* A ↔ B (they imply each other)
* ¬A ↔ ¬B (they imply each other)

But:

* no cycle connects A with ¬A
* no cycle connects B with ¬B

So we’re still safe.

---

## Step 4: Find Strongly Connected Components (SCCs)

**SCCs are groups where everything can reach everything else.**

Here we get:

* SCC₁ = { A, B }
* SCC₂ = { ¬A, ¬B }

Since:

* A and ¬A are in **different SCCs**
* B and ¬B are in **different SCCs**

👉 **Solution exists**

---

## Step 5: Condense SCCs → DAG

Now compress each SCC into a single node:

```
[ ¬A, ¬B ] ─────▶ [ A, B ]
```

This arrow means:

> If you choose ¬A or ¬B, you are forced to choose A and B

---

## Step 6: Assign truth values (the key trick 🔑)

Process SCCs in **reverse topological order** (from sinks):

1. `[ A, B ]` → assign **true**
2. `[ ¬A, ¬B ]` → assign **false**

So:

* A = true
* B = true

---

## Step 7: Check wishes ✅

| Person | Clause | Result |
| ------ | ------ | ------ |
| 1      | A ∨ B  | true   |
| 2      | ¬A ∨ B | true   |
| 3      | A ∨ ¬B | true   |

Everyone’s happy 🎉🍕

---

## Why SCCs make this easy

* SCC = “these literals must share the same truth”
* If a variable and its negation are in the same SCC → ❌ impossible
* Otherwise:

  * DAG gives safe assignment order
  * No backtracking needed

---

## Mental shortcut to remember

> **SCCs detect unavoidable consequences.**
> If choosing A *forces* ¬A and vice versa → contradiction.
> Otherwise, choose values from the “end” of the implication chain.

---

If you want, next I can:

* show a **contradiction example**
* map this directly to **Kosaraju/Tarjan**
* or show **why reverse topo order works** step-by-step

*/
