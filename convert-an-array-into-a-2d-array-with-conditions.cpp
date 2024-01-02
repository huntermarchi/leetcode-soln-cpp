class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;

        for (auto i : nums)
            mp[i]++;

        while (!mp.empty()) {
            vector<int> temp;
            vector<int> toErase;  // Store elements to be erased

            for (auto& [num, count] : mp) {
                temp.push_back(num);
                if (--count == 0)
                    toErase.push_back(num);
            }

            // Erase elements outside the loop
            for (auto num : toErase) {
                mp.erase(num);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
