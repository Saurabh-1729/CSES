

# 🧠 1. What is Modulo?

```text
a % m = remainder when a is divided by m
```

Range:

```text
0 ≤ a % m < m   (if implemented correctly)
```

---

# ⚠️ 2. Negative Modulo (Common Bug)

In many languages (like C/C++/Java):

```text
-3 % 5 = -3   ❌ (language behavior)
```

But mathematically:

```text
-3 mod 5 = 2  ✅
```

### Fix:

```cpp
((a % m) + m) % m
```

---

# 🔑 3. Core Properties (Must Know)

## Addition

```text
(a + b) % m = (a % m + b % m) % m
```

## Subtraction

```text
(a - b) % m = (a % m - b % m + m) % m
```

## Multiplication

```text
(a * b) % m = (a % m * b % m) % m
```

## Division ❌ (Not direct)

```text
(a / b) % m ≠ (a % m / b % m)
```

Instead use **modular inverse**.

---

# ⚡ 4. Modular Inverse

You want:

```text
a / b mod m
```

Convert to:

```text
a * b⁻¹ mod m
```

Where:

```text
b * b⁻¹ ≡ 1 mod m
```

---

## When does inverse exist?

Only if:

```text
gcd(b, m) = 1
```

---

## Methods to find inverse

### 1. Fermat’s Little Theorem (when m is prime)

```text
b⁻¹ ≡ b^(m-2) mod m
```

Used everywhere.

---

### 2. Extended Euclidean Algorithm

Works for non-prime m also.

---

# 🚀 5. Fast Exponentiation (Critical)

Instead of O(n):

```text
a^b % m
```

Use:

```text
Binary exponentiation → O(log b)
```

---

### Code

```cpp
long long modPow(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;

    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
```

---

# 🧠 6. Why Modulo is Used

## 1. Prevent overflow

```text
10^9 * 10^9 → overflow
```

Use mod to keep numbers small.

---

## 2. Constraints

Common mod:

```text
1,000,000,007  (10^9 + 7)
```

Why?

* Prime
* Fits in int
* Good distribution

---

# 🔥 7. Important Identities

## Distributive

```text
(a * b) % m = ((a % m) * (b % m)) % m
```

---

## Power

```text
(a^b) % m = ((a % m)^b) % m
```

---

## Factorial Mod

```text
n! % m
```

Used in combinations.

---

# ⚡ 8. Modular Division Example

Compute:

```text
10 / 3 mod 7
```

Step 1: Find inverse of 3 mod 7

```text
3^(7-2) = 3^5 mod 7 = 5
```

Step 2:

```text
10 * 5 mod 7 = 50 % 7 = 1
```

---

# 🧠 9. Common Use Cases

* Competitive programming
* Combinatorics (nCr mod m)
* Hashing (rolling hash)
* Cryptography
* Distributed systems (hash partitioning)

---

# ⚠️ 10. Mistakes You Will Make

## ❌ Forgetting mod after multiplication

```cpp
res = res * a; // overflow
```

---

## ❌ Wrong subtraction

```cpp
(a - b) % m   // can be negative
```

---

## ❌ Direct division

```cpp
(a / b) % m   // WRONG
```

---

## ❌ Using inverse when gcd ≠ 1

No inverse exists.

---

# 🏗 11. nCr with Mod (Important)

```text
nCr = n! / (r! * (n-r)!)
```

Under mod:

```text
nCr = n! * inv(r!) * inv((n-r)!) % m
```

Precompute factorials.

---

# 🔥 12. Advanced Concepts (Know if serious)

* Modular exponentiation with large exponent
* Chinese Remainder Theorem (CRT)
* Lucas Theorem (nCr large n)
* Fermat’s theorem
* Euler’s theorem

---

# 🎯 Interview-Level Summary

If interviewer asks:

> What are key properties of modulo arithmetic?

Answer:

> Modulo arithmetic preserves addition, subtraction, and multiplication under modulus, but not division. Division is handled using modular inverse, which exists when gcd(b, m) = 1. Efficient computations use binary exponentiation and Fermat’s Little Theorem when modulus is prime.

---

# Brutal Truth

Most people:

* memorize formulas
* don’t understand inverse
* mess up negative mod

That’s why they fail CP and math-heavy interviews.

---
