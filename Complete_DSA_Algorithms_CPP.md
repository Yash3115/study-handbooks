# Complete DSA Algorithms in C++17/20

This README is written as a topic-by-topic learning handbook. Everything related to a topic stays together: intuition, when to use it, when it fails, time complexity, solved example, C++ code, and practice links.

Use it like this:

1. Read one topic from start to finish.
2. Type the code yourself.
3. Solve the included example without looking.
4. Try the linked problems.
5. Only then move to the next topic.

## Table of Contents

- [0. How Each Topic Is Organized](#0-how-each-topic-is-organized)
- [1. Foundations and C++ Setup](#1-foundations-and-c-setup)
- [2. Arrays, Strings, Prefix Sums, and Difference Arrays](#2-arrays-strings-prefix-sums-and-difference-arrays)
- [3. Searching and Sorting](#3-searching-and-sorting)
- [4. Two Pointers, Sliding Window, and Contribution Tricks](#4-two-pointers-sliding-window-and-contribution-tricks)
- [5. Stack, Queue, Hashing, Heap, and Basic Containers](#5-stack-queue-hashing-heap-and-basic-containers)
- [6. Recursion and Backtracking](#6-recursion-and-backtracking)
- [7. Greedy Algorithms](#7-greedy-algorithms)
- [8. Dynamic Programming](#8-dynamic-programming)
- [9. Trees](#9-trees)
- [10. Range Query Data Structures](#10-range-query-data-structures)
- [11. Graph Algorithms](#11-graph-algorithms)
- [12. Network Flow and Matching](#12-network-flow-and-matching)
- [13. String Algorithms](#13-string-algorithms)
- [14. Bit Manipulation](#14-bit-manipulation)
- [15. Number Theory and Combinatorics](#15-number-theory-and-combinatorics)
- [16. Computational Geometry](#16-computational-geometry)
- [17. Advanced Competitive Programming Topics](#17-advanced-competitive-programming-topics)
- [18. Constraint-to-Algorithm Guide](#18-constraint-to-algorithm-guide)
- [19. Final Revision Checklist](#19-final-revision-checklist)

## 0. How Each Topic Is Organized

Every topic follows the same shape:

| Part | Meaning |
|---|---|
| Plain idea | The simplest mental model. |
| Use when | Problem clues that suggest this topic. |
| Do not use when | Cases where the technique fails or becomes a bad choice. |
| Complexity | Time and memory cost. |
| Common mistakes | Bugs to watch for. |
| Algorithms in this topic | A table of tools, complexities, failure cases, and practice links. |
| Solved example | A small original problem statement with C++ solution. |
| Code templates | Reusable C++17/20 snippets. |

### Plain-English Glossary

| Word | Simple meaning |
|---|---|
| invariant | A rule that stays true while the algorithm runs. |
| monotonic | Always moving in one direction, like false to true or small to large. |
| brute force | Try everything directly. Simple but often too slow. |
| state | The information needed to describe a subproblem. |
| transition | How one state moves to another state. |
| greedy | Make the best local choice now, then prove it is safe. |
| amortized | Average cost across many operations. |
| online | Queries must be answered in the given order. |
| offline | All queries are known first, so you may reorder or preprocess them. |
| static | Data does not change. |
| dynamic | Data changes through updates. |

### Learning Order

| Stage | Learn before moving on |
|---|---|
| Early | arrays, strings, prefix sums, sorting, binary search |
| Early plus | two pointers, sliding window, stack, queue, hash map, heap |
| Core | recursion, backtracking, greedy, basic DP |
| Intermediate | trees, BFS, DFS, topological sort, DSU |
| Strong | Dijkstra, MST, Fenwick tree, segment tree, trie, KMP |
| Advanced | SCC, bridges, flow, matching, advanced DP, suffix structures, number theory, geometry |
| ICPC hard | rollback DSU, HLD, centroid decomposition, persistent segment tree, Li Chao tree, NTT, Blossom |

## 1. Foundations and C++ Setup

### Plain Idea

Foundations are the rules that help you decide whether a solution is fast enough and safe enough.

### Use When

- Always.
- Before choosing any algorithm.
- When constraints are large and brute force may fail.

### Do Not Use When

- Do not overcomplicate small constraints.
- Do not use a hard algorithm when a simple one passes.

### Complexity Basics

| Complexity | Rough input size that may pass |
|---|---|
| `O(1)` | any normal input |
| `O(log n)` | huge input |
| `O(n)` | up to `1e7` or more depending on constant |
| `O(n log n)` | often up to `2e5` or `1e6` |
| `O(n^2)` | usually up to `5000`, sometimes less |
| `O(n^3)` | usually up to `500` |
| `O(2^n)` | usually up to `20-25` |
| `O(n!)` | usually up to `10-11` |

### Common Mistakes

- Using `int` when answer can exceed `2e9`.
- Forgetting `ios::sync_with_stdio(false); cin.tie(nullptr);`.
- Assuming recursion is safe for very deep graphs or trees.
- Mixing 0-based and 1-based indexing.
- Using floating point equality directly.

### Starter Code

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;
const long long LINF = 4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        // solve();
    }
    return 0;
}
```

### Practice Links

- [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)
- [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
- [Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/)

## 2. Arrays, Strings, Prefix Sums, and Difference Arrays

### Plain Idea

Arrays store values in order. Prefix sums store answers for everything before an index. Difference arrays store changes instead of final values.

### Use When

- You need quick range sums.
- You need many offline range updates.
- You need string or array scanning.
- You need subarray sum patterns.

### Do Not Use When

- The array changes and you need online queries; use Fenwick or segment tree.
- You need range minimum or maximum; prefix sums cannot undo `min` or `max`.
- Updates and queries are mixed online.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Direct scan | One pass statistics | `O(n)` | `O(1)` | repeated range queries | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |
| Prefix sum | static range sum | build `O(n)`, query `O(1)` | `O(n)` | data updates often | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) |
| 2D prefix sum | static rectangle sum | build `O(nm)`, query `O(1)` | `O(nm)` | matrix updates often | [Matrix Block Sum](https://leetcode.com/problems/matrix-block-sum/) |
| Difference array | many offline range additions | `O(n+q)` | `O(n)` | online queries between updates | [Car Pooling](https://leetcode.com/problems/car-pooling/) |
| Prefix sum + hash map | subarray sum equals target | `O(n)` average | `O(n)` | only positive array where sliding window is simpler | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) |
| Kadane | max subarray sum | `O(n)` | `O(1)` | need actual all subarrays | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) |

### Solved Example

Problem: Given an array and queries `(l, r)`, return the sum from index `l` to `r`, inclusive.

```cpp
vector<long long> build_prefix(const vector<int>& a) {
    int n = a.size();
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    return pref;
}

long long range_sum(const vector<long long>& pref, int l, int r) {
    return pref[r + 1] - pref[l];
}
```

### Code Templates

#### Difference Array

```cpp
vector<long long> apply_range_adds(int n, vector<array<int, 3>> queries) {
    vector<long long> diff(n + 1, 0);
    for (auto [l, r, x] : queries) {
        diff[l] += x;
        if (r + 1 < n) diff[r + 1] -= x;
    }
    vector<long long> ans(n);
    long long cur = 0;
    for (int i = 0; i < n; i++) {
        cur += diff[i];
        ans[i] = cur;
    }
    return ans;
}
```

#### Kadane

```cpp
long long max_subarray_sum(const vector<int>& a) {
    long long best = LLONG_MIN;
    long long cur = 0;
    for (int x : a) {
        cur = max<long long>(x, cur + x);
        best = max(best, cur);
    }
    return best;
}
```

#### Prefix Sum With Hash Map

```cpp
int subarray_sum_equals_k(const vector<int>& a, int k) {
    unordered_map<long long, int> freq;
    freq[0] = 1;
    long long pref = 0;
    int ans = 0;
    for (int x : a) {
        pref += x;
        if (freq.count(pref - k)) ans += freq[pref - k];
        freq[pref]++;
    }
    return ans;
}
```

## 3. Searching and Sorting

### Plain Idea

Searching finds a value or an answer. Sorting arranges data so later logic becomes easier.

### Use When

- Data is sorted or can be sorted.
- The answer has a monotonic yes/no pattern.
- You need kth smallest, inversion count, or ordered processing.

### Do Not Use When

- Sorting destroys needed original order and you do not store indices.
- Binary search condition is not monotonic.
- You need online order maintenance; use set, heap, Fenwick, or segment tree.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Linear search | tiny or unsorted data | `O(n)` | `O(1)` | many queries | [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/) |
| Binary search | sorted array lookup | `O(log n)` | `O(1)` | unsorted data | [Binary Search](https://leetcode.com/problems/binary-search/) |
| Lower/upper bound | first `>= x` or `> x` | `O(log n)` | `O(1)` | data not sorted | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) |
| Binary search on answer | minimum valid answer | `O(log range * check)` | varies | check is not monotonic | [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) |
| Merge sort | stable sorting, inversion count | `O(n log n)` | `O(n)` | memory tight | [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) |
| Quicksort | average fast sorting | avg `O(n log n)` | recursion | bad pivots without randomization | [Sort an Array](https://leetcode.com/problems/sort-an-array/) |
| Heap sort | in-place guaranteed sort | `O(n log n)` | `O(1)` | not stable | [Sort an Array](https://leetcode.com/problems/sort-an-array/) |
| Counting sort | small integer range | `O(n+K)` | `O(K)` | huge value range | [Sort Colors](https://leetcode.com/problems/sort-colors/) |
| Quickselect | kth element | avg `O(n)` | `O(1)` | worst case without randomization | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) |

### Solved Example

Problem: Find the smallest integer `x` such that `ok(x)` is true.

```cpp
long long first_true(long long lo, long long hi, function<bool(long long)> ok) {
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (ok(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
```

### Code Templates

```cpp
int first_greater_equal(const vector<int>& a, int x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int first_greater_than(const vector<int>& a, int x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}
```

```cpp
long long count_inversions(vector<int>& a, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    long long inv = count_inversions(a, l, m) + count_inversions(a, m, r);
    vector<int> tmp;
    int i = l, j = m;
    while (i < m || j < r) {
        if (j == r || (i < m && a[i] <= a[j])) tmp.push_back(a[i++]);
        else {
            inv += m - i;
            tmp.push_back(a[j++]);
        }
    }
    copy(tmp.begin(), tmp.end(), a.begin() + l);
    return inv;
}
```

## 4. Two Pointers, Sliding Window, and Contribution Tricks

### Plain Idea

Two pointers move through data without restarting. Sliding window keeps a subarray or substring that changes by adding one item and removing one item.

### Use When

- You need pairs in sorted arrays.
- You need longest or shortest valid subarray.
- Moving one pointer makes the condition better or worse in a predictable way.
- You can count contribution of each element separately.

### Do Not Use When

- Negative numbers break a sum window.
- The window condition is not repairable by moving left.
- You need arbitrary pairs, not ordered movement.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Opposite two pointers | sorted pair search | `O(n)` after sort | `O(1)` | unsorted and cannot sort | [Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) |
| Same direction pointers | remove duplicates, merge-like scan | `O(n)` | `O(1)` | pointer movement not monotonic | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) |
| Fixed window | every subarray of size `k` | `O(n)` | `O(1)` | variable length needed | [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) |
| Variable window | longest/shortest valid window | `O(n)` | varies | condition not monotonic | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) |
| Contribution technique | count total effect per element | `O(n)` or `O(n log n)` | varies | contribution not separable | [Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) |

### Solved Example

Problem: Return the length of the longest substring with no repeated characters.

```cpp
int longest_unique_substring(const string& s) {
    vector<int> last(256, -1);
    int ans = 0, l = 0;
    for (int r = 0; r < (int)s.size(); r++) {
        unsigned char ch = s[r];
        if (last[ch] >= l) l = last[ch] + 1;
        last[ch] = r;
        ans = max(ans, r - l + 1);
    }
    return ans;
}
```

### Code Templates

```cpp
bool has_pair_sum(const vector<int>& a, int target) {
    int l = 0, r = (int)a.size() - 1;
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == target) return true;
        if (sum < target) l++;
        else r--;
    }
    return false;
}
```

## 5. Stack, Queue, Hashing, Heap, and Basic Containers

### Plain Idea

These containers store data with useful access rules. The right container can turn a slow solution into a simple fast one.

### Use When

- Stack: nearest previous/next greater/smaller, undo, parsing.
- Queue: BFS and first-in-first-out processing.
- Deque: sliding window min/max.
- Hash map: frequency and fast lookup.
- Heap: repeated min/max.
- Set/map: sorted online data.

### Do Not Use When

- Hash map is needed but ordered traversal is required.
- Heap is used but arbitrary deletion is required without lazy deletion.
- Stack is used when nearest relation is not monotonic.

### Algorithms in This Topic

| Tool | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Monotonic stack | next greater/smaller | `O(n)` | `O(n)` | need all greater elements | [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) |
| Monotonic deque | sliding max/min | `O(n)` | `O(k)` | window is not contiguous | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) |
| Hash map | counts, first seen | average `O(1)` | `O(n)` | ordered queries | [Two Sum](https://leetcode.com/problems/two-sum/) |
| Heap | top k, repeated best | `O(log n)` update | `O(n)` | arbitrary search/deletion | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) |
| Ordered set/map | sorted online data | `O(log n)` | `O(n)` | need index order statistics without PBDS/Fenwick | [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/) |

### Solved Example

Problem: For each index, return the next greater index to the right, or `-1`.

```cpp
vector<int> next_greater_index(const vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1), st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] < a[i]) {
            ans[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}
```

### Code Templates

```cpp
vector<int> sliding_window_max(const vector<int>& a, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < (int)a.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) ans.push_back(a[dq.front()]);
    }
    return ans;
}
```

```cpp
struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t seed =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + seed);
    }
};
```

## 6. Recursion and Backtracking

### Plain Idea

Recursion solves a problem by solving smaller versions. Backtracking tries a choice, explores it, then undoes it.

### Use When

- Generate subsets, permutations, combinations.
- Explore board placement problems.
- Search space is small or can be pruned.

### Do Not Use When

- `n` is too large for exponential search.
- Repeated subproblems should be cached with DP.
- Recursion depth is too large for stack.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Subset recursion | all choose/skip possibilities | `O(2^n)` | `O(n)` stack | large `n` | [Subsets](https://leetcode.com/problems/subsets/) |
| Permutations | all orders | `O(n!)` | `O(n)` stack | large `n` | [Permutations](https://leetcode.com/problems/permutations/) |
| Combinations | choose `k` items | `O(C(n,k))` | `O(k)` | large combinations | [Combinations](https://leetcode.com/problems/combinations/) |
| Backtracking with pruning | constraint search | depends | depends | weak pruning | [N-Queens](https://leetcode.com/problems/n-queens/) |
| BFS/DFS over states | shortest or reachable states | states + transitions | states | state count explodes | [Open the Lock](https://leetcode.com/problems/open-the-lock/) |

### Solved Example

Problem: Generate all subsets of an array.

```cpp
void dfs_subsets(int i, const vector<int>& a, vector<int>& cur, vector<vector<int>>& ans) {
    if (i == (int)a.size()) {
        ans.push_back(cur);
        return;
    }
    dfs_subsets(i + 1, a, cur, ans);
    cur.push_back(a[i]);
    dfs_subsets(i + 1, a, cur, ans);
    cur.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> cur;
    dfs_subsets(0, nums, cur, ans);
    return ans;
}
```

## 7. Greedy Algorithms

### Plain Idea

Greedy makes the best choice right now. It is only correct if you can prove the local choice never blocks the best final answer.

### Use When

- Sorting reveals a natural order.
- There is an exchange argument.
- Intervals, scheduling, or heap-based choices appear.

### Do Not Use When

- You cannot prove the choice is safe.
- Future choices can make an early local choice bad.
- DP state is needed.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Sort by end time | max non-overlap intervals | `O(n log n)` | `O(1)` | wrong sort key | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) |
| Merge intervals | combine overlapping intervals | `O(n log n)` | `O(n)` | intervals not comparable | [Merge Intervals](https://leetcode.com/problems/merge-intervals/) |
| Heap greedy | always use current best | `O(n log n)` | `O(n)` | local best not globally safe | [Course Schedule III](https://leetcode.com/problems/course-schedule-iii/) |
| Huffman coding | optimal prefix code | `O(n log n)` | `O(n)` | weights change dynamically | conceptual |
| Fractional knapsack | divisible items | `O(n log n)` | `O(1)` | 0/1 items | conceptual |

### Solved Example

Problem: Remove the fewest intervals so the remaining intervals do not overlap.

```cpp
int erase_overlap_intervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[1] < b[1];
         });

    int removed = 0;
    int lastEnd = INT_MIN;
    for (auto& in : intervals) {
        if (in[0] >= lastEnd) {
            lastEnd = in[1];
        } else {
            removed++;
        }
    }
    return removed;
}
```

## 8. Dynamic Programming

### Plain Idea

DP stores answers to smaller subproblems so repeated work is avoided.

### Use When

- The problem asks for min, max, count, possible/impossible.
- Choices repeat the same subproblems.
- A small set of variables describes the future.

### Do Not Use When

- No repeated subproblems exist.
- A greedy proof is simpler.
- State count is too large.

### Algorithms in This Topic

| DP type | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| 1D DP | index-based choices | `O(n * transitions)` | `O(n)` | future depends on too much | [House Robber](https://leetcode.com/problems/house-robber/) |
| 2D DP | two indices or grid | `O(nm)` | `O(nm)` | dimensions too large | [Unique Paths](https://leetcode.com/problems/unique-paths/) |
| Knapsack | choose items under capacity | `O(nW)` | `O(W)` possible | `W` huge | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) |
| LIS | increasing subsequence | `O(n log n)` | `O(n)` | need count/all LIS without extra logic | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) |
| LCS | compare two sequences | `O(nm)` | `O(nm)` | strings too large | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) |
| Interval DP | merge intervals | `O(n^3)` often | `O(n^2)` | no interval structure | [Burst Balloons](https://leetcode.com/problems/burst-balloons/) |
| Bitmask DP | subsets as states | `O(n 2^n)` | `O(2^n)` | `n > 22` usually | [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) |
| Digit DP | count numbers with digit rules | `O(digits * states)` | states | hard to define tight/started | advanced |
| Tree DP | combine child answers | `O(n * states)` | states | graph has cycles | [House Robber III](https://leetcode.com/problems/house-robber-iii/) |

### Solved Example

Problem: Given coin values and an amount, return the minimum number of coins needed, or `-1`.

```cpp
int coin_change(vector<int>& coins, int amount) {
    const int INF = 1e9;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int x = 1; x <= amount; x++) {
        for (int c : coins) {
            if (x >= c) dp[x] = min(dp[x], dp[x - c] + 1);
        }
    }
    return dp[amount] >= INF ? -1 : dp[amount];
}
```

### Code Templates

```cpp
int lis_length(const vector<int>& a) {
    vector<int> tail;
    for (int x : a) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    return tail.size();
}
```

```cpp
int lcs(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
```

## 9. Trees

### Plain Idea

A tree is a connected graph with no cycles. Because there is exactly one simple path between two nodes, DFS and parent-child logic become powerful.

### Use When

- Input has `n` nodes and `n-1` edges and is connected.
- You need subtree sizes, depths, ancestors, path queries, diameter, or tree DP.

### Do Not Use When

- The graph has cycles.
- You forget to avoid going back to the parent.
- Recursion depth is too large.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Tree DFS | depth, parent, subtree | `O(n)` | `O(n)` | graph has cycles and no visited | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) |
| Tree diameter | longest path | `O(n)` | `O(n)` | graph not tree | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) |
| Binary lifting LCA | many ancestor/LCA queries | build `O(n log n)`, query `O(log n)` | `O(n log n)` | root/parent wrong | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) |
| Euler tour | subtree as range | `O(n)` | `O(n)` | dynamic tree changes | tree query problems |
| Trie | prefix tree for strings | `O(length)` | nodes | huge alphabet memory | [Implement Trie](https://leetcode.com/problems/implement-trie-prefix-tree/) |
| HLD | path queries | `O(log^2 n)` often | `O(n)` | implementation mistakes | advanced |
| Centroid decomposition | distance queries on tree | `O(n log n)` build | `O(n log n)` | graph not tree | advanced |
| DSU on tree | subtree frequency queries | `O(n log n)` or `O(n)` | `O(n)` | updates online | advanced |

### Solved Example

Problem: Given a tree rooted at `0`, compute every subtree size.

```cpp
void subtree_dfs(int u, int p, const vector<vector<int>>& g, vector<int>& sub) {
    sub[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        subtree_dfs(v, u, g, sub);
        sub[u] += sub[v];
    }
}
```

### Code Templates

```cpp
struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up, g;

    LCA(vector<vector<int>> graph, int root = 0) : g(move(graph)) {
        n = g.size();
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        depth.assign(n, 0);
        up.assign(LOG, vector<int>(n, root));
        dfs(root, root);
    }

    void dfs(int u, int p) {
        up[0][u] = p;
        for (int k = 1; k < LOG; k++) up[k][u] = up[k - 1][up[k - 1][u]];
        for (int v : g[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    int lift(int u, int d) {
        for (int k = 0; k < LOG; k++) if (d & (1 << k)) u = up[k][u];
        return u;
    }

    int query(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = lift(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }
};
```

## 10. Range Query Data Structures

### Plain Idea

Range data structures answer questions about intervals quickly, sometimes while values change.

### Use When

- You have many range queries.
- You have point or range updates.
- You need sums, min, max, gcd, xor, kth, or frequency over ranges.

### Do Not Use When

- One query only; direct scan is simpler.
- The operation does not merge cleanly.
- A static sparse table is enough and you built a complex segment tree anyway.

### Algorithms in This Topic

| Structure | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Prefix sum | static range sum | query `O(1)` | `O(n)` | updates | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) |
| Fenwick tree | point update, prefix/range sum | `O(log n)` | `O(n)` | complex custom range merge | [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/) |
| Segment tree | flexible range query/update | `O(log n)` | `O(n)` | static idempotent query simpler | [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/) |
| Lazy segment tree | range update + range query | `O(log n)` | `O(n)` | lazy logic wrong | [My Calendar III](https://leetcode.com/problems/my-calendar-iii/) |
| Sparse table | static min/max/gcd | build `O(n log n)`, query `O(1)` | `O(n log n)` | updates | [Range Minimum Query style](https://leetcode.com/problems/sliding-window-maximum/) |
| Sqrt decomposition | simple blocks | `O(sqrt n)` | `O(n)` | high constraints | block problems |
| Merge sort tree | count/order in range | `O(log^2 n)` | `O(n log n)` | updates | [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) |
| Persistent segment tree | kth in static range | `O(log n)` | `O(n log n)` | many updates with lazy | advanced |
| Wavelet tree | kth/count/rank static ranges | `O(log sigma)` | `O(n log sigma)` | complex updates | advanced |

### Solved Example

Problem: Support point updates and range sum queries.

```cpp
struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    void add(int idx, long long val) {
        for (++idx; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    long long prefix_sum(int idx) const {
        long long ans = 0;
        for (++idx; idx > 0; idx -= idx & -idx) ans += bit[idx];
        return ans;
    }

    long long range_sum(int l, int r) const {
        if (r < l) return 0;
        return prefix_sum(r) - (l ? prefix_sum(l - 1) : 0);
    }
};
```

### Segment Tree Template

```cpp
struct SegTree {
    int n;
    vector<long long> seg;

    void build(const vector<int>& a) {
        n = a.size();
        seg.assign(2 * n, 0);
        for (int i = 0; i < n; i++) seg[n + i] = a[i];
        for (int i = n - 1; i > 0; i--) seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }

    void update(int p, long long val) {
        for (seg[p += n] = val; p > 1; p >>= 1) {
            seg[p >> 1] = seg[p] + seg[p ^ 1];
        }
    }

    long long query(int l, int r) {
        long long left = 0, right = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left += seg[l++];
            if (r & 1) right = seg[--r] + right;
        }
        return left + right;
    }
};
```

## 11. Graph Algorithms

### Plain Idea

A graph is a set of nodes connected by edges. Graph algorithms answer reachability, shortest path, ordering, connectivity, cycles, components, matching, and flow questions.

### Use When

- The problem has cities, people, courses, dependencies, roads, transformations, states, grids, networks, or relationships.
- You can model items as nodes and allowed moves as edges.

### Do Not Use When

- The relation is not actually pairwise.
- You need only array order and no edges.
- Edge weights or direction do not match the chosen algorithm.

### Graph Representation

| Representation | Use when | Memory | Notes |
|---|---|---:|---|
| Adjacency list | most sparse graphs | `O(n+m)` | best default |
| Adjacency matrix | dense graph, `n` small | `O(n^2)` | fast edge lookup |
| Edge list | MST, Bellman-Ford | `O(m)` | easy to sort/relax |
| Grid graph | matrix movement | `O(nm)` | neighbors are directions |

### All Core Graph Algorithms Together

| Algorithm | Best use | Time | Space | When it fails or is wrong | Example problem pattern | Practice links |
|---|---|---:|---:|---|---|---|
| BFS | shortest path with unweighted edges | `O(n+m)` | `O(n)` | weighted edges need Dijkstra/0-1 BFS | minimum moves in grid | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/), [Word Ladder](https://leetcode.com/problems/word-ladder/) |
| DFS | explore components, cycles, traversal | `O(n+m)` | `O(n)` | recursion depth too large | count connected groups | [Number of Islands](https://leetcode.com/problems/number-of-islands/), [Clone Graph](https://leetcode.com/problems/clone-graph/) |
| Connected components | group undirected graph | `O(n+m)` | `O(n)` | directed graph needs SCC for mutual reachability | provinces/groups | [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) |
| Bipartite check | 2-color graph | `O(n+m)` | `O(n)` | odd cycle exists | split people into two groups | [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/), [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) |
| Topological sort | order DAG dependencies | `O(n+m)` | `O(n)` | directed cycle exists | course prerequisites | [Course Schedule](https://leetcode.com/problems/course-schedule/), [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) |
| Cycle detection undirected | detect undirected cycle | `O(n+m)` | `O(n)` | parent check missing | redundant edge | [Redundant Connection](https://leetcode.com/problems/redundant-connection/) |
| Cycle detection directed | detect dependency cycle | `O(n+m)` | `O(n)` | using undirected logic | course cycle | [Course Schedule](https://leetcode.com/problems/course-schedule/) |
| Multi-source BFS | nearest source distance | `O(n+m)` | `O(n)` | weighted edges | nearest zero/cell/source | [01 Matrix](https://leetcode.com/problems/01-matrix/), [As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible/) |
| 0-1 BFS | edges weights only 0 or 1 | `O(n+m)` | `O(n)` | weights not 0/1 | minimum reversals/cost grid | [Minimum Cost to Make at Least One Valid Path in a Grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/) |
| Dijkstra | nonnegative weighted shortest path | `O((n+m) log n)` | `O(n+m)` | negative weights | network delay/path effort | [Network Delay Time](https://leetcode.com/problems/network-delay-time/), [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) |
| Bellman-Ford | negative weights and cycle detection | `O(nm)` | `O(n)` | too slow for huge graphs | negative edge shortest path | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) |
| Floyd-Warshall | all pairs shortest paths, small `n` | `O(n^3)` | `O(n^2)` | `n` large | every city to every city | [Find the City With the Smallest Number of Neighbors](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) |
| DSU | merge components | almost `O(1)` | `O(n)` | edge deletion online | connectivity after additions | [Accounts Merge](https://leetcode.com/problems/accounts-merge/), [Redundant Connection](https://leetcode.com/problems/redundant-connection/) |
| Kruskal MST | minimum cost to connect undirected graph | `O(m log m)` | `O(n)` | directed graph or shortest path needed | connect all points | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) |
| Prim MST | MST from adjacency list | `O(m log n)` | `O(n+m)` | disconnected graph not handled | network construction | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) |
| SCC Tarjan/Kosaraju | mutual reachability in directed graph | `O(n+m)` | `O(n+m)` | undirected components are simpler | compress directed graph | [Critical Connections uses low-link idea](https://leetcode.com/problems/critical-connections-in-a-network/) |
| Bridges | edges whose removal disconnects graph | `O(n+m)` | `O(n)` | parallel edges need care | critical connections | [Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/) |
| Articulation points | vertices whose removal disconnects graph | `O(n+m)` | `O(n)` | root case mishandled | network cut points | graph interview variants |
| Euler path/circuit | use every edge exactly once | `O(n+m)` | `O(m)` | degree conditions fail | reconstruct itinerary | [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/) |
| Functional graph lifting | every node has one outgoing edge | `O(n log K)` | `O(n log K)` | node has many outgoing edges | kth successor | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) for idea |
| 2-SAT | boolean constraints | `O(n+m)` | `O(n+m)` | clauses not size 2 | satisfiability of pairs | no direct standard LeetCode staple |
| Dinic max flow | maximum flow/min cut | about `O(E V^2)` general, faster often | `O(n+m)` | graph not capacity model | assignment/cut reductions | [Maximum Students Taking Exam](https://leetcode.com/problems/maximum-students-taking-exam/) can use matching/flow |
| Bipartite matching | pair left and right nodes | Kuhn `O(VE)`, Hopcroft `O(E sqrt V)` | `O(n+m)` | graph not bipartite | assign workers/tasks | [Maximum Students Taking Exam](https://leetcode.com/problems/maximum-students-taking-exam/) |

### Graph Algorithm Selection

| Problem clue | Choose |
|---|---|
| shortest path, all edges same cost | BFS |
| shortest path, weights 0 or 1 | 0-1 BFS |
| shortest path, all weights nonnegative | Dijkstra |
| shortest path with negative edge | Bellman-Ford |
| all pairs shortest path, `n <= 400` | Floyd-Warshall |
| prerequisites/order | Topological sort |
| undirected connectivity with additions | DSU |
| cheapest way to connect all nodes | MST |
| directed mutual groups | SCC |
| critical edge | Bridge |
| critical vertex | Articulation point |
| use every edge once | Euler path |
| capacity network | Max flow |
| pair left items with right items | Bipartite matching |

### Solved Example

Problem: Given a grid of `0` and `1`, count connected groups of `1`s using 4-direction movement.

```cpp
int count_islands(vector<vector<char>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    int ans = 0;
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] != '1') continue;
            ans++;
            queue<pair<int, int>> q;
            q.push({r, c});
            grid[r][c] = '0';
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dr[d], ny = y + dc[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (grid[nx][ny] != '1') continue;
                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }
        }
    }
    return ans;
}
```

### Graph Code Templates

#### BFS

```cpp
vector<int> bfs(int src, const vector<vector<int>>& g) {
    vector<int> dist(g.size(), -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
```

#### Topological Sort

```cpp
vector<int> topo_sort(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> indeg(n), order;
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) indeg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return order;
}
```

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
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
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
vector<long long> dijkstra(int src, const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<long long> dist(n, LINF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

#### 0-1 BFS

```cpp
vector<int> zero_one_bfs(int src, const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<int> dist(n, INF);
    deque<int> dq;
    dist[src] = 0;
    dq.push_front(src);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    return dist;
}
```

#### Bellman-Ford

```cpp
struct EdgeBF {
    int u, v;
    long long w;
};

bool bellman_ford(int n, int src, const vector<EdgeBF>& edges, vector<long long>& dist) {
    dist.assign(n, LINF);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        bool changed = false;
        for (auto e : edges) {
            if (dist[e.u] < LINF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    for (auto e : edges) {
        if (dist[e.u] < LINF && dist[e.v] > dist[e.u] + e.w) return false;
    }
    return true;
}
```

#### Floyd-Warshall

```cpp
void floyd_warshall(vector<vector<long long>>& d) {
    int n = d.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] < LINF && d[k][j] < LINF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}
```

#### Kruskal MST

```cpp
struct EdgeMST {
    int u, v;
    long long w;
    bool operator<(const EdgeMST& other) const {
        return w < other.w;
    }
};

long long kruskal(int n, vector<EdgeMST> edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long cost = 0;
    int used = 0;
    for (auto e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cost += e.w;
            used++;
        }
    }
    if (used != n - 1) return -1;
    return cost;
}
```

#### Tarjan SCC

```cpp
struct TarjanSCC {
    int n, timer = 0, compCnt = 0;
    vector<vector<int>> g;
    vector<int> disc, low, comp, st;
    vector<bool> inStack;

    TarjanSCC(const vector<vector<int>>& graph) : g(graph) {
        n = g.size();
        disc.assign(n, -1);
        low.assign(n, 0);
        comp.assign(n, -1);
        inStack.assign(n, false);
        for (int i = 0; i < n; i++) if (disc[i] == -1) dfs(i);
    }

    void dfs(int u) {
        disc[u] = low[u] = timer++;
        st.push_back(u);
        inStack[u] = true;
        for (int v : g[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (low[u] == disc[u]) {
            while (true) {
                int v = st.back();
                st.pop_back();
                inStack[v] = false;
                comp[v] = compCnt;
                if (v == u) break;
            }
            compCnt++;
        }
    }
};
```

#### Bridges

```cpp
struct Bridges {
    int n, timer = 0;
    vector<vector<int>> g;
    vector<int> tin, low;
    vector<pair<int, int>> bridges;

    Bridges(const vector<vector<int>>& graph) : g(graph) {
        n = g.size();
        tin.assign(n, -1);
        low.assign(n, 0);
        for (int i = 0; i < n; i++) if (tin[i] == -1) dfs(i, -1);
    }

    void dfs(int u, int p) {
        tin[u] = low[u] = timer++;
        for (int v : g[u]) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) bridges.push_back({u, v});
            }
        }
    }
};
```

## 12. Network Flow and Matching

### Plain Idea

Flow pushes quantity through edges with capacities. Matching pairs items so each item is used at most once.

### Use When

- You see capacity, send, cut, assign, match, pair, disjoint paths, or minimum cut.
- A greedy pairing is not enough.

### Do Not Use When

- The problem is simply shortest path or MST.
- The graph is too large for the chosen flow algorithm.
- The matching graph is not bipartite but you use bipartite matching.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Kuhn | simple bipartite matching | `O(VE)` | `O(V+E)` | huge dense graph | matching practice |
| Hopcroft-Karp | faster bipartite matching | `O(E sqrt V)` | `O(V+E)` | not bipartite | advanced matching |
| Dinic | max flow | general `O(EV^2)`, often fast | `O(V+E)` | capacities/model wrong | min cut reductions |
| Min-cost max-flow | cheapest flow | depends on implementation | `O(V+E)` | negative cycles mishandled | assignment with costs |
| Hungarian | min cost perfect assignment | `O(n^3)` | `O(n^2)` | not complete/padded | assignment problems |
| Blossom | general graph matching | `O(n^3)` | `O(n^2)` | bipartite simpler | ICPC hard |

### Dinic Template

```cpp
struct Dinic {
    struct Edge {
        int to, rev;
        long long cap;
    };
    int n;
    vector<vector<Edge>> g;
    vector<int> level, it;

    Dinic(int n) : n(n), g(n), level(n), it(n) {}

    void addEdge(int u, int v, long long c) {
        Edge a{v, (int)g[v].size(), c};
        Edge b{u, (int)g[u].size(), 0};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& e : g[u]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int u, int t, long long f) {
        if (u == t) return f;
        for (int& i = it[u]; i < (int)g[u].size(); i++) {
            Edge& e = g[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                long long ret = dfs(e.to, t, min(f, e.cap));
                if (ret) {
                    e.cap -= ret;
                    g[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    long long maxFlow(int s, int t) {
        long long flow = 0;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (long long f = dfs(s, t, LINF)) flow += f;
        }
        return flow;
    }
};
```

## 13. String Algorithms

### Plain Idea

String algorithms avoid comparing the same characters again and again.

### Use When

- Pattern matching.
- Prefix/suffix logic.
- Palindromes.
- Many dictionary words.
- Suffix or substring questions.

### Do Not Use When

- Built-in find is enough for tiny data.
- You need many patterns but use KMP one pattern at a time.
- Hash collisions are unacceptable without double hash or deterministic algorithm.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| KMP prefix function | one pattern in text | `O(n+m)` | `O(n+m)` | many patterns | [Find First Occurrence](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) |
| Z algorithm | prefix matches at each index | `O(n)` | `O(n)` | not intuitive for many patterns | pattern matching |
| Rolling hash | substring equality | `O(1)` query after build | `O(n)` | collision risk | [Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/) |
| Trie | prefixes/dictionary | `O(length)` | nodes | huge alphabet | [Implement Trie](https://leetcode.com/problems/implement-trie-prefix-tree/) |
| Aho-Corasick | many patterns in one text | `O(text + total pattern + matches)` | nodes | one pattern only simpler | [Word Search II](https://leetcode.com/problems/word-search-ii/) idea |
| Manacher | all palindrome radii | `O(n)` | `O(n)` | dynamic edits | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) |
| Suffix array | lexicographic suffix queries | `O(n log n)` | `O(n)` | online updates | advanced |
| Suffix automaton | distinct substrings, online build | `O(n)` | `O(n)` | implementation hard | advanced |

### Solved Example

Problem: Return the first index where `pat` occurs in `text`, or `-1`.

```cpp
vector<int> prefix_function(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int kmp_first(const string& text, const string& pat) {
    if (pat.empty()) return 0;
    string s = pat + "#" + text;
    vector<int> pi = prefix_function(s);
    int m = pat.size();
    for (int i = m + 1; i < (int)s.size(); i++) {
        if (pi[i] == m) return i - 2 * m;
    }
    return -1;
}
```

## 14. Bit Manipulation

### Plain Idea

Bits let integers represent sets, flags, parity, and xor relationships.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Basic bit ops | set/check/toggle | `O(1)` | `O(1)` | bit index too high | [Counting Bits](https://leetcode.com/problems/counting-bits/) |
| XOR tricks | pairs cancel out | `O(n)` | `O(1)` | values do not follow xor property | [Single Number](https://leetcode.com/problems/single-number/) |
| Submask enumeration | all submasks of mask | `O(3^n)` across masks | `O(1)` | `n` large | advanced |
| Bitmask DP | subset states | `O(n 2^n)` | `O(2^n)` | `n > 22` | [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) |
| XOR basis | max xor subset | `O(n log A)` | `O(log A)` | not xor-linear | advanced |

### Code Templates

```cpp
bool has_bit(long long x, int b) { return x & (1LL << b); }
long long set_bit(long long x, int b) { return x | (1LL << b); }
long long clear_bit(long long x, int b) { return x & ~(1LL << b); }
long long toggle_bit(long long x, int b) { return x ^ (1LL << b); }
bool is_power_of_two(long long x) { return x > 0 && (x & (x - 1)) == 0; }
```

```cpp
for (int sub = mask; ; sub = (sub - 1) & mask) {
    // use sub
    if (sub == 0) break;
}
```

## 15. Number Theory and Combinatorics

### Plain Idea

Number theory handles primes, divisibility, gcd, modular arithmetic, and counting.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| GCD Euclid | greatest common divisor | `O(log min(a,b))` | `O(1)` | none for integers | [GCD of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/) |
| Fast power | large exponent modulo | `O(log e)` | `O(1)` | multiplication overflow without cast | [Pow(x, n)](https://leetcode.com/problems/powx-n/) |
| Sieve | primes up to `n` | `O(n log log n)` | `O(n)` | `n` huge | [Count Primes](https://leetcode.com/problems/count-primes/) |
| Modular inverse | division modulo prime | `O(log mod)` | `O(1)` | inverse does not exist | combinatorics |
| nCr precompute | many combinations | build `O(n)`, query `O(1)` | `O(n)` | mod not prime with Fermat inverse | counting |
| CRT | combine congruences | `O(log mod)` | `O(1)` | inconsistent equations | advanced |
| Miller-Rabin | 64-bit primality | `O(log n)` per base | `O(1)` | wrong bases | advanced |
| Pollard Rho | 64-bit factorization | expected fast | recursion | random bad luck | advanced |
| FFT/NTT | polynomial multiplication | `O(n log n)` | `O(n)` | modulus/root mismatch | advanced |

### Code Templates

```cpp
long long mod_pow(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    while (e) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}
```

```cpp
vector<int> sieve(int n) {
    vector<int> isPrime(n + 1, true), primes;
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            if (1LL * i * i <= n) {
                for (long long j = 1LL * i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    return primes;
}
```

```cpp
struct Comb {
    long long mod;
    vector<long long> fact, invFact;

    Comb(int n, long long mod) : mod(mod), fact(n + 1), invFact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
        invFact[n] = mod_pow(fact[n], mod - 2, mod);
        for (int i = n; i > 0; i--) invFact[i - 1] = invFact[i] * i % mod;
    }

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
    }
};
```

## 16. Computational Geometry

### Plain Idea

Geometry converts shapes into points, vectors, cross products, and orientation tests.

### Algorithms in This Topic

| Algorithm | Use case | Time | Space | Fails when | Example problems |
|---|---|---:|---:|---|---|
| Orientation | left/right/collinear | `O(1)` | `O(1)` | overflow with large coords | [Erect the Fence](https://leetcode.com/problems/erect-the-fence/) |
| Segment intersection | line segment crossing | `O(1)` | `O(1)` | precision if using double carelessly | geometry tasks |
| Polygon area | shoelace formula | `O(n)` | `O(1)` | points unordered | geometry tasks |
| Convex hull | outer boundary | `O(n log n)` | `O(n)` | collinear policy unclear | [Erect the Fence](https://leetcode.com/problems/erect-the-fence/) |
| Rotating calipers | diameter/width on convex hull | `O(n)` after hull | `O(1)` | polygon not convex | advanced |
| Sweep line | events ordered by x/time | `O(n log n)` | `O(n)` | event tie handling wrong | [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) |

### Code Templates

```cpp
struct Point {
    long long x, y;
    bool operator<(const Point& other) const {
        return x == other.x ? y < other.y : x < other.x;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

Point operator-(Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}

long long cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

long long orient(Point a, Point b, Point c) {
    return cross(b - a, c - a);
}
```

```cpp
vector<Point> convex_hull(vector<Point> p) {
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1) return p;

    vector<Point> hull;
    for (Point pt : p) {
        while (hull.size() >= 2 &&
               orient(hull[hull.size() - 2], hull.back(), pt) < 0) {
            hull.pop_back();
        }
        hull.push_back(pt);
    }
    int lowerSize = hull.size();
    for (int i = (int)p.size() - 2; i >= 0; i--) {
        Point pt = p[i];
        while ((int)hull.size() > lowerSize &&
               orient(hull[hull.size() - 2], hull.back(), pt) < 0) {
            hull.pop_back();
        }
        hull.push_back(pt);
    }
    hull.pop_back();
    return hull;
}
```

## 17. Advanced Competitive Programming Topics

This section keeps advanced topics grouped by the kind of problem they solve.

### Advanced Range and Tree Tools

| Topic | Use case | Time | Fails when | Learn after |
|---|---|---:|---|---|
| Heavy-Light Decomposition | path queries on tree | `O(log^2 n)` | graph not tree | LCA, segment tree |
| Centroid decomposition | distance queries on tree | `O(log n)` per update/query often | not tree | tree DFS |
| DSU on tree | subtree frequency queries | `O(n log n)` or `O(n)` | online updates | tree DFS, maps |
| Persistent segment tree | historical versions/kth query | `O(log n)` per version/query | too much memory | segment tree |
| Wavelet tree | kth/rank/frequency static ranges | `O(log sigma)` | dynamic updates | merge sort tree |
| Segment Tree Beats | range chmin/chmax/sum | amortized `O(log n)` | operation not compatible | lazy segment tree |
| Li Chao tree | dynamic line minimum | `O(log C)` | x-domain unknown or floating hard | CHT |
| Link-Cut Tree | dynamic forest paths | `O(log n)` amortized | implementation risk | splay trees |

### Advanced DP Tools

| Topic | Use case | Time | Fails when | Learn after |
|---|---|---:|---|---|
| Divide and conquer DP | monotonic best split | `O(k n log n)` or `O(k n)` style | opt not monotonic | interval/partition DP |
| Knuth optimization | special interval DP | `O(n^2)` | quadrangle conditions fail | interval DP |
| Convex Hull Trick | line transitions | `O(log n)` or amortized `O(1)` | not linear transition | DP optimization |
| Li Chao DP | arbitrary line order | `O(log C)` | x-domain issue | CHT |
| SOS DP | subset transforms | `O(n 2^n)` | `n` too large | bitmask DP |
| Digit DP | count numbers by digits | digits * states | state unclear | memoization |
| Slope trick | convex piecewise costs | varies | problem not convex | advanced DP |

### Advanced Graph Tools

| Topic | Use case | Time | Fails when | Learn after |
|---|---|---:|---|---|
| Rollback DSU | offline connectivity with undo | `O(log q)` intervals * DSU | online deletion required | DSU |
| Offline dynamic connectivity | edge add/delete queries | `O((m+q) log q)` | online answers with no offline allowed | rollback DSU |
| Dominator tree | mandatory vertices in directed flow graph | near-linear | graph not rooted/reachable | DFS, DSU ideas |
| Gomory-Hu tree | all-pairs min cut undirected | `n-1` max flows | directed graph | max flow |
| Blossom | general graph matching | `O(n^3)` | bipartite graph simpler | matching |
| Min-cost circulation | flow with demands/costs | depends | constraints modeled wrong | min-cost flow |

### Advanced String and Math Tools

| Topic | Use case | Time | Fails when | Learn after |
|---|---|---:|---|---|
| Aho-Corasick | many patterns | linear in text + matches | one pattern only | trie, BFS |
| Suffix array | suffix ordering | `O(n log n)` | online edits | sorting, strings |
| Suffix automaton | substring set | `O(n)` | implementation hard | automata idea |
| Eertree | palindromic substrings | `O(n log alphabet)` | no palindrome need | Manacher |
| NTT | convolution under friendly mod | `O(n log n)` | wrong modulus/root | modular arithmetic |
| FWHT | xor/and/or convolution | `O(n log n)` | operation mismatch | bitmask DP |
| Berlekamp-Massey | find linear recurrence | `O(n^2)` | sequence not linear recurrence | modular arithmetic |
| Pollard Rho | factor huge integers | expected fast | random bad cases | Miller-Rabin |

## 18. Constraint-to-Algorithm Guide

| Constraint clue | Likely algorithms |
|---|---|
| `n <= 10` | permutations, backtracking |
| `n <= 20` | bitmask DP, meet in the middle |
| `n <= 500` | `O(n^3)` DP/Floyd-Warshall |
| `n <= 5000` | `O(n^2)` DP |
| `n <= 2e5` | `O(n log n)`, graph linear, Fenwick, segment tree |
| many range sum queries, no updates | prefix sums |
| range queries with updates | Fenwick or segment tree |
| shortest path, unweighted | BFS |
| shortest path, nonnegative weights | Dijkstra |
| shortest path, negative weights | Bellman-Ford |
| graph has dependencies | topological sort |
| undirected graph connectivity additions | DSU |
| cheapest connect all nodes | MST |
| many patterns in text | Aho-Corasick |
| palindromes | Manacher or DP |
| primes up to `n` | sieve |
| huge primality/factorization | Miller-Rabin, Pollard Rho |

## 19. Final Revision Checklist

Before saying you know a topic, make sure you can answer:

1. What problem pattern triggers it?
2. What does it store?
3. What rule stays true while it runs?
4. What is the time complexity?
5. What is the memory complexity?
6. When does it fail?
7. What edge cases break beginner code?
8. Can you write the template without looking?
9. Can you solve the included example from scratch?
10. Can you solve at least three linked practice problems?

### Common C++ Bugs

- `int` overflow; use `long long`.
- `1 << k` when `k >= 31`; use `1LL << k`.
- Bad comparator that violates strict weak ordering.
- Forgetting to clear global arrays between test cases.
- Recursion depth stack overflow.
- Mixing directed and undirected graph logic.
- Using Dijkstra with negative edges.
- Forgetting disconnected graph components.
- Negative modulo not normalized.
- Floating point equality in geometry.

### Suggested Study Plan

1. Arrays, prefix sums, sorting, binary search.
2. Two pointers, sliding window, stack, queue, hash map, heap.
3. Recursion, backtracking, greedy, basic DP.
4. Trees, BFS, DFS, topological sort, DSU.
5. Dijkstra, MST, Fenwick, segment tree.
6. Strings, bit manipulation, number theory.
7. Flow, matching, SCC, bridges, articulation points.
8. Advanced DP, HLD, centroid, persistence, Li Chao.
9. Geometry, suffix structures, FFT/NTT, Pollard Rho.
10. Mixed timed contests and stress testing.
