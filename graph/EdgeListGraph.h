#include <list>

/**
 * 简单的图数据结构，直接保存边的列表，预处理外部输入的数据。
 */
class EdgeListGraph {
private:
    class Edge {
    public:
        int src;
        int snk;
        int cost;

        inline bool same(Edge const & other) const {
            return this->src == other.src 
                && this->snk == other.snk;
        }

        bool operator==(Edge const & other) const {
            return this->src == other.src
                && this->snk == other.snk
                && this->cost == other.cost;
        }
    };

    std::list<Edge> edges;

public:
    /**
     * capability 预估总共有多少条边，优化性能。
     */
    EdgeListGraph(unsigned int capability) : edges(capability) {

    }

    /**
     * 添加一条边，不判断是否重复。
     */
    void addEdge(int src, int snk, int cost);

    /**
     * 去掉重复的边，以后添加的边为准。
     * ui 是不是单向图，默认是双向图
     * return 有多少重复的边
     */
    int uniqueEdges(bool ui = false);

    bool operator==(EdgeListGraph & other) const {
        return this->edges == other.edges;
    }
};