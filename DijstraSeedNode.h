/**
 * 最短路算法的备选种子节点，保存在优先队列中。
 */
class DijstraSeedNode {
private:
    int node; // 节点的标识
    int cost; // 节点的费用

public:
    DijstraSeedNode(int node, int cost) {
        this->cost = cost;
        this->node = node;
    }

    /**
     * 费用越小优先级越高
     */
    bool operator<(DijstraSeedNode const & other) const {
        return this->cost > other.cost;
    }

    int getNode() const {
        return node;
    }

    int getCost() const {
        return cost;
    }
};