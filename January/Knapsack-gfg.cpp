double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size(); // Number of items

        // Create a vector of pairs (value-to-weight ratio, index)
        vector<pair<double, int>> items;
        for (int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], i});
        }

        // Sort items in descending order of value-to-weight ratio
        sort(items.rbegin(), items.rend());

        double maxValue = 0.0; // Maximum value that can be achieved
        for (auto& item : items) {
            int idx = item.second; // Get the index of the current item
            if (capacity >= wt[idx]) {
                // Take the whole item
                maxValue += val[idx];
                capacity -= wt[idx];
            } else {
                // Take a fraction of the item
                maxValue += item.first * capacity;
                break; // Knapsack is full
            }
        }

        return maxValue;
    }