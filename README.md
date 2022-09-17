# Sudoku-Solver
A class written in C++17 for solving sudoku table using backtracking.

## How to run example?

You can use bazel:
<div>
<pre><code>$ bazel run :sudoku_solver_example
</code></pre>
</div>

or g++:
<div>
<pre><code>$ g++ sudoku_solver_example.cc ./a.out && ./a.out
</code></pre>
</div>


## How to run tests?

You can use bazel:
<div>
<pre><code>$ bazel test test:test_sudoku
</code></pre>
</div>
