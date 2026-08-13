#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

void bfs(int start_node, const std::vector<std::vector<int>>& graph) {
    std::queue<int> q;               // 创建一个队列来管理当前层次的节点
    std::unordered_set<int> visited; // 使用集合记录已访问的节点

    q.push(start_node);       // 将起始节点加入队列
    visited.insert(start_node); // 标记起始节点为已访问

    while (!q.empty()) {
        int node = q.front();  // 获取队列的第一个节点
        q.pop();
        std::cout << node << " ";  // 处理当前节点，例如打印节点编号

        // 遍历与当前节点相邻的所有节点
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {  // 如果邻居未访问过
                q.push(neighbor);          // 将邻居加入队列
                visited.insert(neighbor);   // 标记为已访问
            }
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

    std::cout << "BFS Traversal: ";
    bfs(0, graph);  // 从节点 0 开始BFS
    std::cout << std::endl;

    return 0;
}
