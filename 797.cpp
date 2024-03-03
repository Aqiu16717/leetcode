#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path_.push_back(0);
        dfs(graph, 0);
        return ret_;
    }

private:
    void dfs(vector<vector<int>>& graph, int x) {
        if (x == graph.size() - 1) {
            ret_.push_back(path_);
            return;
        }

        for (int i = 0; i < graph[x].size(); ++i) {
            path_.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path_.pop_back();
        }
    }

private:
    vector<int> path_;
    vector<vector<int>> ret_;
};

int main()
{
    vector<vector<int>> g{{1,2},{3},{3},{}};

    Solution s;

    vector<vector<int>> ret = s.allPathsSourceTarget(g);
    return 0;
}