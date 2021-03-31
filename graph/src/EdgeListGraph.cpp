#include <EdgeListGraph.h>

void EdgeListGraph::addEdge(int src, int snk, int cost) {
    Edge edge;
    edge.src = src;
    edge.snk = snk;
    edge.cost = cost;
    edges.push_back(edge);
}

int EdgeListGraph::uniqueEdges(bool ui) {
    
    if (!ui) {
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if (it->snk < it->src) {
                std::swap(it->src, it->snk);
            }
        }
    }

    int count = 0;
    for (auto it = edges.begin(); it != edges.end(); ) {
        if (it->src == it->snk) {
            it = edges.erase(it);
            count++;
            continue;
        }
        bool erased = false;
        for (auto search = edges.begin(); search != it; ++search) {
            if (search->same(*it)) {
                search->cost = it->cost;
                it = edges.erase(it);
                count++;
                erased = true;
                break;
            }
        }
        if (!erased) {
            ++it;
        }
    }
    return count;
}