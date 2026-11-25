# cpp-algorithms

Clean, commented **C++17** implementations of classic competitive-programming algorithms.
Written by **Hung Dao** — IT teacher (since 2008) coaching students for informatics olympiads.

Every file is a self-contained program: read the comment at the top for the problem, input format and complexity.

| Topic | File | Complexity |
|---|---|---|
| BFS (shortest path, unweighted) | [graph/bfs.cpp](graph/bfs.cpp) | O(N + M) |
| Dijkstra | [graph/dijkstra.cpp](graph/dijkstra.cpp) | O((N + M) log N) |
| Disjoint Set Union + Kruskal MST | [data-structures/dsu_kruskal.cpp](data-structures/dsu_kruskal.cpp) | O(M log M) |
| Segment Tree (range sum, point update) | [data-structures/segment_tree.cpp](data-structures/segment_tree.cpp) | O(log N) / query |
| Fenwick Tree (BIT) | [data-structures/fenwick.cpp](data-structures/fenwick.cpp) | O(log N) / query |
| 0/1 Knapsack | [dp/knapsack.cpp](dp/knapsack.cpp) | O(N · W) |
| Longest Increasing Subsequence | [dp/lis.cpp](dp/lis.cpp) | O(N log N) |
| Sieve of Eratosthenes | [math/sieve.cpp](math/sieve.cpp) | O(N log log N) |
| Fast modular exponentiation | [math/power_mod.cpp](math/power_mod.cpp) | O(log B) |

## Compile
```bash
g++ -std=c++17 -O2 -o main file.cpp
```

## Need a custom solution or explanation?
I solve and explain C++ algorithm problems step by step → **[fiverr.com/hungdaoj](https://www.fiverr.com/hungdaoj)**

## License
MIT — free to use for learning and contests.
