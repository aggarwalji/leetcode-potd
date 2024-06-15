class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
    vector<pair<int, int>> projects(n);
    
    // Combine the profits and capital into a single vector of pairs
    for (int i = 0; i < n; ++i) {
        projects[i] = {capital[i], profits[i]};
    }
    
    // Sort projects based on the required capital
    sort(projects.begin(), projects.end());
    
    priority_queue<int> maxHeap;
    int projectIndex = 0;
    
    for (int i = 0; i < k; ++i) {
        // Push all projects that can be started with the current capital into the max-heap
        while (projectIndex < n && projects[projectIndex].first <= w) {
            maxHeap.push(projects[projectIndex].second);
            ++projectIndex;
        }
        
        // If there are no projects that can be started, break out of the loop
        if (maxHeap.empty()) {
            break;
        }
        
        // Select the project with the maximum profit
        w += maxHeap.top();
        maxHeap.pop();
    }
    
    return w;

    }
};