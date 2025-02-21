class Solution{
public:
    int pageFaults(int N, int C, int pages[]) {
        list<int> cache;  // Stores pages in LRU order
        unordered_map<int, list<int>::iterator> pageMap; // Maps page to its position in cache
        int faults = 0;

        for (int i = 0; i < N; i++) {
            int page = pages[i];

            // Page not in cache -> Page Fault
            if (pageMap.find(page) == pageMap.end()) {
                faults++;
                
                // If cache is full, remove LRU page (last element in list)
                if (cache.size() == C) {
                    int lru = cache.back();
                    cache.pop_back();
                    pageMap.erase(lru);
                }
            } else {
                // Page is in cache, move it to the front
                cache.erase(pageMap[page]);
            }

            // Insert the page at the front (most recently used)
            cache.push_front(page);
            pageMap[page] = cache.begin();
        }
        
        return faults;
    }
};