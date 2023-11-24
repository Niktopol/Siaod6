#ifndef GRAPH
#define GRAPH
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
class graph{
    double **matrix;
    int size;
    bool is_oriented;
    void print_chains(std::vector<int>, int);
    void find_path(std::vector<int>, int, int, double, double&);
public:
    void add_graph_edge();
    void print_graph();
    void print_chains();
    void find_path();
    graph(bool);
    ~graph();
};
#endif