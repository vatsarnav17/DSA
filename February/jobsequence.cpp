struct Job {  // Keep Job outside the class
    int id, deadline, profit;
};

class Solution {
  public:
    static bool comparision(const struct Job &a, const struct Job &b) {
        return a.profit > b.profit;
    }

    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        int n = id.size();
        vector<Job> jobs(n);

        // Creating Job objects
        for (int i = 0; i < n; i++) {
            jobs[i] = {id[i], deadline[i], profit[i]};
        }

        // Sorting jobs by profit in descending order
        sort(jobs.begin(), jobs.end(), Solution::comparision);

        // Finding maximum deadline
        int maxdeadline = 0;
        for (int i = 0; i < n; i++) {
            maxdeadline = max(maxdeadline, jobs[i].deadline);
        }

        // Time slots array to track job assignment
        vector<int> slots(maxdeadline + 1, -1);
        int jobcount = 0, maxprofit = 0;

        // Assign jobs to the latest available slot before their deadline
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].deadline; j > 0; j--) {
                if (slots[j] == -1) {
                    slots[j] = jobs[i].id;
                    jobcount++;
                    maxprofit += jobs[i].profit;
                    break;
                }
            }
        }

        return {jobcount, maxprofit};
    }
};