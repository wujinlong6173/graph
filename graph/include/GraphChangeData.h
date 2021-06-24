#include <list>
#include <unordered_set>

/**
 * 频繁修改图存在性能问题，应该把一段时间内的所有变化收集起来，
 * 最后一次性构建新图。
 */
class GraphChangeData {
private:
    std::unordered_set<int> removeNodes;

    class EdgeChangeData {
    public:
        int src;
        int snk;
        int cost; // 费用等于零表示移除边
    };

    std::list<EdgeChangeData> changeEdges;

public:
    /**
     * 移除一个节点。
     */
    inline void removeNode(int node);

    /**
     * 移除一条双向边。
     */
    inline void removeEdge(int src, int snk);

    /**
     * 添加一条双向边，费用必须大于零。
     * 如果边已存在，则修改边的费用。
     */
    void addEdge(int src, int snk, int cost = 1);

    /**
     * 返回变化的数量。
     */
    inline int size() const;
};