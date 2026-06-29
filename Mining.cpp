#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>

using namespace std;

struct Block {
    int id;
    int row;
    int col;
    int value;
};


int getBlockId(int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return -1;
    return r * cols + c;
}


void dfs(int blockId, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, stack<int>& order) {
    visited[blockId] = true;

    if (adjList.count(blockId)) {
        for (int requiredParent : adjList[blockId]) {
            if (!visited[requiredParent]) {
                dfs(requiredParent, adjList, visited, order);
            }
        }
    }

    order.push(blockId);
}

int main() {
    int rows = 3;
    int cols = 5;

    vector<Block> blocks;
    unordered_map<int, list<int>> adjList;

    /*Initializing Grid*/
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int id = getBlockId(i, j, rows, cols);
            int val = (i == rows - 1 && j == cols / 2) ? 500 : -50; 
            blocks.push_back({id, i, j, val});
        }
    }

    for (int r = 1; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int currentBlock = getBlockId(r, c, rows, cols);

            int parents[3] = { 
                getBlockId(r - 1, c - 1, rows, cols), 
                getBlockId(r - 1, c, rows, cols), 
                getBlockId(r - 1, c + 1, rows, cols) 
            };

            for (int p : parents) {
                if (p != -1) {
                    adjList[currentBlock].push_back(p);
                }
            }
        }
    }

    unordered_map<int, bool> visited;
    stack<int> order;

    int targetBlockId = getBlockId(rows - 1, cols / 2, rows, cols);

    dfs(targetBlockId, adjList, visited, order);

    cout << "=== SAFE EXTRACTION PIT SEQUENCE ===\n";
    cout << "Targeting Block ID: " << targetBlockId << "\n\n";
    
    int step = 1;
    int netProfit = 0;

    while (!order.empty()) {
        int id = order.top();
        order.pop();
        
        Block b = blocks[id];
        netProfit += b.value;

        cout << "Step " << step++ << ": Mine Block " << b.id 
             << " at [" << b.row << "][" << b.col << "] | Value: $" << b.value << "\n";
    }

    cout << "Net Profit for this pit: $" << netProfit << "\n";
    
    return 0;
}