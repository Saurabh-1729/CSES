# CSES Graph Problems → Concepts Mapping

---

## Basic Graph Traversal

### Counting Rooms
- Grid DFS / BFS
- Connected Components

### Labyrinth
- Grid BFS
- Shortest Path
- Path Reconstruction

### Building Roads
- Connected Components
- DFS / DSU

### Message Route
- BFS Shortest Path
- Parent Tracking

### Building Teams
- Bipartite Graph
- 2 Coloring
- BFS / DFS

### Round Trip
- Cycle Detection in Undirected Graph
- DFS Parent Tracking

### Monsters
- Multi-source BFS
- Escape Path
- Grid shortest path

---

# Shortest Paths

### Shortest Routes I
- Dijkstra

### Shortest Routes II
- Floyd Warshall
- All Pair Shortest Path

### High Score
- Bellman Ford
- Positive/Negative Cycle Reachability

### Flight Discount
- Dijkstra with State
- One discounted edge

### Cycle Finding
- Bellman Ford
- Negative Cycle Detection

### Flight Routes
- K Shortest Paths
- Priority Queue

### Investigation
- Dijkstra
- Count shortest paths
- Min/Max edges on shortest path

---

# DAG / Topological Sort

### Round Trip II
- Directed Cycle Detection
- DFS Colors

### Course Schedule
- Topological Sort (Kahn / DFS)

### Longest Flight Route
- Longest Path in DAG
- DP + Toposort

### Game Routes
- Count paths in DAG
- DP + Toposort

---

# Functional Graph / Binary Lifting

### Planets Queries I
- Binary Lifting
- K-th successor

### Planets Queries II
- Functional Graph
- Binary Lifting
- Cycle + distance queries

### Planets Cycles
- Functional Graph
- Cycle length
- Distance to cycle

---

# MST / DSU

### Road Reparation
- Minimum Spanning Tree
- Kruskal / Prim

### Road Construction
- DSU
- Components count
- Largest component after each union

---

# SCC / Strong Connectivity

### Flight Routes Check
- Strong Connectivity Check
- Kosaraju / Tarjan

### Planets and Kingdoms
- Strongly Connected Components

### Coin Collector
- SCC Compression DAG
- DP on DAG

### Giant Pizza
- 2-SAT
- SCC

---

# Euler Path / Circuit

### Mail Delivery
- Euler Circuit (Undirected)

### Teleporters Path
- Euler Path (Directed)

### De Bruijn Sequence
- Eulerian Path on De Bruijn Graph

---

# DP on Bitmask / Advanced Paths

### Hamiltonian Flights
- Bitmask DP
- Hamiltonian Path Count

### Knight's Tour
- Backtracking
- Warnsdorff heuristic

---

# Max Flow / Matching

### Download Speed
- Max Flow
- Edmonds Karp / Dinic

### Police Chase
- Max Flow / Min Cut

### School Dance
- Bipartite Matching
- Max Flow / Hopcroft Karp

### Distinct Routes
- Edge-disjoint Paths
- Max Flow

---

# Highest ROI for Interviews

## Must Know
- Counting Rooms
- Labyrinth
- Building Roads
- Message Route
- Building Teams
- Round Trip
- Shortest Routes I
- Course Schedule
- Road Reparation
- Flight Routes Check

## Strong Candidate
- High Score
- Flight Discount
- Investigation
- Coin Collector
- Giant Pizza

## Advanced / CP Heavy
- Hamiltonian Flights
- De Bruijn Sequence
- Max Flow set
- Planets Queries II

---

# ⭐ Tier 1 — ABSOLUTE MUST-KNOW (asked all the time)

If you do **only these**, you’re already in very good shape.

## 🔹 Graph traversal (DFS / BFS)

### ✅ Counting Rooms

📌 **Concept:** Grid DFS/BFS
📌 **Interview use:** Flood fill, islands, connected components
💬 *Extremely common*

---

### ✅ Labyrinth

📌 **Concept:** BFS + path reconstruction
📌 **Interview use:** Shortest path in grid
💬 *Classic maze problem*

---

### ✅ Message Route

📌 **Concept:** BFS in unweighted graph
📌 **Interview use:** Shortest path, parent tracking
💬 *Bread-and-butter BFS*

---

### ✅ Building Roads

📌 **Concept:** Connected components
📌 **Interview use:** “How many edges to connect graph?”
💬 *Very popular conceptual question*

---

## 🔹 Graph properties

### ✅ Building Teams

📌 **Concept:** Bipartite graph (2-coloring)
📌 **Interview use:** Conflict graphs, grouping problems
💬 *Extremely common*

---

### ✅ Round Trip

📌 **Concept:** Cycle detection (undirected)
📌 **Interview use:** Detect cycles
💬 *Often asked*

---

### ✅ Round Trip II

📌 **Concept:** Cycle detection (directed)
📌 **Interview use:** Deadlocks, dependency cycles
💬 *Very important*

---

### ✅ Course Schedule

📌 **Concept:** Topological sort
📌 **Interview use:** Prerequisites, scheduling
💬 *FAANG favorite*

---

# ⭐⭐ Tier 2 — VERY IMPORTANT (frequently asked)

These come up a lot, but not every interview.

## 🔹 Shortest paths

### ✅ Shortest Routes I

📌 **Concept:** Dijkstra
📌 **Interview use:** Weighted shortest path
💬 *Essential*

---

### ✅ Flight Discount

📌 **Concept:** Modified Dijkstra (state graph)
📌 **Interview use:** “One special edge allowed” problems
💬 *Great interview pattern*

---

### ✅ Investigation

📌 **Concept:** Shortest path + counting paths
📌 **Interview use:** Multi-criteria shortest paths
💬 *Advanced but valuable*

---

### ✅ High Score

📌 **Concept:** Bellman-Ford + negative cycles
📌 **Interview use:** Detect arbitrage, infinite gain
💬 *Occasionally asked*

---

## 🔹 Stronger graph theory

### ✅ Planets and Kingdoms

📌 **Concept:** Strongly connected components (SCC)
📌 **Interview use:** Condensed graphs
💬 *Very important*

---

### ✅ Cycle Finding

📌 **Concept:** Negative cycle detection
📌 **Interview use:** Financial modeling, constraints
💬 *Classic*

---

### ✅ Road Reparation

📌 **Concept:** Minimum Spanning Tree (Kruskal)
📌 **Interview use:** Network design
💬 *Very common*

---

### ✅ Road Construction

📌 **Concept:** DSU (Union-Find)
📌 **Interview use:** Dynamic connectivity
💬 *Must-know DS*

---

# ⭐⭐⭐ Tier 3 — Advanced / Situational

Great problems, **rare in interviews** unless senior or competitive-heavy.

### ⚠️ Lower priority

* Monsters (multi-source BFS)
* Longest Flight Route (DP on DAG)
* Game Routes (count paths in DAG)
* Flight Routes / Flight Routes Check
* Planets Queries I / II / Cycles
* Giant Pizza (2-SAT)
* Coin Collector (SCC + DP)
* Mail Delivery (Eulerian path)
* Teleporters Path
* Hamiltonian Flights
* Knight’s Tour
* Download Speed (Max Flow)
* Police Chase (Min Cut)
* School Dance (Bipartite Matching)
* Distinct Routes (Flow)

💬 These are **excellent**, but interviewers usually don’t go this far unless:

* Systems role
* Graph-heavy role
* Competitive programming background expected

---

# 🧠 What interviewers REALLY test with graphs

They want to see if you can:

✔ Choose **DFS vs BFS** correctly
✔ Detect **cycles**
✔ Recognize **shortest path** variants
✔ Apply **toposort / SCC / MST**
✔ Explain **why the algorithm works**

They **do not expect** Hamiltonian paths or Knight’s Tour.

---

# 🎯 If you had to study only 10 graph problems

Study these concepts:

1. DFS / BFS
2. Connected components
3. Bipartite graph
4. Cycle detection
5. Topological sort
6. Dijkstra
7. Bellman-Ford
8. SCC
9. Union-Find
10. MST

That covers **80–90% of interview graph questions**.

---

