#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull; // 2^64-1
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define umll unordered_map<ll, ll>
#define mll map<ll, ll>
#define vbl vector<bool>

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pie 3.141592653589793238462643383279

#define nline "\n"
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound

#define SB(a) sort(a.begin(), a.end(), greater<ll>());
#define SS(a) sort(a.begin(), a.end());

#define NN cout << "No" << nline
#define YY cout << "Yes" << nline

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mx_ele(x) max_element(all(x))
#define mn_ele(x) min_element(all(x))
#define accum(x) accumulate(all(x), 0)

int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#define SPEED()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define TIME()                                                         \
    double time_taken = double(stop - start) / double(CLOCKS_PER_SEC); \
    cerr << fixed << time_taken << setprecision(5);                    \
    cerr << " sec " << nline
#define START() auto start = clock()
#define STOP() auto stop = clock()

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_set<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(multimap<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// sort(v.begin(), v.end(), [](auto &left, auto &right) {
// return left.second < right.second;
// });

// class DSU{
// void find_parent(int v) {
//     parent[v] = v;
//     size[v] = 1;
// }

// void union(int a, int b) {
//     a = find_parent(a);
//     b = find_parent(b);
//     if (a != b) {
//         if (size[a] < size[b])
//             swap(a, b);
//         parent[b] = a;
//         size[a] += size[b];
//     }
// }
// };

// Calculate p^q % m using binary exponentiation.
// ll calculate(ll p, ll q)
// {
//     ll m = 1e9 + 7, expo;
//     expo = m - 2;
//     while (expo)
//     {
//         if (expo & 1) // odd
//         {
//             p = (p * q) % m;
//         }
//         q = (q * q) % m;
//         expo >>= 1; // divide by 2
//     }
//     return p;
// }

// Calculate every subset sum
// vector<int> sum1[n + 1], sum2[n + 1];
// for (int mask = 0; mask < (1 << n); ++mask)
// {
//     int tot1 = 0, count = 0;
//     for (int j = 0; j < n; ++j)
//         if (mask & (1 << j))
//         {
//             tot1 += nums1[j];
//             count += 1;
//         }
//     sum1[count].push_back(tot1);
// }

ll power(ll base, ll exponent)
{
    ll result = 1;
    while (exponent != 0)
    {
        result *= base;
        --exponent;
    }
    return result;
}

ll fact(ll x)
{
    ll res = 1;
    for (int i = 1; i <= x; i++)
    {
        res = (res * i) % MOD1;
    }
    return res;
}

// MATHS
// https://usaco.guide/gold/modular?lang=cpp
//

/*  Range Quesries:
https://www.geeksforgeeks.org/precomputation-technique-on-arrays/?ref=lbp
*/

/*
https://www.geeksforgeeks.org/gcd-greatest-common-divisor-practice-problems-for-competitive-programming/?ref=lbp
*/

// TODO/
// Order statistic tree (Policy Based DS)
// Stair case nim game problem
// Bit manipulation / Masking
// DP with mask
// Lazy segment tree
// Binary Lifting
// Euler Path
// Number Theory Basics
// ordered set, multiset, set, unordered set, unordered multiset

/*
DP / Binary Search / Graph / Stack / Queue / PQ / DSU / TOPO /
check for equality condition/check for interval qus..
Check if stack NSE/NGE can be applied for some subarrays ques.
no.of cycles with help of no.edges and vertices
to find if 2 numbers has common factors use prime factorization method
->ans[current_node] = ans[Parent_node] + n - 2 * size_of_subtree[current_node];
Count of possible subarrays(containing that particular index) = N * (i + 1) - i * (i + 1)
int nodeNo = row*n + col; //using formula to convert grid into 1d array for DSU
Shift + Alt + F
xmodm=ymodm, then |x−y|modm=0
One string can be converted to the other look for block size and kind of operation
Rewriting (count[i] - count[j]) % modulo == k becomes count[j] = (count[i] + modulo - k) % modulo.
Degenrate Case (No elements occur at its original pos) :  D(n)=(D(n−1)+D(n−2))(n−1)
Change the way you are looping
Check for total Bits positions in Bits Questions
A + B = A XOR B + 2 * A AND B
A−B=A+(NOT B)+1
// Normal division does not work, we take help of modular division
ans=ans×(fact(v[i]))^−1%MOD1 => bpow(fact(val), MOD1-2))
*/

const int mod = 1e9 + 7;

void Saurabh()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    vector<ll> dp(n, 0);

    // Start at level 1
    dp[0] = 1;

    // Kahn's algorithm
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            dp[v] = (dp[v] + dp[u]) % mod;
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    cout << dp[n - 1] << '\n';
}

int main()
{
    SPEED();
    START();
    ll t = 1;
    while (t--)
        Saurabh();
    STOP();
    TIME();
}
