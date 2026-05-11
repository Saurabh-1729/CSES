# Harmonic Lemma / Floor Division Optimization

## Core Observation

The value:

[
\left\lfloor \frac{n}{i} \right\rfloor
]

does NOT change for every (i).

Many consecutive values of (i) produce the same quotient.

Example for (n=20):

| i     | floor(20/i) |
| ----- | ----------- |
| 1     | 20          |
| 2     | 10          |
| 3     | 6           |
| 4     | 5           |
| 5     | 4           |
| 6     | 3           |
| 7     | 2           |
| 8     | 2           |
| 9     | 2           |
| 10    | 2           |
| 11-20 | 1           |

Important:

* quotient values repeat
* number of distinct quotients is about:

[
O(\sqrt n)
]

---

# Main Trick

Suppose:

[
q = \left\lfloor \frac{n}{l} \right\rfloor
]

Then all values from:

[
l \to r
]

have same quotient where:

[
r = \left\lfloor \frac{n}{q} \right\rfloor
]

This lets us process ranges together.

---

# Common Formula

Used in divisor problems:

[
\sum_{d=1}^{n} d \left\lfloor \frac{n}{d} \right\rfloor
]

Interpretation:

* divisor (d) contributes to all multiples of (d)
* count of multiples:

[
\left\lfloor \frac{n}{d} \right\rfloor
]

---

# Range Sum Formula

Needed for grouped processing:

[
\sum_{i=l}^{r} i
================

\frac{(r-l+1)(l+r)}{2}
]

---

# Generic Template

```cpp
for (long long l = 1; l <= n;) {

    long long q = n / l;

    long long r = n / q;

    // process range [l, r]

    l = r + 1;
}
```

---

# Why Fast?

Naive:

```cpp
O(n)
```

Optimized:

```cpp
O(sqrt(n))
```

because quotient changes only about (2\sqrt n) times.

---

# Full CSES Sum of Divisors Code

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

const int64 MOD = 1e9 + 7;

int64 range_sum(int64 l, int64 r) {

    int64 cnt = (r - l + 1) % MOD;
    int64 sum = (l + r) % MOD;

    // divide by 2 safely
    if (cnt % 2 == 0)
        cnt /= 2;
    else
        sum /= 2;

    return (cnt % MOD) * (sum % MOD) % MOD;
}

int main() {

    int64 n;
    cin >> n;

    int64 ans = 0;

    for (int64 l = 1; l <= n;) {

        int64 q = n / l;

        int64 r = n / q;

        int64 block = range_sum(l, r);

        ans = (ans + (q % MOD) * block) % MOD;

        l = r + 1;
    }

    cout << ans << '\n';
}
```

---

# Recognition Pattern

If you see:

* floor division
* divisor summation
* count multiples
* huge (n) like (10^{12})

Think:

```text
Can equal quotients be grouped?
```

---

# Mental Model

Beginner:

```text
Loop through numbers
```

Advanced:

```text
Group repeated values
Invert contribution
```

That mindset is the actual skill.
