class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Frequency array (only 26 letters A–Z)
        int freq[26] = {0};
        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        // Step 2: Push frequencies into max-heap
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push(freq[i]);
        }

        int ans = 0;

        // Step 3: Simulation loop
        while (!pq.empty()) {
            int cycle = n + 1;       // length of one scheduling frame
            vector<int> temp;        // store remaining counts

            // Execute up to (n+1) tasks in this cycle
            while (cycle > 0 && !pq.empty()) {
                int cnt = pq.top(); 
                pq.pop();
                cnt--;
                if (cnt > 0) temp.push_back(cnt);
                ans++;
                cycle--;
            }

            // Push remaining tasks back into heap
            for (int cnt : temp) {
                pq.push(cnt);
            }

            // If heap still has tasks, account for idle slots
            if (!pq.empty()) {
                ans += cycle;
            }
        }

        return ans;
    }
};
