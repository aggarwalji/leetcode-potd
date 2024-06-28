class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       vector<int> degree(n, 0);

    // Calculate the degree of each city
    for (const auto& road : roads) {
        degree[road[0]]++;
        degree[road[1]]++;
    }

    // Create an array of city indices
    vector<int> cities(n);
    iota(cities.begin(), cities.end(), 0);

    // Sort the cities based on their degree in descending order
    sort(cities.begin(), cities.end(), [&](int a, int b) {
        return degree[a] > degree[b];
    });

    // Assign values from 1 to n to cities in descending order of their degrees
    vector<int> value(n);
    for (int i = 0; i < n; ++i) {
        value[cities[i]] = n - i;
    }

    // Calculate the maximum total importance of all roads
    long long max_importance = 0;
    for (const auto& road : roads) {
        max_importance += value[road[0]] + value[road[1]];
    }

    return max_importance;
    }
};