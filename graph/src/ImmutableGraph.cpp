#include <stdarg.h>
#include <ImmutableGraph.h>

void ImmutableGraph::addNode(int node, std::vector<int> const & neighbors) {
    if (locked) return;

    nodes.emplace(node, neighbors);
}

void ImmutableGraph::addNode(int node, ...) {
    if (locked) return;
    std::vector<int> neighbors;

    va_list args;
    va_start(args, node);
    int arg = va_arg(args, int);
    while (arg != 0) {
        neighbors.push_back(arg);
        arg = va_arg(args, int);   
    }
    va_end(args);

    nodes.emplace(node, neighbors);
}