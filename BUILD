cc_library(
    name = "sudoku",
    hdrs = [
        "sudoku.hh"
    ],
    copts = [
        "-std=c++17",
    ],
    visibility = ["//visibility:public"]
)

cc_binary(
    name = "sudoku_solver_example",
    srcs = ["sudoku_solver_example.cc"],
        deps = [
        ":sudoku",
    ],
)