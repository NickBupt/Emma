#include <iostream>
#include <vector>
#include <unordered_set>

void dfs(int node, const std::vector<std::vector<int>>& graph, std::unordered_set<int>& visited) {
    // 标记当前节点为已访问
    visited.insert(node);
    std::cout << node << " ";  // 处理当前节点，例如打印节点编号

    // 遍历与当前节点相邻的节点
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {  // 如果邻居未访问过
            dfs(neighbor, graph, visited);  // 递归调用
        }
    }
}

int main() {
    // 示例图的邻接表表示（假设图节点编号从0开始）
    std::vector<std::vector<int>> graph = {
            {1, 2},     // 节点 0 的邻居
            {0, 3, 4},  // 节点 1 的邻居
            {0, 5},     // 节点 2 的邻居
            {1},        // 节点 3 的邻居
            {1, 5},     // 节点 4 的邻居
            {2, 4}      // 节点 5 的邻居
    };

    std::unordered_set<int> visited;  // 使用集合记录访问过的节点
    std::cout << "DFS Traversal: ";
    dfs(0, graph, visited);  // 从节点 0 开始DFS
    std::cout << std::endl;

    return 0;
}

