#include <algorithm>
#include <GraphChangeData.h>

void GraphChangeData::removeNode(int node) {
    removeNodes.insert(node);
}

void GraphChangeData::removeEdge(int src, int snk) {
    addEdge(src, snk, 0);
}

void GraphChangeData::addEdge(int src, int snk, int cost) {
    if (src > snk) {
        std::swap(src, snk);
    }

    for (auto it = changeEdges.begin(); it != changeEdges.end(); ++it) {
         if (it->src == src && it->snk == snk) {
            it->cost = cost;
            return;
        }
    }

    EdgeChangeData chg;
    chg.src = src;
    chg.snk = snk;
    chg.cost = cost;
    changeEdges.push_back(chg);
}

int GraphChangeData::size() const {
    return removeNodes.size() + changeEdges.size();
}