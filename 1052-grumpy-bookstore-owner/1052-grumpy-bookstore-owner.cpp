class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
         int n = customers.size();
          int totalSatisfied = 0;

    // Calculate the initial number of satisfied customers without any technique
    for (int i = 0; i < n; ++i) {
        if (!grumpy[i]) {
            totalSatisfied += customers[i];
        }
    }

    // Calculate the extra satisfied customers if we apply the technique from the start
    int maxExtraSatisfied = 0;
    int currentExtraSatisfied = 0;

    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i]) {
            currentExtraSatisfied += customers[i];
        }
    }

    maxExtraSatisfied = currentExtraSatisfied;

    // Slide the window over the rest of the array
    for (int i = minutes; i < n; ++i) {
        if (grumpy[i]) {
            currentExtraSatisfied += customers[i];
        }
        if (grumpy[i - minutes]) {
            currentExtraSatisfied -= customers[i - minutes];
        }
        maxExtraSatisfied = max(maxExtraSatisfied, currentExtraSatisfied);
    }

    return totalSatisfied + maxExtraSatisfied;

    }
};