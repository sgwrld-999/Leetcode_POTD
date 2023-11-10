#include<bits/stdc++.h>
using namespace std;
/*
There is dependency between the adjacent pairs. So by that we can think of graph.
We will create a graph and then we will do dfs on it but the modification is that we will start dfs from the node which has only one adjacent node 
as it will be the starting node of the array.
Aur kaise socha humne ki DFS lagega?
Ek node ki poistion depend kar rhi atmost 2 nodes pe.
So if we write the dependcy or write the element in 
rightNeighbours , Element , leftNeighbours
We can se a tree.             
            3
           / \
          4   2
         /     \
        5       1 

Output: 5 4 3 2 1
Therefor we can think of BFS
*/ 
class Solution1 {
private:
    void dfs(int currentNode, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adjacencyMap, vector<int>& result) {
        visited[currentNode] = true;
        result.push_back(currentNode);
        for (auto neighbor : adjacencyMap[currentNode]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adjacencyMap, result);
            }
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjacencyMap;
        for (auto pair : adjacentPairs) {
            adjacencyMap[pair[0]].push_back(pair[1]);
            adjacencyMap[pair[1]].push_back(pair[0]);
        }

        unordered_map<int, bool> visited;
        for (auto entry : adjacencyMap) {
            visited[entry.first] = false;
        }

        vector<int> result;
        int startNode = 0;

        for (auto entry : adjacencyMap) {
            if (entry.second.size() == 1) {
                startNode = entry.first;
                break;
            }
        }

        dfs(startNode, visited, adjacencyMap, result);
        return result;
    }
};

int main(){
    Solution1 s;
    vector<vector<int>> adjacentPairs = {{2,1},{3,4},{3,2}};
    vector<int> result = s.restoreArray(adjacentPairs);
    for(int i = 0 ; i < result.size() ; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}