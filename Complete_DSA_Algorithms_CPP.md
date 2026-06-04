# Complete DSA Algorithms in C++17/20

An in-depth handbook for learning Data Structures and Algorithms from scratch, preparing for coding interviews, competitive programming, ICPC-style contests, and advanced algorithmic problem solving.

This file is written for practical C++17/C++20 use. It emphasizes invariants, recognition signals, complexity, implementation hazards, and contest-ready templates.

## Table of Contents

- [1. Foundations](#1-foundations)
- [2. Basic Data Structures](#2-basic-data-structures)
- [3. Searching and Sorting](#3-searching-and-sorting)
- [4. Arrays, Prefix Techniques, and Windows](#4-arrays-prefix-techniques-and-windows)
- [5. Recursion, Backtracking, and Search](#5-recursion-backtracking-and-search)
- [6. Greedy Algorithms](#6-greedy-algorithms)
- [7. Dynamic Programming](#7-dynamic-programming)
- [8. Trees](#8-trees)
- [9. Range Query Data Structures](#9-range-query-data-structures)
- [10. Graph Algorithms](#10-graph-algorithms)
- [11. Network Flow and Matching](#11-network-flow-and-matching)
- [12. String Algorithms](#12-string-algorithms)
- [13. Bit Manipulation](#13-bit-manipulation)
- [14. Number Theory](#14-number-theory)
- [15. Combinatorics and Probability](#15-combinatorics-and-probability)
- [16. Computational Geometry](#16-computational-geometry)
- [17. Advanced Competitive Programming Techniques](#17-advanced-competitive-programming-techniques)
- [18. ICPC-Level Problem Solving](#18-icpc-level-problem-solving)
- [19. Hardest / Research-Oriented Overviews](#19-hardest-research-oriented-overviews)
- [20. Final Guides](#20-final-guides)

## How to Study This Handbook

- First pass: read the mental models and recognition signals.
- Second pass: implement the templates without looking.
- Third pass: solve problems that isolate each technique.
- Fourth pass: mix topics under time pressure.
- For every topic, ask: what invariant is preserved, what constraints justify it, and what counterexample breaks a naive approach?


For each algorithm or data structure, use this review checklist:

1. What is the mathematical object being maintained or optimized?
2. What is the invariant after every step?
3. Why does the transition preserve the invariant?
4. What exact problem pattern triggers this tool?
5. Which constraints make it necessary?
6. Which assumptions can break it?
7. What is the time complexity and why?
8. What is the memory complexity and why?
9. Which indices are inclusive, exclusive, 0-based, or 1-based?
10. What are the empty, single-element, duplicate, negative, and maximum-size cases?
11. What can overflow?
12. What should be brute-forced for stress testing?
13. What alternative algorithm would work if constraints changed?
14. What part of the proof would you explain to an interviewer or teammate?



## 1. Foundations

This section is for build the vocabulary needed to reason about every later algorithm.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Big-O, Big-Theta, Big-Omega | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Time complexity analysis | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Space complexity analysis | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Recurrence relations | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Master theorem | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Amortized analysis | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Potential method | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Loop invariants | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Correctness proofs | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Exchange arguments | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Cut and cycle properties | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Pigeonhole principle | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Invariants and monovariants | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Mathematical induction | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Strong induction | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Recursion | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Divide and conquer | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Iterative vs recursive thinking | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Overflow and integer limits | Send limited resources through a network. | Capacities, cuts, disjoint paths, assignment with constraints. | Bad graph modeling or missing reverse edges. |
| Floating point precision | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Modular arithmetic basics | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| C++ fast I/O | Language/tooling feature for shorter, safer implementations. | You need robust templates, custom ordering, or standard containers. | Undefined behavior, invalidated iterators, or comparator that is not strict weak ordering. |
| C++ STL overview | Language/tooling feature for shorter, safer implementations. | You need robust templates, custom ordering, or standard containers. | Undefined behavior, invalidated iterators, or comparator that is not strict weak ordering. |
| Custom comparators | Language/tooling feature for shorter, safer implementations. | You need robust templates, custom ordering, or standard containers. | Undefined behavior, invalidated iterators, or comparator that is not strict weak ordering. |
| Lambda functions | Language/tooling feature for shorter, safer implementations. | You need robust templates, custom ordering, or standard containers. | Undefined behavior, invalidated iterators, or comparator that is not strict weak ordering. |
| Policy based data structures | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Random number generation | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Debugging templates | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Stress testing | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Brute force verification | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Coordinate compression | Core foundations idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |


### Deep Dives and Templates

#### Asymptotic Notation

**Formal definition.** `f(n) = O(g(n))` means there exist constants `c > 0` and `n0` such that `f(n) <= c*g(n)` for all `n >= n0`. `Theta` gives a tight upper and lower bound. `Omega` gives a lower bound.

**Beginner intuition.** Ignore machine-dependent constants and ask how the work grows when input doubles. If an algorithm loops over all pairs, doubling `n` roughly quadruples the work: that is quadratic behavior.

**Common growth rates.**

| Complexity | Typical source | Feasible rough scale |
|---|---|---|
| O(1) | direct formula, array access | any input |
| O(log n) | binary search, balanced tree height | enormous n |
| O(n) | one scan | up to 1e7 or more in C++ |
| O(n log n) | sorting, divide and conquer | up to 1e6 or 1e7 depending constants |
| O(n^2) | all pairs, 2D DP | up to 2e3-1e4 depending time |
| O(n^3) | Floyd-Warshall, interval DP | up to 300-700 |
| O(2^n) | subsets | up to 20-25 |
| O(n!) | permutations | up to 10-11 |

#### Correctness Proof Patterns

**Invariant proof.** State what remains true before and after each iteration. Binary search maintains that the answer is inside the active interval. Dijkstra maintains that once a vertex is extracted with the smallest tentative distance, its distance is final when all edges are nonnegative.

**Exchange argument.** Start with an optimal solution and show that replacing one of its choices with the greedy choice does not hurt. Activity selection uses this: picking the earliest finishing interval leaves at least as much room as any other first compatible interval.

**Induction.** Prove base cases, then show that solving smaller states correctly implies the current state is correct. Most DP proofs are induction over state order.

#### Recurrences and Master Theorem

For `T(n) = aT(n/b) + f(n)`:

| Case | Condition | Result |
|---|---|---|
| 1 | `f(n) = O(n^(log_b(a)-eps))` | `T(n)=Theta(n^log_b(a))` |
| 2 | `f(n)=Theta(n^log_b(a) log^k n)` | `T(n)=Theta(n^log_b(a) log^(k+1)n)` |
| 3 | `f(n)=Omega(n^(log_b(a)+eps))` and regularity | `T(n)=Theta(f(n))` |

Merge sort has `T(n)=2T(n/2)+O(n)`, so `T(n)=O(n log n)`.

#### Amortized Analysis

Amortized complexity bounds average cost over a sequence, not random average. Vector push-back is amortized O(1): occasional resizing costs O(n), but each element is copied only O(log n) times under doubling, and total copies over n pushes are O(n). The potential method assigns stored credit to states; dynamic arrays store potential in unused capacity.

#### Overflow and Precision

- Use `long long` for sums/products beyond about 2e9.
- Use `__int128` for multiplying two 64-bit values before modulo.
- Do not compare floating values with `==` unless they are constructed identically; use an epsilon.
- Beware `mid = (l + r) / 2` overflow; prefer `l + (r-l)/2`.
- Modular subtraction should normalize: `(a - b + MOD) % MOD`.

#### C++ Starter Template

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const ll INF64 = (1LL << 62);
const int INF = 1e9;

template<class T>
bool chmin(T& a, const T& b) {
    if (b < a) { a = b; return true; }
    return false;
}

template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
```


#### Debugging and Random Testing Helpers

```cpp
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x) ((void)0)
#endif

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
```


#### Coordinate Compression

**What it is.** Replace large sparse values by their rank in sorted order.

**When to use it.** Values are up to `1e18` but only `n` distinct coordinates matter, as in Fenwick trees, sweep lines, or DP over values.

**Dry run.** `[100, -5, 100, 7]` has sorted uniques `[-5, 7, 100]` and compresses to `[2, 0, 2, 1]`.


```cpp
template<class T>
vector<int> compress_values(const vector<T>& a, vector<T>* values_out = nullptr) {
    vector<T> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<int> id(a.size());
    for (int i = 0; i < (int)a.size(); ++i) {
        id[i] = int(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin());
    }
    if (values_out) *values_out = vals;
    return id;
}
```




## 2. Basic Data Structures

This section is for choose a storage model whose operations match the problem.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Arrays | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Dynamic arrays / vectors | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Strings | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Linked lists | Find ordered subsequence structure. | Need longest increasing/decreasing chain. | Confusing subsequence with subarray. |
| Doubly linked lists | Find ordered subsequence structure. | Need longest increasing/decreasing chain. | Confusing subsequence with subarray. |
| Circular linked lists | Find ordered subsequence structure. | Need longest increasing/decreasing chain. | Confusing subsequence with subarray. |
| Stack | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Queue | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Deque | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Hash table | Compare substrings probabilistically. | Many equality checks on substrings. | Single modulus collision risk. |
| Hash set | Compare substrings probabilistically. | Many equality checks on substrings. | Single modulus collision risk. |
| Ordered set | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Multiset | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Map | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Multimap | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Unordered map | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Priority queue | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Binary heap | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Min heap | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Max heap | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Monotonic stack | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Monotonic queue | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Sparse set basics | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bitset | Core basic data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |


### Deep Dives and Templates

#### Choosing the Basic Container

| Need | Prefer | Why |
|---|---|---|
| random access and compact memory | `vector` | contiguous, cache-friendly, O(1) indexing |
| push/pop both ends | `deque` | O(1) amortized at both ends |
| membership, no order | `unordered_set` | average O(1), but watch hacking/collisions |
| sorted unique values | `set` | O(log n), ordered iteration |
| duplicates sorted | `multiset` | O(log n), supports equal keys |
| key-value map sorted | `map` | ordered by key |
| max/min extraction | `priority_queue` | heap operations O(log n) |
| fixed-size dense boolean flags | `bitset<N>` | word-parallel operations |

#### Monotonic Stack

**What it is.** A stack whose values are kept increasing or decreasing by popping dominated elements.

**Why it works.** Once a new element is smaller than previous larger elements, those larger elements can never be the nearest smaller element for future positions because the new element is closer and smaller.

**Use it for.** Next greater/smaller element, histogram rectangle, stock span, removing digits, Cartesian tree.

**Common mistakes.** Choosing `<` vs `<=` incorrectly when duplicates exist.


```cpp
vector<int> next_greater_index(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> ans(n, -1), st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] < a[i]) {
            ans[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}
```


#### Monotonic Queue

**What it is.** A deque that stores candidates for window minimum/maximum in sorted order.

**Complexity.** Each index enters and leaves once, so total O(n).


```cpp
vector<int> sliding_window_max(const vector<int>& a, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < (int)a.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) ans.push_back(a[dq.front()]);
    }
    return ans;
}
```


#### Hash Tables

Average O(1) operations depend on good hashing. For adversarial online judges, protect `unordered_map` by using a custom hash or switch to `map` if O(log n) is acceptable. Never rely on iteration order.

#### Priority Queue and Heap

A binary heap supports O(log n) push/pop and O(1) top. It does not support arbitrary deletion efficiently; use lazy deletion with an auxiliary map, or use `set` when deletion by iterator is needed.




## 3. Searching and Sorting

This section is for order data, exploit monotonicity, and select values efficiently.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Linear search | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Binary search | Search over a sorted domain or monotone predicate. | Answer space is ordered and feasibility flips from false to true. | Predicate is not actually monotone, or midpoint overflows. |
| Ternary search | Optimize a unimodal function. | The function decreases then increases, or increases then decreases. | The function is not unimodal, especially on discrete domains. |
| Binary search on answer | Search over a sorted domain or monotone predicate. | Answer space is ordered and feasibility flips from false to true. | Predicate is not actually monotone, or midpoint overflows. |
| Parallel binary search | Search over a sorted domain or monotone predicate. | Answer space is ordered and feasibility flips from false to true. | Predicate is not actually monotone, or midpoint overflows. |
| Exponential search | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Interpolation search | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Lower bound | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Upper bound | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bubble sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Selection sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Insertion sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Merge sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Quick sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Randomized quicksort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Heap sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Counting sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Radix sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bucket sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Shell sort | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| TimSort overview | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Stable vs unstable sorting | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Custom sorting in C++ | Language/tooling feature for shorter, safer implementations. | You need robust templates, custom ordering, or standard containers. | Undefined behavior, invalidated iterators, or comparator that is not strict weak ordering. |
| Sorting pairs and structs | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Inversion count | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Quickselect | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Median of medians | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| K-th order statistics | Core searching and sorting idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |


### Deep Dives and Templates

#### Binary Search on Answer

**Formal model.** You have a totally ordered answer domain and a monotone predicate `ok(x)`. For minimization, `ok(x)` is false before the answer and true from the answer onward.

**Recognition checklist.**
- The statement asks for minimum maximum, maximum minimum, smallest feasible, largest possible.
- You can verify a candidate faster than constructing the optimum directly.
- Constraints allow `O(check * log range)`.

**Dry run.** Minimum capacity to ship packages in D days: if capacity 10 works, any capacity greater than 10 also works. Binary search the capacity, greedily count days in `ok(cap)`.


```cpp
template<class F>
long long first_true(long long lo, long long hi, F pred) {
    // Search in [lo, hi]. Requires: pred(lo..ans-1)=false, pred(ans..hi)=true.
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (pred(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

template<class F>
long long last_true(long long lo, long long hi, F pred) {
    // Requires: pred(lo..ans)=true, pred(ans+1..hi)=false.
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if (pred(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}
```


#### Sorting Families

| Algorithm | Time | Space | Stable | Use case |
|---|---:|---:|---|---|
| insertion sort | O(n^2) | O(1) | yes | tiny or almost sorted arrays |
| merge sort | O(n log n) | O(n) | yes | stable sort, inversion count |
| quicksort | average O(n log n), worst O(n^2) | O(log n) | no | fast in practice with randomization |
| heap sort | O(n log n) | O(1) | no | memory-constrained deterministic sorting |
| counting sort | O(n + K) | O(K) | yes possible | small integer range |
| radix sort | O(d(n + B)) | O(n+B) | yes | fixed-width integers/strings |

#### Inversion Count

**What it is.** Number of pairs `i < j` with `a[i] > a[j]`. It measures how far an array is from sorted order.


```cpp
long long count_inversions(vector<long long>& a) {
    vector<long long> tmp(a.size());
    function<long long(int,int)> solve = [&](int l, int r) -> long long {
        if (r - l <= 1) return 0;
        int m = (l + r) / 2;
        long long inv = solve(l, m) + solve(m, r);
        int i = l, j = m, k = l;
        while (i < m || j < r) {
            if (j == r || (i < m && a[i] <= a[j])) tmp[k++] = a[i++];
            else {
                tmp[k++] = a[j++];
                inv += m - i;
            }
        }
        for (int p = l; p < r; ++p) a[p] = tmp[p];
        return inv;
    };
    return solve(0, (int)a.size());
}
```


#### Quickselect and Median of Medians

Quickselect partitions like quicksort but recurses only into the side containing the k-th element. Randomized quickselect is expected O(n). Median of medians chooses a deterministic pivot guaranteeing O(n), but constants are larger; it is mainly useful when worst-case guarantees matter.

#### C++ Custom Sorting

Comparators must be strict weak orderings: for equal elements, the comparator must return false both ways. A bad comparator can make `sort` undefined.


```cpp
struct Person { string name; int score, age; };

sort(v.begin(), v.end(), [](const Person& a, const Person& b) {
    if (a.score != b.score) return a.score > b.score; // higher first
    if (a.age != b.age) return a.age < b.age;         // younger first
    return a.name < b.name;
});
```




## 4. Arrays, Prefix Techniques, and Windows

This section is for replace repeated range work with precomputation, movement, or offline ordering.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Prefix sums | Precompute cumulative information. | Many static range sums/counts are requested. | Off-by-one indexing and mixing inclusive/exclusive bounds. |
| 2D prefix sums | Precompute cumulative information. | Many static range sums/counts are requested. | Off-by-one indexing and mixing inclusive/exclusive bounds. |
| 3D prefix sums overview | Precompute cumulative information. | Many static range sums/counts are requested. | Trying to code it in contest without enough implementation practice. |
| Difference arrays | Store range updates as boundary changes. | Many range additions are followed by final reconstruction. | Forgetting the final prefix pass. |
| 2D difference arrays | Store range updates as boundary changes. | Many range additions are followed by final reconstruction. | Forgetting the final prefix pass. |
| Imos method | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Partial sums | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Suffix sums | Index all suffixes/substrings. | Need lexicographic substring or repeated substring queries. | Large constants and indexing mistakes. |
| Contribution technique | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Sweep line basics | Process events in sorted coordinate order. | Intervals/segments change active set over time. | Wrong event tie-breaking. |
| Two pointers | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Opposite-direction pointers | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Same-direction pointers | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Fast and slow pointers | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Sliding window fixed size | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Sliding window variable size | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Mo's algorithm | Offline reorder queries to reduce pointer movement. | Static array, many range queries, add/remove is cheap. | Large update dimension or expensive add/remove. |
| Mo's algorithm with updates | Offline reorder queries to reduce pointer movement. | Static array, many range queries, add/remove is cheap. | Large update dimension or expensive add/remove. |
| Kadane's algorithm | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Maximum subarray variants | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Circular subarray | Core arrays, prefix techniques, and windows idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Prefix minimum/maximum tricks | Precompute cumulative information. | Many static range sums/counts are requested. | Off-by-one indexing and mixing inclusive/exclusive bounds. |


### Deep Dives and Templates

#### Prefix Sums and Difference Arrays

Prefix sums answer static range sums. Difference arrays batch range updates.


```cpp
vector<long long> prefix_sum(const vector<long long>& a) {
    vector<long long> pref(a.size() + 1, 0);
    for (int i = 0; i < (int)a.size(); ++i) pref[i + 1] = pref[i] + a[i];
    return pref; // sum [l, r) = pref[r] - pref[l]
}

vector<long long> apply_range_adds(int n, const vector<tuple<int,int,long long>>& updates) {
    vector<long long> diff(n + 1, 0);
    for (auto [l, r, x] : updates) { // inclusive l, inclusive r
        diff[l] += x;
        if (r + 1 < n) diff[r + 1] -= x;
    }
    vector<long long> a(n);
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += diff[i];
        a[i] = cur;
    }
    return a;
}
```


**2D prefix formula.** For 0-based grid `a`, build `pref[n+1][m+1]`:


```cpp
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        pref[i + 1][j + 1] = a[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
    }
}
auto sum = [&](int r1, int c1, int r2, int c2) { // inclusive rectangle
    return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
};
```


#### Two Pointers and Sliding Window

Use two pointers when each pointer moves monotonically. This usually requires sorted data or a window property that becomes easier/harder as the right endpoint moves.

**Variable window invariant.** Maintain the smallest left index such that the current window is valid, or the largest window that remains valid.

#### Kadane's Algorithm


```cpp
long long max_subarray_sum(const vector<long long>& a) {
    long long best = LLONG_MIN;
    long long cur = 0;
    for (long long x : a) {
        cur = max(x, cur + x);
        best = max(best, cur);
    }
    return best;
}
```


**Why it works.** At each position, the best subarray ending here either starts here or extends the best subarray ending at the previous position. If the previous sum is harmful, discard it.

#### Contribution Technique

Instead of enumerating objects and counting their total effect directly, count each element's contribution across all objects. Example: sum of all subarray minimums can be computed by finding how many subarrays choose each element as the minimum using monotonic stacks.

#### Sweep Line

Create events, sort them, and maintain active intervals/segments. Tie-breaking is part of the algorithm: for closed intervals, starts often need to be processed before ends at the same coordinate if touching counts as overlap.

#### Mo's Algorithm


```cpp
struct Query {
    int l, r, idx; // [l, r]
};

vector<long long> mos_algorithm(vector<int>& a, vector<Query> qs) {
    int n = (int)a.size();
    int block = max(1, (int)sqrt(n));
    sort(qs.begin(), qs.end(), [&](const Query& x, const Query& y) {
        int bx = x.l / block, by = y.l / block;
        if (bx != by) return bx < by;
        return (bx & 1) ? x.r > y.r : x.r < y.r;
    });

    vector<long long> ans(qs.size());
    long long cur = 0;
    int L = 0, R = -1;
    auto add = [&](int pos) { cur += a[pos]; };
    auto remove = [&](int pos) { cur -= a[pos]; };

    for (auto q : qs) {
        while (L > q.l) add(--L);
        while (R < q.r) add(++R);
        while (L < q.l) remove(L++);
        while (R > q.r) remove(R--);
        ans[q.idx] = cur;
    }
    return ans;
}
```


Mo's algorithm with updates adds a time dimension; each query has `l, r, t` and sort by blocks of `l`, `r`, and time. It is powerful but easy to bug, so prefer Fenwick/segment tree if the query operation supports it.




## 5. Recursion, Backtracking, and Search

This section is for navigate exponential search spaces deliberately and cut them down.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Recursion tree analysis | Visualize recursive branching and per-level work. | A recurrence or recursive brute force needs complexity analysis. | Counting only depth and forgetting the number of calls per level. |
| Backtracking template | Enumerate candidates with undo. | Need all solutions or exact search under small constraints. | Missing pruning and failing to restore state. |
| Subsets | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Permutations | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Combinations | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| N-Queens | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Sudoku solver | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Generate parentheses | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Branch and bound | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Pruning | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Meet in the middle | Split exponential set into two halves. | n around 30-45 and subset enumeration appears. | Memory blowup from storing half results. |
| Iterative deepening | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| IDDFS | Explore graph/tree recursively or with stack. | Need components, times, lowlinks, topological ideas. | Recursion depth and parent-edge handling. |
| State-space search | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| BFS over states | Shortest number of unweighted steps. | All moves cost 1 or states expand by layers. | Using plain BFS on weighted edges. |
| DFS over states | Explore graph/tree recursively or with stack. | Need components, times, lowlinks, topological ideas. | Recursion depth and parent-edge handling. |
| Bidirectional BFS | Shortest number of unweighted steps. | All moves cost 1 or states expand by layers. | Using plain BFS on weighted edges. |
| A* search | Best-first search using admissible heuristic. | Shortest path in huge state graph with good heuristic. | Heuristic overestimates and breaks optimality. |
| Minimax | Adversarial optimal play. | Two-player perfect-information game. | State space too large without pruning or memoization. |
| Alpha-beta pruning | Core recursion, backtracking, and search idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Game tree search | Explore moves and opponent replies as a state tree. | Two-player games require optimal play over future choices. | State space blows up without pruning, memoization, or symmetry reduction. |


### Deep Dives and Templates

#### Backtracking

**Mental model.** Build a partial solution, test whether it can still become valid, recurse, then undo the choice.


```cpp
void generate_subsets(int i, const vector<int>& a, vector<int>& cur) {
    if (i == (int)a.size()) {
        // process cur
        return;
    }
    generate_subsets(i + 1, a, cur);
    cur.push_back(a[i]);
    generate_subsets(i + 1, a, cur);
    cur.pop_back(); // restore state
}
```


**Pruning examples.**
- N-Queens: reject a queen if its column or diagonal is occupied.
- Sudoku: choose the empty cell with the fewest possible digits.
- Combinations: stop when not enough remaining elements exist.

#### Meet in the Middle

Split `n` choices into two groups of `n/2`. Enumerate all results for each half, sort/search/combine. It changes `O(2^n)` into roughly `O(2^(n/2))` memory and time plus sorting.

#### BFS Over States

State graphs appear when a vertex is not enough information. Examples: `(node, used_coupon)`, `(r, c, keymask)`, `(position, fuel)`, `(mask, last)`.

**Invariant.** Plain BFS is correct only when every transition has equal cost. For 0/1 costs use 0-1 BFS; for nonnegative costs use Dijkstra.

#### Bidirectional BFS

Run BFS from source and target simultaneously when branching factor is high and all edges are reversible. Instead of exploring `b^d` nodes, it explores about `2*b^(d/2)`.

#### Minimax and Alpha-Beta

Minimax assumes both players play optimally. Alpha-beta pruning maintains lower and upper bounds on achievable values and cuts branches that cannot affect the result. Memoize by game state when transpositions are common.




## 6. Greedy Algorithms

This section is for make locally forced choices and prove they do not block a global optimum.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Greedy intuition | Choose a locally best action. | There is an exchange, matroid, or stays-ahead proof. | No proof; greedy often fails silently. |
| Greedy proof methods | Choose a locally best action. | There is an exchange, matroid, or stays-ahead proof. | No proof; greedy often fails silently. |
| Exchange argument | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Stays-ahead argument | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Matroid intuition | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Activity selection | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Interval scheduling | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Interval partitioning | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Minimum platforms | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Fractional knapsack | Optimize value under capacity. | Items have weights/costs and choose/take counts. | Iterating capacity in the wrong direction. |
| Huffman coding | Optimal prefix coding by merging cheapest weights. | Repeatedly combine two least costly objects. | Using it when code lengths are constrained differently. |
| Job sequencing | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Scheduling with deadlines | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Greedy with sorting | Choose a locally best action. | There is an exchange, matroid, or stays-ahead proof. | No proof; greedy often fails silently. |
| Greedy with priority queues | Choose a locally best action. | There is an exchange, matroid, or stays-ahead proof. | No proof; greedy often fails silently. |
| Greedy on graphs | Choose a locally best action. | There is an exchange, matroid, or stays-ahead proof. | No proof; greedy often fails silently. |
| Greedy on trees | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Greedy with stacks | Choose a locally best action. | There is an exchange, matroid, or stays-ahead proof. | No proof; greedy often fails silently. |
| Greedy with heaps | Choose a locally best action. | There is an exchange, matroid, or stays-ahead proof. | No proof; greedy often fails silently. |
| When greedy fails | Choose a locally best action. | There is an exchange, matroid, or stays-ahead proof. | No proof; greedy often fails silently. |
| Counterexample construction | Core greedy algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |


### Deep Dives and Templates

#### Greedy Proof Methods

| Method | Core idea | Example |
|---|---|---|
| exchange argument | transform some optimal solution to include greedy choice | interval scheduling |
| stays-ahead | greedy prefix is always at least as good as any other prefix | earliest finish time |
| cut property | lightest crossing edge is safe for MST | Kruskal/Prim |
| matroid intuition | independent sets obey exchange property | selecting max weight independent set in a matroid |

#### Interval Scheduling


```cpp
int max_non_overlapping_intervals(vector<pair<int,int>> intervals) {
    sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    int taken = 0;
    int last_end = INT_MIN;
    for (auto [l, r] : intervals) {
        if (l >= last_end) {
            ++taken;
            last_end = r;
        }
    }
    return taken;
}
```


**Why it works.** Among all intervals that could be first, the earliest finishing one leaves the most room for the future. Exchange any optimal solution's first interval with the greedy interval; the rest still fits.

#### Huffman Coding

Repeatedly merge the two lowest frequencies. The two rarest symbols can be siblings at maximum depth in some optimal prefix tree, so merging them reduces the problem size.


```cpp
long long huffman_cost(vector<long long> freq) {
    priority_queue<long long, vector<long long>, greater<long long>> pq(freq.begin(), freq.end());
    long long cost = 0;
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}
```


#### When Greedy Fails

Greedy fails when a local choice can block a globally better structure. Coin change with denominations `1, 3, 4` and target `6`: taking `4` first gives `4+1+1`, but optimum is `3+3`. If you cannot prove an exchange/stays-ahead property, suspect DP or shortest path.




## 7. Dynamic Programming

This section is for turn overlapping subproblems into a graph of states with reusable answers.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| DP intuition | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Memoization | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Tabulation | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| State design | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Transition design | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Base cases | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Ordering states | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Space optimization | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Path reconstruction | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| 1D DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| 2D DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| 3D DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| DP on grids | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| DP on strings | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| DP on subsequences | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| DP on intervals | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| DP on trees | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| DP on DAGs | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| DP on graphs | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| DP with bitmasks | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Digit DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Probability DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Expected value DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Minimax DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Game DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Knapsack 0/1 | Optimize value under capacity. | Items have weights/costs and choose/take counts. | Iterating capacity in the wrong direction. |
| Unbounded knapsack | Optimize value under capacity. | Items have weights/costs and choose/take counts. | Iterating capacity in the wrong direction. |
| Bounded knapsack | Optimize value under capacity. | Items have weights/costs and choose/take counts. | Iterating capacity in the wrong direction. |
| Multiple knapsack optimization | Optimize value under capacity. | Items have weights/costs and choose/take counts. | Iterating capacity in the wrong direction. |
| Coin change | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Subset sum | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Partition DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Longest Increasing Subsequence | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| LIS with binary search | Search over a sorted domain or monotone predicate. | Answer space is ordered and feasibility flips from false to true. | Predicate is not actually monotone, or midpoint overflows. |
| Longest Common Subsequence | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Longest Common Substring | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Edit distance | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Matrix chain multiplication | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Palindrome partitioning | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Optimal BST | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Traveling Salesman DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Steiner Tree DP overview | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | Trying to code it in contest without enough implementation practice. |
| SOS DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Broken profile DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Plug DP overview | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | Trying to code it in contest without enough implementation practice. |
| Convex Hull Trick DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Li Chao Tree DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Divide and Conquer DP optimization | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Knuth optimization | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Monotone queue optimization | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Aliens trick / Lagrangian relaxation | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Slope trick overview | Core dynamic programming idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |


### Deep Dives and Templates

#### DP State Design

Ask four questions:

1. What decision remains?
2. What information from the past affects future choices?
3. How can the answer be composed from smaller answers?
4. In what order can states be computed without cycles, or do we need memoization?

**Correctness invariant.** `dp[state]` equals the optimal/count/probability answer for exactly the subproblem encoded by `state`.

#### Knapsack


```cpp
long long knapsack_01(const vector<int>& w, const vector<int>& val, int W) {
    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < (int)w.size(); ++i) {
        for (int cap = W; cap >= w[i]; --cap) {
            dp[cap] = max(dp[cap], dp[cap - w[i]] + val[i]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

long long unbounded_knapsack(const vector<int>& w, const vector<int>& val, int W) {
    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < (int)w.size(); ++i) {
        for (int cap = w[i]; cap <= W; ++cap) {
            dp[cap] = max(dp[cap], dp[cap - w[i]] + val[i]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
```


For 0/1 knapsack, iterate capacity downward so each item is used once. For unbounded knapsack, iterate upward so the current item can be reused.

#### LIS


```cpp
int lis_length_strict(const vector<int>& a) {
    vector<int> tail;
    for (int x : a) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    return (int)tail.size();
}
```


`tail[len-1]` is the smallest possible ending value of a strict increasing subsequence of length `len`. Smaller tails are always at least as good for future extension.

#### LCS


```cpp
int lcs_length(const string& a, const string& b) {
    int n = (int)a.size(), m = (int)b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
```


#### Bitmask TSP


```cpp
long long tsp_bitmask(const vector<vector<long long>>& dist) {
    int n = (int)dist.size();
    const long long INF = (1LL << 60);
    vector<vector<long long>> dp(1 << n, vector<long long>(n, INF));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) if (dp[mask][u] < INF) {
            for (int v = 0; v < n; ++v) if (!(mask & (1 << v))) {
                int nmask = mask | (1 << v);
                dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }
    long long ans = INF;
    for (int u = 0; u < n; ++u) ans = min(ans, dp[(1 << n) - 1][u] + dist[u][0]);
    return ans;
}
```


#### DP Optimization Recognition

| Optimization | Transition shape | Typical complexity improvement |
|---|---|---|
| prefix sums | range sum/count in transition | O(n^2) to O(n) or O(n^3) to O(n^2) |
| monotone queue | max/min over sliding transition window | O(nK) to O(n) per layer |
| divide and conquer DP | `opt[i][j] <= opt[i][j+1]` | O(k n^2) to O(k n log n) or O(k n) |
| Knuth | interval DP with quadrangle inequality | O(n^3) to O(n^2) |
| convex hull trick | lines queried by x | O(n^2) to O(n log n) or O(n) |
| Li Chao tree | arbitrary line insertion/query order | O(n log C) |
| SOS DP | subset transitions | O(3^n) to O(n2^n) |

#### Digit DP

Use state `(pos, tight, started, other_info)` to count numbers up to `N`. The tight flag says whether the prefix equals `N`'s prefix; if tight is false, any digit is allowed.

#### Rerooting DP

First compute answers for subtrees. Then pass parent-side information downward so every node can act as root. The invariant is that each directed edge has a DP value representing the contribution from one side of the edge.




## 8. Trees

This section is for exploit hierarchy, ancestry, paths, and subtrees.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Tree basics | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Rooted trees | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Binary trees | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| N-ary trees | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Tree traversals | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Iterative traversals | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Level order traversal | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Binary Search Tree | Search over a sorted domain or monotone predicate. | Answer space is ordered and feasibility flips from false to true. | Predicate is not actually monotone, or midpoint overflows. |
| Balanced BST concept | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| AVL tree | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Red-black tree | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Treap | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Splay tree overview | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Trying to code it in contest without enough implementation practice. |
| Cartesian tree | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Rope overview | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Trie / prefix tree | Precompute cumulative information. | Many static range sums/counts are requested. | Off-by-one indexing and mixing inclusive/exclusive bounds. |
| Compressed trie | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Persistent trie | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Tree diameter | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Tree center | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Tree centroid | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Centroid decomposition | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Heavy-Light Decomposition | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Euler tour | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Euler tour technique for subtree queries | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Binary lifting | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Lowest Common Ancestor | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| LCA with Euler tour + RMQ | Answer ancestor/path questions. | Repeated distance or path queries on static tree. | Depth alignment and log table bounds. |
| K-th ancestor | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Distance between nodes | Core trees idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| DSU on tree / small-to-large | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Rerooting DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Virtual tree | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Link-Cut Tree overview | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Trying to code it in contest without enough implementation practice. |
| Euler Tour Tree overview | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Trying to code it in contest without enough implementation practice. |


### Deep Dives and Templates

#### Tree Mental Models

- There is exactly one simple path between any two nodes.
- Rooting a tree creates parent, depth, subtree, and ancestor relationships.
- Many tree problems become range problems after Euler tour.
- Path problems often decompose into root paths or heavy-light segments.

#### Trie


```cpp
struct Trie {
    struct Node {
        int next[26];
        int terminal = 0;
        Node() { fill(begin(next), end(next), -1); }
    };
    vector<Node> tr{Node()};

    void insert(const string& s) {
        int v = 0;
        for (char c : s) {
            int x = c - 'a';
            if (tr[v].next[x] == -1) {
                tr[v].next[x] = (int)tr.size();
                tr.push_back(Node());
            }
            v = tr[v].next[x];
        }
        tr[v].terminal++;
    }

    bool contains(const string& s) const {
        int v = 0;
        for (char c : s) {
            int x = c - 'a';
            if (x < 0 || x >= 26 || tr[v].next[x] == -1) return false;
            v = tr[v].next[x];
        }
        return tr[v].terminal > 0;
    }
};
```


Use tries for prefix queries, dictionary matching, binary XOR queries, and persistent versioned prefix sets.

#### Binary Lifting LCA


```cpp
struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> g;

    LCA(int n) : n(n), LOG(1), depth(n), g(n) {
        while ((1 << LOG) <= n) ++LOG;
        up.assign(LOG, vector<int>(n));
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int v, int p) {
        up[0][v] = p;
        for (int j = 1; j < LOG; ++j) up[j][v] = up[j - 1][up[j - 1][v]];
        for (int to : g[v]) if (to != p) {
            depth[to] = depth[v] + 1;
            dfs(to, v);
        }
    }

    void build(int root = 0) {
        depth[root] = 0;
        dfs(root, root);
    }

    int lift(int v, int k) const {
        for (int j = 0; j < LOG; ++j) if (k & (1 << j)) v = up[j][v];
        return v;
    }

    int query(int a, int b) const {
        if (depth[a] < depth[b]) swap(a, b);
        a = lift(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; --j) {
            if (up[j][a] != up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }
        return up[0][a];
    }
};
```


**Distance formula.** `dist(u,v)=depth[u]+depth[v]-2*depth[lca(u,v)]` for unweighted trees. For weighted trees, store root distance sums.

#### Euler Tour for Subtree Queries

During DFS, record `tin[v]` before children and `tout[v]` after. The subtree of `v` corresponds to the contiguous interval `[tin[v], tout[v])`. Use Fenwick/segment tree on this order.

#### Heavy-Light Decomposition

HLD splits each root-to-leaf path into O(log n) heavy paths. It supports path queries by jumping the deeper chain head upward. Use it when tree path queries have updates and the operation can be handled by a segment tree.

#### Centroid Decomposition

Repeatedly remove a centroid, which splits every component into size at most half. Use it for distance-to-marked-node, pair counting by distance, or divide-and-conquer over all paths. Complexity is often O(n log n).

#### DSU on Tree / Small-to-Large

Keep data for the heavy child and merge smaller child maps into larger maps. Each element moves O(log n) times or less, giving O(n log n) for map-based merges and often O(n) for vector/frequency arrays.




## 9. Range Query Data Structures

This section is for answer interval questions faster than scanning.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Prefix sums | Precompute cumulative information. | Many static range sums/counts are requested. | Off-by-one indexing and mixing inclusive/exclusive bounds. |
| Difference arrays | Store range updates as boundary changes. | Many range additions are followed by final reconstruction. | Forgetting the final prefix pass. |
| Fenwick Tree / BIT | Maintain prefix-composable values dynamically. | Point updates and prefix/range queries are needed. | Trying to use it for non-invertible arbitrary range queries. |
| 2D Fenwick Tree | Maintain prefix-composable values dynamically. | Point updates and prefix/range queries are needed. | Trying to use it for non-invertible arbitrary range queries. |
| Fenwick Tree for range update point query | Maintain prefix-composable values dynamically. | Point updates and prefix/range queries are needed. | Trying to use it for non-invertible arbitrary range queries. |
| Fenwick Tree for range update range query | Maintain prefix-composable values dynamically. | Point updates and prefix/range queries are needed. | Trying to use it for non-invertible arbitrary range queries. |
| Segment Tree | Maintain interval aggregates under updates. | Queries and updates interleave on arrays. | Incorrect neutral element or lazy push order. |
| Iterative Segment Tree | Maintain interval aggregates under updates. | Queries and updates interleave on arrays. | Incorrect neutral element or lazy push order. |
| Recursive Segment Tree | Maintain interval aggregates under updates. | Queries and updates interleave on arrays. | Incorrect neutral element or lazy push order. |
| Lazy propagation | Core range query data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Segment Tree Beats overview | Maintain interval aggregates under updates. | Queries and updates interleave on arrays. | Trying to code it in contest without enough implementation practice. |
| Persistent Segment Tree | Maintain interval aggregates under updates. | Queries and updates interleave on arrays. | Incorrect neutral element or lazy push order. |
| Dynamic Segment Tree | Maintain interval aggregates under updates. | Queries and updates interleave on arrays. | Incorrect neutral element or lazy push order. |
| Merge Sort Tree | Segment tree where each node stores a sorted list. | Static range queries ask counts or order by value inside intervals. | High memory constants and forgetting binary searches inside nodes. |
| Wavelet Tree | Recursively partitions values to answer range order-statistics. | Static queries ask k-th smallest, rank, or frequency in subarrays. | Incorrect value compression and off-by-one rank transitions. |
| Sparse Table | Static idempotent range queries. | No updates, many RMQ/gcd/min/max queries. | Using it for sum with overlapping intervals. |
| Disjoint Sparse Table | Static idempotent range queries. | No updates, many RMQ/gcd/min/max queries. | Using it for sum with overlapping intervals. |
| Sqrt decomposition | Core range query data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Sqrt tree overview | Block-based static range query structure with fast queries. | Static associative queries need faster than sqrt decomposition. | Large implementation complexity compared with sparse/disjoint sparse table. |
| Mo's algorithm | Offline reorder queries to reduce pointer movement. | Static array, many range queries, add/remove is cheap. | Large update dimension or expensive add/remove. |
| Ordered statistic tree | Balanced tree supporting rank and k-th element. | Need dynamic order statistics under insert/delete. | Nonstandard PBDS behavior, duplicate handling, and portability. |
| Policy based data structures | Core range query data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Range minimum query | Core range query data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Range maximum query | Core range query data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Range sum query | Core range query data structures idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Range gcd query | Exploit divisibility and Euclid. | Divisibility, ratios, normalization, modular equations. | Overflow in lcm = a/g*b. |
| Range xor query | Use parity/linear independence over GF(2). | XOR maximize, subset XOR, parity constraints. | Treating XOR like ordinary addition. |


### Deep Dives and Templates

#### Fenwick Tree


```cpp
struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int idx, long long delta) {
        for (++idx; idx <= n; idx += idx & -idx) bit[idx] += delta;
    }
    long long sum_prefix(int idx) const {
        long long res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    long long sum_range(int l, int r) const {
        if (r < l) return 0;
        return sum_prefix(r) - (l ? sum_prefix(l - 1) : 0);
    }
};
```


Fenwick works when the prefix aggregate can be updated by adding a delta and range queries can be computed from two prefixes. It is ideal for frequency counts, inversion count, order statistics by binary lifting, and dynamic prefix sums.

#### Segment Tree with Lazy Propagation


```cpp
struct SegTree {
    int n;
    vector<long long> st, lazy;

    SegTree(const vector<long long>& a) {
        n = (int)a.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int p, int l, int r, const vector<long long>& a) {
        if (l == r) { st[p] = a[l]; return; }
        int m = (l + r) / 2;
        build(p * 2, l, m, a);
        build(p * 2 + 1, m + 1, r, a);
        st[p] = st[p * 2] + st[p * 2 + 1];
    }

    void apply(int p, int l, int r, long long val) {
        st[p] += val * (r - l + 1);
        lazy[p] += val;
    }

    void push(int p, int l, int r) {
        if (lazy[p] == 0 || l == r) return;
        int m = (l + r) / 2;
        apply(p * 2, l, m, lazy[p]);
        apply(p * 2 + 1, m + 1, r, lazy[p]);
        lazy[p] = 0;
    }

    void update(int p, int l, int r, int ql, int qr, long long val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { apply(p, l, r, val); return; }
        push(p, l, r);
        int m = (l + r) / 2;
        update(p * 2, l, m, ql, qr, val);
        update(p * 2 + 1, m + 1, r, ql, qr, val);
        st[p] = st[p * 2] + st[p * 2 + 1];
    }

    long long query(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return st[p];
        push(p, l, r);
        int m = (l + r) / 2;
        return query(p * 2, l, m, ql, qr) + query(p * 2 + 1, m + 1, r, ql, qr);
    }
};
```


Lazy propagation stores postponed updates at internal nodes. The invariant is that `st[p]` already includes `lazy[p]` for its whole segment, but children may not yet know it.

#### Sparse Table


```cpp
struct SparseTable {
    vector<int> lg;
    vector<vector<int>> st; // min query

    SparseTable(const vector<int>& a) {
        int n = (int)a.size();
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
        st.assign(lg[n] + 1, vector<int>(n));
        st[0] = a;
        for (int k = 1; k <= lg[n]; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int query(int l, int r) const { // inclusive
        int k = lg[r - l + 1];
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
```


Sparse table gives O(1) static idempotent queries such as min, max, gcd. For sums use prefix sums or disjoint sparse table.

#### Persistent Segment Tree

Each update creates a new root and copies only nodes on the updated path. Use it for k-th order statistics in prefixes, versioned arrays, rollback-like queries, and offline time travel.

#### Wavelet Tree

A wavelet tree stores value ranges recursively and supports k-th smallest, count <= x, and frequency in subarray in O(log sigma). It is a favorite for static range order statistics.

#### Segment Tree Beats

Handles updates such as range chmin/chmax/add with sum/min/max queries by using extra node metadata. It is hard because lazy propagation is conditional: you push an update only when node maxima/minima structure proves it is safe.




## 10. Graph Algorithms

This section is for model relations as vertices and edges, then use structure.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Graph representation | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Adjacency list | Find ordered subsequence structure. | Need longest increasing/decreasing chain. | Confusing subsequence with subarray. |
| Adjacency matrix | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Edge list | Find ordered subsequence structure. | Need longest increasing/decreasing chain. | Confusing subsequence with subarray. |
| BFS | Shortest number of unweighted steps. | All moves cost 1 or states expand by layers. | Using plain BFS on weighted edges. |
| DFS | Explore graph/tree recursively or with stack. | Need components, times, lowlinks, topological ideas. | Recursion depth and parent-edge handling. |
| Connected components | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Flood fill | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Cycle detection undirected | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Cycle detection directed | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bipartite graph checking | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Topological sorting | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Kahn's algorithm | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| DFS topological sort | Explore graph/tree recursively or with stack. | Need components, times, lowlinks, topological ideas. | Recursion depth and parent-edge handling. |
| Shortest path in unweighted graphs | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Dijkstra's algorithm | Shortest paths with nonnegative weights. | Weighted graph, no negative edge weights. | Applying it when negative edges exist. |
| Dijkstra with path reconstruction | Shortest paths with nonnegative weights. | Weighted graph, no negative edge weights. | Applying it when negative edges exist. |
| Bellman-Ford | Shortest paths with negative edges and cycle detection. | Negative edges may exist. | Too slow for dense large graphs. |
| SPFA overview and warnings | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Floyd-Warshall | All-pairs shortest paths on small n. | n is usually <= 400-600 depending limits. | Using O(n^3) when n is large. |
| 0-1 BFS | Shortest number of unweighted steps. | All moves cost 1 or states expand by layers. | Using plain BFS on weighted edges. |
| Dial's algorithm | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Johnson's algorithm | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Shortest path DAG | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Multi-source BFS | Shortest number of unweighted steps. | All moves cost 1 or states expand by layers. | Using plain BFS on weighted edges. |
| BFS with states | Shortest number of unweighted steps. | All moves cost 1 or states expand by layers. | Using plain BFS on weighted edges. |
| Minimum Spanning Tree | Cheapest acyclic edge set connecting all vertices. | Need minimum-cost connectivity backbone, not shortest paths. | Applying MST to source-to-target distance problems. |
| Kruskal | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Prim | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Boruvka | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| DSU / Union Find | Maintain merging components. | Edges/relations are added and connectivity is queried. | Cannot directly delete edges without rollback/offline tricks. |
| DSU with rollback | Maintain merging components. | Edges/relations are added and connectivity is queried. | Cannot directly delete edges without rollback/offline tricks. |
| Offline dynamic connectivity | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Strongly Connected Components | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Kosaraju | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Tarjan SCC | Compress directed cycles. | Directed reachability has mutually reachable groups. | Using undirected component logic. |
| Condensation graph | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bridges | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Articulation points | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Biconnected components | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Euler path | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Euler circuit | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Hamiltonian path overview | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Topological DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Functional graphs | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Binary lifting on functional graphs | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| 2-SAT | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Graph coloring basics | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Planar graph basics overview | Core graph algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |


### Deep Dives and Templates

#### Representation

| Representation | Memory | Best for |
|---|---:|---|
| adjacency list | O(n+m) | sparse graphs, most CP problems |
| adjacency matrix | O(n^2) | dense graphs, O(1) edge checks, Floyd-Warshall |
| edge list | O(m) | Kruskal, Bellman-Ford, offline processing |

#### DSU


```cpp
struct DSU {
    vector<int> p, sz;

    DSU(int n = 0) { init(n); }
    void init(int n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        while (x != p[x]) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};
```


#### Dijkstra


```cpp
vector<long long> dijkstra(int n, const vector<vector<pair<int,int>>>& g, int src) {
    const long long INF = (1LL << 60);
    vector<long long> dist(n, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d != dist[v]) continue;
        for (auto [to, w] : g[v]) {
            if (dist[to] > d + w) {
                dist[to] = d + w;
                pq.push({dist[to], to});
            }
        }
    }
    return dist;
}
```


#### 0-1 BFS


```cpp
vector<int> zero_one_bfs(int n, const vector<vector<pair<int,int>>>& g, int src) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    deque<int> dq;
    dist[src] = 0;
    dq.push_front(src);
    while (!dq.empty()) {
        int v = dq.front();
        dq.pop_front();
        for (auto [to, w] : g[v]) {
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                if (w == 0) dq.push_front(to);
                else dq.push_back(to);
            }
        }
    }
    return dist;
}
```


#### Tarjan SCC


```cpp
struct TarjanSCC {
    int n, timer = 0;
    vector<vector<int>> g;
    vector<int> disc, low, in_stack, comp;
    stack<int> st;
    vector<vector<int>> comps;

    TarjanSCC(int n) : n(n), g(n), disc(n, -1), low(n), in_stack(n), comp(n, -1) {}
    void add_edge(int u, int v) { g[u].push_back(v); }

    void dfs(int v) {
        disc[v] = low[v] = timer++;
        st.push(v);
        in_stack[v] = 1;
        for (int to : g[v]) {
            if (disc[to] == -1) {
                dfs(to);
                low[v] = min(low[v], low[to]);
            } else if (in_stack[to]) {
                low[v] = min(low[v], disc[to]);
            }
        }
        if (low[v] == disc[v]) {
            vector<int> c;
            while (true) {
                int x = st.top(); st.pop();
                in_stack[x] = 0;
                comp[x] = (int)comps.size();
                c.push_back(x);
                if (x == v) break;
            }
            comps.push_back(c);
        }
    }

    vector<vector<int>> run() {
        for (int i = 0; i < n; ++i) if (disc[i] == -1) dfs(i);
        return comps;
    }
};
```


#### MST Selection

- Kruskal: sort edges, use DSU. Great when edges are already listed.
- Prim: grow from a node using priority queue. Great on dense-ish adjacency lists.
- Boruvka: repeatedly add cheapest outgoing edge per component. Useful in advanced or parallelizable settings.

#### Bridges and Articulation Points

Use DFS discovery time and lowlink. A tree edge `v -> to` is a bridge if `low[to] > tin[v]`. A non-root vertex is an articulation point if some child cannot reach an ancestor of `v`.

#### 2-SAT

For each variable `x`, create nodes `x` and `not x`. Clause `(a or b)` becomes implications `not a -> b` and `not b -> a`. It is satisfiable iff no variable and its negation are in the same SCC.




## 11. Network Flow and Matching

This section is for move capacity through networks and encode assignment constraints.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Flow network basics | Send limited resources through a network. | Capacities, cuts, disjoint paths, assignment with constraints. | Bad graph modeling or missing reverse edges. |
| Residual graph | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Ford-Fulkerson | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Edmonds-Karp | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Dinic's algorithm | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Push-relabel overview | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Min cut max flow theorem | Send limited resources through a network. | Capacities, cuts, disjoint paths, assignment with constraints. | Bad graph modeling or missing reverse edges. |
| Minimum cut | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bipartite matching | Pair objects under compatibility constraints. | Need maximum compatible pairs or assignment. | Forgetting bipartite requirement for simple algorithms. |
| Kuhn's algorithm | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Hopcroft-Karp | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Weighted bipartite matching | Pair objects under compatibility constraints. | Need maximum compatible pairs or assignment. | Forgetting bipartite requirement for simple algorithms. |
| Hungarian algorithm | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Min-cost max-flow | Send limited resources through a network. | Capacities, cuts, disjoint paths, assignment with constraints. | Bad graph modeling or missing reverse edges. |
| Circulation with demands | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Lower-bound flows | Send limited resources through a network. | Capacities, cuts, disjoint paths, assignment with constraints. | Bad graph modeling or missing reverse edges. |
| Vertex capacity transformation | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Edge-disjoint paths | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Project selection problem | Core network flow and matching idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Matching reductions | Pair objects under compatibility constraints. | Need maximum compatible pairs or assignment. | Forgetting bipartite requirement for simple algorithms. |


### Deep Dives and Templates

#### Flow Modeling

Create source, sink, capacities, and conservation constraints. A cut partitions vertices into source-side and sink-side; max-flow min-cut says the maximum sendable flow equals the minimum capacity cut.

#### Dinic's Algorithm


```cpp
struct Dinic {
    struct Edge { int to, rev; long long cap; };
    int n;
    vector<vector<Edge>> g;
    vector<int> level, it;

    Dinic(int n) : n(n), g(n), level(n), it(n) {}

    void add_edge(int v, int to, long long cap) {
        Edge a{to, (int)g[to].size(), cap};
        Edge b{v, (int)g[v].size(), 0};
        g[v].push_back(a);
        g[to].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (const auto& e : g[v]) if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, int t, long long f) {
        if (v == t) return f;
        for (int& i = it[v]; i < (int)g[v].size(); ++i) {
            Edge& e = g[v][i];
            if (e.cap <= 0 || level[e.to] != level[v] + 1) continue;
            long long pushed = dfs(e.to, t, min(f, e.cap));
            if (pushed) {
                e.cap -= pushed;
                g[e.to][e.rev].cap += pushed;
                return pushed;
            }
        }
        return 0;
    }

    long long max_flow(int s, int t) {
        long long flow = 0;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (long long pushed = dfs(s, t, LLONG_MAX / 4)) flow += pushed;
        }
        return flow;
    }
};
```


**Complexity.** General bound is O(V^2 E), but it is usually fast in competitive programming. For bipartite unit networks it is much faster in practice and has stronger special-case bounds.

#### Bipartite Matching: Hopcroft-Karp


```cpp
struct HopcroftKarp {
    int n, m;
    vector<vector<int>> g;
    vector<int> dist, pairU, pairV;

    HopcroftKarp(int n, int m) : n(n), m(m), g(n), dist(n), pairU(n, -1), pairV(m, -1) {}
    void add_edge(int u, int v) { g[u].push_back(v); }

    bool bfs() {
        queue<int> q;
        bool found = false;
        for (int u = 0; u < n; ++u) {
            if (pairU[u] == -1) dist[u] = 0, q.push(u);
            else dist[u] = -1;
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                int u2 = pairV[v];
                if (u2 == -1) found = true;
                else if (dist[u2] == -1) {
                    dist[u2] = dist[u] + 1;
                    q.push(u2);
                }
            }
        }
        return found;
    }

    bool dfs(int u) {
        for (int v : g[u]) {
            int u2 = pairV[v];
            if (u2 == -1 || (dist[u2] == dist[u] + 1 && dfs(u2))) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int max_matching() {
        int matching = 0;
        while (bfs()) {
            for (int u = 0; u < n; ++u) {
                if (pairU[u] == -1 && dfs(u)) ++matching;
            }
        }
        return matching;
    }
};
```


#### Reductions

| Problem shape | Model |
|---|---|
| assign left objects to right objects | bipartite matching |
| select projects with prerequisites/profits | min cut |
| edge-disjoint paths | unit capacity max flow |
| vertex capacity | split vertex into `v_in -> v_out` with capacity |
| lower bounds | subtract lower bound, add balances, connect super source/sink |
| min-cost assignment | Hungarian or min-cost max-flow |

#### Min-Cost Max-Flow

Use potentials with Dijkstra for nonnegative reduced costs, or SPFA for small/simple cases. Common pitfalls are negative cycles, overflow in cost*flow, and forgetting reverse edges with negative cost.




## 12. String Algorithms

This section is for turn text comparison into reusable structure.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| String basics in C++ | Language/tooling feature for shorter, safer implementations. | You need robust templates, custom ordering, or standard containers. | Undefined behavior, invalidated iterators, or comparator that is not strict weak ordering. |
| Naive pattern matching | Pair objects under compatibility constraints. | Need maximum compatible pairs or assignment. | Forgetting bipartite requirement for simple algorithms. |
| KMP algorithm | Find pattern occurrences in linear time. | Single pattern, many overlap possibilities. | Wrong prefix-function fallback. |
| Prefix function | Precompute cumulative information. | Many static range sums/counts are requested. | Off-by-one indexing and mixing inclusive/exclusive bounds. |
| Z algorithm | Compute prefix matches at each position. | Need string matching, borders, or prefix comparisons. | Incorrect [l,r] window update. |
| Rabin-Karp | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Rolling hash | Compare substrings probabilistically. | Many equality checks on substrings. | Single modulus collision risk. |
| Double hashing | Compare substrings probabilistically. | Many equality checks on substrings. | Single modulus collision risk. |
| Polynomial hashing | Compare substrings probabilistically. | Many equality checks on substrings. | Single modulus collision risk. |
| Trie | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Aho-Corasick automaton | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Manacher's algorithm | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Suffix array | Index all suffixes/substrings. | Need lexicographic substring or repeated substring queries. | Large constants and indexing mistakes. |
| LCP array | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Kasai algorithm | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Suffix automaton | Index all suffixes/substrings. | Need lexicographic substring or repeated substring queries. | Large constants and indexing mistakes. |
| Suffix tree overview | Compressed trie of all suffixes. | Need powerful substring indexing with explicit path labels. | Very difficult implementation; suffix array or suffix automaton is often safer. |
| Lyndon factorization | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Duval's algorithm | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Booth's algorithm | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Minimal string rotation | Core string algorithms idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Palindrome tree / Eertree overview | Structure of all distinct palindromic substrings. | Need online palindrome counting or distinct palindrome queries. | Suffix links and odd/even root initialization are easy to mishandle. |
| Wildcard matching | Match text against patterns with special wildcard symbols. | Need string pattern feasibility with `?`, `*`, or similar tokens. | Greedy rules fail for general patterns; DP state definitions matter. |
| Regex DP overview | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | Trying to code it in contest without enough implementation practice. |


### Deep Dives and Templates

#### KMP Prefix Function


```cpp
vector<int> prefix_function(const string& s) {
    vector<int> pi(s.size());
    for (int i = 1; i < (int)s.size(); ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_find(const string& text, const string& pat) {
    string combined = pat + "#" + text;
    vector<int> pi = prefix_function(combined);
    vector<int> occ;
    int m = (int)pat.size();
    for (int i = m + 1; i < (int)combined.size(); ++i) {
        if (pi[i] == m) occ.push_back(i - 2 * m);
    }
    return occ;
}
```


#### Z Algorithm


```cpp
vector<int> z_function(const string& s) {
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
```


#### Rolling Hash


```cpp
struct RollingHash {
    static const long long MOD = 1000000007;
    static const long long BASE = 911382323;
    vector<long long> pref, pw;

    RollingHash(const string& s) {
        int n = (int)s.size();
        pref.assign(n + 1, 0);
        pw.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = (pref[i] * BASE + s[i]) % MOD;
            pw[i + 1] = pw[i] * BASE % MOD;
        }
    }

    long long get(int l, int r) const { // [l, r)
        long long res = (pref[r] - pref[l] * pw[r - l]) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};
```


Use double hashing or 64-bit randomized hashing when collision risk matters. Hashing is excellent for substring equality, palindrome checks with reverse hash, and binary searching longest common prefix.

#### Aho-Corasick

Build a trie of patterns, then failure links like KMP over trie nodes. It matches many patterns in total O(text length + total matches + alphabet transitions). Use it for dictionary matching, forbidden substring DP, and multi-pattern counting.

#### Manacher

Computes odd/even palindrome radii in O(n). Use it when all palindromic substrings or longest palindrome centered at each position are needed.

#### Suffix Array and LCP

Suffix array sorts all suffixes. Kasai computes adjacent LCP values in O(n). Use RMQ over LCP for longest common prefix of arbitrary suffixes, repeated substring, and lexicographic substring tasks.

#### Suffix Automaton

A SAM compactly represents all substrings of a string. Each state corresponds to an equivalence class of substrings with the same end positions. Use it for number of distinct substrings, longest common substring, occurrence counts, and advanced online string DP.




## 13. Bit Manipulation

This section is for represent small sets and parity information in machine words.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Binary representation | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bitwise operators | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Set bit | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Clear bit | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Toggle bit | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Check bit | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Lowbit | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Counting set bits | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Builtin functions | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Power of two | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| XOR properties | Use parity/linear independence over GF(2). | XOR maximize, subset XOR, parity constraints. | Treating XOR like ordinary addition. |
| XOR basis / linear basis | Use parity/linear independence over GF(2). | XOR maximize, subset XOR, parity constraints. | Treating XOR like ordinary addition. |
| Submask enumeration | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Superset enumeration | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bitmask subsets | Represent subsets as integers. | n is small, often <= 20-25. | Looping over 2^n when n is too large. |
| Bitmask DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Gray code | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bitset optimization | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Fast subset convolution overview | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Popcount tricks | Core bit manipulation idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |


### Deep Dives and Templates

#### Core Operations

| Operation | Expression |
|---|---|
| check bit b | `(x >> b) & 1` |
| set bit b | `x | (1LL << b)` |
| clear bit b | `x & ~(1LL << b)` |
| toggle bit b | `x ^ (1LL << b)` |
| lowbit | `x & -x` |
| power of two | `x > 0 && (x & (x-1)) == 0` |
| popcount | `__builtin_popcountll(x)` |

#### Submask Enumeration


```cpp
for (int sub = mask; sub; sub = (sub - 1) & mask) {
    // sub is a non-empty submask of mask
}
// Include zero if needed after the loop.
```


The total number of `(mask, submask)` pairs is `3^n` because each bit can be absent from mask, present only in mask, or present in both.

#### XOR Basis


```cpp
struct XorBasis {
    static const int LOG = 62;
    long long basis[LOG] = {};

    bool insert(long long x) {
        for (int b = LOG - 1; b >= 0; --b) if (x & (1LL << b)) {
            if (!basis[b]) { basis[b] = x; return true; }
            x ^= basis[b];
        }
        return false;
    }

    long long max_xor(long long start = 0) const {
        long long ans = start;
        for (int b = LOG - 1; b >= 0; --b) ans = max(ans, ans ^ basis[b]);
        return ans;
    }
};
```


**Why it works.** It is Gaussian elimination over bits in GF(2). Each basis vector has a highest set bit not owned by another vector, so vectors are independent.

#### Bitset Optimization

`bitset` can turn O(n^2 / word_size) operations into fast word-parallel code. Classic examples: subset sum, transitive closure with bitsets, matching candidates, and LCS-like speedups.


```cpp
bitset<100001> possible;
possible[0] = 1;
for (int w : weights) possible |= (possible << w);
```





## 14. Number Theory

This section is for solve arithmetic, modular, divisibility, counting, and polynomial problems.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Divisibility | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| GCD | Exploit divisibility and Euclid. | Divisibility, ratios, normalization, modular equations. | Overflow in lcm = a/g*b. |
| Euclidean algorithm | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Extended Euclidean algorithm | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| LCM | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Prime checking | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Sieve of Eratosthenes | Precompute primes or multiplicative functions. | Many prime/factor queries up to N. | Memory or O(N log log N) too high for N. |
| Linear sieve | Precompute primes or multiplicative functions. | Many prime/factor queries up to N. | Memory or O(N log log N) too high for N. |
| Segmented sieve | Precompute primes or multiplicative functions. | Many prime/factor queries up to N. | Memory or O(N log log N) too high for N. |
| Prime factorization | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Number of divisors | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Sum of divisors | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Euler's totient function | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Mobius function | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Mobius inversion overview | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Modular arithmetic | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Modular exponentiation | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Modular inverse | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Fermat's little theorem | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Euler's theorem | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Chinese Remainder Theorem | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| General CRT | Combine modular congruences. | Need x satisfying several remainders. | Non-coprime moduli conflict. |
| Diophantine equations | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Modular linear equations | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Primitive roots overview | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Discrete logarithm | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Baby-step giant-step | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Miller-Rabin primality test | Fast primality for large integers. | 64-bit primality checks. | Using random bases without deterministic coverage. |
| Pollard Rho factorization | Factor large composite integers. | 64-bit factorization beyond trial division. | Bad randomness or overflow in multiplication. |
| Combinatorics | Count arrangements exactly. | Problem asks number of ways, modulo arithmetic, symmetries. | Double counting or ignoring indistinguishable objects. |
| Factorials modulo prime | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| nCr precomputation | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Lucas theorem | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Catalan numbers | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Stirling numbers overview | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Inclusion-exclusion | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Burnside's lemma | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Polya enumeration overview | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Fast Fourier Transform | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Number Theoretic Transform | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Polynomial multiplication | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Formal power series overview | Core number theory idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |


### Deep Dives and Templates

#### GCD, Modular Power, Extended Euclid


```cpp
long long gcd_ll(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return abs(a);
}

long long mod_pow(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

long long ext_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

optional<long long> mod_inverse(long long a, long long mod) {
    long long x, y;
    long long g = ext_gcd(a, mod, x, y);
    if (g != 1) return nullopt;
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
```


#### Sieve


```cpp
vector<int> sieve_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;
    for (long long p = 2; p * p <= n; ++p) if (is_prime[p]) {
        for (long long x = p * p; x <= n; x += p) is_prime[x] = false;
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i) if (is_prime[i]) primes.push_back(i);
    return primes;
}
```


#### Combinations Modulo Prime


```cpp
const long long MOD = 1000000007;
vector<long long> fact, invfact;

long long mod_pow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void build_combinations(int n) {
    fact.assign(n + 1, 1);
    invfact.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
    invfact[n] = mod_pow(fact[n], MOD - 2);
    for (int i = n; i >= 1; --i) invfact[i - 1] = invfact[i] * i % MOD;
}

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}
```


#### CRT

For coprime moduli, combine `x = ai mod mi` using modular inverses. For non-coprime moduli, two congruences are compatible only if remainders agree modulo `gcd(m1,m2)`.

#### Mobius Inversion

If `F(n)=sum_{d|n} f(d)`, then `f(n)=sum_{d|n} mu(d) F(n/d)`. Use it when a count over divisors includes objects with gcd divisible by something and you need gcd exactly equal to something.

#### Miller-Rabin and Pollard Rho

Miller-Rabin tests primality quickly for 64-bit integers with deterministic bases. Pollard Rho factors large composites using randomized cycle detection and gcd. Both need overflow-safe modular multiplication.

#### FFT and NTT

FFT multiplies polynomials using complex roots of unity and must manage precision. NTT uses modular roots under special primes and is exact modulo that prime. Use convolution when a nested pair-counting loop depends only on sums/differences.




## 15. Combinatorics and Probability

This section is for count configurations and reason about randomness.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Counting principles | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Permutations | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Combinations | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Stars and bars | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Inclusion-exclusion | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Pigeonhole principle | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Catalan structures | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Derangements | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Probability basics | Compute likelihoods or expectations. | Random process with linearity or state transitions. | Assuming independence where none exists. |
| Expected value | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Linearity of expectation | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Markov chains overview | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Randomized algorithms | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Reservoir sampling | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Monte Carlo vs Las Vegas algorithms | Core combinatorics and probability idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |


### Deep Dives and Templates

#### Counting Principles

- Product rule: independent stages multiply.
- Sum rule: disjoint alternatives add.
- Complement: count total minus bad cases.
- Inclusion-exclusion: add singles, subtract pair overlaps, add triple overlaps, and so on.

#### Stars and Bars

Number of nonnegative integer solutions to `x1 + ... + xk = n` is `C(n+k-1, k-1)`. With positive variables, subtract 1 from each first.

#### Catalan Structures

`C_n = C(2n,n)/(n+1)`. Appears in balanced parentheses, noncrossing matchings, triangulations, and monotonic lattice paths that do not cross a diagonal.

#### Expected Value

Linearity of expectation says `E[X+Y]=E[X]+E[Y]` even without independence. This is often the simplest way to count expected inversions, expected selected items, or expected number of occupied boxes.

#### Reservoir Sampling


```cpp
int chosen = -1;
for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (randint(0, i) == 0) chosen = x; // each seen item has probability 1/(i+1)
}
```


#### Randomized Algorithms

Monte Carlo algorithms may be wrong with small probability but have bounded time. Las Vegas algorithms are always correct but have random running time. In contests, randomized hashing and treaps are common; seed carefully.




## 16. Computational Geometry

This section is for translate shapes into robust algebraic predicates.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Points and vectors | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Dot product | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Cross product | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Orientation test | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Segment intersection | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Line intersection | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Polygon area | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Pick's theorem | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Convex hull | Keep extreme boundary points. | Need outer envelope or rotating calipers. | Collinear handling mismatch. |
| Graham scan | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Monotonic chain | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Rotating calipers | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Closest pair of points | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Sweep line | Process events in sorted coordinate order. | Intervals/segments change active set over time. | Wrong event tie-breaking. |
| Rectangle union area | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Half-plane intersection overview | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Point in polygon | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Convex polygon point query | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Minkowski sum overview | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Circle-line intersection | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Circle-circle intersection | Core computational geometry idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Geometry precision issues | Use coordinates and predicates. | Points, lines, polygons, distances, intersections. | Floating precision and degenerate cases. |


### Deep Dives and Templates

#### Robust Integer Geometry


```cpp
struct Pt {
    long long x, y;
    bool operator<(const Pt& other) const {
        return x == other.x ? y < other.y : x < other.x;
    }
    bool operator==(const Pt& other) const {
        return x == other.x && y == other.y;
    }
};

Pt operator-(Pt a, Pt b) { return {a.x - b.x, a.y - b.y}; }
long long cross(Pt a, Pt b) { return a.x * b.y - a.y * b.x; }
long long cross(Pt a, Pt b, Pt c) { return cross(b - a, c - a); }

int sgn(long long x) { return (x > 0) - (x < 0); }

bool on_segment(Pt a, Pt b, Pt p) {
    return cross(a, b, p) == 0 &&
           min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

bool segments_intersect(Pt a, Pt b, Pt c, Pt d) {
    long long c1 = cross(a, b, c), c2 = cross(a, b, d);
    long long c3 = cross(c, d, a), c4 = cross(c, d, b);
    if (sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0) return true;
    return on_segment(a, b, c) || on_segment(a, b, d) ||
           on_segment(c, d, a) || on_segment(c, d, b);
}

vector<Pt> convex_hull(vector<Pt> p) {
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1) return p;
    vector<Pt> hull;
    for (Pt x : p) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), x) <= 0) hull.pop_back();
        hull.push_back(x);
    }
    int lower = (int)hull.size();
    for (int i = (int)p.size() - 2; i >= 0; --i) {
        Pt x = p[i];
        while ((int)hull.size() > lower && cross(hull[hull.size()-2], hull.back(), x) <= 0) hull.pop_back();
        hull.push_back(x);
    }
    hull.pop_back();
    return hull;
}
```


#### Orientation

The sign of cross product `cross(b-a, c-a)` tells whether `a -> b -> c` turns left, right, or is collinear. This single predicate powers convex hulls, segment intersection, polygon area, and point-in-convex-polygon checks.

#### Polygon Area

Shoelace formula: twice signed area is `sum cross(p[i], p[i+1])`. Use absolute value for ordinary area. Pick's theorem for lattice polygons: `A = I + B/2 - 1`.

#### Rotating Calipers

After convex hull, antipodal pointers can compute diameter, minimum width, and some farthest pair quantities in linear time over hull size.

#### Geometry Precision Checklist

- Prefer integer predicates for integer coordinates.
- Use `long double` for distances and angles.
- Compare with epsilon only at final floating predicates.
- Handle collinear, duplicate, vertical, horizontal, tangent, and endpoint cases.




## 17. Advanced Competitive Programming Techniques

This section is for combine offline ordering, persistence, decomposition, and algebraic tricks.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Offline queries | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Online queries | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Divide and conquer on queries | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Parallel binary search | Search over a sorted domain or monotone predicate. | Answer space is ordered and feasibility flips from false to true. | Predicate is not actually monotone, or midpoint overflows. |
| CDQ divide and conquer | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Small-to-large merging | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| DSU rollback | Maintain merging components. | Edges/relations are added and connectivity is queried. | Cannot directly delete edges without rollback/offline tricks. |
| Dynamic connectivity | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Persistent data structures | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Randomized data structures | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Treap | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Implicit treap | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Rope | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Link-Cut Tree | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Euler Tour Tree | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Heavy-Light Decomposition | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Centroid decomposition | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Virtual tree | Use connected acyclic structure. | Unique paths, parent/child, subtree, or ancestor constraints appear. | Forgetting root choice or disconnected input. |
| Wavelet tree | Recursively partitions values for range order-statistics. | Static subarray queries ask rank, frequency, or k-th by value. | Coordinate/rank mapping mistakes across levels. |
| Li Chao tree | Maintains lower or upper envelope of lines over an x-domain. | DP or geometry needs min/max of linear functions at query points. | Wrong x-domain, overflow in line evaluation, or mixing min/max variants. |
| Convex Hull Trick | Maintains useful lines for linear DP transitions. | Transition has `m*x+b` and queries need min/max over previous states. | Monotonic assumptions are missing; Li Chao or dynamic CHT may be needed. |
| Dynamic CHT | Online line container for arbitrary insertion/query order. | Lines and queries arrive dynamically and x-values are not monotone. | Comparator and intersection precision bugs. |
| Segment Tree Beats | Maintain interval aggregates under updates. | Queries and updates interleave on arrays. | Incorrect neutral element or lazy push order. |
| Slope trick | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| FFT/NTT | Convolve sequences quickly. | Polynomial multiplication or count pair sums. | Precision for FFT; modulus roots for NTT. |
| SOS DP | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Subset convolution | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Matroid intersection overview | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Simulated annealing overview | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Divide and conquer optimization | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Knuth optimization | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Aliens trick | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Bitset convolution tricks | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Meet-in-the-middle advanced | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Random hashing | Compare substrings probabilistically. | Many equality checks on substrings. | Single modulus collision risk. |
| Sprague-Grundy theorem | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Nim | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Impartial games | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Combinatorial game theory basics | Core advanced competitive programming techniques idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |


### Deep Dives and Templates

#### Rollback DSU


```cpp
struct RollbackDSU {
    vector<int> p, sz;
    vector<pair<int,int>> history;
    int comps;

    RollbackDSU(int n) : p(n), sz(n, 1), comps(n) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) const {
        while (x != p[x]) x = p[x];
        return x;
    }

    int snapshot() const { return (int)history.size(); }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) {
            history.push_back({-1, -1});
            return false;
        }
        if (sz[a] < sz[b]) swap(a, b);
        history.push_back({b, sz[a]});
        p[b] = a;
        sz[a] += sz[b];
        --comps;
        return true;
    }

    void rollback(int snap) {
        while ((int)history.size() > snap) {
            auto [b, oldSizeA] = history.back();
            history.pop_back();
            if (b == -1) continue;
            int a = p[b];
            sz[a] = oldSizeA;
            p[b] = b;
            ++comps;
        }
    }
};
```


Rollback DSU cannot use path compression because rollback needs to undo parent changes. It uses union by size and records enough information to restore snapshots.

#### Li Chao Tree


```cpp
struct LiChao {
    struct Line {
        long long m, b;
        long long get(long long x) const { return m * x + b; }
    };
    struct Node {
        Line ln;
        Node *l = nullptr, *r = nullptr;
        Node(Line ln) : ln(ln) {}
    };
    const long long INF = (1LL << 62);
    long long X_L, X_R;
    Node* root = nullptr;

    LiChao(long long xl, long long xr) : X_L(xl), X_R(xr) {}

    void add_line(Line nw) { add_line(root, X_L, X_R, nw); }

    void add_line(Node*& node, long long l, long long r, Line nw) {
        if (!node) { node = new Node(nw); return; }
        long long mid = (l + r) / 2;
        bool left = nw.get(l) < node->ln.get(l);
        bool middle = nw.get(mid) < node->ln.get(mid);
        if (middle) swap(nw, node->ln);
        if (l == r) return;
        if (left != middle) add_line(node->l, l, mid, nw);
        else add_line(node->r, mid + 1, r, nw);
    }

    long long query(long long x) const { return query(root, X_L, X_R, x); }

    long long query(Node* node, long long l, long long r, long long x) const {
        if (!node) return INF;
        long long ans = node->ln.get(x);
        if (l == r) return ans;
        long long mid = (l + r) / 2;
        if (x <= mid) return min(ans, query(node->l, l, mid, x));
        return min(ans, query(node->r, mid + 1, r, x));
    }
};
```


Use Li Chao when DP has transitions `dp[i] = min_j(m_j*x_i + b_j)` with arbitrary insertion/query order over known integer x-range.

#### Offline vs Online

Offline algorithms read all queries first and reorder them. This enables Mo's algorithm, parallel binary search, CDQ divide and conquer, offline dynamic connectivity, and coordinate compression. Online algorithms answer immediately and need data structures such as Fenwick, segment tree, balanced BST, or dynamic CHT.

#### Game Theory

For impartial games under normal play, Grundy number of a state is the mex of child Grundy numbers. XOR of Grundy numbers over independent subgames determines winner: nonzero means first player can force a win.

#### Persistent Data Structures

Persistence keeps old versions available. Path-copy segment trees, persistent tries, and functional stacks are common. Use persistence when queries ask about historical prefixes or when rollback order is not stack-like.




## 18. ICPC-Level Problem Solving

This section is for turn contest statements into solvable models quickly.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| How to read constraints | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Choosing algorithms from constraints | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Recognizing hidden graph problems | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Recognizing DP states | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| Recognizing greedy proof requirements | Choose a locally best action. | There is an exchange, matroid, or stays-ahead proof. | No proof; greedy often fails silently. |
| Reducing problems to known algorithms | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Modeling as shortest path | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Modeling as flow | Send limited resources through a network. | Capacities, cuts, disjoint paths, assignment with constraints. | Bad graph modeling or missing reverse edges. |
| Modeling as matching | Pair objects under compatibility constraints. | Need maximum compatible pairs or assignment. | Forgetting bipartite requirement for simple algorithms. |
| Modeling as SAT / 2-SAT | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Modeling with DSU | Maintain merging components. | Edges/relations are added and connectivity is queried. | Cannot directly delete edges without rollback/offline tricks. |
| Modeling with intervals | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Modeling with geometry | Use coordinates and predicates. | Points, lines, polygons, distances, intersections. | Floating precision and degenerate cases. |
| Debugging under contest pressure | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Stress testing solutions | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Writing brute force checkers | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Time management in ICPC | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Team strategy for ICPC | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Template organization | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Avoiding overengineering | Core icpc-level problem solving idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |


### Deep Dives and Templates

#### Reading Constraints

| Constraint clue | Likely family |
|---|---|
| `n <= 10` | permutations, backtracking, bitmask with factorial caution |
| `n <= 20` | bitmask DP, meet in the middle |
| `n <= 40` | meet in the middle |
| `n <= 500` | O(n^3), Floyd-Warshall, interval DP |
| `n <= 5000` | O(n^2), LIS DP, bitset optimization |
| `n <= 2e5` | O(n log n), trees, Fenwick, segment tree, graph linear/log |
| huge coordinates | coordinate compression, sweep line |
| many queries | preprocessing, offline algorithms, data structures |
| modulo count | DP/combinatorics/number theory |

#### Modeling Tricks

- Hidden graph: states are configurations, moves are edges.
- Shortest path: minimize cost after transitions; choose BFS/0-1 BFS/Dijkstra by weights.
- Flow: capacity, disjointness, assignment, "at most k" constraints.
- Matching: pair left/right objects with compatibility.
- DSU: equality, components, incremental connectivity.
- Intervals: sort endpoints, sweep, greedy by finish time, interval DP.
- Geometry: replace visual language with orientation, distance, and intersection predicates.

#### Contest Debugging

1. Re-read input constraints and indexing.
2. Test smallest cases by hand.
3. Test all equal, sorted, reverse, negative, disconnected, and maximum values.
4. Add assertions for invariants.
5. Compare optimized solution against brute force on random small cases.
6. Check overflow and modulo normalization.
7. Remove or guard debug output.

#### Team Strategy

During ICPC, divide tasks by risk. One teammate reads and classifies, one codes an easy/medium solution, one challenges proofs and tests. Keep a shared template but avoid importing untested code during the contest.




## 19. Hardest / Research-Oriented Overviews

This section is for know what exists, when it appears, and what to learn before implementing it.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Link-Cut Trees | Splay-based dynamic forest structure for path queries and link/cut. | Edges are inserted/deleted while tree path aggregates are queried. | Reversal flags, preferred paths, and expose/splay invariants. |
| Euler Tour Trees | Dynamic forest representation using Euler tour sequences in balanced BSTs. | Need link/cut plus subtree or component aggregates. | Representing edge occurrences and reroot operations incorrectly. |
| Top Trees overview | Cluster-based framework for dynamic tree queries. | Very advanced dynamic tree problems need flexible path/subtree aggregation. | Complex cluster merge/split interface and heavy implementation burden. |
| Dynamic MST overview | Connect all vertices with minimum edge cost. | Need cheapest network/connectivity backbone. | Trying to code it in contest without enough implementation practice. |
| General graph matching overview | Pair objects under compatibility constraints. | Need maximum compatible pairs or assignment. | Trying to code it in contest without enough implementation practice. |
| Blossom algorithm overview | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Gomory-Hu tree overview | Tree encoding all-pairs min cuts in an undirected graph. | Need many s-t min-cut values. | Requires multiple max-flow runs and careful cut partition updates. |
| Dominator tree overview | Captures mandatory vertices on paths from a start node in a directed graph. | Compiler/control-flow or directed reachability dominance appears. | Semi-dominator implementation is subtle. |
| Heavy graph decomposition ideas | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Min-cost circulation | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Parametric search | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| SMAWK algorithm | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Cartesian tree RMQ | Converts RMQ to LCA through a heap-ordered tree over array indices. | Static RMQ needs linear preprocessing theory or succinct structures. | Mishandling duplicate tie-breaking and Euler depth construction. |
| Suffix automaton advanced applications | Index all suffixes/substrings. | Need lexicographic substring or repeated substring queries. | Large constants and indexing mistakes. |
| Palindromic automaton | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Persistent lazy segment tree | Maintain interval aggregates under updates. | Queries and updates interleave on arrays. | Incorrect neutral element or lazy push order. |
| Kinetic data structures overview | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Advanced polynomial algorithms | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Berlekamp-Massey algorithm | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Linear recurrence exponentiation | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Fast Walsh-Hadamard Transform | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Matroid theory overview | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Matroid intersection overview | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |
| Convex optimization basics for CP | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Min-plus convolution overview | Core hardest / research-oriented overviews idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Trying to code it in contest without enough implementation practice. |


### Deep Dives and Templates

For these topics, full implementation is often too long or too specialized for a first handbook pass. The goal is to recognize them, know the prerequisites, and know why they are difficult.

| Topic | Appears when | Prerequisites | Complexity target | Why it is hard |
|---|---|---|---|---|
| Link-Cut Tree | dynamic tree path queries with link/cut | splay trees, lazy propagation | amortized O(log n) | reversal flags and preferred path invariants |
| Euler Tour Tree | dynamic forests with subtree aggregates | balanced BST/treap | O(log n) | representing each edge occurrence correctly |
| Top Trees | general dynamic tree clustering | dynamic trees | O(log n) | complex cluster interface |
| Dynamic MST | maintain MST under updates | MST, dynamic trees | polylog or harder | replacement edge search |
| Blossom | maximum matching in general graphs | augmenting paths | O(n^3) common | odd cycle contraction |
| Gomory-Hu Tree | all-pairs min cuts in undirected graph | max-flow | n-1 max-flows | cut tree interpretation |
| Dominator Tree | flow graph dominance | DFS trees, union-find ideas | near-linear | semi-dominator logic |
| Parametric Search | optimize parameter with decision procedure | binary search, parallelism insight | varies | monotonicity and precision |
| SMAWK | row minima in totally monotone matrix | monge arrays | O(n+m) | proving total monotonicity |
| Berlekamp-Massey | shortest linear recurrence | finite fields | O(n^2) | modular inverses and indexing |
| FWHT | XOR/AND/OR convolution | bit DP, transforms | O(n log n) | inverse transform normalization |
| Min-plus Convolution | distance-like convolution | convexity/special structure | hard in general | assuming nonexistent speedup |

#### Implementation Advice

- Do not first-code these in an important contest unless you have a tested template.
- Learn the invariant before reading code.
- Build tiny visual tests and brute force checkers.
- Prefer reductions to simpler tools if constraints allow them.
- For research-oriented overviews, know names and use cases even if you cannot implement them yet.




## 20. Final Guides

This section is for select tools under pressure and revise systematically.

### Prerequisites

- Understand the invariant being maintained.
- Know the relevant input size and memory limit.
- Be comfortable translating a statement into states, events, edges, or intervals.

### When to Use This Family

- The statement contains objects naturally matching this section's model.
- A direct brute force has repeated work that this family removes.
- The constraints match the complexity shown in the selection guides.

### When Not to Use This Family

- Its assumptions do not hold, such as monotonicity for binary search, nonnegative weights for Dijkstra, static input for sparse table, or acyclicity for tree DP.
- A simpler structure gives the same complexity with fewer bugs.
- The proof obligation cannot be satisfied.

### Topic Coverage Checklist

| Topic | What it is | Recognition signal | Common failure mode |
|---|---|---|---|
| Constraint-to-algorithm table | Core final guides idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Problem pattern-to-technique table | Core final guides idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Data structure selection guide | Core final guides idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Graph algorithm selection guide | Core final guides idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| DP pattern selection guide | Reuse answers to overlapping subproblems. | Choices form states; brute force repeats work. | State missing information needed for future decisions. |
| String algorithm selection guide | Core final guides idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Range query selection guide | Core final guides idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Number theory selection guide | Core final guides idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Geometry checklist | Find ordered subsequence structure. | Need longest increasing/decreasing chain. | Confusing subsequence with subarray. |
| Common C++ bugs checklist | Language/tooling feature for shorter, safer implementations. | You need robust templates, custom ordering, or standard containers. | Undefined behavior, invalidated iterators, or comparator that is not strict weak ordering. |
| Contest debugging checklist | Find ordered subsequence structure. | Need longest increasing/decreasing chain. | Confusing subsequence with subarray. |
| Study roadmap from beginner to ICPC advanced | Core final guides idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Suggested order to learn topics | Core final guides idea or tool. | The statement asks for repeated decisions, queries, transformations, or proof of optimality in this area. | Using it without checking constraints, invariants, and edge cases. |
| Revision checklist | Find ordered subsequence structure. | Need longest increasing/decreasing chain. | Confusing subsequence with subarray. |


### Constraint-to-Algorithm Guide

| Constraint / feature | Candidate techniques |
|---|---|
| `n <= 10` | brute force, permutations, backtracking, minimax |
| `n <= 20` | bitmask DP, subset enumeration, SOS DP |
| `n <= 40` | meet in the middle |
| `n <= 500` | Floyd-Warshall, O(n^3) DP |
| `n <= 5000` | O(n^2), bitset acceleration |
| `n <= 2e5` | O(n log n), Fenwick, segment tree, graph linear algorithms |
| edge weights 0/1 | 0-1 BFS |
| nonnegative weights | Dijkstra |
| negative edges | Bellman-Ford, Johnson, potentials |
| static range min | sparse table |
| range updates | lazy segment tree, difference array if offline |
| all substring structure | suffix array, suffix automaton, hashes |
| many patterns in text | Aho-Corasick |
| assignment/pairing | matching, flow, Hungarian |
| "minimum possible maximum" | binary search on answer |
| "count ways modulo" | DP, combinatorics, matrix exponentiation |

### Data Structure Selection Guide

| Need | Use |
|---|---|
| append and index | vector |
| sorted dynamic keys | set/map |
| fast average lookup | unordered_map/set with safe hash |
| min/max repeatedly | priority_queue |
| prefix sums with point updates | Fenwick |
| arbitrary range aggregate with updates | segment tree |
| static idempotent query | sparse table |
| versioned queries | persistent segment tree/trie |
| dynamic connectivity with undo | rollback DSU |

### Graph Algorithm Selection Guide

| Problem | Algorithm |
|---|---|
| unweighted shortest path | BFS |
| 0/1 weighted shortest path | 0-1 BFS |
| nonnegative weighted shortest path | Dijkstra |
| negative edge shortest path | Bellman-Ford |
| all-pairs small graph | Floyd-Warshall |
| DAG dependencies | topological sort + DP |
| undirected connectivity under additions | DSU |
| MST | Kruskal/Prim/Boruvka |
| directed cycle compression | SCC |
| articulation/bridges | DFS lowlink |
| capacity/disjointness | max flow |
| boolean implications | 2-SAT |

### DP Pattern Selection Guide

| Pattern | State hint |
|---|---|
| sequence choose/skip | index, last/condition |
| grid paths | row, col, extra state |
| interval merging | left, right |
| tree | node, parent-choice/state |
| subsets | mask, last |
| digits up to N | pos, tight, started |
| expected steps | state equation over probabilities |
| game | state -> win/loss or Grundy |
| convex transition | line/container optimization |

### String Algorithm Selection Guide

| Need | Use |
|---|---|
| one pattern in one text | KMP or Z |
| many substring equality queries | rolling hash |
| many patterns | Aho-Corasick |
| palindromic radii | Manacher |
| lexicographic suffix order | suffix array |
| all substrings online-ish | suffix automaton |
| minimal rotation | Booth or Duval |

### Number Theory Selection Guide

| Need | Use |
|---|---|
| many primes up to N | sieve |
| 64-bit primality | Miller-Rabin |
| 64-bit factorization | Pollard Rho |
| modular inverse prime mod | Fermat |
| modular inverse nonprime | extended gcd if coprime |
| combine congruences | CRT |
| divisibility exact gcd counts | Mobius inversion |
| polynomial multiplication | FFT/NTT |

### Common C++ Bugs Checklist

- Signed overflow in `int`.
- `1 << k` when `k >= 31`; use `1LL << k`.
- Mixing 0-based and 1-based indices.
- Recursion depth stack overflow.
- Bad comparator for `sort` or `set`.
- Iterator invalidation after vector reallocation or erase.
- Modulo negative value not normalized.
- `double` equality in geometry.
- Forgetting disconnected components.
- Not clearing global arrays between test cases.
- Assuming input graph is simple when multiple edges/self-loops exist.

### Study Roadmap

1. Foundations, STL, complexity, recursion.
2. Arrays, sorting, binary search, two pointers.
3. Basic graphs, DFS/BFS, DSU, shortest paths.
4. Greedy proofs and standard DP.
5. Trees, LCA, Fenwick, segment tree.
6. Strings, number theory, combinatorics.
7. Flow, matching, advanced DP optimizations.
8. Geometry, offline algorithms, persistence.
9. Hard topics: dynamic trees, advanced matching, polynomial algorithms.
10. ICPC practice: mixed sets, timed contests, team strategy, stress testing.

### Revision Checklist

- Can you state the invariant?
- Can you derive the complexity?
- Can you identify the constraints that trigger it?
- Can you code a clean template from memory?
- Can you produce a counterexample for wrong alternatives?
- Can you brute force and stress test it?



---

## Short Index of Advanced Topics Included

This handbook includes advanced coverage and recognition notes for Heavy-Light Decomposition, centroid decomposition, virtual trees, DSU on tree, persistent segment trees, wavelet trees, Segment Tree Beats, Li Chao trees, dynamic CHT, rollback DSU, offline dynamic connectivity, Dinic, Hopcroft-Karp, min-cost max-flow, Aho-Corasick, suffix arrays, suffix automata, palindromic automata, Miller-Rabin, Pollard Rho, FFT/NTT, SOS DP, subset convolution, Sprague-Grundy theory, Link-Cut Trees, Euler Tour Trees, Top Trees, Blossom, Gomory-Hu trees, dominator trees, SMAWK, Berlekamp-Massey, FWHT, matroid intersection, and min-plus convolution.
