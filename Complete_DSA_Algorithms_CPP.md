# Complete DSA Algorithms in C++17/20

An in-depth handbook for learning Data Structures and Algorithms from scratch, preparing for coding interviews, competitive programming, ICPC-style contests, and advanced algorithmic problem solving.

This file is written for practical C++17/C++20 use. The explanations try to stay simple first, then go deeper. Each important topic should answer: what is it, when should I use it, when should I avoid it, how fast is it, what mistakes happen, and how do I solve a real problem with it?

## Table of Contents

- [0. Beginner-Friendly Topic Packs](#0-beginner-friendly-topic-packs)
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
- [21. Topic-Wise Code Schedule and C++ Template Vault](#21-topic-wise-code-schedule-and-c-template-vault)

## How to Study This Handbook

- First pass: read one topic pack fully. Do not jump around.
- Second pass: type the code by hand without copying.
- Third pass: solve the included example again from memory.
- Fourth pass: try the linked practice problems.
- Fifth pass: come back to the deeper reference section for that same topic.
- For every topic, ask: what problem does this solve, what rule makes it work, what input breaks it, and what is the time complexity?


For each algorithm or data structure, use this review checklist:

1. What does the algorithm store or compute?
2. What stays true after every step?
3. Why does the answer not miss anything?
4. Which problem words suggest this topic?
5. Which constraints make this algorithm fast enough?
6. Which assumption can break the solution?
7. What is the time complexity?
8. What is the memory complexity?
9. Are indices 0-based or 1-based?
10. What happens for empty, single-element, duplicate, negative, and huge inputs?
11. Can `int` overflow?
12. Can I brute force small tests to check this?
13. What would I use if constraints changed?
14. Can I explain the solution in plain English?



## 0. Beginner-Friendly Topic Packs

Read this section before the deep reference. Each topic pack keeps the important learning pieces in one place:

- plain idea
- when to use it
- when not to use it
- complexity
- common mistakes
- one solved problem statement
- C++ solution
- LeetCode practice links

The later sections of this handbook still contain the bigger theory lists and advanced templates. This section is the guided path.

### Plain-English Glossary

| Word | Simple meaning |
|---|---|
| invariant | A rule that stays true while the algorithm runs. |
| monotonic | Always moving in one direction: increasing, decreasing, true-to-false, or false-to-true. |
| brute force | Try all possibilities directly. Usually simple but slow. |
| state | The information needed to describe where you are in a problem. |
| transition | The move from one state to another. |
| greedy | Make the best-looking choice now, and prove it will not hurt later. |
| amortized | Average cost over many operations, even if one operation can be expensive. |
| online | Process queries as they arrive. You cannot reorder them. |
| offline | You know all queries first, so you may reorder or preprocess them. |
| static | The data does not change. |
| dynamic | The data changes through updates. |
| idempotent | Repeating the same operation does not change the result, like `min(x, x) = x`. |

### Learning Ladder

| Stage | Learn these before moving on |
|---|---|
| 1 | Arrays, strings, sorting, binary search, prefix sums. |
| 2 | Two pointers, sliding window, stack, queue, heap, hash map. |
| 3 | Recursion, backtracking, basic DP. |
| 4 | Trees, BFS, DFS, topological sort, DSU. |
| 5 | Dijkstra, MST, Fenwick tree, segment tree, trie, KMP. |
| 6 | Advanced DP, SCC, bridges, flow, matching, suffix structures, number theory, geometry. |

Do not rush. A good rule is: before starting the next row, solve at least 3 to 5 problems from the current row.

### Pack 1: Prefix Sum

**Plain idea:** Store running sums so range sums become instant.

**Use when:**

- Array does not change.
- Many queries ask for sum from `l` to `r`.
- You need subarray sum tricks.

**Do not use when:**

- There are many updates. Use Fenwick tree or segment tree.
- You need range minimum or maximum. Prefix sums only work for operations that can be undone by subtraction.

**Complexity:** Build `O(n)`, each query `O(1)`, memory `O(n)`.

**Common mistakes:**

- Mixing 0-based and 1-based indices.
- Forgetting that `pref[i]` often means sum of first `i` elements, not up to index `i`.
- Overflowing `int`; use `long long`.

**Solved problem statement:** Given an array and many queries `(l, r)`, return the sum from index `l` to index `r`, inclusive.

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

**Practice links:**

- [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

### Pack 2: Binary Search

**Plain idea:** Repeatedly cut the search space in half.

**Use when:**

- Data is sorted.
- Or the answer has a yes/no pattern like `false false false true true`.
- You need the first position where something becomes true.

**Do not use when:**

- The condition is not monotonic.
- The array is unsorted and you are searching by value without preprocessing.

**Complexity:** `O(log n)` for normal search. For binary search on answer: `O(log answer_range * cost_of_check)`.

**Common mistakes:**

- Infinite loop from wrong `mid` update.
- Using `(l + r) / 2` when values can overflow. Use `l + (r - l) / 2`.
- Choosing `<` instead of `<=` incorrectly.

**Solved problem statement:** Given sorted array `a` and target `x`, return the first index where `a[index] >= x`. If no such index exists, return `n`.

```cpp
int first_greater_equal(const vector<int>& a, int x) {
    int l = 0, r = a.size(); // answer is in [0, n]
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
```

**Practice links:**

- [Binary Search](https://leetcode.com/problems/binary-search/)
- [Search Insert Position](https://leetcode.com/problems/search-insert-position/)
- [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

### Pack 3: Two Pointers

**Plain idea:** Use two indices that move through the array. Each pointer moves only forward or inward, so the solution stays fast.

**Use when:**

- Array is sorted.
- You are looking for pairs, triplets, or a window.
- Moving one pointer has a predictable effect.

**Do not use when:**

- You need to try all unrelated pairs.
- Moving pointers does not preserve useful information.

**Complexity:** Usually `O(n)` after sorting, or `O(n log n)` including sorting.

**Common mistakes:**

- Forgetting to sort when the logic needs sorted order.
- Not skipping duplicates in 3Sum-style problems.
- Moving the wrong pointer.

**Solved problem statement:** Given a sorted array and target, return whether two numbers sum to target.

```cpp
bool has_pair_sum(vector<int> a, int target) {
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

**Practice links:**

- [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
- [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
- [3Sum](https://leetcode.com/problems/3sum/)

### Pack 4: Sliding Window

**Plain idea:** Keep a valid subarray window `[l, r]`. Expand with `r`, shrink with `l`.

**Use when:**

- The problem asks for longest, shortest, or count of subarrays/substrings.
- Removing from the left helps fix the window.
- The condition can be maintained with counts, sum, or frequency map.

**Do not use when:**

- The window condition is not repairable by moving `l`.
- Negative numbers break a sum-based monotonic condition.

**Complexity:** Usually `O(n)`.

**Common mistakes:**

- Updating the answer before the window is valid.
- Forgetting to decrement frequency when moving `l`.
- Using sliding window with negative numbers when prefix sum or hash map is needed.

**Solved problem statement:** Given a string, return the length of the longest substring with no repeated characters.

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

**Practice links:**

- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)

### Pack 5: Monotonic Stack

**Plain idea:** Keep a stack whose values are always increasing or decreasing. When a new value breaks the order, it becomes the answer for older values.

**Use when:**

- You need next greater, next smaller, previous greater, or previous smaller.
- The problem asks for nearest bigger/smaller element.
- Histogram or temperature-style problems appear.

**Do not use when:**

- You need all greater elements, not the nearest one.
- The order of elements does not matter.

**Complexity:** `O(n)` because every index is pushed and popped at most once.

**Common mistakes:**

- Using `<` when you need `<=`, especially with duplicates.
- Storing values when you need indices.
- Thinking the stack is sorted globally. It only stores useful candidates.

**Solved problem statement:** For every index, return the index of the next element to the right that is greater. If none exists, return `-1`.

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

**Practice links:**

- [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)
- [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)
- [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

### Pack 6: Hash Map Counting

**Plain idea:** Store counts or first positions in a hash map so you can answer "have I seen this before?" quickly.

**Use when:**

- You need frequencies.
- You need pairs with a target sum.
- You need prefix sums seen earlier.

**Do not use when:**

- You need sorted order. Use `map`, `set`, heap, or sorting.
- Hash collision attacks are possible and the judge is adversarial. Use custom hash.

**Complexity:** Average `O(1)` per operation, worst case can degrade.

**Common mistakes:**

- Using `mp[x]` only to check existence, which inserts `x`.
- Forgetting duplicates.
- Not using `long long` for prefix sums.

**Solved problem statement:** Count subarrays with sum exactly `k`.

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

**Practice links:**

- [Two Sum](https://leetcode.com/problems/two-sum/)
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- [Group Anagrams](https://leetcode.com/problems/group-anagrams/)

### Pack 7: Heap / Priority Queue

**Plain idea:** Keep quick access to the smallest or largest item while items are added and removed.

**Use when:**

- You repeatedly need current minimum or maximum.
- You need top `k` elements.
- Greedy choice depends on best available item.

**Do not use when:**

- You need to search arbitrary elements quickly.
- You need sorted traversal of all elements. Use sorting or set.

**Complexity:** Push/pop `O(log n)`, top `O(1)`.

**Common mistakes:**

- C++ `priority_queue<int>` is a max-heap by default.
- Forgetting lazy deletion for outdated entries.
- Putting pair fields in the wrong order.

**Solved problem statement:** Return the `k` most frequent numbers.

```cpp
vector<int> top_k_frequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (auto [x, f] : freq) {
        pq.push({f, x});
        if ((int)pq.size() > k) pq.pop();
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
```

**Practice links:**

- [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
- [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)

### Pack 8: Recursion and Backtracking

**Plain idea:** Build an answer step by step. If a choice fails, undo it and try another choice.

**Use when:**

- You need all subsets, permutations, combinations, paths, or board placements.
- Constraints are small enough for exponential search.
- You can prune bad choices early.

**Do not use when:**

- `n` is too large for exponential choices.
- A DP or greedy solution exists and avoids repeated work.

**Complexity:** Depends on the number of generated states. Subsets are `O(2^n)`, permutations are `O(n!)`.

**Common mistakes:**

- Forgetting to undo a choice.
- Passing large vectors by value accidentally.
- Missing duplicate handling.

**Solved problem statement:** Generate all subsets of an array.

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

**Practice links:**

- [Subsets](https://leetcode.com/problems/subsets/)
- [Permutations](https://leetcode.com/problems/permutations/)
- [N-Queens](https://leetcode.com/problems/n-queens/)

### Pack 9: Greedy Intervals

**Plain idea:** Sort intervals, then make the locally best choice. You must be able to explain why that choice cannot hurt the future.

**Use when:**

- Intervals have start/end times.
- You need minimum removals, maximum non-overlapping intervals, or merge coverage.
- Sorting by end time makes future choices easier.

**Do not use when:**

- A local choice can block a better global answer and no proof exists.
- The problem has hidden states that require DP.

**Complexity:** Usually `O(n log n)` because of sorting.

**Common mistakes:**

- Sorting by start when the proof needs sorting by end.
- Confusing overlap rules for closed intervals.
- Not handling equal endpoints carefully.

**Solved problem statement:** Given intervals, remove the fewest intervals so the rest do not overlap.

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

**Practice links:**

- [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
- [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)
- [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)

### Pack 10: Dynamic Programming

**Plain idea:** Save answers to smaller problems so you do not solve them again.

**Use when:**

- You see "maximum/minimum/count ways".
- Choices overlap and repeat.
- A state can describe the remaining problem.

**Do not use when:**

- There are no repeated subproblems.
- A simpler greedy proof works.
- State count is too large.

**Complexity:** `number_of_states * work_per_state`.

**Common mistakes:**

- Bad state definition.
- Missing base cases.
- Computing states in the wrong order.
- Forgetting to use `long long` for counts.

**Solved problem statement:** Given coin values and amount, return the fewest coins needed to make the amount, or `-1` if impossible.

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

**Practice links:**

- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [House Robber](https://leetcode.com/problems/house-robber/)
- [Coin Change](https://leetcode.com/problems/coin-change/)
- [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

### Pack 11: Tree DFS

**Plain idea:** A tree has no cycles, so DFS can safely go from parent to children and combine child answers.

**Use when:**

- Input is a tree.
- You need depth, subtree size, path length, ancestor, diameter, or tree DP.

**Do not use when:**

- The graph has cycles and you do not track visited nodes.
- Recursion depth can exceed stack limits.

**Complexity:** `O(n)`.

**Common mistakes:**

- Forgetting the parent check.
- Treating a general graph as a tree.
- Stack overflow on deep trees.

**Solved problem statement:** Given an undirected tree, compute the size of every node's subtree when rooted at `0`.

```cpp
void subtree_dfs(int u, int p, const vector<vector<int>>& g, vector<int>& sub) {
    sub[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        subtree_dfs(v, u, g, sub);
        sub[u] += sub[v];
    }
}

vector<int> subtree_sizes(const vector<vector<int>>& g) {
    vector<int> sub(g.size());
    subtree_dfs(0, -1, g, sub);
    return sub;
}
```

**Practice links:**

- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)
- [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

### Pack 12: BFS and DFS on Graphs

**Plain idea:** BFS explores by distance layers. DFS explores as far as possible before coming back.

**Use BFS when:**

- You need shortest path in an unweighted graph.
- You need levels or minimum number of moves.

**Use DFS when:**

- You need connected components, cycle detection, or full exploration.

**Do not use when:**

- Edges have different positive weights. Use Dijkstra.
- Edges have negative weights. Use Bellman-Ford or other tools.

**Complexity:** `O(n + m)`.

**Common mistakes:**

- Not marking visited early enough.
- Forgetting disconnected components.
- Mixing grid bounds.

**Solved problem statement:** Given a grid of `0` and `1`, count connected groups of `1`s using 4-direction movement.

```cpp
int count_islands(vector<vector<char>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size(), ans = 0;
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

**Practice links:**

- [Number of Islands](https://leetcode.com/problems/number-of-islands/)
- [Clone Graph](https://leetcode.com/problems/clone-graph/)
- [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)

### Pack 13: Topological Sort

**Plain idea:** Put directed tasks in an order where every prerequisite comes first.

**Use when:**

- The graph is directed.
- You have prerequisites or dependencies.
- You need to detect a cycle in directed graph.

**Do not use when:**

- The graph is undirected.
- Cycles are allowed and no valid ordering exists.

**Complexity:** `O(n + m)`.

**Common mistakes:**

- Using it on undirected graphs.
- Forgetting that multiple valid orders can exist.
- Not checking whether all nodes were processed.

**Solved problem statement:** Given `n` courses and prerequisite pairs `[a, b]` meaning `b` before `a`, return whether all courses can be finished.

```cpp
bool can_finish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(n);
    vector<int> indeg(n);
    for (auto& e : prerequisites) {
        int a = e[0], b = e[1];
        g[b].push_back(a);
        indeg[a]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);

    int seen = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        seen++;
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return seen == n;
}
```

**Practice links:**

- [Course Schedule](https://leetcode.com/problems/course-schedule/)
- [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
- [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/)

### Pack 14: DSU / Union Find

**Plain idea:** Keep track of groups. Quickly ask whether two items are already in the same group.

**Use when:**

- Components merge over time.
- You need connectivity under edge additions.
- You are building MST with Kruskal.

**Do not use when:**

- Edges are deleted online. Basic DSU cannot split groups.
- You need shortest paths.

**Complexity:** Almost `O(1)` per operation with path compression and union by size.

**Common mistakes:**

- Forgetting path compression.
- Not unioning by size/rank.
- Trying to remove edges from normal DSU.

**Solved problem statement:** Given an undirected graph, count connected components.

```cpp
struct DSU_simple {
    vector<int> p, sz;
    DSU_simple(int n) : p(n), sz(n, 1) {
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

int count_components(int n, vector<vector<int>>& edges) {
    DSU_simple dsu(n);
    int comps = n;
    for (auto& e : edges) {
        if (dsu.unite(e[0], e[1])) comps--;
    }
    return comps;
}
```

**Practice links:**

- [Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
- [Redundant Connection](https://leetcode.com/problems/redundant-connection/)
- [Accounts Merge](https://leetcode.com/problems/accounts-merge/)

### Pack 15: Dijkstra's Algorithm

**Plain idea:** Always finalize the unvisited node with the smallest known distance.

**Use when:**

- You need shortest paths.
- Edge weights are nonnegative.
- Graph can be directed or undirected.

**Do not use when:**

- Any edge weight is negative. Use Bellman-Ford or another method.
- All edges are weight `1`. BFS is simpler and faster.

**Complexity:** `O((n + m) log n)` with priority queue.

**Common mistakes:**

- Using Dijkstra with negative weights.
- Not skipping old priority queue entries.
- Overflowing distance.

**Solved problem statement:** Given weighted directed edges, return shortest distance from source to every node.

```cpp
vector<long long> shortest_paths(int n, vector<vector<pair<int, int>>>& g, int src) {
    const long long INF = 4e18;
    vector<long long> dist(n, INF);
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

**Practice links:**

- [Network Delay Time](https://leetcode.com/problems/network-delay-time/)
- [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
- [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

### Pack 16: Fenwick Tree

**Plain idea:** Store partial sums in a clever way so point updates and prefix sums are both fast.

**Use when:**

- You need point update and range sum.
- You need frequency counts with prefix queries.
- You need inversion count or order counting.

**Do not use when:**

- You need range minimum with arbitrary updates.
- You need complex range operations. Segment tree is more flexible.

**Complexity:** Update `O(log n)`, query `O(log n)`, memory `O(n)`.

**Common mistakes:**

- Fenwick tree is internally 1-based.
- Infinite loop if index is not incremented before update.
- Querying wrong inclusive range.

**Solved problem statement:** Support update index `i` by adding `x`, and query sum from `l` to `r`.

```cpp
struct Fenwick_pack {
    int n;
    vector<long long> bit;
    Fenwick_pack(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, long long val) {
        for (idx++; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    long long prefix_sum(int idx) {
        long long ans = 0;
        for (idx++; idx > 0; idx -= idx & -idx) ans += bit[idx];
        return ans;
    }

    long long range_sum(int l, int r) {
        return prefix_sum(r) - (l == 0 ? 0 : prefix_sum(l - 1));
    }
};
```

**Practice links:**

- [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/)
- [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
- [Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)

### Pack 17: Segment Tree

**Plain idea:** Split the array into ranges. Each node stores the answer for one range.

**Use when:**

- You need range query plus updates.
- Operation is sum, min, max, gcd, xor, or a custom merge.
- Fenwick tree is not flexible enough.

**Do not use when:**

- Array is static and sparse table is simpler.
- You only need prefix sums.

**Complexity:** Build `O(n)`, update `O(log n)`, query `O(log n)`.

**Common mistakes:**

- Wrong overlap checks.
- Forgetting to merge after update.
- Making tree size too small.

**Solved problem statement:** Support point assignment and range sum query.

```cpp
struct SegmentTree_pack {
    int n;
    vector<long long> tree;

    SegmentTree_pack(vector<int>& a) {
        n = a.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(node * 2, l, mid, idx, val);
        else update(node * 2 + 1, mid + 1, r, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr)
             + query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};
```

**Practice links:**

- [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/)
- [My Calendar I](https://leetcode.com/problems/my-calendar-i/)
- [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)

### Pack 18: Trie

**Plain idea:** Store strings as paths in a tree, one character at a time.

**Use when:**

- You need prefix search.
- You need many dictionary words.
- You need word matching on grids or streams.

**Do not use when:**

- You only need exact lookup. Hash set is simpler.
- Alphabet is huge and memory is tight.

**Complexity:** Insert/search `O(length_of_word)`.

**Common mistakes:**

- Not marking word endings.
- Assuming all characters are lowercase.
- Memory explosion for large alphabets.

**Solved problem statement:** Implement insert, exact search, and prefix search.

```cpp
struct Trie_pack {
    struct Node {
        int next[26];
        bool end = false;
        Node() { fill(next, next + 26, -1); }
    };
    vector<Node> t{Node()};

    void insert(const string& word) {
        int u = 0;
        for (char ch : word) {
            int c = ch - 'a';
            if (t[u].next[c] == -1) {
                t[u].next[c] = t.size();
                t.push_back(Node());
            }
            u = t[u].next[c];
        }
        t[u].end = true;
    }

    bool search(const string& word) {
        int u = 0;
        for (char ch : word) {
            int c = ch - 'a';
            if (t[u].next[c] == -1) return false;
            u = t[u].next[c];
        }
        return t[u].end;
    }

    bool starts_with(const string& pref) {
        int u = 0;
        for (char ch : pref) {
            int c = ch - 'a';
            if (t[u].next[c] == -1) return false;
            u = t[u].next[c];
        }
        return true;
    }
};
```

**Practice links:**

- [Implement Trie](https://leetcode.com/problems/implement-trie-prefix-tree/)
- [Word Search II](https://leetcode.com/problems/word-search-ii/)
- [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

### Pack 19: KMP String Matching

**Plain idea:** When a pattern match fails, do not restart from zero. Reuse the longest prefix that is also a suffix.

**Use when:**

- You need exact pattern matching in linear time.
- You need border, prefix, or repetition logic.

**Do not use when:**

- You only need one small search; built-in `find` may be enough.
- You need many patterns. Use Aho-Corasick.

**Complexity:** `O(n + m)`.

**Common mistakes:**

- Building prefix function on the wrong string.
- Off-by-one when converting match position.
- Confusing prefix function with Z-function.

**Solved problem statement:** Return the first index where pattern appears in text, or `-1`.

```cpp
vector<int> prefix_function_pack(const string& s) {
    vector<int> pi(s.size());
    for (int i = 1; i < (int)s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int first_occurrence_kmp(const string& text, const string& pat) {
    if (pat.empty()) return 0;
    string combined = pat + "#" + text;
    vector<int> pi = prefix_function_pack(combined);
    int m = pat.size();
    for (int i = m + 1; i < (int)combined.size(); i++) {
        if (pi[i] == m) return i - 2 * m;
    }
    return -1;
}
```

**Practice links:**

- [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)
- [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/)
- [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)

### Pack 20: Bit Manipulation

**Plain idea:** Use binary bits directly. A number can represent a set, flags, or choices.

**Use when:**

- `n <= 20` suggests subsets.
- You need xor tricks.
- You need fast set/check/toggle operations.

**Do not use when:**

- The bit count is too large for integer masks.
- Simpler arrays make code clearer.

**Complexity:** Bit operations are usually `O(1)`. Enumerating masks is `O(2^n)`.

**Common mistakes:**

- Writing `1 << k` when `k >= 31`; use `1LL << k`.
- Confusing xor with addition.
- Forgetting operator precedence.

**Solved problem statement:** Given numbers where every value appears twice except one, return the single value.

```cpp
int single_number(vector<int>& nums) {
    int ans = 0;
    for (int x : nums) ans ^= x;
    return ans;
}
```

**Practice links:**

- [Single Number](https://leetcode.com/problems/single-number/)
- [Subsets](https://leetcode.com/problems/subsets/)
- [Counting Bits](https://leetcode.com/problems/counting-bits/)

### Pack 21: Number Theory Basics

**Plain idea:** Use math properties of divisibility, primes, gcd, and modulo.

**Use when:**

- Problem mentions prime, gcd, lcm, divisibility, modulo, factors, or combinations.
- You need fast repeated multiplication under modulo.

**Do not use when:**

- Direct simulation is enough and constraints are small.
- You assume modulo division works without modular inverse.

**Complexity:** GCD is `O(log min(a, b))`. Sieve is `O(n log log n)`.

**Common mistakes:**

- Dividing under modulo without inverse.
- Not normalizing negative modulo.
- Overflowing during multiplication.

**Solved problem statement:** Count primes less than `n`.

```cpp
int count_primes(int n) {
    if (n <= 2) return 0;
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i < n; i++) {
        if (!isPrime[i]) continue;
        for (long long j = i * i; j < n; j += i) {
            isPrime[j] = false;
        }
    }
    int ans = 0;
    for (bool x : isPrime) ans += x;
    return ans;
}
```

**Practice links:**

- [Count Primes](https://leetcode.com/problems/count-primes/)
- [Pow(x, n)](https://leetcode.com/problems/powx-n/)
- [Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

### Pack 22: Minimum Spanning Tree

**Plain idea:** Connect all nodes with minimum total edge cost without cycles.

**Use when:**

- You need cheapest way to connect everything.
- Graph is undirected and weighted.
- Keywords include network, connect, minimum total cost.

**Do not use when:**

- You need shortest path from one node to another. Use shortest path algorithms.
- Graph is directed. MST is for undirected graphs.

**Complexity:** Kruskal is `O(m log m)`.

**Common mistakes:**

- Using MST for shortest path.
- Forgetting graph must be connected, or checking if MST has `n - 1` edges.
- Sorting edges incorrectly.

**Solved problem statement:** Given points on a plane, connect all points with minimum total Manhattan distance.

```cpp
int min_cost_connect_points(vector<vector<int>>& points) {
    int n = points.size();
    vector<array<int, 3>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back({w, i, j});
        }
    }
    sort(edges.begin(), edges.end());

    DSU_simple dsu(n);
    int cost = 0, used = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            cost += w;
            used++;
            if (used == n - 1) break;
        }
    }
    return cost;
}
```

**Practice links:**

- [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)
- [Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)
- [Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)

### Pack 23: Advanced Graphs in Simple Words

Use this pack after BFS, DFS, DSU, and shortest paths.

| Topic | Simple use | First thing to remember |
|---|---|---|
| SCC | Group directed nodes that can all reach each other. | Compress SCCs into a DAG. |
| Bridges | Find edges that disconnect an undirected graph if removed. | Use DFS entry time and low-link values. |
| Articulation points | Find vertices that disconnect graph if removed. | Similar to bridges, but vertex-based. |
| 2-SAT | Solve true/false constraints. | Convert clauses to implications, then use SCC. |
| Flow | Push as much quantity as possible through capacities. | Residual graph tells where more flow can still go. |
| Matching | Pair items under rules. | Bipartite matching is easier than general matching. |

**Solved problem statement:** Given prerequisite implications in a directed graph, group mutually reachable nodes using SCC. If two nodes are in the same group, each can reach the other.

```cpp
struct SCC_pack {
    int n, timer = 0, compCount = 0;
    vector<vector<int>> g;
    vector<int> disc, low, comp, st;
    vector<bool> inStack;

    SCC_pack(vector<vector<int>> graph) : n(graph.size()), g(move(graph)) {
        disc.assign(n, -1);
        low.assign(n, 0);
        comp.assign(n, -1);
        inStack.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) dfs(i);
        }
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
                comp[v] = compCount;
                if (v == u) break;
            }
            compCount++;
        }
    }
};
```

**Practice links:**

- [Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/)
- [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/)
- [Maximum Students Taking Exam](https://leetcode.com/problems/maximum-students-taking-exam/)

### Pack 24: How to Use LeetCode Links

Use links as practice, not as the main explanation. For every linked problem:

1. Identify the topic before coding.
2. Write the brute force idea first.
3. Explain why brute force is too slow.
4. Write the optimized idea in plain English.
5. Code from memory.
6. Test edge cases manually.
7. Compare with the template only after trying.

When a problem can be solved by many methods, write down all valid methods. Example: `Range Sum Query - Mutable` can be solved by Fenwick tree or segment tree. `Course Schedule` can be solved by topological sort or DFS cycle detection.



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



## 21. Topic-Wise Code Schedule and C++ Template Vault

Use this section as the code-first companion to the theory above. The goal is to practice in a staged order: first implement simple patterns from memory, then combine them, then move to ICPC-hard templates.

All snippets assume C++17 unless stated otherwise.

### Code Practice Schedule

| Level | Study order | Must-code templates |
|---|---|---|
| Early 1 | STL, arrays, strings, sorting, binary search | starter template, lower/upper bound, comparator, prefix sum, difference array |
| Early 2 | Two pointers, sliding window, stacks, queues | fixed/variable window, monotonic stack, monotonic queue, heap patterns |
| Early 3 | Recursion and brute force | subsets, permutations, combinations, backtracking skeleton |
| Early 4 | Basic graphs and basic DP | BFS, DFS, connected components, grid BFS, 0/1 knapsack, LIS, LCS |
| Moderate 1 | Range queries | Fenwick tree, segment tree, lazy propagation, sparse table, sqrt decomposition |
| Moderate 2 | Trees | tree DFS, diameter, binary lifting LCA, Euler tour, trie, DSU |
| Moderate 3 | Shortest paths and MST | Dijkstra, Bellman-Ford, Floyd-Warshall, 0-1 BFS, Kruskal, Prim |
| Moderate 4 | Strings and number theory | KMP, Z, rolling hash, sieve, modular inverse, nCr, CRT |
| Advanced 1 | Graph structure | SCC, bridges, articulation points, 2-SAT, Euler path, functional graph lifting |
| Advanced 2 | Flow and matching | Dinic, min-cost max-flow, Kuhn, Hopcroft-Karp, Hungarian |
| Advanced 3 | Tree/range hard tools | HLD, centroid decomposition, DSU on tree, persistent segment tree, wavelet tree |
| Advanced 4 | DP optimization | SOS DP, divide-and-conquer DP, Knuth optimization, CHT, Li Chao tree |
| ICPC-hard | Mixed advanced topics | rollback DSU, offline dynamic connectivity, suffix array, suffix automaton, Aho-Corasick, NTT, Pollard Rho, geometry, Link-Cut Tree |

### Starter and Utility Templates

#### Contest Starter

Use this for almost every competitive programming solution.

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

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

#### Coordinate Compression

Use when values are large but only their relative order matters. Complexity: `O(n log n)`.

```cpp
vector<int> compress(vector<long long> a) {
    vector<long long> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<int> id(a.size());
    for (int i = 0; i < (int)a.size(); i++) {
        id[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }
    return id;
}
```

#### Custom Hash for Unordered Maps

Use when adversarial tests can break `unordered_map` with many collisions.

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

// unordered_map<long long, int, CustomHash> mp;
```

### Early Level: Arrays, Searching, Sorting, Windows

#### Prefix Sum

Use for static range-sum queries. Query complexity: `O(1)` after `O(n)` build.

```cpp
vector<long long> buildPrefix(const vector<int>& a) {
    int n = a.size();
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    return pref;
}

long long rangeSum(const vector<long long>& pref, int l, int r) {
    // inclusive l, inclusive r, 0-based
    return pref[r + 1] - pref[l];
}
```

#### 2D Prefix Sum

Use for static rectangle-sum queries. Query complexity: `O(1)` after `O(nm)` build.

```cpp
vector<vector<long long>> build2DPrefix(const vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    vector<vector<long long>> pref(n + 1, vector<long long>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i + 1][j + 1] = a[i][j] + pref[i][j + 1]
                                + pref[i + 1][j] - pref[i][j];
        }
    }
    return pref;
}

long long rectSum(const vector<vector<long long>>& pref,
                  int r1, int c1, int r2, int c2) {
    // inclusive corners, 0-based
    return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1]
         - pref[r2 + 1][c1] + pref[r1][c1];
}
```

#### Difference Array

Use for many offline range additions and final point values. Complexity: `O(n + q)`.

```cpp
vector<long long> applyRangeAdds(int n, vector<array<int, 3>> queries) {
    vector<long long> diff(n + 1);
    for (auto [l, r, x] : queries) {
        diff[l] += x;
        if (r + 1 < n) diff[r + 1] -= x;
    }
    vector<long long> a(n);
    long long cur = 0;
    for (int i = 0; i < n; i++) {
        cur += diff[i];
        a[i] = cur;
    }
    return a;
}
```

#### Binary Search on Answer

Use only when feasibility is monotonic: if answer `x` works, then every larger or smaller value also works.

```cpp
long long firstTrue(long long lo, long long hi, function<bool(long long)> ok) {
    // returns first x in [lo, hi] with ok(x) == true
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (ok(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
```

#### Ternary Search on Unimodal Integer Function

Use when function decreases then increases, or increases then decreases. Do not use if the function is not unimodal.

```cpp
long long ternaryMin(long long l, long long r, function<long long(long long)> f) {
    while (r - l > 3) {
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;
        if (f(m1) <= f(m2)) r = m2 - 1;
        else l = m1 + 1;
    }
    long long best = l;
    for (long long x = l; x <= r; x++) {
        if (f(x) < f(best)) best = x;
    }
    return best;
}
```

#### Lower Bound and Upper Bound Patterns

Use `lower_bound` for first `>= x`; use `upper_bound` for first `> x`.

```cpp
int firstGreaterEqual(const vector<int>& a, int x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int firstGreaterThan(const vector<int>& a, int x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}

int countInSortedRange(const vector<int>& a, int lo, int hi) {
    return upper_bound(a.begin(), a.end(), hi)
         - lower_bound(a.begin(), a.end(), lo);
}
```

#### Basic Sorting Implementations

Use these for learning. In contests, prefer `sort`, `stable_sort`, or specialized linear sorts when constraints justify them.

```cpp
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        bool changed = false;
        for (int j = 1; j < n - i; j++) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                changed = true;
            }
        }
        if (!changed) break;
    }
}

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int best = i;
        for (int j = i + 1; j < n; j++) if (a[j] < a[best]) best = j;
        swap(a[i], a[best]);
    }
}

void insertionSort(vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        int x = a[i], j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}
```

#### Merge Sort

```cpp
void mergeSort(vector<int>& a, int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m, r);
    vector<int> tmp;
    int i = l, j = m;
    while (i < m || j < r) {
        if (j == r || (i < m && a[i] <= a[j])) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }
    copy(tmp.begin(), tmp.end(), a.begin() + l);
}
```

#### Randomized Quicksort

```cpp
void quickSort(vector<int>& a, int l, int r) {
    if (r - l <= 1) return;
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int pivot = a[uniform_int_distribution<int>(l, r - 1)(rng)];
    int i = l, lt = l, gt = r - 1;
    while (i <= gt) {
        if (a[i] < pivot) swap(a[i++], a[lt++]);
        else if (a[i] > pivot) swap(a[i], a[gt--]);
        else i++;
    }
    quickSort(a, l, lt);
    quickSort(a, gt + 1, r);
}
```

#### Counting Sort

Use when values are integers in a small range.

```cpp
vector<int> countingSort(const vector<int>& a, int minVal, int maxVal) {
    vector<int> cnt(maxVal - minVal + 1), out;
    for (int x : a) cnt[x - minVal]++;
    for (int i = 0; i < (int)cnt.size(); i++) {
        while (cnt[i]--) out.push_back(i + minVal);
    }
    return out;
}
```

#### Radix Sort for Nonnegative Integers

```cpp
void radixSort(vector<unsigned int>& a) {
    vector<unsigned int> b(a.size());
    const int B = 8, MASK = (1 << B) - 1;
    for (int shift = 0; shift < 32; shift += B) {
        vector<int> cnt(1 << B);
        for (unsigned int x : a) cnt[(x >> shift) & MASK]++;
        for (int i = 1; i < (1 << B); i++) cnt[i] += cnt[i - 1];
        for (int i = (int)a.size() - 1; i >= 0; i--) {
            b[--cnt[(a[i] >> shift) & MASK]] = a[i];
        }
        a.swap(b);
    }
}
```

#### Merge Sort Inversion Count

Use to count pairs `i < j` with `a[i] > a[j]`. Complexity: `O(n log n)`.

```cpp
long long mergeCount(vector<int>& a, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    long long inv = mergeCount(a, l, m) + mergeCount(a, m, r);
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

#### Quickselect

Use for kth smallest average `O(n)`. Worst case is `O(n^2)` unless randomized.

```cpp
int kthSmallest(vector<int> a, int k) {
    // k is 0-based
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int pivot = a[uniform_int_distribution<int>(l, r)(rng)];
        int i = l, lt = l, gt = r;
        while (i <= gt) {
            if (a[i] < pivot) swap(a[i++], a[lt++]);
            else if (a[i] > pivot) swap(a[i], a[gt--]);
            else i++;
        }
        if (k < lt) r = lt - 1;
        else if (k > gt) l = gt + 1;
        else return a[k];
    }
    return -1;
}
```

#### Sliding Window, Variable Size

Use when the condition is monotonic as the left pointer moves.

```cpp
int longestAtMostKDistinct(const string& s, int k) {
    vector<int> freq(256);
    int distinct = 0, ans = 0;
    for (int l = 0, r = 0; r < (int)s.size(); r++) {
        if (freq[(unsigned char)s[r]]++ == 0) distinct++;
        while (distinct > k) {
            if (--freq[(unsigned char)s[l]] == 0) distinct--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}
```

#### Kadane's Algorithm

Use for maximum subarray sum. Complexity: `O(n)`.

```cpp
long long maxSubarraySum(const vector<int>& a) {
    long long best = LLONG_MIN, cur = 0;
    for (int x : a) {
        cur = max<long long>(x, cur + x);
        best = max(best, cur);
    }
    return best;
}
```

#### Monotonic Stack

Use for next smaller/greater element, span problems, and histogram-like tasks.

```cpp
vector<int> nextSmallerToRight(const vector<int>& a) {
    int n = a.size();
    vector<int> nxt(n, n);
    vector<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[i] < a[st.back()]) {
            nxt[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return nxt;
}
```

#### Monotonic Queue

Use for sliding-window minimum or maximum in `O(n)`.

```cpp
vector<int> slidingWindowMax(const vector<int>& a, int k) {
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

### Early Level: Recursion and Backtracking

#### Subset Generation

```cpp
void genSubsets(int i, const vector<int>& a, vector<int>& cur) {
    if (i == (int)a.size()) {
        // use cur
        return;
    }
    genSubsets(i + 1, a, cur);
    cur.push_back(a[i]);
    genSubsets(i + 1, a, cur);
    cur.pop_back();
}
```

#### Permutations with Duplicates Removed

```cpp
vector<vector<int>> uniquePermutations(vector<int> a) {
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    do {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end()));
    return ans;
}
```

#### Combination Backtracking

```cpp
void combinations(int start, int n, int k, vector<int>& cur) {
    if ((int)cur.size() == k) {
        // use cur
        return;
    }
    for (int x = start; x <= n; x++) {
        cur.push_back(x);
        combinations(x + 1, n, k, cur);
        cur.pop_back();
    }
}
```

#### N-Queens

```cpp
void solveQueens(int row, int n, vector<string>& board,
                 vector<int>& col, vector<int>& diag1, vector<int>& diag2,
                 vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }
    for (int c = 0; c < n; c++) {
        if (col[c] || diag1[row + c] || diag2[row - c + n - 1]) continue;
        board[row][c] = 'Q';
        col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;
        solveQueens(row + 1, n, board, col, diag1, diag2, ans);
        col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
        board[row][c] = '.';
    }
}
```

### Early to Moderate Level: Dynamic Programming

#### 0/1 Knapsack

Use when each item can be selected once. Complexity: `O(nW)`.

```cpp
long long knapsack01(const vector<int>& wt, const vector<int>& val, int W) {
    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < (int)wt.size(); i++) {
        for (int cap = W; cap >= wt[i]; cap--) {
            dp[cap] = max(dp[cap], dp[cap - wt[i]] + val[i]);
        }
    }
    return dp[W];
}
```

#### Unbounded Knapsack

Use when each item can be chosen many times.

```cpp
long long unboundedKnapsack(const vector<int>& wt, const vector<int>& val, int W) {
    vector<long long> dp(W + 1, 0);
    for (int cap = 0; cap <= W; cap++) {
        for (int i = 0; i < (int)wt.size(); i++) {
            if (cap >= wt[i]) dp[cap] = max(dp[cap], dp[cap - wt[i]] + val[i]);
        }
    }
    return dp[W];
}
```

#### Longest Increasing Subsequence

Complexity: `O(n log n)`.

```cpp
int lisLength(const vector<int>& a) {
    vector<int> tail;
    for (int x : a) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    return tail.size();
}
```

#### Longest Common Subsequence

Complexity: `O(nm)`.

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

#### Edit Distance

```cpp
int editDistance(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min({dp[i - 1][j] + 1,
                            dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
        }
    }
    return dp[n][m];
}
```

#### Interval DP Skeleton

Use for merging intervals, matrix chain multiplication, and palindrome partitions.

```cpp
long long intervalDP(const vector<int>& a) {
    int n = a.size();
    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = LLONG_MAX / 4;
            for (int mid = l; mid < r; mid++) {
                long long cost = dp[l][mid] + dp[mid + 1][r]; // + merge cost
                dp[l][r] = min(dp[l][r], cost);
            }
        }
    }
    return dp[0][n - 1];
}
```

#### Bitmask TSP DP

Use when `n <= 20` and state is subset + last node.

```cpp
long long tsp(const vector<vector<int>>& dist) {
    int n = dist.size();
    const long long INFLL = 4e18;
    vector<vector<long long>> dp(1 << n, vector<long long>(n, INFLL));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) if (dp[mask][u] < INFLL) {
            for (int v = 0; v < n; v++) if (!(mask & (1 << v))) {
                dp[mask | (1 << v)][v] =
                    min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]);
            }
        }
    }
    long long ans = INFLL;
    for (int u = 0; u < n; u++) ans = min(ans, dp[(1 << n) - 1][u] + dist[u][0]);
    return ans;
}
```

#### Digit DP Skeleton

Use for counting numbers up to `N` with digit constraints.

```cpp
string S;
long long memo[20][2][2][200];
bool seen[20][2][2][200];

long long dfsDigit(int pos, bool tight, bool started, int sum) {
    if (pos == (int)S.size()) return started && sum % 3 == 0;
    long long& res = memo[pos][tight][started][sum];
    if (seen[pos][tight][started][sum]) return res;
    seen[pos][tight][started][sum] = true;
    res = 0;
    int lim = tight ? S[pos] - '0' : 9;
    for (int d = 0; d <= lim; d++) {
        res += dfsDigit(pos + 1, tight && d == lim,
                        started || d != 0, (sum + d) % 3);
    }
    return res;
}

long long countUpTo(long long n) {
    S = to_string(n);
    memset(seen, 0, sizeof(seen));
    return dfsDigit(0, true, false, 0);
}
```

#### SOS DP

Use for subset sums over all submasks. Complexity: `O(n 2^n)`.

```cpp
vector<long long> sumOverSubsets(vector<long long> f, int n) {
    for (int bit = 0; bit < n; bit++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << bit)) f[mask] += f[mask ^ (1 << bit)];
        }
    }
    return f;
}
```

### Moderate Level: Range Query Data Structures

#### Fenwick Tree / Binary Indexed Tree

Use for point updates and prefix/range sums. Complexity: `O(log n)`.

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
    long long sumPrefix(int idx) const {
        long long res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    long long rangeSum(int l, int r) const {
        if (r < l) return 0;
        return sumPrefix(r) - (l ? sumPrefix(l - 1) : 0);
    }
};
```

#### Fenwick Range Add and Range Sum

Use two BITs to support range add and range sum in `O(log n)`.

```cpp
struct RangeFenwick {
    int n;
    Fenwick b1, b2;
    RangeFenwick(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        b1.init(n);
        b2.init(n);
    }
    void addInternal(Fenwick& b, int idx, long long val) {
        if (idx < n) b.add(idx, val);
    }
    void rangeAdd(int l, int r, long long val) {
        addInternal(b1, l, val);
        addInternal(b1, r + 1, -val);
        addInternal(b2, l, val * l);
        addInternal(b2, r + 1, -val * (r + 1));
    }
    long long prefixSum(int idx) const {
        return b1.sumPrefix(idx) * (idx + 1) - b2.sumPrefix(idx);
    }
    long long rangeSum(int l, int r) const {
        return prefixSum(r) - (l ? prefixSum(l - 1) : 0);
    }
};
```

#### Iterative Segment Tree

Use for static associative operations with point updates.

```cpp
struct SegTree {
    int n;
    vector<long long> seg;
    SegTree(const vector<int>& a = {}) { if (!a.empty()) build(a); }
    long long merge(long long x, long long y) { return x + y; }
    void build(const vector<int>& a) {
        n = a.size();
        seg.assign(2 * n, 0);
        for (int i = 0; i < n; i++) seg[n + i] = a[i];
        for (int i = n - 1; i > 0; i--) seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
    void update(int p, long long val) {
        for (seg[p += n] = val; p > 1; p >>= 1) {
            seg[p >> 1] = merge(seg[p], seg[p ^ 1]);
        }
    }
    long long query(int l, int r) {
        long long resL = 0, resR = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = merge(resL, seg[l++]);
            if (r & 1) resR = merge(seg[--r], resR);
        }
        return merge(resL, resR);
    }
};
```

#### Lazy Segment Tree for Range Add and Range Sum

```cpp
struct LazySegTree {
    int n;
    vector<long long> tree, lazy;
    LazySegTree(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;
        tree[node] += lazy[node] * (r - l + 1);
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void add(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        add(node * 2, l, mid, ql, qr, val);
        add(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    long long query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr)
             + query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};
```

#### Sparse Table for Idempotent Queries

Use for static range min/max/gcd. Build `O(n log n)`, query `O(1)`.

```cpp
struct SparseTable {
    vector<vector<int>> st;
    vector<int> lg;
    int merge(int a, int b) { return min(a, b); }
    SparseTable(const vector<int>& a = {}) { if (!a.empty()) build(a); }
    void build(const vector<int>& a) {
        int n = a.size();
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        st.assign(lg[n] + 1, vector<int>(n));
        st[0] = a;
        for (int k = 1; k < (int)st.size(); k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = merge(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int k = lg[r - l + 1];
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
```

#### Sqrt Decomposition

Use for simple range queries with point updates when segment tree is overkill.

```cpp
struct SqrtDecomp {
    int n, B;
    vector<long long> a, block;
    SqrtDecomp(const vector<int>& v = {}) { if (!v.empty()) build(v); }
    void build(const vector<int>& v) {
        n = v.size();
        B = sqrt(n) + 1;
        a.assign(v.begin(), v.end());
        block.assign(B, 0);
        for (int i = 0; i < n; i++) block[i / B] += a[i];
    }
    void update(int idx, long long val) {
        block[idx / B] += val - a[idx];
        a[idx] = val;
    }
    long long query(int l, int r) {
        long long ans = 0;
        while (l <= r && l % B != 0) ans += a[l++];
        while (l + B - 1 <= r) {
            ans += block[l / B];
            l += B;
        }
        while (l <= r) ans += a[l++];
        return ans;
    }
};
```

### Moderate Level: Trees and Disjoint Set Union

#### Disjoint Set Union

Use for dynamic connectivity under only edge additions, Kruskal MST, and grouping. Amortized complexity: almost `O(1)`.

```cpp
struct DSU {
    vector<int> parent, sz;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};
```

#### Tree DFS, Subtree Size, Depth, Parent

```cpp
void dfsTree(int u, int p, const vector<vector<int>>& g,
             vector<int>& parent, vector<int>& depth, vector<int>& sub) {
    parent[u] = p;
    sub[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfsTree(v, u, g, parent, depth, sub);
        sub[u] += sub[v];
    }
}
```

#### Tree Diameter

```cpp
pair<int, int> farthest(int src, const vector<vector<int>>& g) {
    vector<int> dist(g.size(), -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    int best = src;
    for (int i = 0; i < (int)g.size(); i++) {
        if (dist[i] > dist[best]) best = i;
    }
    return {best, dist[best]};
}

int treeDiameter(const vector<vector<int>>& g) {
    auto [a, _] = farthest(0, g);
    auto [b, d] = farthest(a, g);
    return d;
}
```

#### Binary Lifting LCA

Build `O(n log n)`, query `O(log n)`.

```cpp
struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> g;

    LCA(const vector<vector<int>>& graph, int root = 0) : g(graph) {
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

#### Euler Tour for Subtree Queries

Flatten a rooted tree so each subtree becomes a contiguous range.

```cpp
void eulerDfs(int u, int p, const vector<vector<int>>& g,
              vector<int>& tin, vector<int>& tout, vector<int>& order, int& timer) {
    tin[u] = timer++;
    order.push_back(u);
    for (int v : g[u]) if (v != p) eulerDfs(v, u, g, tin, tout, order, timer);
    tout[u] = timer - 1;
}
```

#### Trie

Use for prefix queries, dictionary matching, and bitwise tries.

```cpp
struct Trie {
    struct Node {
        int nxt[26];
        int pass = 0, end = 0;
        Node() { fill(nxt, nxt + 26, -1); }
    };
    vector<Node> tr{Node()};

    void insert(const string& s) {
        int u = 0;
        tr[u].pass++;
        for (char ch : s) {
            int c = ch - 'a';
            if (tr[u].nxt[c] == -1) {
                tr[u].nxt[c] = tr.size();
                tr.push_back(Node());
            }
            u = tr[u].nxt[c];
            tr[u].pass++;
        }
        tr[u].end++;
    }

    bool search(const string& s) {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (tr[u].nxt[c] == -1) return false;
            u = tr[u].nxt[c];
        }
        return tr[u].end > 0;
    }
};
```

#### Heavy-Light Decomposition

Use for path queries/updates on trees. Pair with a segment tree over `pos[u]`.

```cpp
struct HLD {
    int n, cur = 0;
    vector<vector<int>> g;
    vector<int> parent, depth, heavy, head, pos, sz;

    HLD(const vector<vector<int>>& graph, int root = 0) : g(graph) {
        n = g.size();
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sz.assign(n, 0);
        dfs(root);
        decompose(root, root);
    }

    int dfs(int u) {
        sz[u] = 1;
        int best = 0;
        for (int v : g[u]) if (v != parent[u]) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            int child = dfs(v);
            sz[u] += child;
            if (child > best) best = child, heavy[u] = v;
        }
        return sz[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = cur++;
        if (heavy[u] != -1) decompose(heavy[u], h);
        for (int v : g[u]) {
            if (v != parent[u] && v != heavy[u]) decompose(v, v);
        }
    }

    template <class F>
    void pathQuery(int a, int b, F useRange) {
        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]]) swap(a, b);
            useRange(pos[head[a]], pos[a]);
            a = parent[head[a]];
        }
        if (depth[a] > depth[b]) swap(a, b);
        useRange(pos[a], pos[b]);
    }
};
```

#### Centroid Decomposition Skeleton

Use for distance queries on trees where each update/query should touch `O(log n)` centroids.

```cpp
struct CentroidDecomposition {
    int n;
    vector<vector<int>> g;
    vector<int> sub, parent;
    vector<bool> dead;

    CentroidDecomposition(vector<vector<int>> graph) : g(move(graph)) {
        n = g.size();
        sub.assign(n, 0);
        parent.assign(n, -1);
        dead.assign(n, false);
        build(0, -1);
    }

    int dfsSize(int u, int p) {
        sub[u] = 1;
        for (int v : g[u]) if (v != p && !dead[v]) sub[u] += dfsSize(v, u);
        return sub[u];
    }

    int dfsCentroid(int u, int p, int total) {
        for (int v : g[u]) {
            if (v != p && !dead[v] && sub[v] > total / 2) return dfsCentroid(v, u, total);
        }
        return u;
    }

    void build(int entry, int p) {
        int total = dfsSize(entry, -1);
        int c = dfsCentroid(entry, -1, total);
        parent[c] = p;
        dead[c] = true;
        for (int v : g[c]) if (!dead[v]) build(v, c);
    }
};
```

### Moderate to Advanced Level: Graph Algorithms

#### BFS

Use for shortest paths in unweighted graphs.

```cpp
vector<int> bfs(int src, const vector<vector<int>>& g) {
    vector<int> dist(g.size(), -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist;
}
```

#### DFS Connected Components

```cpp
void dfsComponent(int u, const vector<vector<int>>& g, vector<int>& comp, int id) {
    comp[u] = id;
    for (int v : g[u]) if (comp[v] == -1) dfsComponent(v, g, comp, id);
}

vector<int> components(const vector<vector<int>>& g) {
    int n = g.size(), id = 0;
    vector<int> comp(n, -1);
    for (int i = 0; i < n; i++) if (comp[i] == -1) dfsComponent(i, g, comp, id++);
    return comp;
}
```

#### Topological Sort

Use only on DAGs. If output size is less than `n`, there is a directed cycle.

```cpp
vector<int> topoSort(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> indeg(n), order;
    for (int u = 0; u < n; u++) for (int v : g[u]) indeg[v]++;
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
    }
    return order;
}
```

#### Dijkstra

Use with nonnegative edge weights only. Complexity: `O((n + m) log n)`.

```cpp
vector<long long> dijkstra(int src, const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<long long> dist(n, LINF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
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

Use when edge weights are only `0` or `1`.

```cpp
vector<int> zeroOneBfs(int src, const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<int> dist(n, INF);
    deque<int> dq;
    dist[src] = 0;
    dq.push_front(src);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
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

Use for negative weights and negative-cycle detection. Complexity: `O(nm)`.

```cpp
struct EdgeBF {
    int u, v;
    long long w;
};

bool bellmanFord(int n, int src, const vector<EdgeBF>& edges, vector<long long>& dist) {
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

Use for all-pairs shortest path when `n` is small.

```cpp
void floydWarshall(vector<vector<long long>>& d) {
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
    bool operator<(const EdgeMST& other) const { return w < other.w; }
};

long long kruskal(int n, vector<EdgeMST> edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long cost = 0;
    for (auto e : edges) {
        if (dsu.unite(e.u, e.v)) cost += e.w;
    }
    return cost;
}
```

#### Prim MST

```cpp
long long prim(const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<int> used(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    long long cost = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (used[u]) continue;
        used[u] = 1;
        cost += w;
        for (auto [v, nw] : g[u]) if (!used[v]) pq.push({nw, v});
    }
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

#### Bridges and Articulation Points

```cpp
struct BridgesArticulation {
    int n, timer = 0;
    vector<vector<int>> g;
    vector<int> tin, low, isArt;
    vector<pair<int, int>> bridges;

    BridgesArticulation(const vector<vector<int>>& graph) : g(graph) {
        n = g.size();
        tin.assign(n, -1);
        low.assign(n, 0);
        isArt.assign(n, 0);
        for (int i = 0; i < n; i++) if (tin[i] == -1) dfs(i, -1);
    }

    void dfs(int u, int p) {
        tin[u] = low[u] = timer++;
        int children = 0;
        for (int v : g[u]) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) bridges.push_back({u, v});
                if (p != -1 && low[v] >= tin[u]) isArt[u] = 1;
                children++;
            }
        }
        if (p == -1 && children > 1) isArt[u] = 1;
    }
};
```

#### Euler Path in Directed Graph

```cpp
vector<int> eulerDirected(int n, vector<vector<int>> g, int start) {
    vector<int> it(n), path, st{start};
    while (!st.empty()) {
        int u = st.back();
        if (it[u] < (int)g[u].size()) {
            st.push_back(g[u][it[u]++]);
        } else {
            path.push_back(u);
            st.pop_back();
        }
    }
    reverse(path.begin(), path.end());
    return path;
}
```

#### 2-SAT

Use implication graph + SCC. Variable `x` has nodes `2*x` false and `2*x+1` true.

```cpp
struct TwoSAT {
    int n;
    vector<vector<int>> g;
    TwoSAT(int n) : n(n), g(2 * n) {}

    int id(int x, bool val) { return 2 * x + val; }
    void imply(int a, int b) { g[a].push_back(b); }
    void addOr(int x, bool xv, int y, bool yv) {
        imply(id(x, !xv), id(y, yv));
        imply(id(y, !yv), id(x, xv));
    }

    vector<int> solve() {
        TarjanSCC scc(g);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (scc.comp[id(i, false)] == scc.comp[id(i, true)]) return {};
            ans[i] = scc.comp[id(i, false)] > scc.comp[id(i, true)];
        }
        return ans;
    }
};
```

#### Functional Graph Binary Lifting

Use when every node has exactly one outgoing edge.

```cpp
struct FunctionalLift {
    int n, LOG;
    vector<vector<int>> up;
    FunctionalLift(const vector<int>& nxt) {
        n = nxt.size();
        LOG = 60;
        up.assign(LOG, vector<int>(n));
        up[0] = nxt;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) up[k][i] = up[k - 1][up[k - 1][i]];
        }
    }
    int jump(int u, long long steps) {
        for (int k = 0; k < LOG; k++) if (steps & (1LL << k)) u = up[k][u];
        return u;
    }
};
```

### Advanced Level: Flow and Matching

#### Dinic Max Flow

Use for max flow, min cut, bipartite matching reductions, and edge-disjoint paths.

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
            int u = q.front(); q.pop();
            for (auto& e : g[u]) if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
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

#### Kuhn Bipartite Matching

Simple and easy. Complexity: `O(VE)`.

```cpp
struct Kuhn {
    int n, m;
    vector<vector<int>> g;
    vector<int> matchR, seen;
    Kuhn(int n, int m) : n(n), m(m), g(n), matchR(m, -1), seen(n) {}
    void addEdge(int l, int r) { g[l].push_back(r); }
    bool dfs(int u, int tag) {
        if (seen[u] == tag) return false;
        seen[u] = tag;
        for (int v : g[u]) {
            if (matchR[v] == -1 || dfs(matchR[v], tag)) {
                matchR[v] = u;
                return true;
            }
        }
        return false;
    }
    int maxMatching() {
        int ans = 0;
        for (int u = 0; u < n; u++) ans += dfs(u, u + 1);
        return ans;
    }
};
```

#### Hopcroft-Karp

Faster bipartite matching. Complexity: `O(E sqrt(V))`.

```cpp
struct HopcroftKarp {
    int n, m;
    vector<vector<int>> g;
    vector<int> dist, pairU, pairV;
    HopcroftKarp(int n, int m) : n(n), m(m), g(n), dist(n), pairU(n, -1), pairV(m, -1) {}
    void addEdge(int u, int v) { g[u].push_back(v); }

    bool bfs() {
        queue<int> q;
        for (int u = 0; u < n; u++) {
            if (pairU[u] == -1) dist[u] = 0, q.push(u);
            else dist[u] = -1;
        }
        bool found = false;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                int nxt = pairV[v];
                if (nxt == -1) found = true;
                else if (dist[nxt] == -1) {
                    dist[nxt] = dist[u] + 1;
                    q.push(nxt);
                }
            }
        }
        return found;
    }

    bool dfs(int u) {
        for (int v : g[u]) {
            int nxt = pairV[v];
            if (nxt == -1 || (dist[nxt] == dist[u] + 1 && dfs(nxt))) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int maxMatching() {
        int matching = 0;
        while (bfs()) {
            for (int u = 0; u < n; u++) {
                if (pairU[u] == -1 && dfs(u)) matching++;
            }
        }
        return matching;
    }
};
```

#### Min-Cost Max-Flow

Use for assignment-like problems, min-cost circulation variants, and flow with costs.

```cpp
struct MinCostFlow {
    struct Edge {
        int to, rev, cap;
        long long cost;
    };
    int n;
    vector<vector<Edge>> g;
    MinCostFlow(int n) : n(n), g(n) {}

    void addEdge(int u, int v, int cap, long long cost) {
        Edge a{v, (int)g[v].size(), cap, cost};
        Edge b{u, (int)g[u].size(), 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    pair<int, long long> minCostMaxFlow(int s, int t) {
        int flow = 0;
        long long cost = 0;
        vector<long long> dist(n), pot(n);
        vector<int> pv(n), pe(n);
        while (true) {
            fill(dist.begin(), dist.end(), LINF);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            dist[s] = 0;
            pq.push({0, s});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d != dist[u]) continue;
                for (int i = 0; i < (int)g[u].size(); i++) {
                    Edge& e = g[u][i];
                    if (e.cap <= 0) continue;
                    long long nd = d + e.cost + pot[u] - pot[e.to];
                    if (nd < dist[e.to]) {
                        dist[e.to] = nd;
                        pv[e.to] = u;
                        pe[e.to] = i;
                        pq.push({nd, e.to});
                    }
                }
            }
            if (dist[t] == LINF) break;
            for (int i = 0; i < n; i++) if (dist[i] < LINF) pot[i] += dist[i];
            int add = INF;
            for (int v = t; v != s; v = pv[v]) add = min(add, g[pv[v]][pe[v]].cap);
            for (int v = t; v != s; v = pv[v]) {
                Edge& e = g[pv[v]][pe[v]];
                e.cap -= add;
                g[v][e.rev].cap += add;
                cost += 1LL * add * e.cost;
            }
            flow += add;
        }
        return {flow, cost};
    }
};
```

### Moderate to Advanced Level: String Algorithms

#### Prefix Function and KMP

Use for exact pattern matching. Complexity: `O(n + m)`.

```cpp
vector<int> prefixFunction(const string& s) {
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

vector<int> kmpSearch(const string& text, const string& pat) {
    string s = pat + '#' + text;
    vector<int> pi = prefixFunction(s), ans;
    int m = pat.size();
    for (int i = m + 1; i < (int)s.size(); i++) {
        if (pi[i] == m) ans.push_back(i - 2 * m);
    }
    return ans;
}
```

#### Z Algorithm

Use for pattern matching, border analysis, and string periodicity.

```cpp
vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
```

#### Rolling Hash

Use for substring equality. Use double hash when collision risk matters.

```cpp
struct RollingHash {
    static const long long MOD = 1000000007;
    static const long long BASE = 911382323;
    vector<long long> h, p;
    RollingHash(const string& s) {
        int n = s.size();
        h.assign(n + 1, 0);
        p.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * BASE + s[i]) % MOD;
            p[i + 1] = p[i] * BASE % MOD;
        }
    }
    long long get(int l, int r) {
        // inclusive l, inclusive r
        long long res = (h[r + 1] - h[l] * p[r - l + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};
```

#### Aho-Corasick

Use for matching many patterns in one text.

```cpp
struct AhoCorasick {
    struct Node {
        int next[26];
        int link = 0;
        vector<int> out;
        Node() { fill(next, next + 26, -1); }
    };
    vector<Node> t{Node()};

    void addString(const string& s, int id) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.push_back(Node());
            }
            v = t[v].next[c];
        }
        t[v].out.push_back(id);
    }

    void build() {
        queue<int> q;
        for (int c = 0; c < 26; c++) {
            int u = t[0].next[c];
            if (u == -1) t[0].next[c] = 0;
            else q.push(u);
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int c = 0; c < 26; c++) {
                int u = t[v].next[c];
                if (u == -1) t[v].next[c] = t[t[v].link].next[c];
                else {
                    t[u].link = t[t[v].link].next[c];
                    for (int id : t[t[u].link].out) t[u].out.push_back(id);
                    q.push(u);
                }
            }
        }
    }

    vector<pair<int, int>> search(const string& s) {
        vector<pair<int, int>> hits; // {ending position, pattern id}
        int v = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            v = t[v].next[s[i] - 'a'];
            for (int id : t[v].out) hits.push_back({i, id});
        }
        return hits;
    }
};
```

#### Manacher

Use for all palindrome radii in `O(n)`.

```cpp
pair<vector<int>, vector<int>> manacher(const string& s) {
    int n = s.size();
    vector<int> odd(n), even(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(odd[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        odd[i] = k--;
        if (i + k > r) l = i - k, r = i + k;
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        even[i] = k--;
        if (i + k > r) l = i - k - 1, r = i + k;
    }
    return {odd, even};
}
```

#### Suffix Array and LCP

Use for lexicographic suffix order, substring queries, and repeated substring problems.

```cpp
vector<int> suffixArray(string s) {
    s.push_back('$');
    int n = s.size();
    vector<int> p(n), c(n);
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) p[i] = a[i].second;
    for (int i = 1; i < n; i++) c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);

    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) p[i] = (p[i] - (1 << k) + n) % n;
        vector<int> cnt(n), pn(n), cn(n);
        for (int x : c) cnt[x]++;
        for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) pn[--cnt[c[p[i]]]] = p[i];
        p.swap(pn);
        cn[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            cn[p[i]] = cn[p[i - 1]] + (cur != prev);
        }
        c.swap(cn);
    }
    p.erase(p.begin());
    return p;
}

vector<int> lcpArray(const string& s, const vector<int>& sa) {
    int n = s.size();
    vector<int> rank(n), lcp(n - 1);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
```

#### Suffix Automaton

Use for distinct substrings, substring existence, and many advanced string DP tasks.

```cpp
struct SuffixAutomaton {
    struct State {
        int link = -1, len = 0;
        map<char, int> next;
    };
    vector<State> st;
    int last;

    SuffixAutomaton() {
        st.reserve(200000);
        st.push_back(State());
        last = 0;
    }

    void extend(char c) {
        int cur = st.size();
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) st[cur].link = q;
            else {
                int clone = st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
};
```

#### Booth's Algorithm for Minimal Rotation

```cpp
int minRotationIndex(const string& s) {
    string t = s + s;
    int n = s.size(), i = 0, ans = 0;
    while (i < n) {
        ans = i;
        int j = i + 1, k = i;
        while (j < 2 * n && t[k] <= t[j]) {
            if (t[k] < t[j]) k = i;
            else k++;
            j++;
        }
        while (i <= k) i += j - k;
    }
    return ans;
}
```

### Early to Advanced Level: Bit Manipulation

#### Common Bit Operations

```cpp
bool hasBit(long long x, int b) { return x & (1LL << b); }
long long setBit(long long x, int b) { return x | (1LL << b); }
long long clearBit(long long x, int b) { return x & ~(1LL << b); }
long long toggleBit(long long x, int b) { return x ^ (1LL << b); }
long long lowbit(long long x) { return x & -x; }
bool isPowerOfTwo(long long x) { return x > 0 && (x & (x - 1)) == 0; }
```

#### Submask Enumeration

```cpp
for (int sub = mask; ; sub = (sub - 1) & mask) {
    // use sub
    if (sub == 0) break;
}
```

#### XOR Linear Basis

Use for maximum xor subset and linear independence over bits.

```cpp
struct XorBasis {
    static const int LOG = 62;
    long long basis[LOG]{};

    void insert(long long x) {
        for (int b = LOG - 1; b >= 0; b--) {
            if (!(x & (1LL << b))) continue;
            if (!basis[b]) {
                basis[b] = x;
                return;
            }
            x ^= basis[b];
        }
    }

    long long maxXor() const {
        long long ans = 0;
        for (int b = LOG - 1; b >= 0; b--) ans = max(ans, ans ^ basis[b]);
        return ans;
    }
};
```

### Moderate to ICPC Level: Number Theory and Combinatorics

#### GCD, Extended GCD, Modular Power, Modular Inverse

```cpp
long long modPow(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    while (e) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

long long extGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

long long modInverse(long long a, long long mod) {
    long long x, y;
    long long g = extGcd(a, mod, x, y);
    if (g != 1) return -1;
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
```

#### Sieve and Linear Sieve

```cpp
vector<int> sieve(int n) {
    vector<int> isPrime(n + 1, true), primes;
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            if (1LL * i * i <= n) {
                for (long long j = 1LL * i * i; j <= n; j += i) isPrime[j] = false;
            }
        }
    }
    return primes;
}

vector<int> linearSieve(int n) {
    vector<int> lp(n + 1), primes;
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) lp[i] = i, primes.push_back(i);
        for (int p : primes) {
            if (p > lp[i] || 1LL * i * p > n) break;
            lp[i * p] = p;
        }
    }
    return primes;
}
```

#### Factorials and nCr Mod Prime

```cpp
struct Comb {
    long long mod;
    vector<long long> fact, invFact;
    Comb(int n, long long mod) : mod(mod), fact(n + 1), invFact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
        invFact[n] = modPow(fact[n], mod - 2, mod);
        for (int i = n; i > 0; i--) invFact[i - 1] = invFact[i] * i % mod;
    }
    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
    }
};
```

#### Chinese Remainder Theorem

Works for non-coprime moduli too; returns `{answer, lcm}` or `{0, -1}` if impossible.

```cpp
pair<long long, long long> crt(long long a1, long long m1, long long a2, long long m2) {
    long long x, y;
    long long g = extGcd(m1, m2, x, y);
    if ((a2 - a1) % g != 0) return {0, -1};
    long long lcm = m1 / g * m2;
    long long t = (__int128)(a2 - a1) / g * x % (m2 / g);
    long long ans = (a1 + (__int128)m1 * t) % lcm;
    if (ans < 0) ans += lcm;
    return {ans, lcm};
}
```

#### Baby-Step Giant-Step Discrete Log

Solves `a^x = b (mod m)` when gcd assumptions are friendly. Complexity: `O(sqrt(m))`.

```cpp
long long discreteLog(long long a, long long b, long long m) {
    a %= m; b %= m;
    long long n = sqrt(m) + 1;
    unordered_map<long long, long long, CustomHash> vals;
    long long cur = b;
    for (long long q = 0; q <= n; q++) {
        vals[cur] = q;
        cur = (__int128)cur * a % m;
    }
    long long an = 1;
    for (int i = 0; i < n; i++) an = (__int128)an * a % m;
    cur = 1;
    for (long long p = 1; p <= n; p++) {
        cur = (__int128)cur * an % m;
        if (vals.count(cur)) {
            long long ans = p * n - vals[cur];
            if (ans >= 0) return ans;
        }
    }
    return -1;
}
```

#### Miller-Rabin and Pollard Rho

Use for 64-bit primality and factorization.

```cpp
using u64 = uint64_t;
using u128 = __uint128_t;

u64 mulMod(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}

u64 powMod64(u64 a, u64 d, u64 mod) {
    u64 r = 1;
    while (d) {
        if (d & 1) r = mulMod(r, a, mod);
        a = mulMod(a, a, mod);
        d >>= 1;
    }
    return r;
}

bool isPrime64(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
        if (n % p == 0) return n == p;
    }
    u64 d = n - 1, s = 0;
    while ((d & 1) == 0) d >>= 1, s++;
    for (u64 a : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
        u64 x = powMod64(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (u64 r = 1; r < s; r++) {
            x = mulMod(x, x, n);
            if (x == n - 1) {
                comp = false;
                break;
            }
        }
        if (comp) return false;
    }
    return true;
}

u64 pollard(u64 n) {
    if (n % 2 == 0) return 2;
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (true) {
        u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
        u64 x = uniform_int_distribution<u64>(0, n - 1)(rng);
        u64 y = x, d = 1;
        auto f = [&](u64 v) { return (mulMod(v, v, n) + c) % n; };
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = gcd<u64>(x > y ? x - y : y - x, n);
        }
        if (d != n) return d;
    }
}

void factor(u64 n, vector<u64>& res) {
    if (n == 1) return;
    if (isPrime64(n)) {
        res.push_back(n);
        return;
    }
    u64 d = pollard(n);
    factor(d, res);
    factor(n / d, res);
}
```

#### NTT Polynomial Multiplication

Use when modulus supports primitive roots, commonly `998244353`.

```cpp
const int MOD_NTT = 998244353;
const int G_NTT = 3;

int modPowInt(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD_NTT;
        a = a * a % MOD_NTT;
        e >>= 1;
    }
    return r;
}

void ntt(vector<int>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = modPowInt(G_NTT, (MOD_NTT - 1) / len);
        if (invert) wlen = modPowInt(wlen, MOD_NTT - 2);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = a[i + j + len / 2] * w % MOD_NTT;
                a[i + j] = (u + v) % MOD_NTT;
                a[i + j + len / 2] = (u - v + MOD_NTT) % MOD_NTT;
                w = w * wlen % MOD_NTT;
            }
        }
    }
    if (invert) {
        int invN = modPowInt(n, MOD_NTT - 2);
        for (int& x : a) x = 1LL * x * invN % MOD_NTT;
    }
}

vector<int> multiply(vector<int> a, vector<int> b) {
    int n = 1;
    while (n < (int)a.size() + (int)b.size() - 1) n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % MOD_NTT;
    ntt(a, true);
    return a;
}
```

#### Fast Walsh-Hadamard Transform for XOR Convolution

```cpp
void fwht(vector<long long>& a, bool inverse) {
    int n = a.size();
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                long long u = a[i + j], v = a[i + j + len];
                a[i + j] = u + v;
                a[i + j + len] = u - v;
            }
        }
    }
    if (inverse) for (long long& x : a) x /= n;
}
```

#### Berlekamp-Massey over Mod

Use to find the shortest linear recurrence from initial terms.

```cpp
vector<long long> berlekampMassey(vector<long long> s, long long mod) {
    vector<long long> C{1}, B{1};
    long long b = 1;
    int L = 0, m = 1;
    for (int n = 0; n < (int)s.size(); n++) {
        long long d = 0;
        for (int i = 0; i <= L; i++) d = (d + C[i] * s[n - i]) % mod;
        if (d == 0) {
            m++;
            continue;
        }
        vector<long long> T = C;
        long long coef = d * modPow(b, mod - 2, mod) % mod;
        if ((int)C.size() < (int)B.size() + m) C.resize(B.size() + m);
        for (int i = 0; i < (int)B.size(); i++) {
            C[i + m] = (C[i + m] - coef * B[i]) % mod;
            if (C[i + m] < 0) C[i + m] += mod;
        }
        if (2 * L <= n) {
            L = n + 1 - L;
            B = T;
            b = d;
            m = 1;
        } else {
            m++;
        }
    }
    C.erase(C.begin());
    for (long long& x : C) x = (mod - x) % mod;
    return C;
}
```

### Moderate to Advanced Level: Computational Geometry

#### Point, Dot, Cross, Orientation

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

Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
long long dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
long long cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
long long orient(Point a, Point b, Point c) { return cross(b - a, c - a); }
```

#### Segment Intersection

```cpp
bool onSegment(Point a, Point b, Point p) {
    return orient(a, b, p) == 0
        && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
        && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

bool segmentsIntersect(Point a, Point b, Point c, Point d) {
    long long o1 = orient(a, b, c), o2 = orient(a, b, d);
    long long o3 = orient(c, d, a), o4 = orient(c, d, b);
    if ((o1 > 0) != (o2 > 0) && (o3 > 0) != (o4 > 0)) return true;
    return onSegment(a, b, c) || onSegment(a, b, d)
        || onSegment(c, d, a) || onSegment(c, d, b);
}
```

#### Convex Hull, Monotonic Chain

```cpp
vector<Point> convexHull(vector<Point> p) {
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1) return p;
    vector<Point> hull;
    for (Point pt : p) {
        while (hull.size() >= 2 &&
               orient(hull[hull.size() - 2], hull.back(), pt) <= 0) hull.pop_back();
        hull.push_back(pt);
    }
    int lowerSize = hull.size();
    for (int i = (int)p.size() - 2; i >= 0; i--) {
        Point pt = p[i];
        while ((int)hull.size() > lowerSize &&
               orient(hull[hull.size() - 2], hull.back(), pt) <= 0) hull.pop_back();
        hull.push_back(pt);
    }
    hull.pop_back();
    return hull;
}
```

#### Polygon Area

```cpp
long long twicePolygonArea(const vector<Point>& p) {
    long long area = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) area += cross(p[i], p[(i + 1) % n]);
    return llabs(area);
}
```

#### Point in Polygon

Returns `0` outside, `1` inside, `2` on boundary.

```cpp
int pointInPolygon(const vector<Point>& poly, Point q) {
    bool inside = false;
    int n = poly.size();
    for (int i = 0, j = n - 1; i < n; j = i++) {
        Point a = poly[i], b = poly[j];
        if (onSegment(a, b, q)) return 2;
        bool intersect = ((a.y > q.y) != (b.y > q.y)) &&
            (q.x < (long double)(b.x - a.x) * (q.y - a.y) / (b.y - a.y) + a.x);
        if (intersect) inside = !inside;
    }
    return inside;
}
```

### Advanced Level: Offline, Persistent, and Hard Range Structures

#### Merge Sort Tree

Use for static queries like count numbers `<= x` in range. Build `O(n log n)`, query `O(log^2 n)`.

```cpp
struct MergeSortTree {
    int n;
    vector<vector<int>> tree;
    MergeSortTree(const vector<int>& a = {}) { if (!a.empty()) build(a); }
    void build(const vector<int>& a) {
        n = a.size();
        tree.assign(4 * n, {});
        build(1, 0, n - 1, a);
    }
    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) {
            tree[node] = {a[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        merge(tree[node * 2].begin(), tree[node * 2].end(),
              tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
              back_inserter(tree[node]));
    }
    int countLE(int node, int l, int r, int ql, int qr, int x) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) {
            return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
        }
        int mid = (l + r) / 2;
        return countLE(node * 2, l, mid, ql, qr, x)
             + countLE(node * 2 + 1, mid + 1, r, ql, qr, x);
    }
};
```

#### Persistent Segment Tree for Kth Order Statistic

Use for static range kth queries after coordinate compression.

```cpp
struct PersistentSeg {
    struct Node {
        int left = 0, right = 0, sum = 0;
    };
    vector<Node> st{{}};
    vector<int> root{0};
    int n;

    PersistentSeg(int n = 0) : n(n) {}

    int update(int prev, int l, int r, int pos) {
        int cur = st.size();
        st.push_back(st[prev]);
        st[cur].sum++;
        if (l != r) {
            int mid = (l + r) / 2;
            if (pos <= mid) st[cur].left = update(st[prev].left, l, mid, pos);
            else st[cur].right = update(st[prev].right, mid + 1, r, pos);
        }
        return cur;
    }

    void addVersion(int compressedValue) {
        root.push_back(update(root.back(), 0, n - 1, compressedValue));
    }

    int kth(int leftRoot, int rightRoot, int l, int r, int k) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        int cntLeft = st[st[rightRoot].left].sum - st[st[leftRoot].left].sum;
        if (k <= cntLeft) return kth(st[leftRoot].left, st[rightRoot].left, l, mid, k);
        return kth(st[leftRoot].right, st[rightRoot].right, mid + 1, r, k - cntLeft);
    }
};
```

#### Wavelet Tree

Use for kth, count `<= x`, and frequency in static ranges.

```cpp
struct WaveletTree {
    int lo, hi;
    WaveletTree *l = nullptr, *r = nullptr;
    vector<int> b;

    WaveletTree(vector<int>::iterator from, vector<int>::iterator to, int x, int y) : lo(x), hi(y) {
        if (from >= to || lo == hi) return;
        int mid = lo + (hi - lo) / 2;
        auto f = [mid](int v) { return v <= mid; };
        b.reserve(to - from + 1);
        b.push_back(0);
        for (auto it = from; it != to; ++it) b.push_back(b.back() + f(*it));
        auto pivot = stable_partition(from, to, f);
        l = new WaveletTree(from, pivot, lo, mid);
        r = new WaveletTree(pivot, to, mid + 1, hi);
    }

    int kth(int left, int right, int k) {
        if (lo == hi) return lo;
        int inLeft = b[right] - b[left - 1];
        if (k <= inLeft) return l->kth(b[left - 1] + 1, b[right], k);
        return r->kth(left - b[left - 1], right - b[right], k - inLeft);
    }

    int countLTE(int left, int right, int x) {
        if (left > right || x < lo) return 0;
        if (hi <= x) return right - left + 1;
        return l->countLTE(b[left - 1] + 1, b[right], x)
             + r->countLTE(left - b[left - 1], right - b[right], x);
    }
};
```

#### Mo's Algorithm

Use for offline range queries when add/remove is cheap.

```cpp
struct Query {
    int l, r, id;
};

vector<long long> mosAlgorithm(vector<int> a, vector<Query> queries) {
    int n = a.size();
    int B = max(1, (int)sqrt(n));
    sort(queries.begin(), queries.end(), [&](const Query& x, const Query& y) {
        int bx = x.l / B, by = y.l / B;
        if (bx != by) return bx < by;
        return (bx & 1) ? x.r > y.r : x.r < y.r;
    });

    vector<long long> ans(queries.size());
    long long cur = 0;
    auto add = [&](int idx) { cur += a[idx]; };
    auto remove = [&](int idx) { cur -= a[idx]; };

    int l = 0, r = -1;
    for (auto q : queries) {
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) remove(l++);
        while (r > q.r) remove(r--);
        ans[q.id] = cur;
    }
    return ans;
}
```

#### Rollback DSU

Use for offline dynamic connectivity, divide-and-conquer over time, and backtracking connectivity.

```cpp
struct RollbackDSU {
    vector<int> parent, sz;
    vector<pair<int, int>> history;
    int comps;

    RollbackDSU(int n = 0) { init(n); }
    void init(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        history.clear();
        comps = n;
    }
    int find(int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            history.push_back({-1, -1});
            return false;
        }
        if (sz[a] < sz[b]) swap(a, b);
        history.push_back({b, sz[a]});
        parent[b] = a;
        sz[a] += sz[b];
        comps--;
        return true;
    }
    int snapshot() const { return history.size(); }
    void rollback(int snap) {
        while ((int)history.size() > snap) {
            auto [b, oldSizeA] = history.back();
            history.pop_back();
            if (b == -1) continue;
            int a = parent[b];
            sz[a] = oldSizeA;
            parent[b] = b;
            comps++;
        }
    }
};
```

#### Offline Dynamic Connectivity Skeleton

Add every edge to the segment-tree intervals where it is alive, then DFS with rollback DSU.

```cpp
struct OfflineDynamicConnectivity {
    int q;
    vector<vector<pair<int, int>>> seg;
    RollbackDSU dsu;
    vector<int> answer;

    OfflineDynamicConnectivity(int n, int q) : q(q), seg(4 * q), dsu(n), answer(q) {}

    void addInterval(int node, int l, int r, int ql, int qr, pair<int, int> edge) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            seg[node].push_back(edge);
            return;
        }
        int mid = (l + r) / 2;
        addInterval(node * 2, l, mid, ql, qr, edge);
        addInterval(node * 2 + 1, mid + 1, r, ql, qr, edge);
    }

    void dfs(int node, int l, int r) {
        int snap = dsu.snapshot();
        for (auto [u, v] : seg[node]) dsu.unite(u, v);
        if (l == r) {
            answer[l] = dsu.comps;
        } else {
            int mid = (l + r) / 2;
            dfs(node * 2, l, mid);
            dfs(node * 2 + 1, mid + 1, r);
        }
        dsu.rollback(snap);
    }
};
```

#### Segment Tree Beats, Range Chmin and Sum

Use when updates are `a[i] = min(a[i], x)` and queries ask sums/max. Complexity is amortized `O(log n)`.

```cpp
struct SegTreeBeats {
    struct Node {
        long long sum = 0;
        int mx = INT_MIN, secondMx = INT_MIN, cntMx = 0;
    };
    int n;
    vector<Node> st;

    SegTreeBeats(const vector<int>& a = {}) { if (!a.empty()) build(a); }

    Node merge(Node a, Node b) {
        Node c;
        c.sum = a.sum + b.sum;
        if (a.mx == b.mx) {
            c.mx = a.mx;
            c.cntMx = a.cntMx + b.cntMx;
            c.secondMx = max(a.secondMx, b.secondMx);
        } else if (a.mx > b.mx) {
            c.mx = a.mx;
            c.cntMx = a.cntMx;
            c.secondMx = max(a.secondMx, b.mx);
        } else {
            c.mx = b.mx;
            c.cntMx = b.cntMx;
            c.secondMx = max(a.mx, b.secondMx);
        }
        return c;
    }

    void build(const vector<int>& a) {
        n = a.size();
        st.assign(4 * n, {});
        build(1, 0, n - 1, a);
    }
    void build(int p, int l, int r, const vector<int>& a) {
        if (l == r) {
            st[p] = {a[l], a[l], INT_MIN, 1};
            return;
        }
        int m = (l + r) / 2;
        build(p * 2, l, m, a);
        build(p * 2 + 1, m + 1, r, a);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    void applyChmin(int p, int x) {
        if (x >= st[p].mx) return;
        st[p].sum -= 1LL * (st[p].mx - x) * st[p].cntMx;
        st[p].mx = x;
    }
    void push(int p) {
        applyChmin(p * 2, st[p].mx);
        applyChmin(p * 2 + 1, st[p].mx);
    }
    void rangeChmin(int p, int l, int r, int ql, int qr, int x) {
        if (qr < l || r < ql || x >= st[p].mx) return;
        if (ql <= l && r <= qr && x > st[p].secondMx) {
            applyChmin(p, x);
            return;
        }
        push(p);
        int m = (l + r) / 2;
        rangeChmin(p * 2, l, m, ql, qr, x);
        rangeChmin(p * 2 + 1, m + 1, r, ql, qr, x);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }
    long long querySum(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return st[p].sum;
        push(p);
        int m = (l + r) / 2;
        return querySum(p * 2, l, m, ql, qr)
             + querySum(p * 2 + 1, m + 1, r, ql, qr);
    }
};
```

### Advanced Level: DP Optimizations

#### Divide and Conquer DP Optimization

Use when the optimal split point is monotonic.

```cpp
void computeDC(int l, int r, int optL, int optR,
               const vector<long long>& prev, vector<long long>& cur) {
    if (l > r) return;
    int mid = (l + r) / 2;
    pair<long long, int> best = {LINF, -1};
    for (int k = optL; k <= min(mid, optR); k++) {
        long long val = prev[k] + cost(k, mid); // define cost separately
        best = min(best, {val, k});
    }
    cur[mid] = best.first;
    int opt = best.second;
    computeDC(l, mid - 1, optL, opt, prev, cur);
    computeDC(mid + 1, r, opt, optR, prev, cur);
}
```

#### Knuth Optimization Skeleton

Use for interval DP when quadrangle inequality and monotone opt hold.

```cpp
void knuthDP(int n) {
    vector<vector<long long>> dp(n, vector<long long>(n));
    vector<vector<int>> opt(n, vector<int>(n));
    for (int i = 0; i < n; i++) opt[i][i] = i;
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = LINF;
            for (int k = opt[l][r - 1]; k <= opt[l + 1][r]; k++) {
                long long val = dp[l][k] + dp[k + 1][r] + cost(l, r); // define cost
                if (val < dp[l][r]) {
                    dp[l][r] = val;
                    opt[l][r] = k;
                }
            }
        }
    }
}
```

#### Convex Hull Trick for Monotonic Lines and Queries

Use when slopes and query `x` are monotonic.

```cpp
struct Line {
    long long m, b;
    long long value(long long x) const { return m * x + b; }
};

bool bad(const Line& a, const Line& b, const Line& c) {
    return (__int128)(b.b - a.b) * (a.m - c.m)
        >= (__int128)(c.b - a.b) * (a.m - b.m);
}

struct CHT {
    deque<Line> dq;
    void add(long long m, long long b) {
        Line ln{m, b};
        while (dq.size() >= 2 && bad(dq[dq.size() - 2], dq.back(), ln)) dq.pop_back();
        dq.push_back(ln);
    }
    long long query(long long x) {
        while (dq.size() >= 2 && dq[0].value(x) >= dq[1].value(x)) dq.pop_front();
        return dq.front().value(x);
    }
};
```

#### Li Chao Tree

Use for arbitrary line insertions and min queries over fixed integer `x` domain.

```cpp
struct LiChao {
    struct Line {
        long long m, b;
        long long get(long long x) const { return m * x + b; }
    };
    struct Node {
        Line line;
        Node *left = nullptr, *right = nullptr;
        Node(Line line) : line(line) {}
    };
    long long L, R;
    Node* root = nullptr;
    LiChao(long long L, long long R) : L(L), R(R) {}

    void addLine(Line nw) { addLine(root, L, R, nw); }
    void addLine(Node*& node, long long l, long long r, Line nw) {
        if (!node) {
            node = new Node(nw);
            return;
        }
        long long mid = (l + r) / 2;
        bool lef = nw.get(l) < node->line.get(l);
        bool m = nw.get(mid) < node->line.get(mid);
        if (m) swap(nw, node->line);
        if (l == r) return;
        if (lef != m) addLine(node->left, l, mid, nw);
        else addLine(node->right, mid + 1, r, nw);
    }

    long long query(long long x) { return query(root, L, R, x); }
    long long query(Node* node, long long l, long long r, long long x) {
        if (!node) return LINF;
        long long ans = node->line.get(x);
        if (l == r) return ans;
        long long mid = (l + r) / 2;
        if (x <= mid) return min(ans, query(node->left, l, mid, x));
        return min(ans, query(node->right, mid + 1, r, x));
    }
};
```

### Advanced Level: Tree and Sequence Structures

#### DSU on Tree / Small-to-Large

Use for subtree color-frequency queries in `O(n log n)` or `O(n)` depending on operations.

```cpp
struct DSUOnTree {
    int n;
    vector<vector<int>> g;
    vector<int> color, sub, heavy, cnt, ans;
    int bestColor = 0, bestFreq = 0;

    DSUOnTree(vector<vector<int>> g, vector<int> color)
        : n(g.size()), g(move(g)), color(move(color)), sub(n), heavy(n, -1), ans(n) {
        cnt.assign(n + 1, 0);
        dfsSize(0, -1);
        dfs(0, -1, true);
    }

    int dfsSize(int u, int p) {
        sub[u] = 1;
        int mx = 0;
        for (int v : g[u]) if (v != p) {
            sub[u] += dfsSize(v, u);
            if (sub[v] > mx) mx = sub[v], heavy[u] = v;
        }
        return sub[u];
    }

    void addSubtree(int u, int p, int delta) {
        int c = color[u];
        cnt[c] += delta;
        if (cnt[c] > bestFreq) bestFreq = cnt[c], bestColor = c;
        for (int v : g[u]) if (v != p) addSubtree(v, u, delta);
    }

    void dfs(int u, int p, bool keep) {
        for (int v : g[u]) if (v != p && v != heavy[u]) dfs(v, u, false);
        if (heavy[u] != -1) dfs(heavy[u], u, true);
        for (int v : g[u]) if (v != p && v != heavy[u]) addSubtree(v, u, 1);
        cnt[color[u]]++;
        if (cnt[color[u]] > bestFreq) bestFreq = cnt[color[u]], bestColor = color[u];
        ans[u] = bestColor;
        if (!keep) {
            addSubtree(u, p, -1);
            bestColor = bestFreq = 0; // recompute logic may be needed for different query types
        }
    }
};
```

#### Implicit Treap

Use for dynamic arrays with split/merge, range reverse, insert, erase.

```cpp
struct Treap {
    struct Node {
        int val, prio, sz = 1;
        bool rev = false;
        Node *l = nullptr, *r = nullptr;
        Node(int v) : val(v), prio((rand() << 16) ^ rand()) {}
    };

    int sz(Node* t) { return t ? t->sz : 0; }
    void push(Node* t) {
        if (!t || !t->rev) return;
        swap(t->l, t->r);
        if (t->l) t->l->rev ^= 1;
        if (t->r) t->r->rev ^= 1;
        t->rev = false;
    }
    void pull(Node* t) {
        if (t) t->sz = 1 + sz(t->l) + sz(t->r);
    }
    void split(Node* t, int k, Node*& a, Node*& b) {
        if (!t) {
            a = b = nullptr;
            return;
        }
        push(t);
        if (sz(t->l) >= k) {
            split(t->l, k, a, t->l);
            b = t;
        } else {
            split(t->r, k - sz(t->l) - 1, t->r, b);
            a = t;
        }
        pull(t);
    }
    Node* merge(Node* a, Node* b) {
        if (!a || !b) return a ? a : b;
        if (a->prio > b->prio) {
            push(a);
            a->r = merge(a->r, b);
            pull(a);
            return a;
        }
        push(b);
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
    void reverseRange(Node*& root, int l, int r) {
        Node *a, *b, *c;
        split(root, l, a, b);
        split(b, r - l + 1, b, c);
        if (b) b->rev ^= 1;
        root = merge(a, merge(b, c));
    }
};
```

#### Link-Cut Tree Skeleton

Use for dynamic forest connectivity and path queries. This skeleton supports link, cut, and connected.

```cpp
struct LinkCut {
    struct Node {
        int ch[2] = {0, 0}, p = 0;
        bool rev = false;
    };
    vector<Node> t;
    LinkCut(int n = 0) : t(n + 1) {}

    bool isRoot(int x) {
        int p = t[x].p;
        return p == 0 || (t[p].ch[0] != x && t[p].ch[1] != x);
    }
    void push(int x) {
        if (!x || !t[x].rev) return;
        swap(t[x].ch[0], t[x].ch[1]);
        if (t[x].ch[0]) t[t[x].ch[0]].rev ^= 1;
        if (t[x].ch[1]) t[t[x].ch[1]].rev ^= 1;
        t[x].rev = false;
    }
    void rotate(int x) {
        int p = t[x].p, g = t[p].p;
        push(p); push(x);
        int dir = (t[p].ch[1] == x);
        int b = t[x].ch[dir ^ 1];
        if (!isRoot(p)) t[g].ch[t[g].ch[1] == p] = x;
        t[x].p = g;
        t[x].ch[dir ^ 1] = p;
        t[p].p = x;
        t[p].ch[dir] = b;
        if (b) t[b].p = p;
    }
    void splay(int x) {
        static vector<int> stk;
        stk.clear();
        int y = x;
        stk.push_back(y);
        while (!isRoot(y)) y = t[y].p, stk.push_back(y);
        while (!stk.empty()) push(stk.back()), stk.pop_back();
        while (!isRoot(x)) {
            int p = t[x].p, g = t[p].p;
            if (!isRoot(p)) {
                bool zigzig = (t[p].ch[0] == x) == (t[g].ch[0] == p);
                rotate(zigzig ? p : x);
            }
            rotate(x);
        }
    }
    void access(int x) {
        for (int y = 0; x; y = x, x = t[x].p) {
            splay(x);
            t[x].ch[1] = y;
        }
    }
    void makeRoot(int x) {
        access(x);
        splay(x);
        t[x].rev ^= 1;
    }
    int findRoot(int x) {
        access(x);
        splay(x);
        push(x);
        while (t[x].ch[0]) {
            x = t[x].ch[0];
            push(x);
        }
        splay(x);
        return x;
    }
    bool connected(int a, int b) {
        return findRoot(a) == findRoot(b);
    }
    void link(int a, int b) {
        makeRoot(a);
        if (findRoot(b) != a) t[a].p = b;
    }
    void cut(int a, int b) {
        makeRoot(a);
        access(b);
        splay(b);
        if (t[b].ch[0] == a && t[a].ch[1] == 0) {
            t[b].ch[0] = 0;
            t[a].p = 0;
        }
    }
};
```

### ICPC-Hard: Matching and String Palindrome Structures

#### Hungarian Algorithm for Minimum Cost Assignment

Use for square or padded rectangular assignment. Complexity: `O(n^3)`.

```cpp
long long hungarian(const vector<vector<long long>>& a) {
    int n = a.size(), m = a[0].size();
    vector<long long> u(n + 1), v(m + 1);
    vector<int> p(m + 1), way(m + 1);
    for (int i = 1; i <= n; i++) {
        p[0] = i;
        int j0 = 0;
        vector<long long> minv(m + 1, LINF);
        vector<char> used(m + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], j1 = 0;
            long long delta = LINF;
            for (int j = 1; j <= m; j++) if (!used[j]) {
                long long cur = a[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                if (minv[j] < delta) delta = minv[j], j1 = j;
            }
            for (int j = 0; j <= m; j++) {
                if (used[j]) u[p[j]] += delta, v[j] -= delta;
                else minv[j] -= delta;
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }
    return -v[0];
}
```

#### Palindromic Tree / Eertree

Use for distinct palindromic substrings online.

```cpp
struct Eertree {
    struct Node {
        int len, link;
        map<char, int> next;
        int occ = 0;
    };
    vector<Node> t;
    string s;
    int suff;

    Eertree() {
        t.push_back({-1, 0, {}, 0});
        t.push_back({0, 0, {}, 0});
        suff = 1;
    }

    int getLink(int v, int pos) {
        while (true) {
            int l = t[v].len;
            if (pos - 1 - l >= 0 && s[pos - 1 - l] == s[pos]) return v;
            v = t[v].link;
        }
    }

    void addChar(char c) {
        s += c;
        int pos = s.size() - 1;
        int cur = getLink(suff, pos);
        if (!t[cur].next.count(c)) {
            int now = t.size();
            t.push_back({t[cur].len + 2, 0, {}, 0});
            if (t[now].len == 1) t[now].link = 1;
            else {
                int linkCandidate = getLink(t[cur].link, pos);
                t[now].link = t[linkCandidate].next[c];
            }
            t[cur].next[c] = now;
        }
        suff = t[cur].next[c];
        t[suff].occ++;
    }
};
```

#### Edmonds Blossom for General Graph Maximum Matching

Use when matching is not bipartite. Complexity: `O(n^3)`.

```cpp
struct Blossom {
    int n;
    vector<vector<int>> g;
    vector<int> match, p, base, q;
    vector<bool> used, blossom;

    Blossom(int n) : n(n), g(n), match(n, -1), p(n), base(n), q(n), used(n), blossom(n) {}
    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int lca(int a, int b) {
        vector<bool> usedPath(n, false);
        while (true) {
            a = base[a];
            usedPath[a] = true;
            if (match[a] == -1) break;
            a = p[match[a]];
        }
        while (true) {
            b = base[b];
            if (usedPath[b]) return b;
            b = p[match[b]];
        }
    }

    void markPath(int v, int b, int child) {
        while (base[v] != b) {
            blossom[base[v]] = blossom[base[match[v]]] = true;
            p[v] = child;
            child = match[v];
            v = p[match[v]];
        }
    }

    int findPath(int root) {
        fill(used.begin(), used.end(), false);
        fill(p.begin(), p.end(), -1);
        iota(base.begin(), base.end(), 0);
        int qh = 0, qt = 0;
        q[qt++] = root;
        used[root] = true;
        while (qh < qt) {
            int v = q[qh++];
            for (int u : g[v]) {
                if (base[v] == base[u] || match[v] == u) continue;
                if (u == root || (match[u] != -1 && p[match[u]] != -1)) {
                    int curbase = lca(v, u);
                    fill(blossom.begin(), blossom.end(), false);
                    markPath(v, curbase, u);
                    markPath(u, curbase, v);
                    for (int i = 0; i < n; i++) {
                        if (blossom[base[i]]) {
                            base[i] = curbase;
                            if (!used[i]) used[i] = true, q[qt++] = i;
                        }
                    }
                } else if (p[u] == -1) {
                    p[u] = v;
                    if (match[u] == -1) return u;
                    u = match[u];
                    used[u] = true;
                    q[qt++] = u;
                }
            }
        }
        return -1;
    }

    int maxMatching() {
        int matching = 0;
        for (int i = 0; i < n; i++) if (match[i] == -1) {
            int v = findPath(i);
            if (v == -1) continue;
            while (v != -1) {
                int pv = p[v], nv = match[pv];
                match[v] = pv;
                match[pv] = v;
                v = nv;
            }
            matching++;
        }
        return matching;
    }
};
```

### ICPC-Hard: Additional Math, Games, and Graph Extras

#### Matrix Exponentiation

Use for linear recurrences and state transitions repeated many times.

```cpp
using Matrix = vector<vector<long long>>;

Matrix multiplyMatrix(const Matrix& a, const Matrix& b, long long mod) {
    int n = a.size(), m = b[0].size(), k = b.size();
    Matrix c(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int mid = 0; mid < k; mid++) if (a[i][mid]) {
            for (int j = 0; j < m; j++) {
                c[i][j] = (c[i][j] + (__int128)a[i][mid] * b[mid][j]) % mod;
            }
        }
    }
    return c;
}

Matrix matrixPower(Matrix a, long long e, long long mod) {
    int n = a.size();
    Matrix r(n, vector<long long>(n));
    for (int i = 0; i < n; i++) r[i][i] = 1;
    while (e) {
        if (e & 1) r = multiplyMatrix(r, a, mod);
        a = multiplyMatrix(a, a, mod);
        e >>= 1;
    }
    return r;
}
```

#### Sprague-Grundy for DAG Games

Use for impartial games where states form a DAG.

```cpp
int grundy(int u, const vector<vector<int>>& moves, vector<int>& memo) {
    if (memo[u] != -1) return memo[u];
    set<int> seen;
    for (int v : moves[u]) seen.insert(grundy(v, moves, memo));
    int g = 0;
    while (seen.count(g)) g++;
    return memo[u] = g;
}

bool firstPlayerWins(const vector<int>& pileStates,
                     const vector<vector<int>>& moves) {
    vector<int> memo(moves.size(), -1);
    int xr = 0;
    for (int s : pileStates) xr ^= grundy(s, moves, memo);
    return xr != 0;
}
```

#### Reservoir Sampling

Use to pick one random item from a stream without knowing its length.

```cpp
template <class T>
T reservoirSample(istream& in) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    T x, ans{};
    long long cnt = 0;
    while (in >> x) {
        cnt++;
        if (uniform_int_distribution<long long>(1, cnt)(rng) == 1) ans = x;
    }
    return ans;
}
```

#### Lengauer-Tarjan Dominator Tree

Use in directed flow graphs to find immediate dominators from a start node.

```cpp
struct DominatorTree {
    int n, timer = 0;
    vector<vector<int>> g, rg, bucket;
    vector<int> arr, rev, par, sdom, dom, dsu, label;

    DominatorTree(const vector<vector<int>>& graph, int src) : n(graph.size()), g(graph) {
        rg.assign(n, {});
        bucket.assign(n, {});
        arr.assign(n, -1);
        rev.assign(n, -1);
        par.assign(n, -1);
        sdom.resize(n);
        dom.resize(n);
        dsu.resize(n);
        label.resize(n);
        dfs(src);
        int N = timer;
        for (int i = 0; i < N; i++) sdom[i] = dom[i] = dsu[i] = label[i] = i;

        for (int i = N - 1; i >= 0; i--) {
            for (int v : rg[i]) sdom[i] = min(sdom[i], sdom[find(v)]);
            if (i > 0) bucket[sdom[i]].push_back(i);
            for (int v : bucket[i]) {
                int y = find(v);
                dom[v] = (sdom[y] == sdom[v]) ? sdom[v] : y;
            }
            if (i > 0) unite(par[i], i);
        }
        for (int i = 1; i < N; i++) {
            if (dom[i] != sdom[i]) dom[i] = dom[dom[i]];
        }
        // dom[index] is an index in DFS order; rev[dom[arr[v]]] is immediate dominator of v.
    }

    void dfs(int u) {
        arr[u] = timer;
        rev[timer] = u;
        timer++;
        for (int w : g[u]) {
            if (arr[w] == -1) {
                dfs(w);
                par[arr[w]] = arr[u];
            }
            rg[arr[w]].push_back(arr[u]);
        }
    }

    int find(int u, int x = 0) {
        if (u == dsu[u]) return x ? -1 : u;
        int v = find(dsu[u], x + 1);
        if (v < 0) return u;
        if (sdom[label[dsu[u]]] < sdom[label[u]]) label[u] = label[dsu[u]];
        dsu[u] = v;
        return x ? v : label[u];
    }

    void unite(int u, int v) {
        dsu[v] = u;
    }

    int immediateDominator(int v) {
        if (arr[v] <= 0) return -1;
        return rev[dom[arr[v]]];
    }
};
```

### Final Template Checklist

Before treating any template as memorized, verify:

- You can state the invariant in one sentence.
- You know which inputs break the assumptions.
- You can explain every array's indexing convention.
- You can write a brute force checker for small random cases.
- You have tested empty, single-element, duplicate, disconnected, and maximum-size cases.
- You know whether the graph is directed or undirected.
- You know whether weights can be negative.
- You know whether updates are online or can be processed offline.
- You know whether the operation is associative, idempotent, invertible, or monotonic.
