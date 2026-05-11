Stars and Bars Notes

Purpose:
Used to count:

* number of integer solutions
* ways to distribute identical objects into groups

---

Core Equation

x1 + x2 + x3 + ... + xk = n

where:

* n = total objects
* k = number of groups

---

CASE 1: Nonnegative Integer Solutions

Condition:
xi >= 0

Formula:

\binom{n+k-1}{k-1}

Equivalent:
C(n+k-1, n)

---

Example

x1 + x2 + x3 = 5
xi >= 0

Answer:

C(5+3-1, 3-1)
= C(7,2)
= 21

---

Visual Meaning

Stars = objects

---

Bars = separators

**|*|**

Meaning:

* box1 = 2
* box2 = 1
* box3 = 2

Need:

* n stars
* k-1 bars

Total positions:
n+k-1

Choose positions of bars.

---

CASE 2: Positive Integer Solutions

Condition:
xi >= 1

Give 1 to every variable first.

Remaining:
n-k

Formula:

\binom{n-1}{k-1}

---

Example

x1 + x2 + x3 = 5
xi >= 1

Give each variable 1.

Remaining:
5-3 = 2

Now solve nonnegative version.

Answer:
C(4,2) = 6

---

Recognition Pattern

If problem says:

* distribute identical objects
* count integer solutions
* sum constraints
* partition numbers

Think:
"Stars and Bars"

---

Common Formulas

1. Nonnegative Solutions

x1 + x2 + ... + xk = n
xi >= 0

Answer:
C(n+k-1, k-1)

---

2. Positive Solutions

x1 + x2 + ... + xk = n
xi >= 1

Answer:
C(n-1, k-1)

---

Small CP Code

```cpp id="fwb6y5"
const int MOD = 1e9 + 7;
const int N = 2e6;

long long fact[N], invFact[N];

long long power(long long a, long long b) {

    long long res = 1;

    while (b) {

        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;

        b >>= 1;
    }

    return res;
}

void init() {

    fact[0] = 1;

    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[N - 1] = power(fact[N - 1], MOD - 2);

    for (int i = N - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

long long nCr(int n, int r) {

    if (r < 0 || r > n)
        return 0;

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
```

Usage:

Nonnegative:

```cpp id="0jx5wx"
nCr(n + k - 1, k - 1);
```

Positive:

```cpp id="s8g4jr"
nCr(n - 1, k - 1);
```

---

Most Common Mistake

Confusing:

* xi >= 0
  with
* xi >= 1

That changes the formula completely.
