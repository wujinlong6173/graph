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
    bool ui = false;

public:
    EdgeListGraph(bool ui = false) {
        this->ui = ui;
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
    int uniqueEdges();

    bool operator==(EdgeListGraph const & other) const {
        return this->edges == other.edges;
    }
};