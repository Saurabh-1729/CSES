Yes. For each node `u`, compute **both states**:

---

# 1️⃣ `dp[u][0]`

`u` is **not matched with any child**

```cpp id="jlwm47"
dp[u][0] = 0;
for(each child v)
    dp[u][0] += max(dp[v][0], dp[v][1]);
```

---

# 2️⃣ `dp[u][1]`

`u` is matched with **exactly one child**

Try every child `v` as matched child:

```cpp id="l4xjgj"
dp[u][1] = 0;

for(each child v)
{
    candidate =
    dp[u][0]
    - max(dp[v][0], dp[v][1])
    + dp[v][0]
    + 1;

    dp[u][1] = max(dp[u][1], candidate);
}
```

---

# Final Answer

At root:

```cpp id="gk4exs"
max(dp[root][0], dp[root][1])
```

---

# Meaning

```text id="ccl0o6"
dp[u][0] = skip matching u
dp[u][1] = match u with best one child
```
