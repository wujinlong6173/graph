#include "EdgeListGraph.h"

void EdgeListGraph::addEdge(int src, int snk, int cost) {
    Edge edge;
    edge.src = src;
    edge.snk = snk;
    edge.cost = cost;
    edges.push_back(edge);
}

int EdgeListGraph::uniqueEdges(bool ui) {
    if (!ui) {
        for (auto edge : edges) {
            if (edge.snk > edge.src) {
                std::swap(edge.src, edge.snk);
            }
        }
    }

    int count = 0;
    for (auto it = edges.begin(); it != edges.end(); /* null */) {
        if (it->src == it->snk) {
            it = edges.erase(it);
            continue;
        }
        for (auto search = edges.begin(); search != it; ++search) {
            if (search->same(*it)) {
                count++;
                it = edges.erase(it);
            } else {
                ++it;
            }
        }
    }
    return count;
}