#include <vector>
#include <unordered_map>

/**
 * 锁定后就不会被修改的有向图。
 */
class ImmutableGraph {
private:
    // 节点和它的邻居
    std::unordered_map<int, std::vector<int> const> nodes;

    // 锁定后禁止修改，不提供解锁的方法
    bool locked = false;

public:
    /**
     * 增加一个节点和它的邻居。
     * 注意：调用者保证没有重复的邻居。
     */
    void addNode(int node, std::vector<int> const & neighbors);

    /**
     * 增加一个节点和它的邻居。
     * 注意：调用者保证没有重复的邻居；必须以零结束参数列表。
     */
    void addNode(int node, ...);

    void lock() {
        locked = true;
    }

    bool operator==(ImmutableGraph const & other) const {
        return this->nodes == other.nodes;
    }
};