A **Derangement** means:

> permutation where NO element stays in its original position.

Also called:

* complete permutation
* forbidden fixed points problem

---

Example:

Suppose:

```text id="lkw47e"
[1,2,3]
```

Valid derangements:

```text id="z9lf3u"
[2,3,1]
[3,1,2]
```

Invalid:

```text id="h5v3bo"
[2,1,3]
```

because:

* 3 stayed in original position.

---

# Formal Definition

Count permutations such that:

[
p_i \ne i
]

for all positions.

---

# Small Examples

n = 1

```text id="b4eq5t"
[1]
```

No derangement.

Answer:
0

---

n = 2

Permutations:

```text id="ndksko"
[1,2]
[2,1]
```

Only:

```text id="2ml6gc"
[2,1]
```

works.

Answer:
1

---

n = 3

Permutations:

```text id="slr09u"
123
132
213
231
312
321
```

Valid:

```text id="6y1lyw"
231
312
```

Answer:
2

---

# Standard Formula

Number of derangements of n:

Usually written as:

[
!n
]

Formula:

!n = n!\left(1-\frac1{1!}+\frac1{2!}-\frac1{3!}+\cdots+(-1)^n\frac1{n!}\right)

This comes from:

* Inclusion Exclusion Principle

---

# Simpler Recurrence (Most Useful in CP)

D(n)=(n-1)(D(n-1)+D(n-2))

Base cases:

[
D(1)=0
]
[
D(2)=1
]

---

# Why Recurrence Works

Suppose person 1 cannot stay at position 1.

Choose some position (k).

Now two cases:

Case 1:

* kth element goes to position 1
* remaining becomes derangement of (n-2)

Case 2:

* kth element does NOT go to position 1
* remaining becomes derangement of (n-1)

Multiply by:
[
(n-1)
]

because position 1 can go to any other place.

---

# Values to Remember

| n | D(n) |
| - | ---- |
| 1 | 0    |
| 2 | 1    |
| 3 | 2    |
| 4 | 9    |
| 5 | 44   |
| 6 | 265  |

---

# Important Approximation

D(n) \approx \frac{n!}{e}

Very famous result.

---

# CP Code

```cpp id="1pmv5u"
const int MOD = 1e9 + 7;

long long derangement(int n) {

    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    long long a = 0; // D(1)
    long long b = 1; // D(2)

    for (int i = 3; i <= n; i++) {

        long long c = (i - 1) * (a + b) % MOD;

        a = b;
        b = c;
    }

    return b;
}
```

---

# Recognition Pattern

If problem says:

* nobody gets own gift
* permutation with restrictions
* no fixed points
* secret santa
* hat-check problem

Think:

```text id="ljlwmf"
Derangements
```

---

# Common Blind Spot

Many beginners try brute force permutations.

That immediately dies because:

* permutations = (n!)

Need:

* recurrence
  or
* inclusion exclusion.
